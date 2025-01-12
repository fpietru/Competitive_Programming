#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e3+3;
int a[MxN], b[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i] >> b[i];

	int ans = 1e9+9;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
		{
			if (i == j)
				ans = min(ans, a[i]+b[j]);
			else
				ans = min(ans, max(a[i], b[j]));
		}

	cout << ans << "\n";

	return 0;
}