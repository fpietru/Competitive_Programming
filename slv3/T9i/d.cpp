#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n; cin >> n;

	ll st = 0, sum = 0;
	for (ll ed = 1; ed * ed <= n; ed++)
	{	
		while (sum < n)
		{
			st++;
			sum += st * st;
		}

		if (sum == n)
		{
			cout << ed << " " << st << "\n";
			return 0;
		}

		sum -= ed*ed;
	}

	cout << "NIE\n";
	
	return 0;
}