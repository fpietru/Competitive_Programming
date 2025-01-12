/*
	Zadanie "B - Little Elephant and Array" z Codeforces
*/
#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

const int MxN = 1e5+5;
pair<int, int> q[MxN];
map<int, int> mp;
vector<int> vec;
int arr[MxN], ans[MxN];
int n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i=0; i<n; i++)
	{
		cin >> arr[i];
		mp[arr[i]]++;
	}
	for (int i=1; i<=m; i++)
		cin >> q[i].FR >> q[i].SD;

	for (auto p : mp)
		if (p.SD >= p.FR)
			vec.push_back(p.FR);

	for (auto v : vec)
	{
		vector<int> pref(n+1, 0);
		for (int i=1; i<=n; i++)
			pref[i] = pref[i-1] + (arr[i-1] == v);

		for (int i=1; i<=m; i++)
			ans[i] += (pref[q[i].SD] - pref[q[i].FR-1] == v);
	}

	for (int i=1; i<=m; i++)
		cout << ans[i] << "\n";

	return 0;
}