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

constexpr int MxN = 1e5+5;
int deg[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n-1; i++)
	{
		int a, b; cin >> a >> b;
		deg[a]++;
		deg[b]++;
	}
	
	bool flag = 0;
	for (int i=1; i<=n; i++)
		if (deg[i] == n-1)
			flag = 1;
	
	cout << (flag ? "Yes\n" : "No\n");

    return 0;
}
