#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int x)
{
	if (floor(sqrt((double)x) == ceil(sqrt((double)x))))
		return 1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	ll n; cin >> n;
	int ans = 0;
	
	for (int i=1; i*i<=n; i++)
		if (n % i == 0)
		{
			if (n / (ll)i == (ll)i)
				ans += check(i);
			else
			{
				ans += check(i);
				ans += check(n/i);
			}
		}
		
	cout << ans << "\n";
	
	return 0;
}
