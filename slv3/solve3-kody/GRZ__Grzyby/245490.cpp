#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P {int y, x;};
constexpr int MxN = 1e3+5;
ll p[MxN][MxN];

ll suma(int y1, int x1, int y2, int x2)
{
	P A = {y2, x1};
	P B = {y2, x2};
	P C = {y1, x2};
	P D = {y1, x1};
	return p[B.y][B.x] - p[A.y][A.x-1] - p[C.y-1][C.x] + p[D.x-1][D.y-1];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			ll x; cin >> x;
			p[i][j] = p[i][j-1] + p[i-1][j] - p[i-1][j-1] + x;
		}
		
	int q; cin >> q;
	while (q--)
	{
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << suma(y1, x1, y2, x2) << "\n";
	}

    return 0;
}
