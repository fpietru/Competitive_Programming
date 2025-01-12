#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int ile = 1;
	string s; cin >> s;
	for (auto c : s)
	{
		if (c == 'x')
		{
			for (int i=1; i<=ile; i++)
				cout << "y";
			ile++;
		}
		else
			cout << c;
	}
	cout << "\n";

    return 0;
}
