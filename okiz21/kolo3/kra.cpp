/*
	Zadanie "Krążki" z XIII OI, etap I
	Bisearch
*/
#include <bits/stdc++.h>
using namespace std;
const int MxN = 3e5+55;
int p[MxN], otw[MxN];

int bisearch(int st, int ed, int val)
{
	while (st < ed)
	{
		int md = (st + ed) >> 1;
		if (val <= p[md])
			st = md + 1;
		else
			ed = md;
	}

	if (p[st] >= val)
		st++;

	return st;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> otw[i];

	p[0] = otw[0];
	for (int i=1; i<=n; i++)
		p[i] = min(p[i-1], otw[i-1]);

	int st = 1, ed = n, ans;
	for (int i=0; i<m; i++)
	{
		int x; cin >> x;
		if (st <= ed)
		{
			ans = bisearch(st, ed, x) - 1;
			ed = ans - 1;
		}
		else
			ans = 0;
	}

	cout << ans << "\n";

	return 0;
}