#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n; cin >> n;

	while (n--)
	{
		string s; cin >> s;
		stack<char> st;
		bool ok = 1;

		for (long long i=0; i<s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				st.push(s[i]);
			else
			{
				if (abs(st.top()-s[i]) > 2)
					ok = 0;
				else
					st.pop();
			}
		}
		if (st.size() == 0 && ok)
			cout<<"TAK\n";
		else
			cout<<"NIE\n";
	}


	return 0;
}
