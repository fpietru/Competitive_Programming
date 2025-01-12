#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll m = 0;
	ll e = 0;
	ll c = -1e9;

	int n, x; cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> x;
		m += (ll)abs(x);
		e += (ll)abs(x)*(ll)abs(x);
		c = max(c, (ll)abs(x));
	}

	cout << fixed << setprecision(18);
	cout << m << "\n";
	cout << double(sqrt(e)) << "\n";
	cout << c << "\n";
	
	return 0;
}