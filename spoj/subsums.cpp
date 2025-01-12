#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MxN = 35;
int t[MxN];

vector<ll> comp(int st, int ed)
{
	int sz = ed-st+1;
	vector<ll> v;
	for (int mask=0; mask<(1<<sz); mask++)
	{
		ll sum = 0;
		for (int k=0, p=ed; k<sz; k++, p--)
			if (mask&(1<<k)) sum += t[p];
		v.push_back(sum);
	}
	return v;
}

int upper(vector<ll> &v, int x)
{
	int st = 0, ed = v.size()-1;
	while (st <= ed)
	{
		int md = (st + ed) >> 1;
		if (v[md] <= x)
			st = md + 1;
		else ed = md - 1; 
	}
	return ed;
}

int lower(vector<ll> &v, int x)
{
	int st = 0, ed = v.size()-1;
	while (st <= ed)
	{
		int md = (st + ed) >> 1;
		if (v[md] >= x)
			ed = md - 1;
		else st = md + 1; 
	}
	return st;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	for (int i=0; i<n; i++)
		cin >> t[i];

	vector<ll> X = comp(0, n/2-1);
	vector<ll> Y = comp(n/2, n-1);
	
	sort(Y.begin(), Y.end());

/*	for (auto p : X)
			cout << p << "\n";
	cout << "\n";
	for (auto p : Y)
			cout << p << "\n";*/

	ll ans = 0;
	for (ll x : X)
		ans += upper(Y, b-x) - lower(Y, a-x) + 1;

	cout << ans << "\n";

	return 0;
}