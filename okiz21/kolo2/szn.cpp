#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e6+6;
int s[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, w; cin >> n >> w;
	for (int i=0; i<n; i++)
		cin >> s[i];
	
	int i = 1;	
	int sum = s[0], ans = 0;
	while (i < n)
	{
		while (sum < w && i < n)
		{
			sum += s[i];
			i++;
		}
		
		if (sum >= w)
			ans++;

		sum = s[i];
		i++;
	}

	if (sum >= w)
		ans++;

	cout << ans << "\n";

	return 0;
}