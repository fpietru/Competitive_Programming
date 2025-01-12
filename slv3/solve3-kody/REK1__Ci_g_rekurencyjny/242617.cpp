#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second

constexpr int MxN = 5e6+5;
constexpr int MOD = 1e6+7;
pii a[MxN];

pii oblicz(int n)
{
	if (a[n].FR != -1)
		return a[n];
	
	if (n % 7 == 0)
	{
		int n1 = (n/7) * 6;
		a[n] = oblicz(n1);
		a[n].FR *= 2;
		a[n].SD++;
		return a[n];
	}
	else
	{
		a[n] = oblicz(n-1);
		a[n].FR = ((ll)a[n].FR * a[n].FR) % MOD;
		a[n].SD++;
		return a[n];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i=0; i<MxN; i++)
		a[i].FR = -1;
	a[0].FR = 3;
	
	int n; cin >> n;
	pii ans = oblicz(n);
	cout << ans.FR << " " << ans.SD << "\n";

	// for (int i=0; i<=n; i++)
	// 	cout << a[i] << "\n";

    return 0;
}
