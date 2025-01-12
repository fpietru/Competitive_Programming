#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, m; cin >> n >> m;
	map<int, int> c;

	for (int i=0; i<n; i++)
	{
		int x; cin >> x;
		c[x % m]++;
	}

	int ans = 0;
	for (auto p : c)
	{
		if (p.first == 0 || 2*p.first == m) ans++;
		else if (2*p.first < m || c.find(m-p.first) == c.end())
		{
			int f1 = max(p.second, c[m - p.first]);
			int f2 = min(p.second, c[m - p.first]);
			ans += 1 + max(0, f1-f2-1);
		}
	}
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}