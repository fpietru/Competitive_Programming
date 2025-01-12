#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define FR first
#define SD second
#define PB push_back

constexpr int MxN = 1e5+5;
vector<int> G[MxN];
set<int> ans;
int dp[MxN];

void dfs(int v) {
	ans.insert(v);
	for (auto u : G[v])
		dfs(u);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		vector<int> best; int mx = 0;
		for (int j=1; j<=x-1; j++)
			if (dp[j] >= mx) {
				if (dp[j] == mx) best.PB(j);
				else {
					mx = dp[j];
					best.clear();
					best.PB(j);
				}
			}
		if (mx > 0)
			for (auto it : best)
				G[x].PB(it);
		dp[x] = mx + 1;
	}
	
	// for (int i=1; i<=n; i++)
	// 	cout << i << " dp = " << dp[i] << "\n";
	
	int mx = 0;
	for (int i=1; i<=n; i++)
		mx = max(mx, dp[i]);
	for (int i=1; i<=n; i++)
		if (dp[i] == mx)
			dfs(i);
			
	// cout << "DL = " << mx << "\n";

	cout << ans.size() << "\n";
	for (auto it : ans)
		cout << it << " ";
	cout << "\n";	

	return 0;
}
