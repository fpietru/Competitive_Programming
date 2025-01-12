/*
	Zadanie "Megalopolis" z XIV OI
*/
#include <bits/stdc++.h>
#define FR first
#define SD second
using namespace std;

const int MxN = 25e4+4;
vector<int> G[MxN]; // Lista sąsiedztwa
int ord[MxN][2]; // Pre-Post order
int vis[MxN];
int lvl[MxN];
int n, m, a, b, t=0;

void bfs(int v, int time)
{
	queue<pair<int, int>> qu;
	qu.push({v, 0});
	while (!qu.empty())
	{
		pair<int, int> u = qu.front();
		qu.pop();
		vis[u.FR] = time;
		lvl[u.FR] = u.SD;
		for (auto n : G[u.FR])
			if (vis[n] != time)
				qu.push({n, u.SD+1});
	}
}

void dfs(int v, int time)
{
	ord[v][0] = ++t;
	vis[v] = time;
	for (auto u : G[v])
		if (vis[u] != time)
			dfs(u, time);
	ord[v][1] = ++t;
}

class Tree // wzorowane na https://cp-algorithms.com/data_structures/segment_tree.html
{
private:
	int *tree, leafsize;
public:
	Tree(int base)
	{
		leafsize = 1 << base;
		tree = new int[leafsize << 1];
		for (int i=0; i<(leafsize << 1); i++)
			tree[i] = 0;
	}
	~Tree() { delete[] tree; }

	void update(int v, int tl, int tr, int l, int r, int val)
	{
		if (l > r) return;
		if (tl == l && r == tr)
			tree[v] += val;
		else
		{
			int m = (tl + tr) >> 1;
			update(v << 1, tl, m, l, min(m, r), val);
			update((v << 1)+1, m+1, tr, max(m+1, l), r, val);
		}
	}

	int get(int v, int tl, int tr, int pos)
	{
		if (tl == tr)
			return tree[v];
		else
		{
			int m = (tl + tr) >> 1;
			if (pos <= m)
				return tree[v] + get(v << 1, tl, m, pos);
			else
				return tree[v] + get((v << 1)+1, m+1, tr, pos);
		}
	}
};


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i=0; i<n-1; i++)
	{
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	bfs(1, 1);
	dfs(1, 2);

	cin >> m;
	vector<int> ans;
	Tree drzewo(19);
	for (int i=0; i<n+m; i++)
	{
		char type; cin >> type;
		if (type == 'A')
		{
			int l; cin >> a >> b;
			(ord[a][0] > ord[b][0] && ord[a][1] < ord[b][1] ? l = a : l = b);
			drzewo.update(1, 0, n<<1, ord[l][0], ord[l][1], 1);
		}
		else
		{
			cin >> a;
			ans.push_back(lvl[a] - drzewo.get(1, 0, n<<1, ord[a][0]));
		}
	}

	for (int i=0; i<m; i++)
		cout << ans[i] << "\n";
	
	return 0;
}