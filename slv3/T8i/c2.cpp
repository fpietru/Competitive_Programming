#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string a, b; cin >> a >> b;
	int n = a.size(), ans = 0;
	
	for (int i=0; i<n; i++)
		if (a[i] != b[i])
		{
			ans++;
			char from = a[i];
			char to = b[i];
			for (int j=0; j<n; j++)
			{
				if (a[j] == from) a[j] = to;
				if (b[j] == from) b[j] = to;
			}
		}

	cout << ans << "\n";

	return 0;
}