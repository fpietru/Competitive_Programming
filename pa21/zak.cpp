#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int ones = 0;
	int n; cin >> n;
	string s; cin >> s;
	for (char c : s)
		if (c == '1') ones++;


	if (ones < 3*n || ones > 6*n)
	{
		cout << "NIE\n";
		return 0;
	}

	vector<int> v(n, 3);
	int sum = 3*n;

	for (int p : v)
	{
		for (int k=3; k>=0; k--)
			if (sum + k <= ones)
			{
				p += k;
				sum += k;
				break; 
			}
		
		if (p == 3)
			cout << "a";
		else if (p == 4)
			cout << "c";
		else if (p == 5)
			cout << "g";
		else cout << "o";
	}

	cout << "\n";
	
	return 0;
}