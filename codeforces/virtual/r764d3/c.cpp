#include <bits/stdc++.h>
using namespace std;

bool solve()
{
	int n; cin >> n;
	vector<int> a(n+1);
	vector<bool> used(55, 0);
	for (int i=0; i<n; i++)
		cin >> a[i];
		
	sort(a.begin(), a.end(), greater<int>());
	
	for (int i=0; i<n; i++)
	{
		int x = a[i];
		while (x > n || used[x]) x /= 2;
		if (x > 0) used[x] = 1;
		else return 0;
	}

	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
		cout << (solve() ? "YES\n" : "NO\n");
	
	return 0;
}
