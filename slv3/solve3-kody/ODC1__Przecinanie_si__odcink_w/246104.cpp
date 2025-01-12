#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}*/

struct P
{
	ll x;
	ll y;
};

bool operator < (P& a, P& b)
{
	if (a.x == b.x)
		return a.y < b.y;
		
	return a.x < b.x; 
}

int ilo(P v, P u)
{
	ll X = v.x*u.y - v.y*u.x;
	if (X > 0)
		return 1;
	else if (X < 0)
		return -1;
	else return 0;
}

bool wspolliniowe(P a, P b, P c, P d)
{
	if (b < a) swap(a, b);
	if (d < c) swap(c, d);

	if (c < b || (b.x == c.x && b.y == c.y))
		return 1;
	return 0;	
}

void solve()
{
	P a, b, c, d;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cin >> d.x >> d.y;
	
	P AB = {b.x - a.x, b.y - a.y};
	P CD = {d.x - c.x, d.y - c.y};
	P AC = {c.x - a.x, c.y - a.y};
	P AD = {d.x - a.x, d.y - a.y};
	P CA = {a.x - c.x, a.y - c.y};
	P CB = {b.x - c.x, b.y - c.y};

	int i1 = ilo(AB, AC);
	int i2 = ilo(AB, AD);
	int i3 = ilo(CD, CA);
	int i4 = ilo(CD, CB);
	
	if ((i1 * i2 < 0) && (i3 * i4 < 0))
		cout << "TAK\n";
	else if (i1 * i2 == 0 && i3*i4 == 0)
	{
		if (wspolliniowe(a, b, c, d))
			cout << "TAK\n";
		else cout << "NIE\n";

	}
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
