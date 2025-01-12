#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;

	for (int i=0; i<s.size(); i++)
	{
		switch (s[i])
		{
			case 'a':
				cout << "4";
				break;
			case 'e':
				cout << "3";
				break;
			case 'i':
				cout << "1";
				break;
			case 'o':
				cout << "0";
				break;
			case 's':
				cout << "5";
				break;
			default:
				cout << s[i];
		}
	}
	
	return 0;
}