/*
	Algorytm Kruskal'a do znajdowania MST
	Złożoność czasowa: O(M logN)
	Sprawdzenie Poprawności: https://www.spoj.com/problems/MST/
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e4+4;
constexpr int MxM = 1e5+5;
struct node { int p, s; };
struct edge { int v, u, w; };
node nodes[MxN];
edge edges[MxM];

void init(int v)
{
	nodes[v].p = v;
	nodes[v].s = 1;
}

int getL(int v)
{
	if (nodes[v].p == v)
		return v;
	return nodes[v].p = getL(nodes[v].p);
}

void join(int a, int b)
{
	a = getL(a);
	b = getL(b);
	if (a != b)
	{
		if (nodes[a].s < nodes[b].s)
			swap(a, b);
		nodes[a].s += nodes[b].s;
		nodes[b].p = a;
	}
}

bool cmp(edge a, edge b)
{
	return a.w <= b.w;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=0; i<m; i++)
		cin >> edges[i].v >> edges[i].u >> edges[i].w;

	sort(edges, edges+m, cmp);
	
	for (int i=1; i<=n; i++)
		init(i);
	
	ll MST_weight = 0LL;
	
	for (int i=0; i<m; i++)
	{
		int A = edges[i].v;
		int B = edges[i].u;
		int W = edges[i].w;
		
		if (getL(A) != getL(B))
		{
			MST_weight += (ll)W;
			join(A, B);
		}
	}
	
	cout << MST_weight << "\n";

    return 0;
}
