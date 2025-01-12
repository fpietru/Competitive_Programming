/*
	Zadanie: Obwód
*/
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);

	ll n; cin >> n;
	ll ans = 1e18+7;

	for (int i=1; i*i<=n; i++)
		if (n % i == 0)
		{
			ll a = (ll)i;
			ll b = n/(ll)i;
			ans = min(ans, 2*a+2*b);
		}

	cout << ans << "\n";

	return 0;
}