#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n; cin >> n;
	set<int> st;
	map<int, int> mp;
	for (int i=0; i<n; i++)
	{
		int a; cin >> a;
		st.insert(a);
		mp[a]++;
	}

	// if (st. != 0)
	// {
	// 	for (auto p : st)
	// 		cout << p << " ";
	// 	cout << "\n";
	// 	return;
	// }

	for (auto p : st)
		cout << p << " ";

	for (auto p : mp)
	{
		if (p.second > 1)
			for (int i=1; i<p.second; i++)
				cout << p.first << " ";
	}
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}