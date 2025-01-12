#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;

	int countZ = 0;
	for (int i=0; i<s.size(); i++)
		if (s[i] == '0')
			countZ++;
	
	if (countZ == 0)
	{
		sort(s.begin(), s.end());
		cout << s << "\n";
	}
	else
	{
		sort(s.begin(), s.end());
		s.erase(0, countZ);
		cout << s[0];
		for (int i=0; i<countZ; i++)
			cout << '0';
		cout << s.substr(1, s.size()-1);
		cout << "\n";
	}

	return 0;
}