/*
	Drzewo Przedział-Przedział
	Wersja iteracyjna
	drzewo (+, suma)
	(bez rozszerzania przedziału [że -1 do a i +1 do b])
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int base = (1<<17);
int tree[2*base+10], lazy[2*base+10];

void insert(int a, int b, int v)
{
	a += base;
	b += base;
	int L = 1;
	
	tree[a] += v;
	lazy[a] += v;
	
	if (a != b)
	{
		tree[b] += v;
		lazy[b] += v;
	}
	
	while (a)
	{
		if (b - a > 1)
		{
			if (a % 2 == 0)
			{
				tree[a+1] += v;
				lazy[a+1] += v * L;
			}
			if (b % 2 != 0)
			{
				tree[b-1] += v;
				lazy[b-1] += v * L;
			}
		}
		
		if (a < base)
		{
			lazy[a] = lazy[2*a] + lazy[2*a+1] + tree[a] * L;
			lazy[b] = lazy[2*b] + lazy[2*b+1] + tree[b] * L;
		}
		
		a /= 2;
		b /= 2;
		L *= 2;
	}
}

int query(int a, int b)
{
	a += base;
	b += base;

	int L = 1;
	int asize = 1;
	int bsize = (a != b ? 1 : 0);
	int res = 0;
	
	while (a)
	{
		res += tree[a] * asize + tree[b] * bsize;
		
		if (b - a > 1)  
		{
			if (a % 2 == 0)
			{
				res += lazy[a+1];
				asize += L;
			}
			if (b % 2 != 0)
			{
				res += lazy[b-1];
				bsize += L;
			}
		}
		
		a /= 2;
		b /= 2;
		L *= 2;
	}

	return res;
}

int main()
{
	char q;
	while (cin >> q)
	{
		if (q == 'i')
		{
			int a, b, v; cin >> a >> b >> v;
			insert(a, b, v);
		}
		else if (q == 'q')
		{
			int a, b; cin >> a >> b;
			//cout << "Suma na przedziale [" << a << "," << b << "] = " << query(a, b) << "\n"; 
			cout << query(a, b) << "\n";
		}
	}
	
	return 0;
}
