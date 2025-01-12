#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 5e5+15;
bool vis[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	vector<int> pos;
	int n, k; cin >> n >> k;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		if (!vis[x])
		{
			vis[x] = 1;
			pos.push_back(i);
		}
	}

	if (pos.size() < k)
	{
		cout << "-1\n";
		return 0;
	}

	ll ans = 0;
	for (int i=1; i<=k; i++)
		if (pos[i-1] != i)
			ans += (ll)(pos[i-1] - i);

	cout << ans << "\n";

	return 0;
}