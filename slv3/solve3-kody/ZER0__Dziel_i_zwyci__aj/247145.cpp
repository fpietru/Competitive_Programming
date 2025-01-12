#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int INF = 1e9+7;

vector<int> divs(int x)
{
	vector<int> res;
	for (int i=2; i*i<=x; i++)
		if (x % i == 0)
		{
			if (x / i == i)
				res.push_back(i);
			else
			{
				res.push_back(i);
				res.push_back(x/i);
			}	
		}
	return res;
}

int bfs(int x)
{
	queue<pii> Q;
	Q.push({x, 0});
	while (!Q.empty())
	{
		pii P = Q.front();
		Q.pop();
		
		if (P.FR == 0)
			return P.SD;
		
		Q.push({P.FR-1, P.SD+1});
		for (auto d : divs(P.FR))
			Q.push({d, P.SD+1});
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	cout << bfs(n) << "\n";

    return 0;
}
