#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n, m; cin >> n >> m;
	n *= 2;

	if (n > m)
	{
		cout << m / 2 << "\n";
		return 0;
	}

	ll samelvls = n / 2;
	ll roz = (m - n) / 4;

	cout << samelvls + roz << '\n';

	return 0;
}