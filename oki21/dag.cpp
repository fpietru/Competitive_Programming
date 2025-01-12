/*
	Zadanie "Destrukcyjny Afiliacyjny Graf" z OKI
*/
#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e6+6;
vector<int> G[MxN];
int W[MxN];
int n, m;

vector<int> tsort()
{
	queue<int> qu;
	vector<int> vec;
	for (int i=1; i<=n; i++)
		if (!W[i]) qu.push(i);

	while (!qu.empty())
	{
		int v = qu.front();
		vec.push_back(v);
		qu.pop();

		for (auto u : G[v])
		{
			W[u]--;
			if (W[u] == 0)
				qu.push(u);
		}
	}

	return vec;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i=0; i<m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		W[b]++;
	}

	for (auto i : tsort())
		cout << i << " ";
	cout << "\n";

	return 0;
}