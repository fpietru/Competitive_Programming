#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}
#define FR first
#define SD second

constexpr int MxN = 1e5+15;
vector<pii> G[MxN];
int deg[MxN];
int n, m;

bool iscycle(int k)
{
	memset(deg, 0, sizeof(deg));
	
	// obliczanie nowego stopnia dla wierzchołków
	for (int i=1; i<=n; i++)
		for (auto e : G[i])
			if (e.SD <= k)
				deg[e.FR]++;
	
	// Toposort
	queue<int> Q;
	vector<int> toposorted;

	for (int i=1; i<=n; i++)
		if (deg[i] == 0)
			Q.push(i);				
	
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		
		toposorted.push_back(v);
		
		for (auto e : G[v])
			if (e.SD <= k)
			{
				deg[e.FR]--;
				if (deg[e.FR] == 0)
					Q.push(e.FR);
			}
	}
	
	return ((int)toposorted.size() != n);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back({b, i});
	}

	int low = 1;
	int high = m + 1;
	
	while (low < high)
	{
		int mid = (low + high) >> 1;
		if (iscycle(mid) == 0)
			low = mid + 1;
		else
			high = mid;
	}
	
	if (low > m)
		cout << "NIE\n";
	else
		cout << low << "\n";

    return 0;
}
