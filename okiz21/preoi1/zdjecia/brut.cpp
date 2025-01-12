#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 12;
vector<int> G[MxN];

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
	
	vector<int> h(n);
	for (int i=1; i<=n; i++)
		h[i-1] = i;
		
	do
	{
		bool ok = 1;
		for (int i=1; i<=n; i++)
		{
			if (i == 1 || i == 2)
				continue;
				
			int less = 0;
			int more = 0;
			for (int u : G[i])
			{
				if (h[i-1] < h[u-1])
					more++;
				else
					less++;
			}
			if (more != less)
				ok = 0;			
		}
		
		if (ok)
		{
			cout << "TAK\n";
			//for (auto p : h)
			//	cout << p << " ";
			//cout << "\n";
			return 0;
		}
	}
	while (next_permutation(h.begin(), h.end()));
	
	cout << "NIE\n";
	
	return 0;
}
