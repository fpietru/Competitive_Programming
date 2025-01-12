/*
	Time: 00:03:15.6
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	n = (int)floor(1.08 * (double)n);

	if (n < 206) cout << "Yay!\n";
	else if (n == 206) cout << "so-so\n";
	else cout << ":(\n";
	
	return 0;
}