#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FR first
#define SD second

constexpr int MxN = 2e5+15;
pair<ll, ll> D[MxN];
int n;

ll w_prawo(int start, ll ile1, ll wys1, ll ile2, ll wys2)
{
	ll res = 1;
	ll L = D[start].FR + D[start].SD;
	
	for (int i=start+1; i<=n; i++)
	{
		while (L < D[i].FR && ile1 > 0)
		{
			ile1--;
			res++;
			L += wys1;
		}
		while (L < D[i].FR && ile2 > 0)
		{
			ile2--;
			res++;
			L += wys2;
		}
		
		if (L >= D[i].FR)
		{
			res++;
			L = D[i].FR + D[i].SD;
		}
		else
			break;
	}
	
	res += ile1;
	res += ile2;
	
	return res;
}

ll w_lewo(int start, ll ile1, ll wys1, ll ile2, ll wys2)
{
	ll res = 1;
	ll L = D[start].FR - D[start].SD;
	
	for (int i=start-1; i>=1; i--)
	{
		while (L > D[i].FR && ile1 > 0)
		{
			ile1--;
			res++;
			L -= wys1;
		}
		while (L > D[i].FR && ile2 > 0)
		{
			ile2--;
			res++;
			L -= wys2;
		}
		
		if (L <= D[i].FR)
		{
			res++;
			L = D[i].FR - D[i].SD;
		}
		else
			break;
	}
	
	res += ile1;
	res += ile2;
	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		ll x; ll h; cin >> x >> h;
		D[i] = {x, h};
	}
	
	ll n1, n2; ll h1, h2;	
	cin >> n1 >> h1 >> n2 >> h2;
	
	if (h1 < h2)
	{
		swap(h1, h2);
		swap(n1, n2);
	}

	ll ans = 0LL;
	for (int i=1; i<=n; i++)
		ans = max(ans, max(w_prawo(i, n1, h1, n2, h2), w_lewo(i, n1, h1, n2, h2)));
	
	cout << ans << "\n";
	
	return 0;
}
