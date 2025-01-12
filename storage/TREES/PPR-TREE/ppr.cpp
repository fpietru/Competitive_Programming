/*
	Drzewo Punkt-Przedział (+, sum)
	Sprawdzenie Poprawności: https://cses.fi/problemset/task/1648/
	(W tym przypadku indeksowane od 1)

	Operacje:
	1: Zmień wartość elementu na danym indeksie
	2: Zwróć sumę elementów na przedziale
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
constexpr int base = (1<<20);
ll Tree[2*base+10];
 
void update(int v, int val)
{
	v += base;
	Tree[v] = (ll)val;
	while (v)
	{
		v /= 2;
		Tree[v] = Tree[2*v] + Tree[2*v+1];						
	}
}
 
ll query(int a, int b)
{
	ll res = 0LL;
	a += base - 1;
	b += base + 1;
	while (a / 2 != b / 2)
	{
		if (a % 2 == 0) res += Tree[a+1];
		if (b % 2 != 0) res += Tree[b-1];
		a /= 2;
		b /= 2;
	}
	return res;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++)
		cin >> Tree[i+base];
		
	for (int i=base-1; i>=1; i--)
		Tree[i] = Tree[2*i] + Tree[2*i+1];
	
	while (q--)
	{
		int op; cin >> op;
		if (op == 1)
		{
			int k, u; cin >> k >> u;
			update(k, u);
		}
		else
		{
			int a, b; cin >> a >> b;
			cout << query(a, b) << "\n";
		}
	}
 
    return 0;
}