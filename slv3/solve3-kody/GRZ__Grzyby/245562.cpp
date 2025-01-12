#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}*/

struct P {int y, x;};
constexpr int MxN = 1e3+5;
ll p[MxN][MxN];
int a[MxN][MxN];

ll suma(int y1, int x1, int y2, int x2)
{
	P A = {y2, x1};
	P B = {y2, x2};
	P C = {y1, x2};
	P D = {y1, x1};
	return p[B.y][B.x] - p[A.y][A.x-1] - p[C.y-1][C.x] + p[D.x-1][D.y-1];
}

ll brut(int y1, int x1, int y2, int x2)
{
	ll res = 0LL;
	for (int i=y1; i<=y2; i++)
		for (int j=x1; j<=x2; j++)
			res += (ll)a[i][j];
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			cin >> a[i][j];
			p[i][j] = p[i][j-1] + p[i-1][j] - p[i-1][j-1] + (ll)a[i][j];
		}
	
	
	int q; cin >> q;
	while (q--)
	{
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << suma(y1, x1, y2, x2) << "\n";
	}
	
	/*
	for (int y1=1; y1<=n; y1++)
		for (int x1=1; x1<=m; x1++)
			for (int y2=y1; y2<=n; y2++)
				for (int x2=x1; x2<=m; x2++)
				{
					ll A = suma(y1, x1, y2, x2);
					ll B = brut(y1, x1, y2, x2);
					
					deb(y1, x1, y2, x2);
					
					if (A != B)
					{
						cout << "ZLE\n";
						break;
					}
				}
	*/

    return 0;
}
