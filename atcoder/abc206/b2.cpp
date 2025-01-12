#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll x) { return ((x+1)*x) / 2; }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n; cin >> n;

	ll low = 0;
	ll high = 3000000000;

	while (high - low > 1)
	{
		ll mid = (low + high) >> 1;
		if (f(mid) < n)
			low = mid;
		else high = mid;
	}

	cout << high << "\n";
	
	return 0;
}