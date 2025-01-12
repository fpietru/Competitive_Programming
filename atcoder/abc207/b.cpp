/*
	Time: 00:14:30.8
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c, d; cin >> a >> b >> c >> d;
	int ans = ceil((double)-a / (b - c*d));

	if (ans < 0)
		cout << "-1\n";
	else cout << ans << "\n";
	
	return 0;
}