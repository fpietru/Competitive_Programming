/*
	Zadanie "Megalopolis" z XIV OI, II etap
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 250011, base = (1<<19);
vector<int> G[MxN];
int T[2*base + 11];
int pre[MxN], post[MxN], lvl[MxN];
int TIME = 0;

void dfs(int v, int p)
{
	pre[v] = ++TIME;
	for (auto u : G[v])
		if (u != p)
		{
			lvl[u] = lvl[v] + 1;
			dfs(u, v);
		}
	post[v] = ++TIME;
}

int getval(int v)
{
	int res = 0;
	v += base;
	while (v)
	{
		res += T[v];
		v /= 2;
	}
	return res;
}

void add(int a, int b, int x)
{
	a += base - 1;
	b += base + 1;
	while (a / 2 != b / 2)
	{
		if (a % 2 == 0) T[a+1] += x;
		if (b % 2 != 0) T[b-1] += x;
		a /= 2;
		b /= 2;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 

	int n; cin >> n;
	for (int i=1; i<=n-1; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	lvl[1] = 0;
	dfs(1, 1);

	int q; cin >> q;
	for (int i=0; i<n+q-1; i++)
	{
		char op; cin >> op;
		if (op == 'W')
		{
			int v; cin >> v;
			cout << lvl[v] - getval(pre[v]-1) << "\n";
		}
		else
		{
			int a, b; cin >> a >> b;
			add(pre[b]-1, post[b]-1, 1);
		}
	}
	
	return 0;
}