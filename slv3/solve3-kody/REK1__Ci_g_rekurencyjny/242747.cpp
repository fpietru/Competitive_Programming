#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second

constexpr int MxN = 5e6+5;
constexpr int MOD = 1e6+7;

pii oblicz(int n)
{
	if (n == 0)
		return {3, 0};
	else if (n % 7 == 0)
	{
		int n1 = (n/7) * 6;
		pii pv = oblicz(n1);
		pv.FR *= 2;
		pv.SD+=2;
		return pv;
	}
	else
	{
		pii pv = oblicz(n-1);
		pv.FR = ((ll)pv.FR * pv.FR) % MOD;
		pv.SD++;
		return pv;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	pii ans = oblicz(n);
	cout << ans.FR << " " << ans.SD << "\n";

	// for (int i=0; i<=n; i++)
	// 	cout << a[i] << "\n";


	// long double mem = sizeof(a) / (long long)(1<<20);
	// cout << mem << "\n"; 

    return 0;
}
