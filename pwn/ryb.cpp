#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> s(n);
	vector<int> d(n);
	for (int i=0; i<n; i++) cin >> s[i];
	for (int i=0; i<n; i++)	cin >> d[i];

	int ans = 0;
	stack<int> st;
	for (int i=0; i<n; i++)
	{
		if (d[i] == 1)
			st.push(s[i]);
		else
		{
			while (!st.empty() && st.top() < s[i])
				st.pop();

			if (st.empty())
				ans++;
		}
	}
	ans += st.size();
	cout<<ans<<"\n";

	return 0;
}