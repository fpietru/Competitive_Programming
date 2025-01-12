/*
	Zadanie "Konewka" z XX OI, etap II

	Drzewa przedział - przedział
*/
#include <bits/stdc++.h>
using namespace std;

const int base = 1<<19;
int T1[2*base]; // (+, max)
int L1[2*base]; // Lazy do T1
int T2[2*base]; // (+, sum)
int L2[2*base]; // Lazy do T2
int n, k, idx; // rozmiar, "współczynnik dojrzałości", index największego liścia w T1

// Wypełnianie T1 wartościami
void build(int v, int st, int ed, int *D)
{
	if (st == ed)
		T1[v] = D[st];
	else
	{
		int md = (st + ed) >> 1;
		build(2*v,   st,   md, D);
		build(2*v+1, md+1, ed, D);
		T1[v] = max(T1[2*v], T1[2*v+1]);
	}
}

// Lazy propatation dla T1
void push1(int v)
{
	int l = 2*v, r = 2*v+1; 
	T1[l] += L1[v];
	T1[r] += L1[v];
	L1[l] += L1[v];
	L1[r] += L1[v];
	L1[v] = 0;
}

// Lazy propatation dla T2
void push2(int v)
{
	int l = 2*v, r = 2*v+1; 
	T2[l] += L2[v] >> 2;
	T2[r] += L2[v] >> 2;
	L2[l] += L2[v] >> 2;
	L2[r] += L2[v] >> 2;
	L2[v] = 0;
}

// Dodawanie na przedziale [a,b] wartości x dla T1
void add1(int v, int st, int ed, int a, int b, int x)
{
	if (st > ed || b < st || ed < a)
		return;
	else if (a <= st && ed <= b)
	{
		T1[v] += x;
		L1[v] += x;
	}
	else
	{
		push1(v);
		int md = (st + ed) >> 1;
		add1(2*v,   st,   md, a, b, x);
		add1(2*v+1, md+1, ed, a, b, x);
		T1[v] = max(T1[2*v], T1[2*v+1]);
	}
}

// Dodawanie na przedziale [a,b] wartości x dla T2
void add2(int v, int st, int ed, int a, int b, int x)
{
	if (st > ed || b < st || ed < a)
		return;
	else if (a <= st && ed <= b)
	{
		T2[v] += (ed-st+1) * x;
		L2[v] += (ed-st+1) * x;
	}
	else
	{
		push2(v);
		int md = (st + ed) >> 1;
		add2(2*v,   st,   md, a, b, x);
		add2(2*v+1, md+1, ed, a, b, x);
		T2[v] = T2[2*v] + T2[2*v+1]; 
	}
}

// Największa wartość na przedziale [a,b] w T1
int gmax(int v, int st, int ed, int a, int b)
{
	if (st > ed || b < st || ed < a)
		return 0;
	else if (a <= st && ed <= b)
		return T1[v];
	else
	{
		push1(v);
		int md = (st + ed) >> 1;
		int ls = gmax(2*v,   st,   md, a, b);
		int rs = gmax(2*v+1, md+1, ed, a, b);
		return max(ls, rs);
	}
}

// Suma liczb na przedziale [a,b] w T2
int gsum(int v, int st, int ed, int a, int b)
{
	if (st > ed || b < st || ed < a)
		return 0;
	else if (a <= st && ed <= b)
		return T2[v];
	else
	{
		push2(v);
		int md = (st + ed) >> 1;
		int ls = gsum(2*v,   st,   md, a, b);
		int rs = gsum(2*v+1, md+1, ed, a, b);
		return ls + rs;
	}	
}

// Znajdowanie indexu największego liścia w T1
void gidx(int v, int st, int ed)
{
	if (st > ed)
		return;
	if (st == ed)
	{
		idx = st;
		return;
	}

	push1(v);
	int md = (st + ed) >> 1;
	if (T1[2*v] >= T1[2*v+1]) gidx(2*v, st, md);
	else gidx(2*v+1, md+1, ed);
}

void inicjuj(int N, int K, int *D) { n=N, k=K, build(1, 0, n-1, D); }
void podlej(int a, int b) { add1(1, 0, n-1, a, b, 1); }
int dojrzale(int a, int b)
{
	// Dopóki jakiś liść w T1 jest dojrzały tj. większy bądz równy k
	while (gmax(1, 0, n-1, 0, n-1) >= k)
	{
		gidx(1, 0, n-1); // Znajdź index tego liścia
		add2(1, 0, n-1, idx, idx, 1); // W drzewie T2 dodaj 1 na tym indexie
		add1(1, 0, n-1, idx, idx, -1e9); // Ustaw wartość liścia z największą wartością na minus nieskończoność
	}

	// Zwróć sumę liczb na przedziale [a,b] w T2
	return gsum(1, 0, n-1, a, b);
}