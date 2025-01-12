/*
	Drzewo przedziałowe Przedział-Punkt
	Sprawdzenie Poprawności: https://cses.fi/problemset/task/1651
	(w tym przypadku indeksowane od 1)
	
	Operacje:
	1: dodaj wartość na przedziale
	2: zwróć wartość elementu na indeksie
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int base = (1<<20);
ll Tree[2*base+10];

void update(int a, int b, int val)
{
	a += base - 1;
	b += base + 1;
	while (a / 2 != b / 2)
	{
		if (a % 2 == 0) Tree[a+1] += (ll)val;
		if (b % 2 != 0) Tree[b-1] += (ll)val;
		a /= 2; b /= 2;
	}
}

ll query(int v)
{
	v += base;
	ll res = 0LL;
	while (v)
	{
		res += Tree[v];
		v /= 2;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		update(i, i, x);
	}
	
	while (q--)
	{
		int op; cin >> op;
		if (op == 1)
		{
			int a, b, val; cin >> a >> b >> val;
			update(a, b, val);
		}
		else
		{
			int k; cin >> k;
			cout << query(k) << "\n";
		}
	}

    return 0;
}
