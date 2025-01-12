#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string a, b;
	cin >> a >> b;
	map<char, int> mp1, mp2;
	
	for (char c : a)
		mp1[c]++;
	for (char c : b)
		mp2[c]++;

	cout << (mp1 == mp2 ? "TAK\n" : "NIE\n");

	return 0;
}