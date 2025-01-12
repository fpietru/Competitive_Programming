#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FR first
#define SD second

constexpr int MxN = 2e5+15;
pair<ll, ll> D[MxN];
int n;

ll w_prawo(int start)
{
	ll res = 1;
	ll L = D[start].FR + D[start].SD;
	
	bool flag = 1;
	for (int i=start+1; i<=n; i++)
	{
		ll to_be_used_bigger = ((D[i].FR - L) / wys1) + ((D[i].FR - L) % wys1 != 0);
		
		if (to_be_used <= ile)
		{
			ile -= to_be_used;
			res += to_be_used + 1;
			L = D[i].FR + D[i].SD;
		}
		else
		{
			res += ile;
			flag = 0;
			break;
		}

	}
	
	if (flag)
		res += ile;
	
	return res;
}

ll w_lewo(int start, ll ile, ll wys)
{
	ll res = 1;
	ll L = D[start].FR - D[start].SD;
	
	bool flag = 1;
	for (int i=start-1; i>=1; i--)
	{
		ll to_be_used = ((L - D[i].FR) / wys) + ((L - D[i].FR) % wys != 0);
		
		if (to_be_used <= ile)
		{
			ile -= to_be_used;
			res += to_be_used + 1;
			L = D[i].FR - D[i].SD;
		}
		else
		{
			res += ile;
			flag = 0;
			break;
		}
	}
	
	if (flag)
		res += ile;
	
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
	
	ll ile1, ile2;
	ll h1, h2;
	
	cin >> ile1 >> h1 >> ile2 >> h2;
	
	ll ans = 0LL;
	for (int i=1; i<=n; i++)
		ans = max(ans, max(w_prawo(i, ile, wys), w_lewo(i, ile, wys)));
	
	cout << ans << "\n";
	
	return 0;
}
