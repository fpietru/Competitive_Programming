/*
	Link do zadania: https://atcoder.jp/contests/dp/tasks/dp_h
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e3+33, MOD = 1e9+7;
char a[MxN][MxN];
int dp[MxN][MxN];

/*
	dp[i][j] = liczba ścieżek jakimi można się dostać do pola (i,j)
	dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD,
	bo do pola (i,j) można wejść tylko od lewego i górnego sąsiada
*/

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int h, w; cin >> h >> w;
	for (int i=1; i<=h; i++)
		for (int j=1; j<=w; j++)
			cin >> a[i][j];

	for (int i=1; i<=h; i++)
		for (int j=1; j<=w; j++)
		{
			// base case
			if (i==1 && j==1)
			{
				dp[i][j] = 1;
				continue;
			}

			if (a[i][j] == '#') dp[i][j] = 0;
			else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
		}

	cout << dp[h][w] << "\n";

	return 0;
}