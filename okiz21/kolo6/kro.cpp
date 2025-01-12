/*
	Zadanie "Króliczek Mareczek" z KI
	Dynamik
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e6+66;
ll dp[MxN][2];
int a[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, x; cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=1; i<=n; i++)
	{
		dp[i][1] = dp[i-1][0] + a[i-1];
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
	}

	cout << max(dp[n][0], dp[n][1]) << "\n";
	
	return 0;
}