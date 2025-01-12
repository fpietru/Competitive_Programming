#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	map<int, ll> mp;
	int n, q; cin >> n >> q;
	for (int i=0; i<n; i++)
	{
		int id, val; cin >> id >> val;
		mp[id] += (ll)val;
	}
	for (int i=0; i<q; i++)
	{
		int id; cin >> id;
		cout << mp[id] << " ";
	}
	cout << "\n";
	
	return 0;
}