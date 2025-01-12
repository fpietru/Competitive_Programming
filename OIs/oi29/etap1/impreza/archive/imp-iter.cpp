/*
	Zadanie "Impreza krasnali" z XXIX OI, etap I
	Autor rozwiązania: Franek Pietrusiak
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e5+15, INF = 99;
constexpr ll MOD = 1e9+7;
int h[MxN], p[MxN];
int dp[MxN][2][2][2];
int n, unused;
struct args { int i, L, M, R; };

ll F(ll x)
{
	ll res = 1;
	for (int i=1; i<=x; i++)
		res = (res * i) % MOD;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

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

	stack<args> st;
	st.push({1, INF, 0, 0});

	int howmany = 0;

	while (!st.empty())
	{
		int i = st.top().i;
		int L = st.top().L;
		int M = st.top().M;
		int R = st.top().R;
		st.pop();

		int s1 = (L != 0); 
		int s2 = (M != 0);
		int s3 = (R != 0);

		if (dp[i][s1][s2][s3] != -1)
		{
			howmany += dp[i][s1][s2][s3];
			continue;
		}

		int next = (i <= n-2 ? 0 : INF);

		if (i == n+1)
		{
			dp[i][s1][s2][s3] = 1;
			howmany++;
			continue;
		}

		if (p[h[i]] < i && L != h[i])
		{
			dp[i][s1][s2][s3] = 0;
			continue;
		}

		if (L == h[i])
		{
			st.push({i+1, M, R, next});
			
			continue;
		}

		int Lside = 0;
		int Rside = 0;

		if (L == 0)
			st.push({i+1, M, R, next});

		if (R == 0)
			st.push({i+1, M, h[i], next});
	}

	ll ans = (F(unused) * (ll)howmany) % MOD;
	cout << ans << "\n";

	return 0;
}
