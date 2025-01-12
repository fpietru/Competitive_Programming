/*
	Zadanie "Impreza krasnali" z XXIX OI, etap I
	Autor rozwiązania: Franek Pietrusiak
	Utility do testowania
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e5+15, INF = 1e9+9, MOD = 1e9+7;
int h[MxN], p[MxN], dp[MxN][2][2][2];
int n;

int F(int x)
{
	int res = 1;
	for (int i=1; i<=x; i++)
		res = ((ll)res * i) % MOD;
	return res;
}

int solve(int i, int L, int M, int R)
{
	int s1 = (L!=0);
	int s2 = (M!=0);
	int s3 = (R!=0);

	if (dp[i][s1][s2][s3] == -1)
	{
		int ans = 0;
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
					ans += solve(i+1, M, R, next);

				if (R == 0 && L != h[i])
					ans += solve(i+1, M, h[i], next);
			}
		}

		dp[i][s1][s2][s3] = ans % MOD;
	}

	return dp[i][s1][s2][s3];
}

int getans(string s)
{
	memset(dp, -1, sizeof(dp));
	memset(h, 0, sizeof(h));
	memset(p, 0, sizeof(p));

	n = s.size();
	s.insert(0, "#");
	for (int i=1; i<=n; i++)
	{
		h[i] = s[i]-'0';
		if (p[h[i]] == 0)
			p[h[i]] = i;
	}

	int unused = 0;
	for (int i=1; i<=n; i++)
		if (p[i] == 0)
			unused++;

	int howmany = solve(1, INF, 0, 0);
	int ans = ((ll)F(unused) * howmany) % MOD;
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int pos = 1;
	string s;
	int expected;
	while (cin >> s >> expected)
	{
		if (getans(s) == expected)
			cout << pos << " OK\n";
		else
		{
			cout << pos << " WA\n";
			return 0;
		}
		pos++;
	}

	return 0;
}
