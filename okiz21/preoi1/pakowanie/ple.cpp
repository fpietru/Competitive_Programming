#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 5015;
constexpr ll INF = 1e18+7;
ll dp[MxN][MxN];
ll a[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	
	for (int i=0; i<MxN; i++)
		dp[i][0] = 0;
	for (int i=1; i<MxN; i++)
		dp[n+1][i] = INF;
		
	for (int k=1; k<=n; k++)
		for (int i=n; i>=1; i--)
		{
			if (a[i] > dp[i+1][k])
				dp[i][k] = dp[i+1][k];
			else
				dp[i][k] = a[i] + dp[i+1][k-1];
		}
		
	for (int i=1; i<=n; i++)
		cout << dp[1][i] << " ";
	cout << "\n";
	
	return 0;
}



