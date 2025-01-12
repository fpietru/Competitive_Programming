#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e5+55;
struct op { int a; int b; };
int msg[MxN][5], flgs[5];
vector<op> ans;

void setflag(int f)
{
	int same = 0;
	if (flgs[0] != 0)
	{
		for (int i=0; i<5; i++)
		{
			if (msg[f][i] == flgs[i])
				same++;
			else break;
		}
		for (int i=0; i<5-same; i++)
		{
			ans.push_back({0,0});
			flgs[4-i] = 0;
		}
	}
	for (int i=same; i<5; i++)
	{
		ans.push_back({1, msg[f][i]});
		flgs[i] = msg[f][i];
	}
}

void takedown()
{
	for (int i=0; i<5; i++)
	{
		ans.push_back({0,0});
		flgs[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<5; j++)
			cin >> msg[i][j];
	}

	while (q--)
	{
		int c; cin >> c;
		setflag(c);
	}
	takedown();

	cout << ans.size() << "\n";
	for (auto o : ans)
	{
		if (o.a == 0)
			cout << o.a << "\n";
		else cout << o.a << " " << o.b << "\n";
	}

	return 0;
}