/*
	Zadanie "Czekolada" z X OI, etap I
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second

constexpr int MxN = 1e3+13;
pii cut[2*MxN];

int main()
{
	int m, n; cin >> m >> n;
	for (int i=1; i<=m+n-2; i++)
	{
		int c; cin >> c;
		if (i <= m-1)
			cut[i] = {c, 1};
		else
			cut[i] = {c, 2};
	}
	
	sort(cut+1, cut+m+n-1, greater<pii>());
	
	ll ans = 0;
	int x_sofar = 0;
	int y_sofar = 0;
	for (int i=1; i<=m+n-2; i++)
	{
		//cout << cut[i].FR << " " << cut[i].SD << "\n";
		if (cut[i].SD == 1)
		{
			ans += (ll)cut[i].FR * (1 + y_sofar);
			x_sofar++;
		}
		else
		{
			ans += (ll)cut[i].FR * (1 + x_sofar);
			y_sofar++;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
