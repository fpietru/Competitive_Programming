/*
	Zadanie "Teleportacja" z VII OIG
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n, sum = 0, p = 1, ans = 0;
	cin >> n;
	
	while (sum + p <= n)
	{
		ans++;
		sum += p;
		p <<= 1;
	}

	n -= sum;

	if (n != 0)
	{
		p = 1;
		while (p <= n)
		{
			if (p & n) ans++;
			p <<= 1;
		}
	}

	cout << ans << "\n";

	return 0;
}