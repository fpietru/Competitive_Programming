#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+6;
bool vis[MxN];
int obok[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> obok[i];
	
	int ans = 0;
	for (int i=1; i<=n; i++)
		if (vis[i] == 0)
		{
			ans++;
			int pocz = i;
			int v = i;
			vis[v] = 1;
			while (vis[obok[v]] == 0)
			{
				v = obok[v];
				vis[v] = 1;
			}
			if (obok[v] != pocz)
			{
				cout << "NIE\n";
				return 0;
			}
		}

	cout << ans << "\n";

    return 0;
}
