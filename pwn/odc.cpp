#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, p, ts = 0, s = 0;
	cin >> n;
	cin >> p;
	for (long long i=1; i<n; i++)
	{
		long long c; cin >> c;
		long long d = p - c;
		s = max(s + d, d);
		ts = max(ts, s);
		p = c;
	}
	cout<<ts<<"\n";

	return 0;
}