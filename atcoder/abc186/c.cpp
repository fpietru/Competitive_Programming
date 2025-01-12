#include <bits/stdc++.h>
using namespace std;

bool check10(int x)
{
	while (x > 0)
	{
		if (x % 10 == 7)
			return 1;
		x /= 10;
	}
	return 0;
}

bool check8(string s)
{
	for (char c : s)
		if (c == '7')
			return 1;
	return 0;
}

string octit(int x)
{
	string s = "";
	while (x > 0)
	{
		s += x%8 + 48;
		x /= 8;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, c=0; cin >> n;
	for (int i=1; i<=n; i++)
		if (check10(i) || check8(octit(i)))
			c++;

	cout << n - c << "\n";

	return 0;
}