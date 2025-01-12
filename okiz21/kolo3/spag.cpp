#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e3+33;
int t[MxN][MxN], p[MxN][MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	for (int i=0; i<q; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		t[a-1][b-1]++;
		t[a-1][d]--;
		t[c][b-1]--;
		t[c][d]++;
	}

	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + t[i-1][j-1];
			cout << p[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}