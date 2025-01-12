#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e6+66;
int a[MxN]; // główna tablica
int s[MxN]; // tymczasowa tablica

// st = start
// md = middle
// ed = end

// funkcja do scalania dwóch połówek
void merge(int st, int md, int ed);

void mergesort(int st, int ed)
{
	if (st < ed) // jeśli tablica nie jest jednoelementowa
	{
		int md = (st + ed) >> 1; // wylicz środkowy index
		mergesort(st, md); // wywołaj mergesort dla lewej połówki
		mergesort(md+1, ed); // wywołaj mergesort dla prawej połówki
		merge(st, md, ed); // scal obie połówki
	}
}

void merge(int st, int md, int ed)
{
	int i = st; // index w lewej połówce
	int j = md + 1; // index w prawej połówce
	int k = st; // index dla tablicy tymczasowej

	// dopóki ani i, ani j nie wykroczyło poza swój zakres
	while (i <= md && j <= ed)
	{
		if (a[i] <= a[j]) // jeśli element pod indexem i jest mniejszy
		{
			s[k] = a[i]; // ustaw komórkę pod indexem k w tablicy tymczasowej jako ten mniejszy element
			i++;
			k++;
		}
		else // jeśli to pod j jest mniejszy element
		{
			s[k] = a[j];
			j++;
			k++;
		}
	}

	// teraz może się okazać, że np. i = md, ale j nadal nie dotarł do końca swojego zakresu
	// więc trzeba dla i, j "przejść" do końca ich zakresów i wypełnić tablice tymczasową
	
	while (i <= md)
	{
		s[k] = a[i];
		i++;
		k++;
	}
	while (j <= ed)
	{
		s[k] = a[j];
		j++;
		k++;
	}
	
	// musimy "przerzucić" warto[ci z tablicy tymczasowej na tą główną
	for (int x=st; x<=ed; x++)
		a[x] = s[x];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	mergesort(0, n-1);

	for (int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << "\n";
	
	return 0;
}

// tyle
