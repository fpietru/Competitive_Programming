#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e2+22;
char a[MxN][MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int h, w; cin >> h >> w;
	int y, x; cin >> y >> x;
	for (int i=1; i<=h; i++)
		for (int j=1; j<=w; j++)
			cin >> a[i][j];
	
	int ans = 1;
	
	int ty = y + 1;
	while (ty <= h && a[ty][x] == '.')
		ans++, ty++;

	ty = y - 1;
	while (ty >= 1 && a[ty][x] == '.')
		ans++, ty--;

	int tx = x + 1;
	while (tx <= w && a[y][tx] == '.')
		ans++, tx++;

	tx = x - 1;
	while (tx >= 1 && a[y][tx] == '.')
		ans++, tx--;

	cout << ans << '\n';

	return 0;
}