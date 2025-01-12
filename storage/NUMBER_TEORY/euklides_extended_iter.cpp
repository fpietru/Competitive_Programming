#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int inverse(int a, int b)
{
	int xa = 1, ya = 0;
	int xb = 0, yb = 1;
	int orib = b;
	
	while (b > 0)
	{
		int howmany = a / b;
		tie(xa, xb) = make_tuple(xb, xa - howmany * xb);
		tie(ya, yb) = make_tuple(yb, ya - howmany * yb);
		tie(a, b) = make_tuple(b, a - howmany * b);  
	}

	int inv = (xa % orib + orib) % orib;

	return inv;
}

int fastpow(int a, int b, int m)
{
	int ans = 1;
	while (b)
	{
		if (b % 2 != 0) ans = ((ll)(ans % m) * (a % m)) % m;
		a = ((ll)(a % m) * (a % m)) % m;
		b /= 2;
	}
	return ans % m;
}

int main()
{
	int a, b; cin >> a >> b;
	cout << inverse(a, b) << "\n";
	cout << fastpow(a, b-2, b) << "\n";
	
	return 0;
}
