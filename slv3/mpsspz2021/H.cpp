/*
	Zadanie "Malowanie" z MPSŚPZ 2021 OPEN
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool p4c(ll x, bool m)
{
	int c[4] = {0,0,0,0};
	while (x)
	{
		c[x % 4]++;
		x /= 4;
	}

	if (m == 0 && !(c[1] + c[2] + c[3] == 1 && c[1] == 1)) return 0;
	if (m == 1 && !(c[1] + c[2] == 0)) return 0;

	return 1;
}

bool solve()
{
	ll W, S, x, y;
	cin >> W >> S >> y >> x;
	return (p4c(W, 0) && p4c(S, 0) && p4c(y, 1) && p4c(x, 1));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--)
		cout << (solve() ? "Tak\n" : "Nie\n");

	return 0;
}