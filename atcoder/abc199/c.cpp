/*
	HAD TO USE EDITORIAL
*/
#include <bits/stdc++.h>
using namespace std;

int translate(int x, int n)
{
	if (x <= n) return x + n;
	else return x - n;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	string s; cin >> s;
	int q; cin >> q;

	int flag = 0;

	while (q--)
	{
		int t, a, b;
		cin >> t >> a >> b;

		if (t == 2) flag ^= 1;
		else
		{
			if (flag == 0)
				swap(s[a-1], s[b-1]);
			else
			{
				a = translate(a, n);
				b = translate(b, n);
				swap(s[a-1], s[b-1]);
			}
		}
	}

	if (flag == 1)
		cout << s.substr(n) + s.substr(0, n) << "\n";
	else
		cout << s << "\n";

	return 0;
}