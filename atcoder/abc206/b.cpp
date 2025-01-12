/*
	Time: 00:05:44.2
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, sum = 0, p = 0; cin >> n;
	while (sum < n)
		sum += ++p;
	
	cout << p << "\n";

	return 0;
}