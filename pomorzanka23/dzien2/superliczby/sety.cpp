#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define FR first
#define SD second
#define PB push_back

constexpr int MxN = 1e5+5;
vector<int> G[MxN];
set<int> warstwa[MxN];
vector<int> ans;
bool vis[MxN];
int dp[MxN];

void dfs(int v) {
	// cout << "Jestem w " << v << "\n";
	ans.PB(v);
	vis[v] = true;
	for (auto u : G[v])
		if (vis[u] == false)
			dfs(u);
	auto it = find(warstwa[dp[v]].begin(), warstwa[dp[v]].end(), v);
	if (it != warstwa[dp[v]].begin()) {
		it--;
		if (vis[*it] == false)
			dfs(*it);		
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		int mx = 0;
		for (int j=1; j<=x-1; j++)
			mx = max(mx, dp[j]);
		if (!warstwa[mx].empty()) {
			auto it = lower_bound(warstwa[mx].begin(), warstwa[mx].end(), x);
			it--;
			G[x].PB(*it);
		}
		dp[x] = mx + 1;
		warstwa[dp[x]].insert(x);
	}
	
	
	for (int i=1; i<=n; i++) {
		cout << "warstwa " << i << ": ";
		for (auto it : warstwa[i])
			cout << it << " ";
		cout << "\n";
	}
	
	
	for (int i=1; i<=n; i++)
		cout << i << " dp = " << dp[i] << "\n";

	int mx = 0;
	for (int i=1; i<=n; i++)
		mx = max(mx, dp[i]);
	for (int i=1; i<=n; i++)
		if (dp[i] == mx && vis[i] == false)
			dfs(i);

	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());
	for (auto it : ans)
		cout << it << " ";
	cout << "\n";

	return 0;
}
