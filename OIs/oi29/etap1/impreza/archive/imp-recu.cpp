/*
	Zadanie "Impreza krasnali" z XXIX OI, etap I
	Autor rozwiązania: Franek Pietrusiak

	Rozwiązanie Brutalne
	Cel: Przekształcić na dynamika
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e5+15, INF = 1e9+9;
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

ll V(int a, int b)
{
	if (a == b)
		return F(a);
	return F(a) / F(a-b);
}

ll solve(int i, int f, int L, int M, int R)
{
	// cout << i << " " << f << " [" << L << "," << M << "," << R << "] ";

	int next = (i <= n-2 ? 0 : INF);

	if (i == n+1)
	{
		// cout << "END\n";
		int free_space = f + (L == 0);
		return V(free_space, unused);
	}

	if (p[h[i]] < i && L != h[i])
	{
		// cout << "ERR\n";
		return 0;
	}

	if (L == h[i])
	{
		// cout << "OP1\n";
		return solve(i+1, f, M, R, next) % MOD;
	}

	if (L == 0 && R == 0)
	{
		// cout << "OP2\n";
		int Lside = solve(i+1, f, M, R, next);
		int Rside = solve(i+1, f+1, M, h[i], next);
		return (Lside + Rside) % MOD;
	}

	if (L != 0 && R == 0)
	{
		// cout << "OP3\n";
		return solve(i+1, f+(L==0), M, h[i], next) % MOD;
	}

	if (L == 0 && R != 0)
	{
		// cout << "OP4\n";
		return solve(i+1, f, M, R, next) % MOD;
	}

	// cout << "OP5\n";
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> h[i];
	
	for (int i=n; i>=1; i--)
		p[h[i]] = i;

	for (int i=1; i<=n; i++)
		if (p[i] == 0)
			unused++;

	ll ans = solve(1, 0, INF, 0, 0) % MOD;
	cout << ans << "\n";

	return 0;
}