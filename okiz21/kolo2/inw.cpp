/*
	Zliczanie inwersji w tablicy za pomocą Merge Sort'a
*/
#include <bits/stdc++.h>
using namespace std;

const int MxN = 6e4+44;
int a[MxN]; // tablica z liczbami
int s[MxN]; // tymczasowa tablica

int merge(int st, int md, int ed);

// funkcja do rozdzielania tablicy na połówki i zliczania inwersji
int mergesort(int st, int ed)
{
	int inv = 0; // licznik inwersji
	if (st < ed) // jeśli tablica nie jest jednoelementowa
	{
		int md = (st + ed) >> 1; // środek
		inv += mergesort(st, md); // inwersje w lewej połówce
		inv += mergesort(md+1, ed); // inwersje w prawej połówce
		inv += merge(st, md, ed); // inwersje w całości
	}
	return inv;
}

// funkcja do łączenia połówek w jedność i zliczania inwersji
int merge(int st, int md, int ed)
{
	int i = st; // index w lewej połówce
	int j = md+1; // index w prawej połówce
	int k = st; // index dla tablicy tymczasowej
	int inv = 0;

	// aby nie wyjść poza rozmiary połówek
	while (i <= md && j <= ed)
	{
		if (a[i] <= a[j]) // nie ma inwersji
		{
			s[k] = a[i];
			i++;
			k++;
		}
		else // jest inwersja
		{
			s[k] = a[j];
			// przez to, że połówki są już posortowane,
			// to wszystkie elementy za a[i] są do niej większe,
			// więc też będą inwersjami w stosunku do a[j]
			inv += (md - i + 1); 
			j++;
			k++;
		}
	}

	// wypełnienie reszty tablicy tymczasowej dla lewej połówki
	while (i <= md)
	{
		s[k] = a[i];
		i++;
		k++;
	}
	// wypełnienie reszty tablicy tymczasowej dla prawej połówki
	while (j <= ed)
	{
		s[k] = a[j];
		j++;
		k++;
	}

	// a = s
	for (int p=st; p<=ed; p++)
		a[p] = s[p];

	return inv;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	cout << mergesort(0, n-1) << "\n";
	
	return 0;
}