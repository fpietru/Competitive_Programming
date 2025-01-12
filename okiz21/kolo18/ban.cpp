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

constexpr int MxN = 3e4+4;
bool vis[MxN];
int to[MxN];

void dfs(int v)
{
	vis[v] = 1;
	if (to[v] > 0 && !vis[to[v]])
		dfs(to[v]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> to[i];

	int ans = 0;
	for (int i=1; i<=n; i++)
		if (!vis[i])
			ans++, dfs(i);
			
	cout << ans << "\n";

    return 0;
}
