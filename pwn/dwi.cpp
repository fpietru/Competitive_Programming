#include <bits/stdc++.h>

using namespace std;

long long findleader(vector<long long> v)
{
	long long value = v[0], dopary = 0;
	for (long long i=0; i<v.size(); i++)
	{
		if (dopary > 0)
		{
			if (value == v[i]) dopary++;
			else dopary--;
		}
		else dopary++, value = v[i];
	}
	long long howm = 0;
	for (long long i=0; i<v.size(); i++)
		if (value == v[i]) howm++;

	if (howm > v.size()/2 && dopary != 0) return value;
	else return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n; cin >> n;
	vector<long long> v(n);
	for (long long i=0; i<n; i++)
		cin >> v[i];

	long long fl = findleader(v);

	long long c = 0;
	vector<long long> pref(n);
	for (long long i=0; i<n; i++)
	{
		if (v[i] == fl)
			c++;
		pref[i] = c;
	}

	c = 0;
	vector<long long> suff(n);
	for (long long i=n-1; i>=0; i--)
	{
		if (v[i] == fl)
			c++;
		suff[i] = c;
	}
/*
	for(auto i : pref)
		cout<<i<<" ";
	cout<<"\n------\n";
	for(auto i : suff)
		cout<<i<<" ";
	cout<<"\n";
*/
	long long ans = 0;
	for (long long i=0; i<n-1; i++)
	{
		//printf("prefix: %d > %d\n", pref[i], (long long)(i+1)/2);
		//printf("sufix: %d > %d\n", suff[i+1], (long long)(n-i-1)/2);
		if (pref[i] > (long long)(i+1)/2 && suff[i+1] > (long long)(n-i-1)/2)
			ans++;
	}
	cout<<ans<<"\n";

	return 0;
}