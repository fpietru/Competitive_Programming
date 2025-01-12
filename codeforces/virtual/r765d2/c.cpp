#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 500;
int d[MxN+10], a[MxN+10];
int dp[MxN+10][MxN+10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, l, k; cin >> n >> l >> k;
	for (int i=1; i<=n; i++)
		cin >> d[i];
	for (int i=1; i<=n; i++)
		cin >> a[i];
	d[n+1] = l;
	
	memset(dp, 0x3f, sizeof(dp)); 
	for (int i=0; i<=k; i++)
		dp[1][i] = 0;
	
	for (int i=2; i<=n+1; i++)
		for (int j=0; j<=k; j++)
			for (int l=1; l<i; l++)
			{
				int len = i - l - 1;
				if (j >= len)
					dp[i][j] = min(dp[i][j], dp[l][j-len] + a[l] * (d[i] - d[l]));
			}
	
	cout << dp[n+1][k] << "\n";
	
	return 0;
}
