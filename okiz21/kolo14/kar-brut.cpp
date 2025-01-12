#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 2e5+15;
int a[MxN], r[MxN], order[MxN];
int n;

bool check()
{
	bool up = 1, down = 1;
	for (int i=1; i<=n-1; i++)
	{
		int A = order[i];
		int B = order[i+1];
		bool nup = 0, ndown = 0;

		if (up == 1)
		{
			if (a[A] <= a[B])
				nup = 1;
			if (a[A] <= r[B])
				ndown = 1;
		}

		if (down == 1)
		{
			if (r[A] <= a[B])
				nup = 1;
			if (r[A] <= r[B])
				ndown = 1;
		}

		up = nup;
		down = ndown;
	}

	return (up || down);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i] >> r[i];
		order[i] = i;
	}

	int q; cin >> q;
	while (q--)
	{
		int a, b; cin >> a >> b;
		swap(order[a], order[b]);
		cout << (check() ? "TAK\n" : "NIE\n");
	}
	
	return 0;
}