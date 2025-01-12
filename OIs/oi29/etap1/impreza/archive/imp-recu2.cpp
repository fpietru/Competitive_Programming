/*
	Zadanie "Impreza krasnali" z XXIX OI, etap I
	Autor rozwiązania: Franek Pietrusiak

	Rozwiązanie Brutalne Wersja 2
	Cel: Przekształcić na dynamika
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e5+15, INF = 99;
constexpr ll MOD = 1e9+7;
int h[MxN], p[MxN];
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
	// cout << i << " " << " [" << (L!=0) << "," << (M!=0) << "," << (R!=0) << "]\n";

	int next = (i <= n-2 ? 0 : INF);

	if (i == n+1)
	{
		// cout << "GOT IT!\n";
		return 1;
	}

	if (p[h[i]] < i && L != h[i])
		return 0;

	if (L == h[i])
		return solve(i+1, M, R, next);

	int Lside = 0;
	int Rside = 0;

	if (L == 0)
		Lside = solve(i+1, M, R, next);

	if (R == 0)
		Rside = solve(i+1, M, h[i], next);

	return Lside + Rside;
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

	int howmany = solve(1, INF, 0, 0);

	ll ans = (F(unused) * (ll)howmany) % MOD;
	cout << ans << "\n";

	return 0;
}
