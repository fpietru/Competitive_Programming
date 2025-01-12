#include <bits/stdc++.h>
using namespace std;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int MxN = 1e3+3;
bool t[MxN][MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		t[a][b] = t[b][a] = 1;
	}
	int q; cin >> q;
	while (q--)
	{
		int a, b; cin >> a >> b;
		cout << (t[a][b] ? "TAK\n" : "NIE\n");
	}

    return 0;
}
