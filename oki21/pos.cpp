/*
	Zadanie "Posterunki" z Codeforces
	Oryginalne Zadanie: https://codeforces.com/problemset/problem/427/C
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = 1e5+5, mod = 1e9+7;
vector<int> G[MxN], tG[MxN]; // graf i graf transponowany
int arr[MxN]; // cena wybudowania posterunku
int comps[MxN]; // do jakiego scc należy dany wierzchołek
int MiE[MxN]; // minimalna cena w scc
int cMi[MxN]; // liczba minimalnych elementów w scc
bool vis[MxN]; // czy dany wierzchołek był już odwiedzony
stack<int> st;
int n, m, c=0; // liczba wierzchołków, krawędzi, scc
ll ans1 = 0, ans2 = 1;

void DFS(int v)
{
	vis[v] = 1;
	for (auto u : G[v])
		if (!vis[u])
			DFS(u);
	st.push(v);
}

void SCC(int v, int c)
{
	comps[v] = c;
	for (auto u : tG[v])
		if (!comps[u])
			SCC(u, c);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> arr[i];
	cin >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		tG[b].push_back(a);
	}

	for (int i=1; i<=n; i++)
		if (!vis[i])
			DFS(i);

	while (!st.empty())
	{
		int v = st.top();
		st.pop();
		if (!comps[v])
			SCC(v, ++c);
	}
	
	for (int i=1; i<=c; i++)
		MiE[i] = 1e9+9;

	// Znajdowanie minimalnej ceny dla każdego scc 
	for (int i=1; i<=n; i++)
		MiE[comps[i]] = min(MiE[comps[i]], arr[i]);

	// Zliczanie ilości minimalnych elementów w scc
	for (int i=1; i<=c; i++)
		ans1 += MiE[i];

	for (int i=1; i<=n; i++)
		if (arr[i] == MiE[comps[i]])
			cMi[comps[i]]++;

	for (int i=1; i<=c; i++)
		ans2 = (ans2 * cMi[i]) % mod;

	cout << ans1 << " " << ans2 << "\n";

	return 0;
}