/*
	Link do zadania: https://atcoder.jp/contests/dp/tasks/dp_d
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e2+22, MxW = 1e5+55, INF = 1e9+7;
int w[MxN], v[MxN];
ll dp[MxN][MxW];

/*
	dp[i][m] = maksymalna wartość przedmiotów spośród i pierwszych,
	które w sumie ważą mniej lub równo m 
	dp[0≤i≤n][0] = 0
	dp[0][0≤j≤W] = 0
*/

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, W; cin >> n >> W;
	for (int i=1; i<=n; i++)
		cin >> w[i] >> v[i];

	for (int i=0; i<=n; i++) dp[i][0] = 0;
	for (int i=0; i<=W; i++) dp[0][i] = 0;

	for (int i=1; i<=n; i++)
		for (int m=0; m<=W; m++)
		{
			if (w[i] <= m)
				dp[i][m] = max((ll)dp[i-1][m-w[i]]+v[i], dp[i-1][m]);
			else
				dp[i][m] = dp[i-1][m];
		}

	cout << dp[n][W] << "\n";
	
	return 0;
}