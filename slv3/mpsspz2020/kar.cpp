#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 2e5+55;
int t[4][MxN], dp[4][MxN][2];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<4; i++)
		for (int j=0; j<n; j++)
			cin >> t[i][j];
	
	for (int i=0; i<4; i++)
		for (int j=0; j<n; j++)
		{
			if (i > 0 && j == 0)
			{
				dp[i][j][1] = dp[i-1][j][0] + t[i][j];
				dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]);
			}
			if (i == 0 && j > 0)
			{
				dp[i][j][1] = dp[i][j-1][0] + t[i][j];
				dp[i][j][0] = max(dp[i][j-1][0], dp[i][j-1][1]);	
			}
			if (i > 0 && j > 0)
			{
				dp[i][j][1] = dp[i-1][j][0] + dp[i][j-1][0] + t[i][j];
				dp[i][j][0] = max({dp[i][j-1][0], dp[i][j-1][1], dp[i-1][j][0], dp[i-1][j][1]});
			}
		}

	cout << max(dp[4][n][0], dp[4][n][1]) << "\n";

	return 0;
}