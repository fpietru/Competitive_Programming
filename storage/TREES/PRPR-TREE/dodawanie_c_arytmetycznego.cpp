/*
	Drzewo Przedział-Przedział
	1) Dodaj ciąg arytmetyczny na przedziale
	2) Zwróć sumę elementów na przedziale

	Każdy wierzchołek przechowuje 3 informacje:
	1) Suma elementów na przedziale, kóry ten wierzchołek obejmuje
	2) a1 - pierwszy element ciągu arytmetycznego, który znajduje się na pozycji lw
	3) r - różnicę ciągu arytmetycznego
	
	lw - początek przedziału bazowego wierzchołka
	rw - koniec przedziału bazowego wierzchołka
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int base = (1<<3);
int Tree[2*base+10];
struct lazyinfo { int a1, r; }; // a1 - pierwszy element ciągu, r - różnica ciągu
lazyinfo Lazy[2*base+10];

// wzór na i-ty element ciągu arytmetycznego
int ity(int a1, int r, int i) {
	return a1 + r*(i-1);
}

// wzór na sumę n wyrazów ciągu arytmetycznego
int suma(int a1, int r, int n) {
	return (2*a1*n + r*n*n - r*n) / 2;
}

// dodawanie informacji do wierzchołka w drzewie
void dodaj(int v, int a1, int r, int poz, int st, int ed)
{
	Tree[v] += suma(ity(a1, r, st-poz+1), r, ed-st+1);
	Lazy[v].a1 += ity(a1, r, st-poz+1);
	Lazy[v].r += r;
}

// funkcja do przepychania (lazy propagation)
void lazypush(int v, int lw, int rw)
{
	int mid = (lw + rw) / 2;
	dodaj(2*v, Lazy[v].a1, Lazy[v].r, lw, lw, mid);
	dodaj(2*v+1, Lazy[v].a1, Lazy[v].r, lw, mid+1, rw);
	Lazy[v] = {0,0};
}

// dodawanie ciągu
void insert(int v, int lw, int rw, int L, int R, int a1, int r)
{
	if (rw < L || R < lw)
		return;
	else if (L <= lw && rw <= R)
		dodaj(v, a1, r, L, lw, rw);
	else
	{
		lazypush(v, lw, rw);
		int mid = (lw + rw) / 2;
		insert(2*v, lw, mid, L, R, a1, r);
		insert(2*v+1, mid+1, rw, L, R, a1, r);
		
		Tree[v] = Tree[2*v] + Tree[2*v+1];
	}
}

// zwracanie sumy na przedziale
int query(int v, int lw, int rw, int L, int R)
{
	if (rw < L || R < lw)
		return 0;
	else if (L <= lw && rw <= R)
		return Tree[v];
	else
	{
		lazypush(v, lw, rw);
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
			int a, b, a1, r; cin >> a >> b >> a1 >> r;
			insert(1, 0, base-1, a, b, a1, r);
		}
		else if (op == 'q')
		{
			int a, b; cin >> a >> b;
			cout << "Suma na przedziale [" << a << "," << b << "]: " << query(1, 0, base-1, a, b) << "\n";
		}
		else if (op == 's')
		{
			for (int i=0; i<8; i++)
				cout << query(1, 0, base-1, i, i) << " ";
			cout << "\n";
		}
	}
	
	return 0;
}
