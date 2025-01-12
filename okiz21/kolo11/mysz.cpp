#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int MxN = 1e3+13;
bool vis[MxN][MxN];
int dst[MxN][MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	pii start, end;
	int N, M; cin >> N >> M;
	for (int i=1; i<=N; i++)
	{
		string s; cin >> s;
		for (int j=1; j<=M; j++)
		{
			char c = s[j-1];
			if (c == 'o')
				start = {i, j};
			if (c == 'w')
				end = {i, j};
			if (c == 'x')
				vis[i][j] = 1;
		}
	}

	queue<pii> Q;
	Q.push(start);
	vis[start.FR][start.SD] = 1;
	dst[start.FR][start.SD] = 1;

	vector<pii> ngb = {{-1,0}, {+1,0}, {0,-1}, {0,+1}};

	while (!Q.empty())
	{
		pii v = Q.front();
		Q.pop();

		for (auto n : ngb)
		{
			int ui = v.FR + n.FR;
			int uj = v.SD + n.SD;

			if (ui >= 1 && ui <= N && uj >= 1 && uj <= M && !vis[ui][uj])
			{
				vis[ui][uj] = 1;
				dst[ui][uj] = dst[v.FR][v.SD] + 1;
				Q.push({ui, uj});
			}
		}
	}

/*	for (int i=1; i<=N; i++)
	{
		for (int j=1; j<=M; j++)
			cout << dst[i][j] << " ";
		cout << "\n";
	}*/

	if (dst[end.FR][end.SD] == 0)
		cout << "NIE\n";
	else
		cout << dst[end.FR][end.SD] << "\n";

	return 0;
}