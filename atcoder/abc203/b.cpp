/*
	Time: 00:03:04.87
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	ll ans = 0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=k; j++)
			ans += (ll)(i*100+j);

	cout << ans << "\n";

	return 0;
}