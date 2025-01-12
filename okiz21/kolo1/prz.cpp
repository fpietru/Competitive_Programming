#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e6+66;
int p[MxN], a[MxN]; 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=0; i<m; i++)
		cin >> p[i];

	int mx = 0, gmx = 0;
	for (int i=0; i<m; i++)
	{
		if (p[i] == n+1)
			gmx = mx;
		else
		{
			if (a[p[i]] < gmx)
				a[p[i]] = gmx;
			a[p[i]]++;
			mx = max(a[p[i]], mx);
		}
	}

	for (int i=1; i<=n; i++)
		cout << max(gmx, a[i]) << " ";
	cout << "\n";
	
	return 0;
}