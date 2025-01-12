/*
	Zadanie "Bankiet" z I OIG
*/
#include <bits/stdc++.h>
using namespace std;

const int MxN = 3e4+3;
vector<int> G[MxN];
vector<bool> V(MxN, 0);

void dfs(int v)
{
	V[v] = 1;
	for (auto w : G[v])
		if (!V[w]) dfs(w);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	int b=1;
	for (int i=1; i<=n; i++)
	{
		int a; cin >> a;
		G[a].push_back(b);
		G[b].push_back(a);
		b++;
	}

	int ans=0;
	for (int i=1; i<=n; i++)
	{
		if (V[i]) continue;
		ans++;
		dfs(i);
	}

	cout<<ans<<"\n";

	return 0;
}