/*
	Zadanie "Łuk triumfalny" z XX OI, etap II
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 3e5+15;
vector<int> G[MxN];
ll dp[MxN];

/*
	dp[v] = minimalna liczba łuków potrzebnych do zbudowania w poddrzewie v,
	aby wchodząc do poddrzewa v król nie odwiedził żadnego wierzchołka bez łuku
	dp[1] = 0 <=> k jest OK
	dp[1] > 0 <=> k nie jest OK
	gdzie k = liczba ekip budowlanych  
*/

void dfs(int v, int p, int k)
{
	// jest liściem
	if (G[v].size() == 1 && G[v].back() == p)
	{
		dp[v] = 0; // nie mają poddrzewa, więc dp[liść] = 0
		return;
	}
	
	for (int u : G[v])
		if (u != p)
			dfs(u, v, k);
			
	ll sons_dp = 0;
	for (int u : G[v])
		if (u != p)
			sons_dp += dp[u] + 1;
	
	dp[v] = max(0LL, sons_dp - (ll)k);		
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n-1; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int low = 0;
	int high = MxN;
	while (low < high)
	{
		int mid = (low + high) / 2;
		dfs(1, 1, mid);
		if (dp[1] > 0)
			low = mid + 1;
		else
			high = mid;
	}
	
	cout << low << "\n";
	
	return 0;
}
