#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n; cin >> n;
	vector<long long> c(n);
	for (long long i=0; i<n; i++)
		cin >> c[i];

	long long opti = c[n-1] + 1, ans = 0;
	for (long long i=n-1; i>=0; i--)
	{
		if (c[i] < opti)
			opti = c[i];
		ans += opti;
	}

	cout<<ans<<endl;

	return 0;
}