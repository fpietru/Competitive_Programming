#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e4+44, MxW = 5e2+22;
ll dp[MxN][MxW];
int w[MxN], v[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, W; cin >> n >> W;
	for (int i=1; i<=n; i++)
		cin >> w[i] >> v[i];

	for (int i=1; i<=n; i++)
		for (int j=0; j<=W; j++)
		{
			if (w[i] <= j)
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+(ll)v[i]);
			else dp[i][j] = dp[i-1][j];
		}

	cout << dp[n][W] << "\n";
	
	return 0;
}