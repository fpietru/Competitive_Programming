#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+6;
bool present[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	int mx = -1e9-7;
	for (int i=0; i<n; i++)
	{
		int x; cin >> x;
		present[x] = 1;
		mx = max(mx, x);
	}
	
	int ans = 0;
	for (int i=1; i<=mx; i++)
	{
		int G = 0;
		for (int j=i; j<=mx; j+=i)
			if (present[j])
				G = __gcd(G, j);
				
		if (G == i && !present[i])
			ans++;
	}
	
	cout << ans << "\n";
		
	return 0;
}
