#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s; cin >> s;
	int n = s.size();

	int ans = 1e9+7;
	for (int i=n-1; i>=1; i--)
	{
		if (s[i] == '0')
		{
			for (int j=i-1; j>=0; j--)
				if (s[j] == '0' || s[j] == '5')
				{
					int dst = i-j-1;
					int tail = n-i-1;
					ans = min(ans, dst + tail);
				}
		}
		
		if (s[i] == '5')
		{
			for (int j=i-1; j>=0; j--)
				if (s[j] == '2' || s[j] == '7')
				{
					int dst = i-j-1;
					int tail = n-i-1;
					ans = min(ans, dst + tail);
				}
		}
	}

	cout << ans << "\n";
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