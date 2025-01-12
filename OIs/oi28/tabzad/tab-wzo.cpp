#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e3+7;
int arr[MxN][MxN];
int ans=0, n, m, q;

void calc(int i, int j)
{
	if (i < 1 || j < 1)
		return;

	ans -= arr[i][j];
	arr[i][j] ^= 1;
	ans += arr[i][j];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> q;
	while (q--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		calc(a-1, b-1);
		calc(c, b-1);
		calc(a-1, d);
		calc(c, d);
		
		cout << ans << "\n";
	}

	return 0;
}