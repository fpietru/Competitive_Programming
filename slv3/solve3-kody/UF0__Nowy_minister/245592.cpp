#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

struct node {
	int p, s;
};
constexpr int MxN = 1e5+5;
constexpr int MxM = 2e5+5;
int Q[MxN];
node nodes[MxN];
pii edges[MxM];
bool niemozna[MxM];

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
	if (nodes[a].s < nodes[b].s)
		swap(a, b);
	nodes[a].s += nodes[b].s;
	nodes[b].p = a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, q; cin >> n >> m >> q;
	for (int i=1; i<=n; i++)
		init(i);
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		join(a, b);
	}
	while (q--)
	{
		int w, a, b; cin >> w >> a >> b;
		if (w == 0)
			cout << (getL(a) == getL(b) ? "TAK\n" : "NIE\n");
		else
			join(a, b);
	}

    return 0;
}
