/*
	Time: 02:17.95
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, ans = 0; cin >> n;
	for (int i=0; i<n; i++)
	{
		int x; cin >> x;
		if (x > 10) ans += x - 10;
	}

	cout << ans << "\n";
	
	return 0;
}