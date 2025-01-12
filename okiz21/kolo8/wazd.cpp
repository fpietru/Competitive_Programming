#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e4+4;
ll dp[MxN];

/*
	Fajna optymalizacja pamięci:
	Zamiast przechowywać tablicę rozmiaru N*M
	będziemy N razy nadpisywać tablicę rozmiaru M
*/

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			ll v; cin >> v;
			if (i == 1 && j == 1) dp[j] = v;
			else if (i > 1 && j == 1) dp[j] += v;
			else if (i == 1 && j > 1) dp[j] = dp[j-1] + v;
			else dp[j] = max(dp[j-1], dp[j]) + v;
		}
	cout << dp[m] << "\n";
	
	return 0;
}