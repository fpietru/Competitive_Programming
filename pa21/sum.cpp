#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int MxN = 5e5+15;
map<int, int> mp;
map<int, bool> ans;
int a[MxN];
ll p[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}

	vector<pii> v;
	v.push_back({0,0});
	for (auto p : mp)
		v.push_back(p);

	int m = v.size();

	if (m > 2)
	{
		for (int i=1; i<m; i++)
			p[i] = p[i-1] + (ll)v[i].FR * v[i].SD;

		ans[v[m-1].FR] = 1;
		for (int i=m-2; i>=1; i--)
		{
			ll tot = 0;
			ll add = p[i-1];
			
			if (add > 0)
				tot = (ll)v[i].FR * v[i].SD + add;
			else
				tot = (ll)v[i].FR + add;

			if (tot > (ll)v[i+1].FR && ans[v[i+1].FR] == 1)
				ans[v[i].FR] = 1;
		}
	}

	for (int i=1; i<=n; i++)
		cout << (ans[a[i]] ? "T" : "N");
	cout << "\n";

	return 0;
}