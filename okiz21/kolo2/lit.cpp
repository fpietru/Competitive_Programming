#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MxN = 1e6+66;
int p[MxN], s[MxN];

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
	ll inv = 0;
	int i = st, j = md + 1, k = st;
	while (i <= md && j <= ed)
	{
		if (p[i] < p[j])
		{
			s[k] = p[i];
			i++, k++;
		}
		else
		{
			inv += (ll)(md - i + 1);
			s[k] = p[j];
			j++, k++;
		}
	}
	while (i <= md)
		s[k] = p[i], i++, k++;
	while (j <= ed)
		s[k] = p[j], j++, k++;

	for (int l=st; l<=ed; l++)
		p[l] = s[l];

	return inv;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	string a, b; cin >> a >> b;

	stack<int> st[26];
	for (int i=n-1; i>=0; i--)
		st[a[i]-'A'].push(i);

	for (int i=0; i<n; i++)
	{
		p[i] = st[b[i]-'A'].top();
		st[b[i]-'A'].pop();
	}

	cout << mergesort(0, n-1) << "\n";

	return 0;
}