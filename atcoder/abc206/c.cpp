#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n; cin >> n;
	vector<int> a(n);
	for (int &p : a)
		cin >> p;

	sort(a.begin(), a.end());

	a.push_back(-1);

	ll c = 1, ans = (n * (n-1)) / 2;
	for (int i=0; i<n; i++)
	{
		if (a[i] != a[i+1])
		{
			ans -= (c * (c-1)) / 2;
			c = 1;
		}
		else c++;
	}

	cout << ans << "\n";

	return 0;
}