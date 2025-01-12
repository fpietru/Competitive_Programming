#include <bits/stdc++.h>
using namespace std;

struct human { int id, w; };
const int MxN = 5e5+5;
int s[MxN], ans[MxN];
human h[MxN];

bool cmp(human a, human b)
{
	return a.w < b.w;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> s[i];
	for (int i=0; i<m; i++)
	{
		cin >> h[i].w;
		h[i].id = i;
	}
	
	sort(h, h+m, cmp);

	int i = 1, j = 0;
	while (i <= n && j < m)
	{
		if (h[j].w <= s[i])
		{
			ans[h[j].id] = i-1;
			j++;
		}
		else i++;
	}

	for (int k=j; k<m; k++)
		ans[h[k].id] = n;

	for (int i=0; i<m; i++)
		cout << ans[i] << " ";
	cout << "\n";

	return 0;
}