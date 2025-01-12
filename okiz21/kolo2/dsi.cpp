#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9;

// Szybkie znajdowanie silni
int fastfact(int n)
{
	if (n > MOD)
		return 0;

	int res = 1;
	for (int i=2; i<=n; i++)
	{
		res = ((ll)res * i) % MOD;
		if (res == 0) // jeśli w którymś momencie res = 0, to zostanie nim na zawsze, bo x * 0 = 0
			return 0;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;

	cout << fastfact(n) << "\n";
	
	return 0;
}