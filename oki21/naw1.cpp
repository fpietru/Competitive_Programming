/*
	Zadanie "Nawiasy kwadratowe kontratakują" z KI
	
	Drzewo przedział - przedział (+, min)
	Aby wyrażenie nawiasów było poprawne:
		-Suma wszystkich nawiasów ma być równa 0 (otwierający = 1, zamykający = -1)
		-Nie może być elementu ujemnego w ciągu prefixowym.

	np. ][ jest nieprawidłowe, bo ciąg prefixowy jest taki : 0 -1 0
*/
#include <bits/stdc++.h>
using namespace std;

const int base = 1<<17, MxN = 1e5+5;
int T[2*base], L[2*base], p[MxN], a[MxN];
int n, sum = 0;

void build(int v, int st, int ed)
{
	if (st == ed)
		T[v] = p[st];
	else
	{
		int md = (st + ed) >> 1;
		build(2*v, st, md);
		build(2*v+1, md+1, ed);
		T[v] = min(T[2*v], T[2*v+1]);
	}
}

void push(int v)
{
	int l = 2*v, r = 2*v+1;
	T[v] += L[v];
	T[l] += L[v];
	T[r] += L[v];
	L[l] += L[v];
	L[r] += L[v];
	L[v] = 0;
}

void add(int v, int st, int ed, int a, int b, int x)
{
	if (st > ed || b < st || ed < a)
		return;
	else if (a <= st && ed <= b)
	{
		T[v] += x;
		L[v] += x;
	}
	else
	{
		push(v);
		int md = (st + ed) >> 1;
		add(2*v, st, md, a, b, x);
		add(2*v+1, md+1, ed, a, b, x);
		T[v] = min(T[2*v], T[2*v+1]);
	}
}

int gmin(int v, int st, int ed, int a, int b)
{
	if (st > ed || b < st || ed < a)
		return 1e9+9;
	else if (a <= st && ed <= b)
		return T[v];
	else
	{
		push(v);
		int md = (st + ed) >> 1;
		int ls = gmin(2*v, st, md, a, b);
		int rs = gmin(2*v+1, md+1, ed, a, b);
		return min(ls, rs);
	}	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> a[i];
		sum += a[i];
		p[i+1] = p[i] + a[i]; 
	}

	build(1, 1, n);

	while (1)
	{
		int x; cin >> x;
		if (x == -1)
			break;
		else if (x == 0)
		{
			if (gmin(1, 1, n, 1, n) >= 0 && sum == 0)
				cout << "TAK\n";
			else cout << "NIE\n";
		}
		else
		{
			a[x-1] *= -1;

			if (a[x-1] == -1)
			{
				sum--;
				add(1, 1, n, x, n, -2);
			}
			else
			{
				sum++;
				add(1, 1, n, x, n, 2);	
			}
		}

	}
	
	return 0;
}