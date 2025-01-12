#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e2+2;
int t[MxN], p[MxN], x[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, sum=0; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> t[i], sum += t[i];
	
	int m, p, x; cin >> m;
	for (int i=1; i<=m; i++)
	{
		cin >> p >> x;
		cout << sum - t[p] + x << "\n";
	}

	return 0;
}