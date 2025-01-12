/*
	Zadanie "Koleje" z IX OI, etap I
	
	Drzewo przedział-przedział (add + max)
*/
#include <bits/stdc++.h>
using namespace std;

const int base = 1<<16;
int T[2*base], L[2*base];

void TREEadd(int v, int start, int end, int a, int b, int x)
{
	if (L[v] != 0)
	{
		T[v] += L[v];
		if (start != end)
		{
			L[2*v] += L[v];
			L[2*v+1] += L[v];
		}
		L[v] = 0;
	}

	if (start > end || start > b || end < a)
		return;

	if (start >= a && end <= b)
	{
		T[v] += x;
		if (start != end)
		{
			L[2*v] += x;
			L[2*v+1] += x;
		}
		return;
	}

	int mid = (start + end) >> 1;
	TREEadd(2*v, start, mid, a, b, x);
	TREEadd(2*v+1, mid+1, end, a, b, x);
	T[v] = max(T[2*v], T[2*v+1]);
}

int TREEget(int v, int start, int end, int a, int b)
{
	if (start > end || start > b || end < a)
		return 0;

	if (L[v] != 0)
	{
		T[v] += L[v];
		if (start != end)
		{
			L[2*v] += L[v];  
			L[2*v+1] += L[v];  
		}
		L[v] = 0;
	}	

	if (start >= a && end <= b)
		return T[v];

	int mid = (start + end) >> 1;
	int lson = TREEget(2*v, start, mid, a, b);
	int rson = TREEget(2*v+1, mid+1, end, a, b);
	return max(lson, rson);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m, z, a, b, c;

	cin >> n >> m >> z;
	while (z--)
	{
		cin >> a >> b >> c;

		TREEadd(1, 1, n-1, a, b-1, c);
		if (TREEget(1, 1, n-1, a, b-1) > m)
		{
			cout << "N\n";
			TREEadd(1, 1, n-1, a, b-1, -c);
		}
		else cout << "T\n";
	}

	return 0;
}
