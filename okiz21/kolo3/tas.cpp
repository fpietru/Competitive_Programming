#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e6+6;
int p[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		int x; cin >> x;
		p[i+1] = p[i] + x;
	}

	int ans = 1e9+7;
	for (int i=0; i<n-1; i++)
	{
		int sumA = p[i+1] - p[0];
		int sumB = p[n] - p[i+1];

		// cout << i << " " << sumA << " " << sumB << "\n";

		ans = min(ans, abs(sumA - sumB));
	}

	cout << ans << "\n";
	
	return 0;
}