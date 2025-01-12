/*
	Time: 00:07:46.79 (sad)
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c; cin >> a >> b >> c;

	if (a == b) cout << c << "\n";
	else if (a == c) cout << b << "\n";
	else if (b == c) cout << a << "\n";
	else cout << "0\n";

	return 0;
}