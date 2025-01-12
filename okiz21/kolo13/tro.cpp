#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e3+13;
int R[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		R[a]++, R[b]++;
	}
	
	ll roznokolorowe = 0;
	for (int i=1; i<=n; i++)
		roznokolorowe += (ll)R[i] * (n-R[i]-1);
		
	ll wszystkie = n*(n-1)*(n-2) / 6;
	
	cout << wszystkie - roznokolorowe/2 << "\n";

	return 0;
}
