/*
	Zadanie "Astmatyk" z KI
*/
#include <bits/stdc++.h>
using namespace std;

struct edge { int a, b, w; };
struct node { int p, s; };
constexpr int MxN = 1e5+55, MxM = 3e5+55;
edge edges[MxM];
node nodes[MxN];
int h[MxN];
int n, m;

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

bool cmp(edge A, edge B)
{
	if (A.w == B.w)
	{
		if (A.a == n || A.b == n)
			return 1;
		else return 0;
	}
	return A.w < B.w;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> h[i], init(i);
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		edges[i] = {a, b, max(h[a], h[b])};
	}

	sort(edges+1, edges+m+1, cmp);

	int ans = -1;
	for (auto e : edges)
	{
		if (getL(e.a) != getL(e.b))
		{
			join(e.a, e.b);
			ans = max(ans, e.w);
		}
		if (getL(1) == getL(n))
			break;
	}
	
	cout << ans << "\n";

	return 0;
}