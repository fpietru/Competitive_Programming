#include <bits/stdc++.h>
using namespace std;

long long candidate(vector<long long> arr)
{
	long long candidate = arr[0], dopary = 1;
	for (long long i=1; i<arr.size(); i++)
	{
		if (dopary > 0)
		{
			if (candidate == arr[i])
				dopary++;
			else
				dopary--;
		}
		else
		{
			dopary++;
			candidate = arr[i];
		}
	}

	return candidate;
}

int main()
{
	long long n; cin >> n;
	vector<long long> pref;
	vector<long long> cand;
	for (long long i=0; i<n; i++)
	{
		long long a; cin >> a;
		pref.push_back(a);
		cand.push_back(candidate(pref));
	}

	long long h = 0;
	long long leader = candidate(cand);
	for (auto i : cand)
		if (i == leader)
			h++;

	if (h > n/2) cout<<leader<<"\n";
	else cout<<"NIE\n";

	return 0;
}