/*
	Zadanie "Historyjka" z OKI
*/
#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e6+6, mod = 1e9+9;
vector<int> G[MxN];
int W[MxN];
long long dp[MxN];
int n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int A, B;
	cin >> n >> m >> A >> B;
	for (int i=0; i<m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		W[b]++;
	}

	queue<int> qu;
	vector<int> tsorted;

	for (int i=1; i<=n; i++)
		if (W[i] == 0)
			qu.push(i);

	while (!qu.empty())
	{
		int v = qu.front();
		qu.pop();

		tsorted.push_back(v);

		for (auto u : G[v])
		{
			W[u]--;
			if (W[u] == 0)
				qu.push(u);
		}
	}

	dp[A] = 1;
	for (auto v : tsorted)
		for (auto u : G[v])
			dp[u] = (dp[u] + dp[v]) % mod;

	cout << dp[B] % mod << "\n";

	return 0;
}