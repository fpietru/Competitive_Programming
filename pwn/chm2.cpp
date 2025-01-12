#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXn = 1e5, K = 17;
int st[MAXn][K+1];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i=0; i<n; i++)
		cin >> st[i][0];

	for (int j=1; j<=K; j++)
		for (int i=0; i<=n-(1<<j); i++)
			st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);

	int log[MAXn+1];
	log[0] = 1;
	for (int i=2; i<=MAXn; i++)
		log[i] = log[i/2] + 1;

	int m;
	cin >> m;

	while (m--)
	{
		int L, R;
		cin >> L >> R;

		int j = log[R - L + 1];
		int ans = min(st[L][j], st[R-(1<<j)+1][j]);
		cout<<ans<<"\n";
	}

	return 0;
}