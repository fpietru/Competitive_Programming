#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 150000;
vector<int> p[MxN+10];

void solve()
{
	for (int i=0; i<=MxN; i++)
		p[i].clear();
		
	int n; cin >> n;
	int cnt = 0;
	
	set<int> st;
	
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		st.insert(x);
		p[x].push_back(i);
		cnt = max(cnt, (int)p[x].size());
	}
	
	if (cnt == 1)
	{
		cout << "-1\n";
		return;
	}
	
	int ans = 0;
	for (auto x : st)
	{
		if (p[x].size() == 1)
			continue;
		
		for (int i=0; i<(int)p[x].size()-1; i++)
			ans = max(ans, n-(p[x][i+1] - p[x][i]));
	}
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
		solve();
	
	return 0;
}
