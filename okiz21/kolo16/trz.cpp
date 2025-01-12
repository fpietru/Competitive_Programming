/*
	Zadanie "Trzy Wieże" z XXII OI, etap II
	Wersja brutalna
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MxN = 1e6+6;
ll p[3][MxN];

ll getsum(int a, int b, int t)
{
	return p[t][b+1] - p[t][a];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	string s; cin >> s;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<3; j++)
			p[j][i+1] = p[j][i];
	
		int t;
		if (s[i] == 'B')
			t = 0;
		else if (s[i] == 'S')
			t = 1;
		else t = 2;
		
		p[t][i+1]++;
	}
	
	ll ans = 0;
	for (int i=0; i<n; i++)
		for (int j=i; j<n; j++)
		{	
			ll biale = getsum(i, j, 0);
			ll szare = getsum(i, j, 1);
			ll czarne = getsum(i, j, 2);
			
			// czyż to nie jest piękne?
			
			if (biale > 0 && szare == 0 && czarne == 0)
				ans = max(ans, biale);
			else if (szare > 0 && biale == 0 && czarne == 0)
				ans = max(ans, szare);
			else if (czarne > 0 && biale == 0 && szare == 0)
				ans = max(ans, czarne);
			else if (biale > 0 && szare > 0 && czarne == 0 && biale != szare)
				ans = max(ans, biale+szare);
			else if (biale > 0 && czarne > 0 && szare == 0 && biale != czarne)
				ans = max(ans, biale+czarne);
			else if (czarne > 0 && szare > 0 && biale == 0 && czarne != szare)
				ans = max(ans, czarne+szare);
			else if (biale > 0 && szare > 0 && czarne > 0 && biale != szare && biale != czarne && szare != czarne)
				ans = max(ans, biale+szare+czarne);
		}
	
	cout << ans << "\n";
	
	return 0;
}
