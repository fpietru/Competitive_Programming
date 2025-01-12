#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

constexpr int MxN = 200;
int ans[MxN][MxN];
bool vis[MxN][MxN];
pair<int, int> dirs[4] = {{-1,0},{1,0},{0,-1},{0,1}};
struct node {int i, j, d;};
int n, m;

bool check(int i, int j)
{
	if (i < 1 || i > n || j < 1 || j > m || vis[i][j] == 1)
		return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	queue<node> qu;
	for (int i=1; i<=n; i++)
	{
		string s; cin >> s;
		for (int j=1; j<=m; j++)
			if (s[j-1] - '0' == 1)
			{
				vis[i][j] = 1;
				qu.push({i, j, 0});
			}
	}

	while (!qu.empty())
	{
		node v = qu.front();
		qu.pop();

		for (auto d : dirs)
		{			
			if (check(v.i+d.FR, v.j+d.SD))
			{
				ans[v.i+d.FR][v.j+d.SD] = v.d + 1;
				vis[v.i+d.FR][v.j+d.SD] = 1;
				qu.push({v.i+d.FR, v.j+d.SD, v.d+1});
			}
		}
	}

	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}

	return 0;
}