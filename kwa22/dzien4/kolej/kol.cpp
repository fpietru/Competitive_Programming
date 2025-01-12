#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int MxN = 2e5+5;
constexpr int LOG = 18;

vector<pii> G[MxN];
pii up[MxN][LOG];
int lvl[MxN];
int PODZADANIE;
bool inicjowaneLCA = 0;
int n;

void dfs(int v, int p, int w)
{
	lvl[v] = lvl[p] + 1;
	up[v][0].FR = p;
	up[v][0].SD = w;

	for (auto e : G[v])
		if (e.FR != p)
			dfs(e.FR, v, e.SD);
}

int lca(int a, int b)
{
	int res = 0;
	
	if (lvl[a] < lvl[b])
		swap(a, b);

	for (int i=LOG-1; i>=0; i--)
		if (lvl[a] - (1<<i) >= lvl[b])
		{
			res += up[a][i].SD;
			a = up[a][i].FR;
		}

	if (a == b)
		return res;

	for (int i=LOG-1; i>=0; i--)
		if (up[a][i].FR != up[b][i].FR)
		{
			res += up[a][i].SD + up[b][i].SD;
			a = up[a][i].FR;
			b = up[b][i].FR;
		}

	return res + up[a][0].SD + up[b][0].SD;
}

void initLCA()
{
	for (int i=1; i<=n; i++)
		if (up[i][0].FR == 0)
			dfs(i, i, 0);

	for (int k=1; k<LOG; k++)
		for (int x=1; x<=n; x++)
		{
			up[x][k].SD = up[up[x][k-1].SD][k-1].SD;
			up[x][k].FR = up[up[x][k-1].FR][k-1].FR;
		}
}

void build(int x, int y, int m)
{
	G[x].push_back({y, m});
	G[y].push_back({x, m});
}

int path(int x, int y)
{
	if (PODZADANIE == 2)
	{
		if (inicjowaneLCA == 0)
		{
			inicjowaneLCA = 1;
			initLCA();
		
			for (int i=1; i<=n; i++)
			{
				cout << i << ": ";
				for (auto e : G[i])
					cout << "[" << e.FR << "," << e.SD << "] ";
				cout << "\n"; 
			}
			
			for (int i=1; i<=n; i++)
			{
				cout << i << ": ";
				for (int j = 0; j<LOG; j++)
					cout << "[" << up[i][j].FR << "," << up[i][j].SD << "] ";
				cout << "\n";
			}
		}
	
		return lca(x, y);
	}
}

void init(int N, int S)
{
	PODZADANIE = S;
	n = N;
}










