/*
	Zadanie "Suma" z OKI
	Meet in the middle
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, bool> comp(vector<ll> &a, int st, int ed)
{
	int sz = ed-st+1;
	map<ll, bool> mp;
	for (int mask=0; mask<(1<<sz); mask++)
	{
		ll sum = 0;
		for (int k=0, p=ed; k<sz; k++, p--)
			if (mask&(1<<k))
				sum += a[p];
		mp[sum] = 1;
	}
	return mp;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	ll s; cin >> s;
	vector<ll> a(n);
	for (int i=0; i<n; i++)
		cin >> a[i];

	map<ll, bool> X = comp(a, 0, n/2-1);
	map<ll, bool> Y = comp(a, n/2, n-1);
	
	/*for (auto p : X) cout << p.first << "\n";
	cout << "\n";
	for (auto p : Y) cout << p.first << "\n";*/ 

	bool ans = 0;
	for (auto x : X)
		if (Y[s-x.first])
		{
			ans = 1;
			break;
		}

	cout << (ans ? "TAK\n" : "NIE\n");

	return 0;
}