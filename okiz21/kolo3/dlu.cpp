#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, ans = 1e9+9; cin >> n;
	for (int i=0; i<n; i++)
	{
		int x; cin >> x;
		ans = min(ans, x);
	}

	cout << fixed << setprecision(2) << (double)ans << "\n";
	
	return 0;
}