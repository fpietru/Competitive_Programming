#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxF = 88;
ll fib[MxF];

bool bisearch(ll x)
{
	int low = 0;
	int high = 88;
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (fib[mid] < x)
			low = mid+1;
		else if (fib[mid] == x)
			return 1;
		else
			high = mid;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	fib[0] = 1;
	fib[1] = 1;
	for (int i=2; i<=87; i++)
		fib[i] = fib[i-1] + fib[i-2];
	
	int n; cin >> n;
	int ans = 0, seg = 0;
	for (int i=0; i<n; i++)
	{
		ll x; cin >> x;
		if (bisearch(x) == 1)
			seg++;
		else
		{
			ans = max(ans, seg);
			seg = 0;
		}
	}
	
	if (seg > 0)
		ans = max(ans, seg);
		
	cout << ans << "\n";
	
	return 0;
}
