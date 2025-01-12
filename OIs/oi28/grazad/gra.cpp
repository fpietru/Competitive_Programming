/*
Zadanie Gra platformowa XXVIII OI, etap I  
Autor: Franek Pietrusiak
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MxN = 1e5+7, MxX = 1e4+7;
bool arr[MxN][MxX];
ll n, x, z, ans;

void DEB_show_arr()
{
	for (ll i=1; i<=n; i++)
	{
		for (ll j=1; j<=x; j++)
			cout << (arr[i][j] ? "#" : " ");
		cout << "\n";
	}
}

void go(ll posy, ll posx, ll cost)
{
	if (posx == x)
	{
		ans = min(ans, cost);
		// cout << cost << " [" << posy << ", " << posx << "]: Dotarlismy na sam koniec\n";
		return;
	}

	if (arr[posy-1][posx] == 0)
		if (posy > 1)
		{
			go(posy-1, posx+1, cost+1);
			// cout << cost+1 << " [" << posy << ", " << posx << "]: Wskakuje na platforme nad dziura\n";
		}
	
	if (arr[posy][posx+1] == 0)
	{
		if (posy < n)
		{
			go(posy+1, posx+1, cost);
			// cout << cost << " [" << posy << ", " << posx << "]: Spadam do dziury\n";
		}		
		go(posy, posx+2, cost+1);
		// cout << cost+1 << " [" << posy << ", " << posx << "]: Przeskakuje dziure\n";
	}
	else
	{
		go(posy, posx+1, cost);
		// cout << cost << " [" << posy << ", " << posx << "]: Nie ma dziury, moge isc dalej prosto\n";
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// Wczytywanie
	cin >> n >> x >> z;

	for (ll i=1; i<=n; i++)
		for (ll j=1; j<=x; j++)
			arr[i][j] = 1;

	for (ll i=1; i<=n; i++)
	{
		ll h, d; cin >> h;
		for (ll j=1; j<=h; j++)
		{
			cin >> d;
			arr[i][d] = 0;
		}
	}
	while (z--)
	{
		ll s; cin >> s;
		ans = 1e9+7;
		go(s,1,0);
		cout << ans << "\n";
	}

	return 0;
}