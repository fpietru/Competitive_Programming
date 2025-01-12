/*
	Time: 04:35.00
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int x, y; cin >> x >> y;
	if (x == y)
		cout  << x << "\n";
	else
	{
		if ((x == 0 && y == 1) || (x == 1 && y == 0)) cout << "2\n";
		else if ((x == 0 && y == 2) || (x == 2 && y == 0)) cout << "1\n";
		else if ((x == 1 && y == 2) || (x == 2 && y == 1)) cout << "0\n";
	}
	
	return 0;
}