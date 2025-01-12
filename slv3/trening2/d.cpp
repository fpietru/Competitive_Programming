#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int MxN = 5e5+15;
int dag[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		dag[a]++;
		dag[b]++;
	}
	
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	
	for (int i=1; i<=n; i++)
		if (dag[i] < 2)
			Q.push({dag[i], i});
	
	int ans = 0;
	while (!Q.empty())
	{
		pii a = Q.top();
		Q.pop();
	
		// cout << a.FR << " " << a.SD << " ";
		
		if (Q.empty())
		{
			// cout << "koniec\n";
			ans += (2-a.FR);
			break;
		}
		
		pii b = Q.top();
		Q.pop();
		
		// cout << b.FR << " " << b.SD << "\n";
		
		if (a.FR == 0 && b.FR == 0)
		{
			ans++;
			dag[a.SD]++;
			dag[b.SD]++;
			Q.push({dag[a.SD], a.SD});
			Q.push({dag[b.SD], b.SD});
		}
		else if ((a.FR == 1 && b.FR == 1))
		{
			ans++;
			dag[a.SD]++;
			dag[b.SD]++;
		}
		else if (a.FR == 0 && b.FR == 1)
		{
			ans++;
			dag[a.SD]++;
			dag[b.SD]++;
			Q.push({dag[a.SD], a.SD});
		}
	}
	
	cout << ans << "\n";

	
	return 0;
}
