/*
	Zadanie "Impreza krasnali" z XXIX OI, etap I
	Autor rozwiązania: Franek Pietrusiak

	Rozwiązanie Brutalne Wersja 2
	Cel: Przekształcić na dynamika
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FR first
#define SD second

constexpr int MxN = 1e5+15, INF = 1e9+9;
constexpr ll MOD = 1e9+7;
int h[MxN], p[MxN];
int dp[MxN+5][2][2][2];
int n, unused;

ll F(ll x)
{
	ll res = 1;
	for (int i=1; i<=x; i++)
		res = (res * i) % MOD;
	return res;
}

int solve(int i, int L, int M, int R)
{
	int s1 = (L!=0);
	int s2 = (M!=0);
	int s3 = (R!=0);

	// cout << i << " " << " [" << L << "," << M << "," << R << "] " << dp[i][s1][s2][s3] << "\n";

	if (dp[i][s1][s2][s3] != -1)
	{
		// cout << "ALREADY SEEN; value = " << dp[i][s1][s2][s3] << "\n";
		return dp[i][s1][s2][s3];
	}

	int next = (i <= n-2 ? 0 : INF);

	if (i == n+1)
	{
		// cout << "GOT IT!\n";
		dp[i][s1][s2][s3] = 1;
		return dp[i][s1][s2][s3];
	}

	if (p[h[i]] < i && L != h[i])
	{
		// cout << "DEAD END\n";
		dp[i][s1][s2][s3] = 0;
		return dp[i][s1][s2][s3];
	}

	if (L == h[i])
	{
		dp[i][s1][s2][s3] = solve(i+1, M, R, next); 
		return dp[i][s1][s2][s3];
	}

	int Lside = 0;
	int Rside = 0;

	if (L == 0)
		Lside = solve(i+1, M, R, next);

	if (R == 0)
		Rside = solve(i+1, M, h[i], next);

	dp[i][s1][s2][s3] = Lside + Rside;
	return dp[i][s1][s2][s3];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	/*double mem = (double)(sizeof(h)+sizeof(p)+sizeof(dp)) / 1048576.0;
	cout << mem << "\n";*/

	for (int i=0; i<=MxN; i++)
		for (int j=0; j<2; j++)
			for (int k=0; k<2; k++)
				for (int l=0; l<2; l++)
					dp[i][j][k][l] = -1;

	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> h[i];
		if (p[h[i]] == 0)
			p[h[i]] = i;
	}

	for (int i=1; i<=n; i++)
		if (p[i] == 0)
			unused++;

	ll howmany = solve(1, INF, 0, 0);

	// cout << howmany << "\n";

	ll ans = ((F(unused) % MOD) * (howmany % MOD)) % MOD;
	cout << ans << "\n";

	return 0;
}