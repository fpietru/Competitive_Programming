#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int mi = 1e9+9;
	int mx = -1e9-9;

	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		int x; cin >> x;
		mi = min(x, mi);
		mx = max(x, mx);
	}

	cout << mx - mi << "\n";
	
	return 0;
}