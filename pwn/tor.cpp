#include <bits/stdc++.h>

using namespace std;

const long long MXn = 1e6;
pair<long long, long long> nigh[MXn];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;

	for (long long i=0; i<n; i++)
		cin >> nigh[i].first >> nigh[i].second;

	sort(nigh, nigh + n);

	long long dst = nigh[0].second;
	long long mdst = 1e9;
	for (long long i=1; i<n; i++)
	{
		dst += (nigh[i].first - nigh[i-1].first);
		mdst = min(mdst, dst+nigh[i].second);
		dst = min(dst, nigh[i].second); 
	}

	cout<<mdst<<"\n";

	return 0;
}