/*
	Time: 00:06:50.30
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, x, mx = 0, mi = 1e9+7; cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> x;
		mx = max(mx, x);
	}

	for (int i=0; i<n; i++)
	{
		cin >> x;
		mi = min(mi, x);
	}

	cout << max(mi - mx + 1, 0) << "\n";

	return 0;
}