/*
	Algorytm Boruvki
	Złożoność czasowa: O(M logN)
	Sprawdzenie Poprawności: https://www.spoj.com/problems/MST/
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node { int p, s; };
struct edge { int v, u, w; };
constexpr int MxN = 1e4+4;
constexpr int MxM = 1e5+5;
node nodes[MxN];
edge edges[MxM];
int min_e[MxN];
/*
	min_e[i] = krawędź o minimalnej wadze, która wychodzi ze spójnej nr. i
	nodes = do DSU
	edges = przechowywanie wszystkich krawędzi
*/

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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++)
		cin >> edges[i].v >> edges[i].u >> edges[i].w;
	
	// na początku każdy wierzchołek jest jedną spójną
	for (int i=1; i<=n; i++)
		init(i);
	
	// sumaryczna waga MST
	ll MST_weight = 0LL;
	int spojne = n;
	
	while (spojne > 1)
	{
		// resetowanie min_e dla każdej spójnej
		for (int i=1; i<=n; i++)
			min_e[i] = -1;
			
		// znajdowanie min_e dla każdej spójnej
		for (int i=1; i<=m; i++)
		{
			if (getL(edges[i].v) == getL(edges[i].u))
				continue;
			
			int Lv = getL(edges[i].v);
			int Lu = getL(edges[i].u);
			
			if (min_e[Lv] == -1 || edges[i].w <= edges[min_e[Lv]].w)
				min_e[Lv] = i;
			
			if (min_e[Lu] == -1 || edges[i].w <= edges[min_e[Lu]].w)
				min_e[Lu] = i;
		}
		
		// łączenie spójnych na podstawie ich min_e
		for (int i=1; i<=n; i++)
			if (min_e[i] != -1)
			{
				int A = edges[min_e[getL(i)]].v;
				int B = edges[min_e[getL(i)]].u;
				int W = edges[min_e[getL(i)]].w;
				
				if (getL(A) != getL(B))
				{
					join(A, B);
					MST_weight += (ll)W;
					spojne--;
				}
			}
	}
	
	cout << MST_weight << "\n";

    return 0;
}
