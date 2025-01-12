#include <bits/stdc++.h>
using namespace std;

string divide(string s)
{
	string res = "";
	int r = 0;
	for (int i=0; i<s.size()-2; i++)
	{
		int d = s[i] - '0';
		r *= 10;
		if (!(((r + d) / 2) == 0 && res.size() == 0))
			res += to_string((r + d) / 2);
		r = d % 2;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;

	string s = to_string(n);

	for (int i=0; i<k; i++)
	{
		int l = s.size();
		if (s[l-1] == '0' && s[l-2] == '0' && (s[l-3] - '0') % 2 == 0)
			s = divide(s);
		else
			s += "200";
	}

	cout << s << "\n";
	
	return 0;
}