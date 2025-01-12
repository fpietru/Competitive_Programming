#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+6;
int h[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
		cin >> h[i];
	
	int ans = 0;
	for (int i=0; i<n-1; i++)
		ans = max(ans, abs(h[i]-h[i+1]));

	cout << ans << "\n";

	return 0;
}