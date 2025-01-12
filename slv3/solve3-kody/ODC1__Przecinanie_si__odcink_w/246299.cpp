#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}*/

struct Point
{
	int x;
	int y;
};

int ilo(Point v, Point u)
{
	ll X = (ll)v.x*u.y - (ll)v.y*u.x;
	if (X > 0) return 1;
	else if (X < 0) return -1;
	else return 0;
}

bool wspolliniowe(Point a, Point b, Point c, Point d)
{
	if (a.x > b.x) swap(a, b);
	if (c.x > d.x) swap(c, d);
		
	if (a.x == b.x)
	{
		if (a.y < b.y) swap(a, b);
		if (c.y < d.y) swap(c, d);
		
		if (b.y > c.y || a.y < d.y)
			return 0;
		return 1;
	}
	
	/*
	deb(a.x, a.y);
	deb(b.x, b.y);
	deb(c.x, c.y);
	deb(d.x, d.y);
	*/
	
	if (b.x < c.x || d.x < a.x)
		return 0;
	return 1;
}

bool solve()
{
	Point a, b, c, d;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cin >> d.x >> d.y;
	
	Point AB = {b.x - a.x, b.y - a.y};
	Point CD = {d.x - c.x, d.y - c.y};
	Point AC = {c.x - a.x, c.y - a.y};
	Point AD = {d.x - a.x, d.y - a.y};
	Point CA = {a.x - c.x, a.y - c.y};
	Point CB = {b.x - c.x, b.y - c.y};

	int i1 = ilo(AB, AC);
	int i2 = ilo(AB, AD);
	int i3 = ilo(CD, CA);
	int i4 = ilo(CD, CB);
	
	if (i1*i2 == 0 && i3*i4 == 0 && wspolliniowe(a, b, c, d))
		return 1;
	else
		return 0;
	
	if (i1*i2 <= 0 && i3*i4 <= 0)
		return 1;
	
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
		cout << (solve() ? "TAK\n" : "NIE\n");

    return 0;
}
