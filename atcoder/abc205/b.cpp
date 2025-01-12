#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

constexpr int MxN = 1e3+33;
bool been[MxN];
map<int, int> mp;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		int x; cin >> x;
		mp[x]++;
	}

	bool flag = 1;

	for (auto p : mp)
	{
		been[p.FR] = 1;
		if (p.SD != 1)
		{
			flag = 0;
			break;
		}
	}

	for (int i=1; i<=n; i++)
		if (!been[i])
		{
			flag = 0;
			break;
		}

	cout << (flag ? "Yes\n" : "No\n");
	
	return 0;
}