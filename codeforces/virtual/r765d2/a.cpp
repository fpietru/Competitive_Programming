#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, l; cin >> n >> l;
	vector<int> a(n+1);
	
	for (int i=1; i<=n; i++)
		cin >> a[i];
	
	int ans = 0;
	for (int i=l-1; i>=0; i--)
	{
		int white = 0, black = 0;
		for (int j=1; j<=n; j++)
		{
			if (a[j]&(1<<i))
				white++;
			else
				black++;
		}
		if (white > black)
			ans |= (1 << i);
	}
	
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while (t--)
		solve();
	
	return 0;
}
