/*
	Link do zadania: https://atcoder.jp/contests/dp/tasks/dp_c
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e5+55;
int a[MxN][3], dp[MxN][3];

/*
	dp[i][k] = maksymalne zadowolenie i-tego dnia jeśli Taro bedzie uprawiał k-tą aktywność
	dp[dzis][aktywność] = max(dp[wczoraj][inna_aktywność]+zadowolenie[dzis][aktywność], dp[wczoraj][jeszcze_inna_aktywność]+zadowolenie[dzis][aktywność])
*/

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=0; j<3; j++)
			cin >> a[i][j];

	for (int k=0; k<3; k++)
		dp[1][k] = a[1][k];

	for (int i=1; i<=n; i++)
		for (int k=0; k<3; k++)
			dp[i][k] = max(dp[i-1][(k+1)%3]+a[i][k], dp[i-1][(k+2)%3]+a[i][k]);

	int ans = -1e9-7;
	for (int k=0; k<3; k++)
		ans = max(ans, dp[n][k]);

	cout << ans << "\n";
	
	return 0;
}