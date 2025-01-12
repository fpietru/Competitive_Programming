#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 2e5+5;
vector<int> G[MxN];
vector<int> roots;
int n;
ll K, k;
ll suma = 0LL;
ll koszt[MxN];
bool flag = 1;

void dfs(int v, int p)
{
	for (auto u : G[v])
		if (u != p)
			dfs(u, v);
			
	ll mx = 0;
	for (auto u : G[v])
		if (u != p)
		 mx = max(mx, koszt[u]);

	koszt[v] = mx + (mx/2) + (mx % 2);

	if (G[v].size() == 1 && G[v].back() == p)
		koszt[v] = k;
		
	suma += koszt[v];
	if (suma > K)
	{
		flag = 0;
		suma = 0LL;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> K;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		if (x > 0)
		{
			G[i].push_back(x);
			G[x].push_back(i);
		}
		else
			roots.push_back(i);
	}
	
	ll low = 1;
	ll high = 1e18 / (ll)n + 1LL;
	while (low < high)
	{
		ll mid = (low + high) >> 1;
		k = mid;
		flag = 1;
		suma = 0LL;
		for (auto r : roots)
			dfs(r, r);
		
		if (flag == 1)
			low = mid + 1;
		else high = mid;		
	}
	low--;
	
	if (low > 0)
		cout << low << "\n";
	else cout << "NIE\n";
	
    return 0;
}
