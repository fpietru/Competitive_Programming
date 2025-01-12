/*
	Link do zadania: https://atcoder.jp/contests/dp/tasks/dp_e
	Link do omówienia: https://leetcode.com/discuss/general-discussion/633255/knapsack-2-atcoder-help
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e2+22, MxV = 1e3+33;
constexpr ll INF = 1e18+7;
ll dp[MxN+1][MxN*MxV+1];
int w[MxN], v[MxN];

/*
	dp[i][j] = minimalna waga przedmiotów spośród i pierwszych,
	których suma wartości jest równa j 
	dp[0][x>0] = INF
	dp[x>0][0] = 0
	dp[0][0] = 0
*/

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, W; cin >> n >> W;
	for (int i=1; i<=n; i++)
		cin >> w[i] >> v[i];

	for (int i=1; i<=MxN*MxV; i++) dp[0][i] = INF;
	for (int i=0; i<=n; i++) dp[i][0] = 0;

	for (int i=1; i<=n; i++)
		for (int j=1; j<=MxN*MxV; j++)
		{
			if (v[i] <= j)
				dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]]+(ll)w[i]);
			else dp[i][j] = dp[i-1][j];
		}

	for (int i=MxN*MxV; i>=0; i--)
		if (dp[n][i] <= W)
		{
			cout << i << "\n";
			break;
		}

	return 0;
}