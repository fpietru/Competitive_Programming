#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<int, int> mp;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	map<int, int> mp; 
	int n, x; cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> x;
		mp[x]++;
	}

	ll ans = 0;
	for (int i=-200; i<200; i++)
		for (int j=i+1; j<=200; j++)
			ans += (ll)mp[i] * (ll)mp[j] * (ll)(i-j)*(i-j);

	cout << ans << "\n";

	return 0;
}