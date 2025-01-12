/*
	Rekurencyjna warsja drzewa przedział-przedział
	drzewo (+, suma)
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int base = (1<<17);
int Tree[2*base], Lazy[2*base];

void lazypush(int v)
{
	Tree[2*v] += Lazy[v] / 2;
	Lazy[2*v] += Lazy[v] / 2;
	Tree[2*v+1] += Lazy[v] / 2;
	Lazy[2*v+1] += Lazy[v] / 2;
	Lazy[v] = 0;
}

void insert(int v, int lw, int rw, int L, int R, int val)
{
	if (rw < L || R < lw)
		return;
	else if (L <= lw && rw <= R)
	{
		Tree[v] += val * (rw-lw+1);
		Lazy[v] += val * (rw-lw+1);
	}
	else
	{
		lazypush(v);
		int mid = (lw + rw) / 2;
		insert(2*v, lw, mid, L, R, val);
		insert(2*v+1, mid+1, rw, L, R, val);
		
		Tree[v] = Tree[2*v] + Tree[2*v+1];
	}
}

int query(int v, int lw, int rw, int L, int R)
{
	if (rw < L || R < lw)
		return 0;
	else if (L <= lw && rw <= R)
		return Tree[v];
	else
	{
		lazypush(v);
		int mid = (lw + rw) / 2;
		int Lson = query(2*v, lw, mid, L, R);
		int Rson = query(2*v+1, mid+1, rw, L, R);
		return Lson + Rson;
	}
}

int main()
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(0), cout.tie(0);
	
	char op;
	while (cin >> op)
	{
		if (op == 'i')
		{
			int a, b, x; cin >> a >> b >> x;
			insert(1, 0, base-1, a, b, x);
		}
		else if (op == 'q')
		{
			int a, b; cin >> a >> b;
			cout << "Suma na przedziale [" << a << "," << b << "]: " << query(1, 0, base-1, a, b) << "\n";
		}
	}
	
	return 0;
}
