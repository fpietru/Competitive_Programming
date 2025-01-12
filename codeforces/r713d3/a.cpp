#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

void solve()
{
	int n, ans=0; cin >> n;
	map<int, pair<int, int>> mp;
	for (int i=0; i<n; i++)
	{
		int x; cin >> x;
		mp[x] = {mp[x].FR+1, i+1};
	}
	for (auto p : mp)
		if (p.SD.FR == 1)
			ans = p.SD.SD;
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