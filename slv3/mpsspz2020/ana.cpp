#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	map<char, int> mp1;

	for (int i=0; i<(int)s.size(); i++)
		mp1[s[i]]++;

	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		string x;
		cin >> x;

		map<char, int> mp2;
		for (int j=0; j<(int)x.size(); j++)
			mp2[x[j]]++;

		if (mp1 == mp2)
			cout << "TAK\n";
		else
			cout << "NIE\n";
	}
	
	return 0;
}