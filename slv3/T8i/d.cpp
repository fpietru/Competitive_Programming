#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e5+55;
int a[MxN], n, sum = 0;

vector<int> getdivisors(int n)
{
	vector<int> res;
	for (int i=1; i*i<=n; i++)
	{
		if (n % i == 0)
		{
			if (n / i == i)
				res.push_back(i);
			else
			{
				res.push_back(i);
				res.push_back(n/i);
			}
		}
	}
	sort(res.begin(), res.end());
	return res;
}

int countsegs(int x)
{
	int s = 0, res = 0;
	for (int i=0; i<n;)
	{
		while (i < n && s + a[i] <= x)
			s += a[i++];
		if (s == x)
		{
			res++;
			s = 0;
		}
		else return -1;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	int ans = 0;
	for (int d : getdivisors(sum))
		ans = max(ans, countsegs(d));
	
	cout << ans << "\n";

	return 0;
}