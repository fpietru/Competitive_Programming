#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second


struct cell { int y; int x; };
constexpr int MxN = 1e3+33;
char t[MxN][MxN];

pair<cell, cell> solve(int n, int m)
{
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (t[i][j] == '#')
			{
				if (t[i-1][j] == '.' && t[i][j-1] == '.') return {{i-1, j}, {i, j-1}};
				if (t[i-1][j] == '.' && t[i][j+1] == '.') return {{i-1, j}, {i, j+1}};
				if (t[i+1][j] == '.' && t[i][j-1] == '.') return {{i+1, j}, {i, j-1}};
				if (t[i+1][j] == '.' && t[i][j+1] == '.') return {{i+1, j}, {i, j+1}};
			}
	return {{0, 0}, {0, 0}};
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			cin >> t[i][j];

	pair<cell, cell> ans = solve(n, m);

	if (ans.FR.y == 0 && ans.FR.x == 0 && ans.SD.y == 0 && ans.SD.x == 0)
		cout << "NIE\n";
	else
	{
		cout << "TAK\n";
		cout << ans.FR.y << " " << ans.FR.x << "\n"; 
		cout << ans.SD.y << " " << ans.SD.x << "\n";
	}


	return 0;
}