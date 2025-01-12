/*
	Time: 00:01:17.95
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c; cin >> a >> b >> c;
	cout << (a*a + b*b < c*c ? "Yes\n" : "No\n");
	
	return 0;
}