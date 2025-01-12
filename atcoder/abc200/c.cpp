#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxK = 200;
ll f[MxK];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	ll ans = 0;
	for (int i=0; i<n; i++)
	{
		int x; cin >> x;
		x %= 200;
		ans += f[x];
		f[x]++;
	}

	cout << ans << "\n";
	
	return 0;
}