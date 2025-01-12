#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n, k;
	cin >> n >> k;

	vector<long long> v;

	long long a;
	for (long long i=0; i<n; i++)
		cin >> a, v.push_back(a);

	sort(v.begin(), v.end());

	long long t = 0, mx = 0;
	for (long long i=0; i<n-k-1; i++)
	{
		if (v[i] == v[i+1])
			t++;
		else
			t=0;

		mx = max(mx, t);
	}

	long long ans = min(n, mx + k + 1);
	cout<<ans<<"\n";

	return 0;
}