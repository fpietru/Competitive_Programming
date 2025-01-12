#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e6+6;
bool a[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, ans = 0; cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	
	int cjump = 0;
	for (int i=0; i<n; i++)
	{
		if (a[i])
		{
			cjump++;
			ans = max(ans, cjump);
		}
		else cjump = 0;
	}

	cout << ans << "\n";

	return 0;
}