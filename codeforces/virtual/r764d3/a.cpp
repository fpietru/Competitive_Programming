#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n; cin >> n;
	int mx = 0, mi = 1e9+7;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		mx = max(mx, x);
		mi = min(mi, x);
	}	
		
	cout << mx - mi << "\n";
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
