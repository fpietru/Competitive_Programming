/*
	Zadanie "Wielokąt" z OKI
*/
#include <bits/stdc++.h>
#define FR first
#define SD second
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	long double area = 0, px, py, cx, cy, fx, fy;
	cin >> px >> py;
	fx = px;
	fy = py;
	for (int i=1; i<=n; i++)
	{
		cin >> cx >> cy;
		if (i == n)
		{
			cx = fx;
			cy = fy;
		}
		area += ((px + cx) * (py - cy));
		px = cx;
		py = cy;
	}

	area = abs(area) / 2;
	if (ceil(area) - floor(area) == 0)
		cout << fixed << setprecision(0) << area << "\n";
	else
		cout << fixed << setprecision(1) << area << "\n";

	return 0;
}