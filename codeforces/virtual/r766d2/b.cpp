#include <bits/stdc++.h>
using namespace std;

int dist(int a, int b, int c, int d)
{
	return abs(a-c) + abs(b-d);
}

void solve()
{
	int n, m; cin >> n >> m;
	vector<int> v;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			v.push_back(max({dist(i,j,1,1), dist(i,j,1,m), dist(i,j,n,1), dist(i,j,n,m)}));
	
	sort(v.begin(), v.end());
	for (int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
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
