#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

pii saveseg(int n, int t, bool k)
{
	if (k)
	{
		n -= t;
		if (n > 0)
		{
			t++;
			return {n, t};
		}
		else
			return {0, t};
	}
	else
	{
		n -= 2*t;
		if (n <= 0)
			return {0, t};
		else
		{
			if (n == 1)
				return {n, t+1};
			else
				return {n-1, t+2};
		}
	}
}

int simulate(vector<int> &a, vector<int> &b, int mode)
{
	int saved = 0, time = 0;
	if (mode == 1)
	{
			
	}
}

void solve()
{
	int n; cin >> n;
	vector<int> a, b;
	string s; cin >> s;
	
	// dla prefiksu
	int p = 0;
	while (p < n && s[p] == '0')
		p++;

	if (p > 0)
		b.push_back(p);

	// jeśli nie ma żadnego miasta zarażonego
	if (p == n)
	{
		cout << "0\n";
		return;
	}

	// dla sufiksu
	int k=n-1;
	while (k >= 0 && s[k] == '0')
		k--;

	if (k < n-1)
		b.push_back(n-1-k);

	int cnt = 0;
	for (int i=p; i<=k; i++)
	{
		if (s[i] == '0')
			cnt++;
		else if (cnt > 0)
		{
			a.push_back(cnt);
			cnt = 0;
		}
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());


}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--)
		solve();
	
	return 0;
}