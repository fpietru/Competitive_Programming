/*
	Zadanie "Impreza krasnali" z XXIX OI, etap I
	Autor rozwiązania: Franek Pietrusiak
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e5+15, MOD = 1e9+7;
int h[MxN], dp[MxN][2][2][2], a[MxN];
vector<int> pos[MxN];
vector<int> spns;
int n, rec = 0;

int F(int x)
{
	int res = 1;
	for (int i=1; i<=x; i++)
		res = ((ll)res * i) % MOD;
	return res;
}

int solve(int i, bool L, bool M, bool R)
{
	int p = spns[i];
	int s1 = (p==1 || a[p-1] != 0 || L);
	int s2 = (        a[p] != 0   || M);
	int s3 = (p==n || a[p+1] != 0 || R);

	// cout << i+1 << " " << p << " [" << s1 << s2 << s3 << "]\n";

	if (dp[p][s1][s2][s3] == -1)
	{
		int ans = 0;

		if (i == spns.size()-1)
			ans = (s1==0) + (s3==0);
		else
		{
			if (s1 == 0)
			{
				bool A = 0, B = 0, C = 0;
				if (spns[i+1] - p == 1)
					A = s2, B = s3;
				if (spns[i+1] - p == 2)
					A = s3;

				if (dp[p][A][B][C] != -1)
					ans += dp[p][A][B][C];
				else
					ans += solve(i+1, A, B, C);
			}
			
			if (s3 == 0)
			{
				bool A = 0, B = 0, C = 0;
				if (spns[i+1] - p == 1)
					A = s2, B = 1;
				if (spns[i+1] - p == 2)
					A = 1;

				if (dp[p][A][B][C] != -1)
					ans += dp[p][A][B][C];
				else
					ans += solve(i+1, A, B, C);
			}
		}

		dp[p][s1][s2][s3] = ans % MOD;
	}

	return dp[p][s1][s2][s3];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));

	cin >> n;	
	for (int i=1; i<=n; i++)
	{
		cin >> h[i];
		pos[h[i]].push_back(i);
	}

	int unused = 0;
	for (int i=1; i<=n; i++)
	{
		if (pos[i].size() == 0)
			unused++;
		else if ((pos[i].size() == 2 && pos[i][1]-pos[i][0] != 2) || pos[i].size() > 2)
		{
			cout << "0\n";
			return 0;
		}
	}

	for (int i=2; i<n; i++)
	{
		if (h[i-1] == h[i+1])
			a[i] = h[i-1];
		else if (n == 3)
		{
			cout << "0\n";
			return 0;
		}
	}

	for (int i=1; i<=n; i++)
	{
		if (a[i-1] != h[i] && h[i] != a[i+1])
			spns.push_back(i);
	}

	int howmany = solve(0, 0, 0, 0);
	int ans = ((ll)F(unused) * howmany) % MOD;
	
	cout << ans << "\n";

	return 0;
}