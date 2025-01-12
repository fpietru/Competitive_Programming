#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back

constexpr int MxN = 2e3+3;
constexpr ll INF = 1e18+7; 
ll cost[MxN][MxN][2];
vector<int> G[MxN];
vector<int> topo;
int tid[MxN];
bool sasiad[MxN][MxN];
bool colored[MxN];
ll dp[MxN][MxN];
int deg[MxN];

void color(int v) {
	colored[v] = true;
	for (auto u : G[v])
		color(u);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int a, b, w1, w2; cin >> a >> b >> w1 >> w2;
		G[a].PB(b);
		sasiad[a][b] = true;
		cost[a][b][0] = w1;
		cost[a][b][1] = w2;
		deg[b]++;
	}
	color(1);
	queue<int> Q;
	for (int i=1; i<=n; i++)
		if (deg[i] == 0 && colored[i])
			Q.push(i);
	
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		topo.PB(v);
		tid[v] = topo.size();
		for (auto u : G[v]) {
			deg[u]--;
			if (deg[u] == 0)
				Q.push(u);
		}
	}
	
	int k = topo.size();
	for (int i=0; i<k; i++)
		for (int j=0; j<k; j++) {
			int x = topo[i];
			int y = topo[j];
			if (x == y && x == 1)
				dp[x][y] = 0;
			else dp[x][y] = INF;
		}
	
	for (int i=0; i<k; i++)
		for (int j=0; j<k; j++) {
			int x = topo[i];
			int y = topo[j];
			
			if (x == y)
				for (auto z : G[x])
					dp[z][z] = min(dp[z][z], dp[x][y] + cost[x][z][0] + cost[y][z][1]);
			
			if (x != y) {
				for (auto z : G[x])
					if (sasiad[y][z])
						dp[z][z] = min(dp[z][z], dp[x][y] + cost[x][z][0] + cost[y][z][1]);
			}
			
			for (auto z : G[x])
				if (tid[z] > tid[y])
					dp[z][y] = min(dp[z][y], dp[x][y] + cost[x][z][0]);
			
			for (auto z : G[y])
				if (tid[z] > tid[x])
					dp[x][z] = min(dp[x][z], dp[x][y] + cost[y][z][1]);
		}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}	
	
	return 0;
}
