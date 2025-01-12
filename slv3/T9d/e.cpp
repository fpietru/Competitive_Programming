#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll MxN = 1e9;
ll fact[MxN+10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fact[0] = 1;
	for (ll i=1; i<=MxN; i++)
		fact[i] = (fact[i-1] * i) % MOD;

	int n, k; cin >> n >> k;

	ll ans = fact[n] * inverse(fact[k] * fact[n-k] % MOD) % MOD;

	cout << ans << "\n";

	return 0;
}