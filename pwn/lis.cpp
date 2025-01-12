/*
	Zadanie "Lista Kontaktów" z książki "Zaprzyjaźnij się z Algorytmami"
	DSU
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+66;
struct node { int p, s; };
node nodes[MxN];

void init(int v)
{
	nodes[v].p = v;
	nodes[v].s = 1;
}

int getLeader(int v)
{
	if (nodes[v].p == v)
		return v;
	return nodes[v].p = getLeader(nodes[v].p);
}

void join(int a, int b)
{
	a = getLeader(a), b = getLeader(b);
	if (nodes[a].s < nodes[b].s)
		swap(a, b);
	nodes[a].s += nodes[b].s;
	nodes[b].p = a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	for (int i=1; i<=n; i++)
		init(i);
	while (m--)
	{
		int a, b; cin >> a >> b;
		join(a, b);
	}
	int q; cin >> q;
	while (q--)
	{
		int a, b; cin >> a >> b;
		cout << (getLeader(a) == getLeader(b) ? "TAK\n" : "NIE\n");
	}

	return 0;
}