#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long z;
	cin >> z;

	while (z--)
	{
		long long n;
		vector<long long> v;
		cin >> n;

		long long a;
		for (long long i=0; i<n; i++)
			cin >> a, v.push_back(a);

		sort(v.begin(), v.end());
		long long a1 = v[n-1] * v[n-2] * v[n-3];
		long long a2 = v[0] * v[1] * v[n-1];
		long long ans = max(a1, a2);

		cout<<ans<<"\n";
	}

	return 0;
}