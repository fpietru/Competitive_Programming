#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18+7;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	ll bestans = -INF;
	ll currans = 0;
	for (int i=1; i<=n; i++)
	{
		ll x; cin >> x;
		currans = max(x, currans + x);
		bestans = max(bestans, currans);
	}
	
	cout << bestans << "\n";

    return 0;
}
