#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
#define FR first
#define SD second

constexpr int MxN = 2e5+55;
vector<pii> G[MxN];
ll dst[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		G[a].push_back({b, c});
	}

	for (int i=1; i<=n; i++)
		dst[i] = 1e18+7;

	priority_queue<pli, vector<pli>, greater<pli>> Q;
	Q.push({0, 1});
	dst[1] = 0;

	while (!Q.empty())
	{
		pli v = Q.top();
		Q.pop();

		if (v.FR != dst[v.SD])
			continue;

		for (auto p : G[v.SD])
			if (v.FR + (ll)p.SD < dst[p.FR])
			{
				dst[p.FR] = v.FR + p.SD;
				Q.push({dst[p.FR], p.FR});
			}
	}

	if (dst[n] == 1e18+7)
		cout << "-1\n";
	else
		cout << dst[n] << "\n";

	return 0;
}