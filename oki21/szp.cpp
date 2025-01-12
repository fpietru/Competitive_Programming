#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int base = (1<<17);
int T[2*base+22], k;

void update(int a, int b, int x)
{
	a += base - 1;
	b += base + 1;
	while ((a>>1) != (b>>1))
	{
		if (a % 2 == 0) T[a+1] = (T[a+1] * x) % k;
		if (b % 2 == 1) T[b-1] = (T[b-1] * x) % k;
		a >>= 1, b >>= 1;
	}
}

ll getANS(int v)
{
	v += base;
	ll res = 1;
	while (v)
	{ 
		res *= (ll)T[v];
		v >>= 1;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fill(T, T+(end(T) - begin(T)), 1);

	int q; cin >> q >> k;
	while (q--)
	{
		int a, b, x;
		char t; cin >> t;
		if (t == 'N')
		{
			cin >> a >> b >> x;
			update(a, b, x);
		}
		else
		{
			cin >> x;
			cout << (getANS(x) == 0 ? "TAK\n" : "NIE\n");
		}
	}
		
	return 0;
}