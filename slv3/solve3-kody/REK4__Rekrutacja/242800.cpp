#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxF = 87;

ll f[MxF+1];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	f[0] = 0;
	f[1] = 1; 
	for (int i=2; i<=MxF; i++)
		f[i] = f[i-1] + f[i-2];

 	/*for (int i=0; i<=MxF; i++)
 		if (f[i] <= (ll)1e18)
	 		cout << i << " " << f[i] << "\n";
	*/

	ll n; int k; cin >> n >> k;
	
	if (k == 1)
	{
		// łatwe punkty ez
		for (int i=0; i<=MxF; i++)
			if (n == f[i])
			{
				cout << f[i] << "\n";
				return 0;
			}
		cout << "NIE\n";
		return 0;
	}

    return 0;
}
