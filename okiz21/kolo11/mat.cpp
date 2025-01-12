#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second

constexpr int MxN = 5e5+55;
vector<pii> G[MxN];
int budki[MxN];
int color[MxN];
int n, m, k;

void dfs(int v, int c, int t)
{
	for (auto e : G[v])
		if (color[e.FR] == 0 && e.SD > t)
		{
			color[e.FR] = c;
			dfs(e.FR, c, t);
		}
}

bool check(int t)
{
	for (int i=1; i<=n; i++)
		color[i] = 0;

	int c = 0;
	for (int i=1; i<=n; i++)
		if (color[i] == 0)
		{
			color[i] = ++c;
			dfs(i, c, t);

			bool flag = 1;
			for (int j=1; j<k; j++)
				if (color[budki[0]] != color[budki[j]])
				{
					flag = 0;
					break;
				}

			if (flag && color[budki[0]] != 0)
				return 1;
		}
	
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<k; i++)
		cin >> budki[i];

	int mx_edge = -1;
	for (int i=0; i<m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		G[a].push_back({b, c});
		G[b].push_back({a, c});
		mx_edge = max(mx_edge, c);
	}

	if (k == 1)
	{
		cout << "KEEP CALM AND FOLLOW THE WHITE RABBIT\n";
		return 0;
	}

	int low = 0;
	int high = mx_edge;

	while (low < high)
	{
		int mid = ((ll)low + high) >> 1;
		if (check(mid))
			low = mid + 1;
		else high = mid;
	}

	cout << low-1 << "\n";
	
	return 0;
}