#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second
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
int d[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(d, -1, sizeof(d));
	
	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	queue<pii> Q;
	Q.push({1, 0});
	d[1] = 0;
	
	while (!Q.empty())
	{
		int v = Q.front().FR;
		int D = Q.front().SD;
		Q.pop();
		for (auto u : G[v])
			if (d[u] == -1)
			{
				d[u] = D + 1;
				Q.push({u, D+1});
			}
	}

	for (int i=1; i<=n; i++)
		cout << d[i] << " ";
	cout << "\n";

    return 0;
}
