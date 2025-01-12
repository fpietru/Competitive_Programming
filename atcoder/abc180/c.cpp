#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n; cin >> n;

	vector<ll> v;
	for (ll i=1; i*i<=n; i++)
		if (n % i == 0)
		{
			if (n / i == i)
				v.push_back(i);
			else
			{
				v.push_back(i);
				v.push_back(n/i);
			}
		}

	sort(v.begin(), v.end());

	for (auto p : v)
		cout << p << "\n";

	return 0;
}