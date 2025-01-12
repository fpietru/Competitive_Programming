#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getsum(ll a, ll b, ll n)
{ return (a * n + b * n) >> 1; }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n, k, i, j; cin >> n >> k >> i >> j;
	
	ll st = (n - k + i) % n;
	ll ed = (n - k + j) % n;

	// bo x % x = 0
	if (st == 0) st = n;
	if (ed == 0) ed = n;

	if (st > ed)
	{
		ll sum1 = getsum(st, n, n-st+1);
		ll sum2 = getsum(1, ed, ed);
		cout << sum1 + sum2 << "\n";
	}
	else
	{
		ll sum = getsum(st, ed, ed-st+1);
		cout << sum << "\n";
	}

	return 0;
}