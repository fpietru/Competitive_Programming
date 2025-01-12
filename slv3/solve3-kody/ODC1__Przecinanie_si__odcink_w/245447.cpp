#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P
{
	ll x;
	ll y;
};

int ilo(P v, P u)
{
	ll X = v.x * u.y - v.y * u.x;
	if (X > 0)
		return 1;
	else if (X < 0)
		return -1;
	else return 0;
}

void solve()
{
	P a, b, c, d;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
	P AB = {b.x - a.x, b.y - a.y};
	P CD = {d.x - c.x, d.y - c.y};
	P AC = {c.x - a.x, c.y - a.y};
	P AD = {d.x - a.x, d.y - a.y};
	P CA = {a.x - c.x, a.y - c.y};
	P CB = {b.x - c.x, b.y - c.y};
	
	
	if ((ilo(AB, AC) * ilo(AB, AD) <= 0) && (ilo(CD, CA) * ilo(CD, CB) <= 0))
		cout << "TAK\n";
	else cout << "NIE\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
		solve();

    return 0;
}
