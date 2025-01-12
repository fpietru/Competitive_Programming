/*
	Zadanie "Impreza krasnali" z XXIX OI, etap I
	Autor rozwiązania: Franek Pietrusiak

	Cel:
	-Porządnie przetestować pod względem bugów
	-Zająć się MOD'ami
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e5+15, INF = 1e9+9;
constexpr ll MOD = 1e9+7;
int h[MxN], p[MxN];
ll dp[MxN+5][2][2][2];
int n;

ll F(ll x)
{
	ll res = 1;
	for (int i=1; i<=x; i++)
		res = (res * i) % MOD;
	return res;
}

ll solve(int i, int L, int M, int R)
{
	int s1 = (L!=0);
	int s2 = (M!=0);
	int s3 = (R!=0);

	// cout << i << " " << " [" << L << "," << M << "," << R << "] " << dp[i][s1][s2][s3] << "\n";

	if (dp[i][s1][s2][s3] == -1)
	{
		ll ans = 0;
		int next = (i <= n-2 ? 0 : INF);

		if (i == n+1)
			ans = 1;
		else
		{
			if (p[h[i]] < i && L != h[i])
				ans = 0;
			else
			{
				if (L == 0 || L == h[i])
					ans += solve(i+1, M, R, next) % MOD;

				if (R == 0 && L != h[i])
					ans += solve(i+1, M, h[i], next) % MOD;
			}
		}

		dp[i][s1][s2][s3] = ans % MOD;
	}
	
	return dp[i][s1][s2][s3] % MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

/*	double mem = (double)(sizeof(h)+sizeof(p)+sizeof(dp)) / 1048576.0;
	cout << mem << "\n";*/

	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> h[i];
		if (p[h[i]] == 0)
			p[h[i]] = i;
	}

	ll unused = 0;
	for (int i=1; i<=n; i++)
		if (p[i] == 0)
			unused++;

	int howmany = solve(1, INF, 0, 0);

	// cout << howmany << " " << unused << "\n";

	ll ans = ((F(unused) % MOD) * ((ll)howmany % MOD)) % MOD;
	cout << ans << "\n";

	return 0;
}