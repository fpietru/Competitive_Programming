#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int MxN = 1e3+13;
constexpr int INF = 1e9+7;
char m[MxN][MxN];
pii start, koniec;
int dst[MxN][MxN];
pii parent[MxN][MxN];
vector<pii> NGB = {{-1,0}, {+1,0}, {0,-1}, {0,+1}};
int n;
pii FRfree = {-1,-1};
set<pii> ceglaRow[MxN][MxN];
set<pii> ceglaCol[MxN][MxN];
bool isceglaR[MxN];
bool isceglaC[MxN];

struct info
{
	pii cord;
	int D;
	pii det;
};


bool ok(int y, int x)
{
	// zmienic potem dla usuwanie cegiel
	if (y < 1 || y > n || x < 1 || x > n || dst[y][x] != INF || m[y][x] == 'X')
		return 0;
	return 1;
}

int bfs()
{
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			dst[i][j] = INF;		

	queue<info> Q;
	Q.push({{start.FR, start.SD}, 0, {-1,-1}});
	dst[start.FR][start.SD] = 0;
	parent[start.FR][start.SD] = {-1,-1};
	
	while (!Q.empty())
	{
		pii v = Q.front().cord;
		int DST = Q.front().D;
		pii detonator = Q.front().det;
		Q.pop();
	
		// deb(v.FR, v.SD, D);
		
		if (v == koniec)
			return DST;
		
		for (auto N : NGB)
		{
			int n_y = v.FR + N.FR;
			int n_x = v.SD + N.SD;
			
			if (ok(n_y, n_x))
			{
				
				if (m[n_y][n_x] == '#')
				{
					if (detonator == make_pair(-1,-1))
					{
						dst[n_y][n_x] = DST + 1;
						parent[n_y][n_x] = {v.FR, v.SD};
						Q.push({{n_y, n_x}, dst[n_y][n_x], });
					}
				}
			
				dst[n_y][n_x] = DST + 1;
				parent[n_y][n_x] = {v.FR, v.SD};
				Q.push({{n_y, n_x}, dst[n_y][n_x]});
			}
		}
	}
	
	return -1;
}

string getwalk()
{
	string walk = "";
	pii v = koniec;
	while (parent[v.FR][v.SD] != make_pair(-1,-1))
	{
		int r_y = v.FR - parent[v.FR][v.SD].FR;
		int r_x = v.SD - parent[v.FR][v.SD].SD;
		
		if (make_pair(r_y, r_x) == make_pair(-1,0)) walk += "G";
		else if (make_pair(r_y, r_x) == make_pair(+1,0)) walk += "D";
		else if (make_pair(r_y, r_x) == make_pair(0,-1)) walk += "L";
		else walk += "P";
					
		//deb(parent[v.FR][v.SD].FR, parent[v.FR][v.SD].SD);
		v = parent[v.FR][v.SD];
	}
	reverse(walk.begin(), walk.end());
	return walk;
}

void podzadanie1()
{
	int ans = bfs();
	
	if (ans == -1)
	{
		cout << "NIE\n";
		return;
	}
		
	cout << ans << "\n";
	cout << FRfree.FR << " " << FRfree.SD << "\n";
	cout << getwalk() << "\n";
}

void zaladujsety()
{
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		{
			if (m[i][j] == '.')
			{
				// ide po kolumnie
				if (isceglaC[j])
				{
					pii bomba = make_pair(i,j);
					int p = i - 1;
					// do gory
					while (p >= 1 && m[p][j] != 'X')
					{
						if (m[p][j] == '#')
							ceglaCol[p][j].insert(bomba);
						p--;
					}
					// do dolu
					p = i + 1;
					while (p <= n && m[p][j] != 'X')
					{
						if (m[p][j] == '#')
							ceglaCol[p][j].insert(bomba);
						p++;
					}
				}
				
				// po wierszu
				if (isceglaR[i])
				{
					pii bomba = make_pair(i,j);
					int p = j - 1;
					// w lewo
					while (p >= 1 && m[i][p] != 'X')
					{
						if (m[i][p] == '#')
							ceglaRow[i][p].insert(bomba);
						p--;
					}
					// do dolu
					p = j + 1;
					while (p <= n && m[i][p] != 'X')
					{
						if (m[i][p] == '#')
							ceglaRow[i][p].insert(bomba);
						p++;
					}					
				}
					
			}
		}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int cnt_brick = 0;
	cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		{
			cin >> m[i][j];
			if (m[i][j] == '#')
			{
				cnt_brick++;
				isceglaR[i] = 1;
				isceglaC[j] = 1;
			}
			else if (m[i][j] == 'P')
				start = {i,j};
			else if (m[i][j] == 'K')
				koniec = {i,j};
			else if (m[i][j] == '.' && FRfree == make_pair(-1, -1))
				FRfree = {i,j};			
		}
		
	// Podzadanie 1
	if (cnt_brick == 0)
		podzadanie1();
		
	zaladujsety();
	
	// test setow
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		{
			if (m[i][j] == '#')
			{
				deb(i, j);
				for (auto p : ceglaCol[i][j])
					cout << p.FR << " " << p.SD << "\n";
				cout << "\n";
				for (auto p : ceglaRow[i][j])
					cout << p.FR << " " << p.SD << "\n";
			}
		}
		

    return 0;
}











