/*
	HAD TO LOOK EDITORIAL
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 2e5+55;
set<int> st;
int a[MxN];
bool vis[MxN];
vector<int> G[MxN];

void dfs(int v)
{
	vis[v] = 1;
	for (int u : G[v])
		if (!vis[u])
			dfs(u);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> a[i];
		st.insert(a[i]); // count different elements
	}
		
	for (int i=0, j=n-1; i<n/2; i++, j--)
		if (a[i] != a[j])
		{
			G[a[i]].push_back(a[j]);			
			G[a[j]].push_back(a[i]);			
		}

	int cc = 0; // connected components count
	for (auto p : st)
	{
		if (!vis[p])
		{
			cc++;
			dfs(p);
		}
	}

	cout << st.size() - cc << "\n";

	return 0;
}