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

constexpr int MxN = 2e5+5;
vector<int> G[MxN];
vector<int> kolejnosc1, kolejnosc2;
bool vis[MxN];

void dfs(int st)
{
	stack<int> S;
	vis[st] = 1;
	S.push(st);
	
	while (!S.empty())
	{
		int X = S.top();
		S.pop();
		
		for (auto u : G[X])
			if (vis[u] == 0)
				S.push(u), vis[u] = 1;

		
		kolejnosc1.push_back(X);
	}
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

	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		kolejnosc2.push_back(x);
	}

	
	for (auto p : kolejnosc2)
	{
		memset(vis, 0, sizeof(vis));
		kolejnosc1.clear();
		dfs(p);
		
		for (auto i : kolejnosc1)
			cout << i << " ";
		cout << "\n";
		
	}
	cout << "\n";	

    return 0;
}
