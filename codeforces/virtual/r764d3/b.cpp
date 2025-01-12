#include <bits/stdc++.h>
using namespace std;

bool isok(double x)
{
	if (floor(x) == ceil(x) && x > 0)
		return 1;
	return 0;
}

bool solve()
{
	int a, b, c; cin >> a >> b >> c;
	
	double f1 = (double)(2*b-c) / (double)a;
	double f2 = (double)(a+c) / (double)(2*b);
	double f3 = (double)(2*b-a) / (double)c;
	
	// cout << f1 << " " << f2 << " " << f3 << "\n";
	
	if (isok(f1) || isok(f2) || isok(f3))
		return 1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
		cout << (solve() ? "YES\n" : "NO\n");
	
	return 0;
}
