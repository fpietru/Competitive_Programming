#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

struct odp
{
	int a; int b; int c;
};

int getpos(vector<int> a, int x)
{
	int pos = -1;
	for (int i=0; i<a.size(); i++)
		if (a[i] == x)
			pos = i;

	return pos;
}

void shift(vector<int> &a, int st, int ed)
{
	vector<int> v;
	v.push_back(a[ed]);
	for (int i=st; i<=ed-1; i++)
		v.push_back(a[i]);

	for (int i=st; i<=ed; i++)
		a[i] = v[i-st];
}

void solve()
{
	int n; cin >> n;
	vector<int> a, b;
	for (int i=0; i<n; i++)
	{
		int x; cin >> x;
		a.push_back(x);
		b.push_back(x);		
	}

	sort(b.begin(), b.end());

	vector<odp> ans;

	for (int i=0; i<b.size(); i++)
	{
		int pos = getpos(a, b[i]);
		if (pos == i)
			continue;
		shift(a, i, pos);
		ans.push_back({i+1, pos+1, pos-i});
	}

	cout << ans.size() << "\n";
	for (auto p : ans)
		cout << p.a << " " << p.b << " " << p.c << "\n";
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