#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, k; cin >> n >> k;
	vector<int> a(26);
	for (int i=0; i<n; i++)
	{
		char c; cin >> c;
		a[c-'a']++;
	}
	
	int pairs = 0, odds = 0;
	for (int i=0; i<26; i++)
	{
		pairs += a[i] / 2;
		odds += (a[i] & 1);
	}
	
	int ans = 2 * (pairs/k);
	if (odds+2*(pairs % k) >= k)
		ans++;
	
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
		solve();
	
	return 0;
}
