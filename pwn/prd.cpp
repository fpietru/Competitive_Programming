#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n; cin >> n;
	vector<long long> arr(n);
	for (long long i=0; i<n; i++)
		cin >> arr[i];

	long long ts=0, s=0;
	vector<long long> p(n);
	for (long long i=n-2; i>=1; i--)
	{
		s = max(s+arr[i], arr[i]);
		ts = max(ts, s);
		p[i] = ts;
	}
	
	ts=0, s=0;
	vector<long long> l(n);
	for (long long i=1; i<n-1; i++)
	{
		s = max(s+arr[i], arr[i]);
		ts = max(ts, s);
		l[i] = ts;
	}
/*
	cout<<"l: ";
	for (auto i:l)
		cout<<i<<" ";
	cout<<"\np: ";
	for (auto i:p)
		cout<<i<<" ";
*/
	long long ans=0;
	for (long long i=1; i<n-1; i++)
	{
		//cout<<"\n"<<l[i-1]<<":"<<p[i+1];
		ans = max(ans, l[i-1] + p[i+1]);
	}
	cout<<ans<<"\n";

	return 0;
}