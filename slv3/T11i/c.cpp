#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 2e5+15;
int a[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
		
	sort(a, a+n);	
	
	if (n <= 2)
	{
		cout << "0\n";
		return 0;
	}
	
	ll ans = 1e18;
	ll pocz = (ll)a[0];
	ll kon = (ll)a[n-1];
	for (int i=0; i<n-1; i++)
	{
		ll tap1 = (ll)a[i] - pocz;
		ll tap2 = kon - (ll)a[i+1];
		ans = min(ans, tap1+tap2);
	}
	
	cout << ans << "\n";
	
	return 0;
}
