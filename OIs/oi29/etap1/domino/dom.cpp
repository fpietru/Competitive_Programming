/*
	Zadanie "Domino" z XXIX OI, etap I
	Autor rozwiązania: Franek Pietrusiak
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxFib = 87;
ll fib[MxFib+10];
int INF = 1e9+7;
ll m;

int solve(ll x, ll check, int i)
{
	if (x == 1 || i < 2)
	{
		if (check == m)
			return 0;		

		return INF;
	}

	if (x % fib[i] == 0)
	{
		int a = solve(x / fib[i], check*fib[i], i) + i+1;
		int b = solve(x / fib[i], check*fib[i], i-1) + i+1;
		int c = solve(x, check, i-1);
		return min({a, b, c});
	}
	else
		return solve(x, check, i-1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m;

	fib[1] = 1;
	fib[2] = 2;
	for (int i=3; i<=MxFib; i++)
		fib[i] = fib[i-2] + fib[i-1];

	if (m == 1)
	{
		cout << "1\n";
		return 0;
	}

	int ans = solve(m, 1, 87);

	if (ans == INF)
		cout << "NIE\n";
	else
		cout << ans-1 << "\n";

	return 0;
}