#include <bits/stdc++.h>
using namespace std;

const int base = 16;
int t[((1<<base)<<1)+22], s[(1<<base)+22];

void build(int v, int st, int ed)
{
	if (st == ed)
		t[v] = st;
	else
	{
		int md = (st + ed) >> 1;
		build(2*v, st, md);
		build(2*v+1, md+1, ed);
		if (s[t[2*v]] >= s[t[2*v+1]])
			t[v] = t[2*v];
		else
			t[v] = t[2*v+1];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=(1<<n); i++)
		cin >> s[i];

	build(1, 1, (1<<n));

	int ans;
	if (t[1] == t[2]) ans = t[3];
	else ans = t[2];
	cout << ans << "\n";

	return 0;
}