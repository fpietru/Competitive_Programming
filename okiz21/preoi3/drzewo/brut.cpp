#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

struct P
{
	int y;
	int x;
};

constexpr int MxN = 1024; 
int mapa[MxN+10][MxN+10];
string s;
int m;
int licznik;

void fillspace(P p1, P p2, int val)
{
	for (int i=p1.y; i<=p2.y; i++)
		for (int j=p1.x; j<=p2.x; j++)
			mapa[i][j] = val;
}

void show()
{
	for (int i=0; i<(1<<m); i++)
	{
		for (int j=0; j<(1<<m); j++)
			cout << mapa[i][j];
		cout << "\n";
	}
}

int sr(int a, int b)
{
	return (a + b) / 2;
}

void dfs(int v, P g1, P g2)
{	
	if (s[v] != '4')
	{
		fillspace(g1, g2, s[v]-'0');
		return;
	}

	P ng1[5];
	P ng2[5];
	
	int mid_y = sr(g1.y, g2.y);
	int mid_x = sr(g1.x, g2.x);
	
	ng1[1] = g1;
	ng2[1] = {mid_y, mid_x};
	
	ng1[2] = {g1.y, mid_x};
	ng2[2] = {mid_y, g2.x};
	
	ng1[3] = {mid_y, g1.x};
	ng2[3] = {g2.y, mid_x};
	
	ng1[4] = {mid_y, mid_x};
	ng2[4] = {g2.y, g2.x};

	for (int i=1; i<=4; i++)
	{
		licznik++;
		dfs(licznik, ng1[i], ng2[i]);
	}
}

bool ok(int i, int j)
{
	if (i < 0 || i > MxN || j < 0 || j > MxN || mapa[i][j] == 0)
		return 0;

	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> m;
	cin >> s;
	
	licznik = 0;
	dfs(0, {0,0}, {(1<<m),(1<<m)});
		
	show();
	
	return 0;
}
