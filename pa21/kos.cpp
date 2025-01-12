#include <bits/stdc++.h>
using namespace std;

map<int, int, greater<int>> mp;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		mp[x]++;
	}

	int ans = 0;
	for (auto p : mp)
	{
		if (ans < k)
			ans += p.second;
		else
			break;
	}

	cout << ans << "\n";
	
	return 0;
}