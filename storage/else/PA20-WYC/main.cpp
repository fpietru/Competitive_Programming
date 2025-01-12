/*
	Rozwiązanie do zadania "Wycieczka górska [C]" z Potyczek Algorytmicznych 2020
*/
#include <bits/stdc++.h>
#define FR first
#define SD second
#define LL long long
using namespace std;

const int MxNM = 2e3+17;
bool arr[MxNM][MxNM];
bool visited[MxNM][MxNM];
pair<int, int> parent[MxNM][MxNM];
queue<pair<int, int>> qu;
map<LL, int> mp;
int n, m, k;
LL ups = 0, downs = 0;

bool ok(int y, int x)
{
	if (y < 0 || y > n-1 || x < 0 || x > m-1 || !arr[y][x] || visited[y][x])
		return 0;
	return 1;
}

void path(pair<int, int> A)
{
	// cout << "[" << A.FR << "," << A.SD <<"]\n";
	pair<int, int> B = parent[A.FR][A.SD];

	if (B == make_pair(-1, -1))
		return;

	if ((B.FR - A.FR == 1 && B.SD - A.SD == 0) || (B.FR - A.FR == 0 && B.SD - A.SD == 1))
		ups++;
	else
		downs++;

	path(B);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
		{
			char c; cin >> c;
			if (c == '.') arr[i][j] = 1;
			else arr[i][j] = 0;
		}

	qu.push({n-1,m-1});
	parent[n-1][m-1] = {-1,-1};
	visited[n-1][m-1] = 1;
	while (!qu.empty())
	{
		pair<int, int> v = qu.front();
		qu.pop();
		int dy[4] = {+1,  0, -1,  0};
		int dx[4] = { 0, +1,  0, -1};
		for (int i=0; i<4; i++)
		{
			pair<int, int> u = {v.FR+dy[i], v.SD+dx[i]};
			if (ok(u.FR, u.SD))
			{
				visited[u.FR][u.SD] = 1;
				parent[u.FR][u.SD] = v;
				qu.push(u);

				if (u.FR == 0 && u.SD == 0)
					break;
			}
		}
	}

	path(make_pair(0, 0));

	while (k--)
	{
		LL a, b; cin >> a >> b;
		mp[a*ups+b*downs]++;
	}

	cout << mp.begin()->FR << " " << mp.begin()->SD << "\n";

	return 0;
}