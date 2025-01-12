#include <bits/stdc++.h>
using namespace std;
using ll = long long;
	
constexpr int MxN = 2e5+5;
ll dp[2][MxN][2];
int a[2][MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<2; i++)
		for (int j=1; j<=n; j++)
			cin >> a[i][j];
	
	for (int i=1; i<=n; i++)
	{
		dp[0][i][1] = max({dp[0][i-1][0], dp[1][i-1][1], dp[1][i-1][0]}) + (ll)a[0][i];
		dp[0][i][0] = max({dp[0][i-1][0], dp[0][i-1][1], dp[1][i-1][0], dp[1][i-1][1]});
		
		dp[1][i][1] = max({dp[1][i-1][0], dp[0][i-1][1], dp[0][i-1][0]}) + (ll)a[1][i];
		dp[1][i][0] = max({dp[1][i-1][0], dp[1][i-1][1], dp[0][i-1][0], dp[0][i-1][1]});
	}
	
	cout << max({dp[0][n][1], dp[0][n][0], dp[1][n][0], dp[1][n][1]}) << "\n";

    return 0;
}
