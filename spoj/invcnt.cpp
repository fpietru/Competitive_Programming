#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MxN = 2e5+55;
int a[MxN], s[MxN];

ll merge(int st, int md, int ed);

ll mergesort(int st, int ed)
{
	ll inv = 0;
	if (st < ed)
	{
		int md = (st + ed) >> 1;
		inv += mergesort(st, md);
		inv += mergesort(md+1, ed);
		inv += merge(st, md, ed);
	}
	return inv;
}

ll merge(int st, int md, int ed)
{
	int i = st;
	int j = md + 1;
	int k = st;
	ll inv = 0;

	while (i <= md && j <= ed)
	{
		if (a[i] <= a[j])
		{
			s[k] = a[i];
			i++;
			k++;
		}
		else
		{
			inv += (ll)(md - i + 1);
			s[k] = a[j];
			j++;
			k++;
		}
	}

	while (i <= md)
	{
		s[k] = a[i];
		i++;
		k++;
	}
	while (j <= ed)
	{
		s[k] = a[j];
		j++;
		k++;
	}

	for (int x = st; x <= ed; x++)
		a[x] = s[x];

	return inv;
}


void solve()
{
	int n; cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	cout << mergesort(0, n-1) << "\n";

/*	for (int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << "\n";*/
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