#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define FR first
#define SD second
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int MxN = 5e5+15;
vector<int> G[MxN];
int K[MxN];
int subtree[MxN];
int color[MxN];
int ktowezmie[MxN][3];
int n, odwiedzone[3], ans;
int licznik = 0;
int ile[3];

void dfs1(int v, int p)
{
	subtree[v] = 1;
	for (auto u : G[v])
		if (u != p)
		{
			dfs1(u, v);
			subtree[v] += subtree[u];
		}
}

void dfs2(int v, int p, int kto)
{
	ktowezmie[v][kto] = ++licznik;
		
	vector<pii> vec;		
	for (auto u : G[v])
		if (u != p)
			vec.push_back({subtree[u], u});
	sort(vec.begin(), vec.end());
	for (auto V : vec)
		dfs2(V.SD, v, kto);
}

void dfs3(int v, int p, int c)
{

	if (p != -1)
		ans++;
	odwiedzone[c]++;
	deb(v, c, odwiedzone[c]);
		
	vector<pii> vec;		
	for (auto u : G[v])
		if (u != p && color[u] == color[v])
			vec.push_back({subtree[u], u});

	sort(vec.begin(), vec.end());
	
	for (auto V : vec)
		dfs3(V.SD, v, c);
	
	if (odwiedzone[c] != ile[c])
		ans++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int k; cin >> n >> k;
	for (int i=1; i<=k; i++)
		cin >> K[i];
	for (int i=1; i<=n-1; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	if (k == 1)
	{
		dfs1(K[1], -1);
		dfs2(K[1], -1, 0);
		
		cout << ans << "\n";
	}
	else if (k == 2)
	{
		// dla A
		dfs1(K[1], -1);
		dfs2(K[1], -1, 0);
		
		// dla B
		licznik = 0;
		dfs1(K[2], -1);
		dfs2(K[2], -1, 1);
		
		for (int i=1; i<=n; i++)
		{
			if (ktowezmie[i][0] < ktowezmie[i][1])
				color[i] = 1, ile[0]++;
			else
				color[i] = 2, ile[1]++;
		}
		
		dfs3(K[1], -1, 1);
		dfs3(K[2], -1, 2);
		
		cout << ans << "\n";
	}
	

    return 0;
}
