#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

int rand(int a, int b) {
	return a + rand() % (b-a+1);
}

constexpr int MxN = 1e2+2;
bool e[MxN][MxN];
int deg[MxN];

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n = rand(3, 6);
	int m = rand(0, n);
	
	for (int i=0; i<m; i++)
	{
		int a = rand(1, n-1);
		int b = rand(a, n);
		if (e[a][b])
		{
			i--;
			continue;
		}
		
		deg[a]++;
		deg[b]++;
		e[a][b] = e[b][a] = 1;
	}

	for (int i=1; i<=n-1; i++)
		for (int j=i+1; j<=n; j++)
			if ((deg[i] % 2 != 0) && (deg[j] % 2 != 0))
			{
				if (e[i][j] == 1)
				{
					e[i][j] = e[j][i] = 0;
					deg[i]--;
					deg[j]--;
				}
				else
				{
					e[i][j] = e[j][i] = 1;
					deg[i]++;
					deg[j]++;
				}
			}
	
	vector<pii> ans;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (e[i][j] == 1 && i != j)
			{
				ans.push_back({i,j});
				e[i][j] = e[j][i] = 0;
			}

	cout << n << " " << ans.size() << "\n";
	for (auto p : ans)
		cout << p.FR << " " << p.SD << "\n";

	return 0;
}
