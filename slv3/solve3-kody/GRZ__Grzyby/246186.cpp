#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int MxN = 1e3+3;
ll a[MxN][MxN], p[MxN][MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			ll x; cin >> x;			
			p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + x;
		}
	
	int q; cin >> q;
	while (q--)
	{
		pii A, B, C, D;
		cin >> D.FR >> D.SD;
		cin >> B.FR >> B.SD;
		A = {B.FR, D.SD};
		C = {D.FR, B.SD};
		
		cout << p[B.FR][B.SD] - p[A.FR][A.SD-1] - p[C.FR-1][C.SD] + p[D.FR-1][D.SD-1] << "\n";
	} 

    return 0;
}
