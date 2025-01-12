#include <bits/stdc++.h>
using namespace std;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int MxN = 1e6+6;
vector<int> G[MxN];
bool vis[MxN];
vector<int> ans;

void dfs(int v)
{
	vis[v] = 1;
	ans.push_back(v);
	for (auto u : G[v])
		if (!vis[u])
			dfs(u);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	dfs(1);
	
	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (auto p : ans)
		cout << p << " ";
	cout << "\n";

    return 0;
}
