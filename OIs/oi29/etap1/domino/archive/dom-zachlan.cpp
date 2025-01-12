/*
	Zadanie "Domino" z XXIX OI, etap I
	Autor rozwiązania: Franek Pietrusiak
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxFib = 87;
ll fib[MxFib+10];

int solve(int st, ll val)
{
	int res = 0;
	ll unchanged = val, check = 1;
	for (int i=st; i>=2 && val > 1; i--)
		while (val % fib[i] == 0)
		{
			// cout << fib[i] << " ";
			res += i + 1;
			check *= fib[i];
			val /= fib[i];
		}

	// cout << "\n";

	res--;

	if (check == unchanged)
		return res;
	else
		return 1e9+7;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll m; cin >> m;

	if (m == 1)
	{
		cout << "1\n";
		return 0;
	}

	fib[1] = 1;
	fib[2] = 2;
	for (int i=3; i<=MxFib; i++)
		fib[i] = fib[i-2] + fib[i-1];

	int ans = 1e9+7;
	for (int i=MxFib; i>=2; i--)
	{
		cout << i << " " << solve(i, m) << "\n";
		ans = min(ans, solve(i, m));
	}

	if (ans != 1e9+7)
		cout << ans << "\n";
	else
		cout << "NIE\n";

	return 0;
}