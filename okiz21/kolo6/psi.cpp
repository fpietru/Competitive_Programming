#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e6+66;
int p[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, a; cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> a;
		p[i+1] = p[i] + a;
	}

	ll ans = 0;
	int parz = 0, niep = 0;
	for (int i=0; i<=n; i++)
	{
		ans += (p[i]&1 ? (ll)niep : (ll)parz);
		if (p[i] & 1) niep++;
		else parz++;
	}

	cout << ans << "\n";

	return 0;
}