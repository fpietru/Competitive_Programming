/*
	Zadanie "Porządek" z VII OIG
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MxN = 1e6+3;
char garden[MxN];
ll liczba_R[MxN];
ll liczba_P[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n; cin >> n;
	for (ll i=1; i<=n; i++)
		cin >> garden[i];

	ll fr=0, fp=0;
	for (ll i=1; i<=n; i++)
	{
		if (garden[i] == 'R') fr++;
		else fp += fr;
		liczba_R[i] = fr;
		liczba_P[i] = fp;
	}

	ll t; cin >> t;
	while (t--)
	{
		ll a, b; cin >> a >> b;
		ll ab_s = b - a + 1;
		ll r_ab = liczba_R[b] - liczba_R[a-1];
		ll n_ab = ab_s - r_ab;
		ll p_ab = liczba_P[b] - liczba_P[a-1];
		ll ans = p_ab - liczba_R[a-1] * n_ab;
		cout<<ans<<"\n";
	}

	return 0;
}