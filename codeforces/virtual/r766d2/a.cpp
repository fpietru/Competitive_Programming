#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 55;
char t[MxN][MxN];

int solve()
{
	int cntb = 0;
	int n, m, y, x; cin >> n >> m >> y >> x;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			cin >> t[i][j];
			if (t[i][j] == 'B')
				cntb++;
		}
	
	if (cntb == 0)
		return -1;
	
	if (t[y][x] == 'B')
		return 0;
	
	// row
	for (int i=1; i<=m; i++) 
		if (t[y][i] == 'B')
			return 1;
	
	// col
	for (int i=1; i<=n; i++)
		if (t[i][x] == 'B')
			return 1;
			
	return 2;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
		cout << solve() << "\n";
	
	
	return 0;
}
