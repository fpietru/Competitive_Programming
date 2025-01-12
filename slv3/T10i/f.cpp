#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FR first
#define SD second

constexpr int MxN = 5e5+5, MxG = 22;
vector<pair<int, ll>> G[MxG];
int gal[MxN];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, g; cin >> n >> m >> g;
	for (int i=1; i<=n; i++)
		cin >> gal[i];

	for (int i=1; i<=m; i++)
	{
		int a, b; ll c;
		cin >> a >> b >> c;
		if (gal[a] != gal[b])
		{
			G[gal[a]].push_back({gal[b], c});
			G[gal[b]].push_back({gal[a], c});
		}
	}

	for (int i=1; i<=g; i++)

	
	return 0;
}