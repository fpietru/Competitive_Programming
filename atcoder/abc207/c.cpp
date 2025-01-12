/*
	Time: 00:26:46.4
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 2e3+33;
double st[MxN], ed[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		int t;
		cin >> t >> st[i] >> ed[i];
		if (t == 2 || t == 4) ed[i] -= 0.5;
		if (t == 3 || t == 4) st[i] += 0.5;
	}

	int ans = 0;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			ans += (max(st[i], st[j]) <= min(ed[i], ed[j]));

	cout << ans << "\n";
	
	return 0;
}