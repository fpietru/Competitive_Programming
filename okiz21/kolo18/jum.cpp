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

constexpr int MxN = 5e5+5;
vector<int> G[MxN];
int pre[2*MxN];
int post[2*MxN];
int timer = 0;

void dfs(int v, int p)
{
	pre[v] = ++timer;
	for (int u : G[v])
		if (u != p)
			dfs(u, v);
	post[v] = ++timer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n-1; i++)
	{
		int x; cin >> x;
		G[i].push_back(x);
		G[x].push_back(i);
	}
	
	dfs(0, 0);
	
	int a, b;
	while (cin >> a)
	{
		if (a == -1)
			break;
		cin >> b;
		cout << (pre[a] < pre[b] && post[a] > post[b] ? "TAK\n" : "NIE\n");
	}

    return 0;
}
