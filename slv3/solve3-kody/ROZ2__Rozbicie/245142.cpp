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

	int n, m; cin >> n >> m;
	for (int i=1; i<=n; i++)
		init(i);
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		edges[i] = {a, b};
	}
	
	int q; cin >> q;
	for (int i=1; i<=q; i++)
	{
		cin >> Q[i];
		niemozna[Q[i]] = 1;
	}
	
	int spojne = n;
	for (int i=1; i<=m; i++)
		if (niemozna[i] == 0)
		{
			int v = edges[i].FR;
			int u = edges[i].SD;
			if (getL(v) != getL(u))
				spojne--;
			join(v, u);
			
			// cout << i << " " << spojne << "\n";
		}

	vector<int> ans;
	for (int i=q; i>=1; i--)
	{
		ans.push_back(spojne);
		if (getL(edges[Q[i]].FR) != getL(edges[Q[i]].SD))
			spojne--;
		join(edges[Q[i]].FR, edges[Q[i]].SD);  
	}
	
	reverse(ans.begin(), ans.end());
	
	for (auto p : ans)
		cout << p << " ";
	cout << "\n";

    return 0;
}
