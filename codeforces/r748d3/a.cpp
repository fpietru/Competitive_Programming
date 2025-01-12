#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int a[3];
	cin >> a[0] >> a[1] >> a[2];

	int mx = max({a[0], a[1], a[2]});

	int ctm = 0;
	for (int i=0; i<3; i++)
		if (mx == a[i])
			ctm++;

	for (int i=0; i<3; i++)
		cout << mx - a[i] + (a[i] != mx || ctm > 1) << " ";
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--)
		solve();
	
	return 0;
}