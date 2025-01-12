/*
	Time: 00:02:14.2
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c; cin >> a >> b >> c;
	int ab = a + b;
	int ac = a + c;
	int bc = b + c;

	cout << max({ab, ac, bc}) << "\n";
	
	return 0;
}