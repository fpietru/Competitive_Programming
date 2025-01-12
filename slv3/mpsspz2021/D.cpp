#include <bits/stdc++.h>
using namespace std;
using ld = long double;

constexpr int MxN = 1e5+55;
constexpr ld PREC = 0.000000001;
int a[MxN], n, k;

bool check(ld x)
{
	int planks = 0;
	for (int i=0; i<n; i++)
		planks += floor(((ld)a[i] / x));
	return planks >= k;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];

	ld low = 0, high = (ld)1e9+9;
	while (high - low >= PREC)
	{
		// cout << low << " " << high << "\n";
		ld md = (low + high) / 2;
		if (check(md)) low = md;
		else high = md;
	}

	ld mi = (ld)1e9+9;
	int P, Q;
	for (int i=0; i<n; i++)
	{
		ld w = (ld)a[i] / low; 
		if (w - floor(w) < mi)
		{
			mi = w - floor(w);
			P = a[i], Q = w;
		}
	}

	while (__gcd(P, Q) != 1)
		P /= __gcd(P, Q), Q /= __gcd(P, Q);

	cout << P << " " << Q << "\n";

	return 0;
}