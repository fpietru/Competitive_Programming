#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 505;
constexpr int INF = 1e9+7;
int p[MxN];
int dp[MxN][MxN];

int suma(int a, int b) {
	return p[b] - p[a-1];
}

void solve()
{
	string s; cin >> s;
	int n = s.size();
	for (int i=1; i<=n; i++)
		p[i] = p[i-1] + (s[i-1]-'a' + 1);

	for (int i=n; i>=1; i--)
		for (int j=i; j<=n; j++)
		{
			if (i == j)
			{
				dp[i][j] = 0;
				continue;
			}

			dp[i][j] = INF;
			for (int k=i; k<j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j] + abs(suma(i,k) - suma(k+1,j)));
		}
	
	/*
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++)
			cout << "[" << i << "," << j << "] = " << dp[i][j] << "\n";
	*/
		
	cout << dp[1][n] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q; cin >> q;
	while (q--)
		solve();

    return 0;
}
