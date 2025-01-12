/*
	Zadanie "Bitmapa" z VI OI
*/
#include <bits/stdc++.h>
using namespace std;

bool ok(int i, int j, int n, int m)
{
	if (i < 0 || i >= n || j < 0 || j >= m)
		return 0;
	return 1;
}

struct cell
{
	int y;
	int x;
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dst(n, vector<int>(m, -1));
	queue<cell> qu;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
		{
			char c; cin >> c;
			if (c == '1')
			{
				dst[i][j] = 0;
				qu.push({i,j});
			}
		}

	int dy[4] = {-1, +1,  0,  0};
	int dx[4] = { 0,  0, -1, +1};
	while (!qu.empty())
	{
		cell vert1 = qu.front();
		qu.pop();
		for (int i=0; i<4; i++)
		{
			cell vert2 = {vert1.y+dy[i], vert1.x+dx[i]};
			if (ok(vert2.y, vert2.x, n, m) && dst[vert2.y][vert2.x] == -1)
			{
				dst[vert2.y][vert2.x] = dst[vert1.y][vert1.x] + 1;
				qu.push(vert2);				
			}
		}
	}

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
			cout << dst[i][j] << " ";
		cout << "\n";
	}
	
	return 0;
}