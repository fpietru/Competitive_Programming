/*
	Zadanie "Domek" z III OIG
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MxN = (1<<17)+7;
ll l, k, p=1;
ll arr[MxN];
ll DP[MxN][27];

void fillDP(ll v, ll k, ll l)
{
	if (k == 0) return;
	else DP[v][1] = arr[v];
	
	if (l == 1) return;
	else
	{
		ll LEFT = 2*v;
		ll RIGHT = 2*v+1;

		fillDP(LEFT, k-1, l-1); 
		fillDP(RIGHT, k-1, l-1);

		for (ll i=2; i<=k; i++)
			for (ll j=0; j<i; j++)
				DP[v][i] = max(DP[v][i], DP[LEFT][j] + DP[RIGHT][i-j-1] + arr[v]); 
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> l >> k;
	k /= 2;
	for (ll i=0; i<l; i++)
		for (ll j=0; j<(1<<i); j++)
		{
			ll i1, i2; cin >> i1 >> i2;
			arr[p] = i1 + i2;
			p++;
		}

	fillDP(1, k, l);

	cout << DP[1][k] << "\n";

	return 0;
}