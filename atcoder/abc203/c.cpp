/*
	Time: 00:20:02.33
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FR first
#define SD second

map<ll, ll> mp;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	ll k; cin >> k;
	for (int i=0; i<n; i++)
	{
		ll a, b; cin >> a >> b;
		mp[a] += b;
	}

	ll curr_pos = 0;

	for (auto p : mp)
	{
		ll dist = p.FR - curr_pos;
		
		if (k - dist < 0)
		{
			cout << curr_pos + k << "\n";
			return 0;
		}

		k -= dist;
		k += p.SD;
		curr_pos = p.FR;
	}

	cout << curr_pos + k << "\n";
	
	return 0;
}