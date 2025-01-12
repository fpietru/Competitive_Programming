/*
	Zadanie "Kalendarze" z OIG, etap II
	Wyszukiwanie Binarne i Sumy Prefiksowe
*/
#include <bits/stdc++.h>
using namespace std;
constexpr int MxN = 1e6+66;
int p[2][MxN], sz[2];

int bisearch(int arr[], int st, int ed, int val)
{
	while (st < ed)
	{
		int md = (st + ed) >> 1;
		if (arr[md] < val)
			st = md + 1;
		else ed = md;
	}
	return st;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> sz[0] >> sz[1];
	for (int t=0; t<2; t++)
		for (int i=0; i<sz[t]; i++)
		{
			int x; cin >> x;
			p[t][i+1] = p[t][i] + x;
		}

	int z; cin >> z;
	while (z--)
	{
		int d, m; cin >> d >> m;
		char t; cin >> t;
		int tot_days = p[t-'A'][m-1] + d;
		int new_month = bisearch(p[(t-'A')^1], 0, sz[(t-'A')^1], tot_days) - 1;

		// Nie może być zerowego dnia
		if (tot_days == p[(t-'A')^1][new_month])
			new_month--;

		int new_days = tot_days - p[(t-'A')^1][new_month];

		cout << new_days << " " << new_month+1 << "\n";
	}
	
	return 0;
}