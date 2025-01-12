#include <bits/stdc++.h>
using namespace std;

int main()
{

	long long z; cin >> z;
	while (z--)
	{
		long long n; cin >> n;
		vector<long long> arr(n-1);
		for (long long i=0; i<n-1; i++)
			cin>>arr[i];

		long long p=0, mp=0;
		for (long long i=0; i<n-1; i++)
		{
			p += arr[i];
			mp = max(mp, p);
		}
		long long s=0, ms=0;
		for (long long i=n-2; i>=0; i--)
		{
			s += arr[i];
			ms = max(ms, s);	
		}
		cout<<mp + ms<<"\n";
	}
	
	return 0;
}