/*
	Link: https://codeforces.com/problemset/problem/463/D
*/
#include <bits/stdc++.h>
using namespace std;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int MxN = 1e3+3, MxK = 6;
int p[MxK][MxN]; // p[i][x] = pozycja elementu x w i-tej permutacji 
int dp[MxN]; // dp[v] = długość najdłuższej ścieżki, kończącej się w wierzchołku v
int deg[MxN]; // deg[v] = stopień wchodzący dla wierzchołka v
vector<int> G[MxN];
vector<int> tG[MxN];
int n, k;

// sprawdź, czy element a jest przed elementem b w każdej permutacji
bool check(int a, int b)
{
	for (int i=1; i<=k; i++)
		if (p[i][a] > p[i][b])
			return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i=1; i<=k; i++)
		for (int j=1; j<=n; j++)
		{
			int x; cin >> x;
			p[i][x] = j;
		}
		
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (i != j && check(i, j))
			{
				G[i].push_back(j), deg[j]++;
				tG[j].push_back(i);
			}
				
	// posortować topologicznie
	vector<int> torder;
	queue<int> Q;
	for (int i=1; i<=n; i++)
		if (deg[i] == 0)
			Q.push(i);
	
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		torder.push_back(v);
		for (auto u : G[v])
		{
			deg[u]--;
			if (deg[u] == 0)
				Q.push(u);
		}
	}
	
	// dp na DAG-u
	for (auto v : torder)
	{
		int mx = 0;
		for (auto u : tG[v])
			mx = max(mx, dp[u]);
		dp[v] = mx + 1;
	}
	
	int ans = 0;
	for (int i=1; i<=n; i++)
		ans = max(ans, dp[i]);
	
	cout << ans << "\n";
	
    return 0;
}
