/*
	Zadanie "Sieć WIFI" z KI
	Binary Search po wyniku
*/
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
constexpr int MxN = 1e5+55, INF = 1e6+6;
int p[MxN];
int n, k;

bool check(int sig)
{
	int Rmost = -1;
	int curr_numb = k;
	for (int i=0; i<n; i++)
	{
		if (curr_numb == 0 && Rmost < p[i])
			return 0;

		if (Rmost < p[i])
		{
			curr_numb--;
			Rmost = p[i] + sig;
		}
	}

	return 1;
}

void solve()
{
	cin >> k >> n;
	for (int i=0; i<n; i++)
		cin >> p[i];

	sort(p, p+n);

	int low = 0, high = INF;
	while (low < high)
	{
		int md = (low + high) >> 1;
		if (check(md))
			high = md;
		else
			low = md + 1;
	}

	cout << fixed << setprecision(1) << ((double)low / 2) << "\n";
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