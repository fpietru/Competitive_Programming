#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 25;
int a[MxN];
ll ans[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	for (int i=0; i<MxN; i++)
		ans[i] = 1e18+7;
	
	int n; cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
		
	for (int mask=0; mask<(1<<n); mask++)
	{
		ll sum = 0;
		for (int j=0; j<n; j++)
			if (mask & (1<<j))
				sum += (ll)a[j];
		
		ll sum2 = sum;
		int items_taken = 0;
		for (int i=0; i<n; i++)
			if (sum - (ll)a[i] >= 0)
			{
				items_taken++;
				sum -= (ll)a[i];
			}
			
		ans[items_taken] = min(ans[items_taken], sum2);
	}
	
	for (int i=1; i<=n; i++)
		cout << ans[i] << " ";
	cout << "\n";	
	
	return 0;
}
