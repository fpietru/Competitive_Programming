/*
	Zadanie "Płot" z MPSŚPZ 2021 OPEN
*/
#include <bits/stdc++.h>
using namespace std;
using ld = long double;

constexpr int MxN = 1e5+55;
constexpr ld prec = 0.000000000000001;
int a[MxN], n, k;

bool check(ld x)
{
	int planks = 0;
	for (int i=0; i<n; i++)
		planks += floor((ld)(a[i] / x));
	return (planks >= k);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];

	ld low = 0, high = 1e9+9;
	while (high - low > prec)
	{
		ld md = (low + high) / 2;
		// cout << low << " " << md << " " << high << "\n";
		if (check(md)) low = md;
		else high = md;
	}

	int P, Q;
	ld mi = 1;
	for (int i=0; i<n; i++)
		if (((ld)a[i] / low) - floor(((ld)a[i] / low)) <= mi)
		{
			mi = ((ld)a[i] / low) - floor(((ld)a[i] / low));
			Q = (ld)a[i] / low, P = a[i];
		}

	while (__gcd(P, Q) != 1)
	{
		int gcd = __gcd(P, Q);
		P /= gcd, Q /= gcd;
	}

	cout << P << " " << Q << "\n";

	return 0;
}