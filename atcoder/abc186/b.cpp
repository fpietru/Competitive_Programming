#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e2+2;
int a[MxN][MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long sum = 0;
	int n, m, c=0, mi=1e9+7;
	cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
		{
			cin >> a[i][j];
			mi = min(mi, a[i][j]);
			sum += (long long)a[i][j];
		}

	cout << sum - n*m*mi << "\n"; 
	
	return 0;
}