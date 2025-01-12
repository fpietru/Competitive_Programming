/*
	https://www.spoj.com/problems/EDIST/
*/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string a, b;
	cin >> a >> b;

	int n = a.size();
	int m = b.size();

	vector<vector<int>> dp(n+1, vector<int>(m+1));
	for (int i=0; i<=n; i++) dp[i][0] = i;
	for (int i=0; i<=m; i++) dp[0][i] = i;

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			int c = 0;
			if (a[i-1] != b[j-1]) c = 1;

			dp[i][j] = min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+c});
		}

	cout << dp[n][m] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}
