#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e6+6;
int k[MxN];
ll ans[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> k[i];
	
	sort(k+1, k+n+1);
	
	ans[1] = k[1];
	for (int i=2; i<=n; i++)
		ans[i] = max(k[i]-(ll)ans[i-1], (ll)ans[i-1]);
	
	cout << ans[n] << "\n";
	
	return 0;
}
