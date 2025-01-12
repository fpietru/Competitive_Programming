#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+6;
constexpr int INF = 1e9+7;
int dp[MxN][3];
int a[MxN][3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=0; j<3; j++)
			cin >> a[i][j];

	for (int i=1; i<=n; i++)
		for (int j=0; j<3; j++)
		{
			dp[i][j] = INF;
			for (int k=0; k<3; k++)
				if (k != j)
					dp[i][j] = min(dp[i][j], dp[i-1][k] + a[i][j]);
		}
	
	cout << min({dp[n][0], dp[n][1], dp[n][2]}) << "\n";

    return 0;
}
