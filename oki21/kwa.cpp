/*
	Zadanie "Kwantowy Generator Kongruencyjny" z OKI
*/
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

map<ll, int> mp;
ll a, x, n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
		
	cin >> a >> x >> n;
	mp[x]++;
	while (1)
	{
		ll g = (x*x + a)%n;
		mp[g]++;
		if (mp[g] > 1)
			break;
		x = g;
	}

	cout << mp.size() << "\n";

	return 0;
}