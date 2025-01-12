/*
	Zadanie "Kontenery" z XXIV OI, etap II
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, q, sqr; cin >> n >> q;
	sqr = ceil(sqrt(n));

	vector<int> A(n, 0); // ciąg kontenerów do wypisania 
	vector<vector<int>> S(sqr+1, vector<int>(n)); // zespolone operacja dla każdego małego skoku

	while (q--)
	{
		int a, l, d;
		cin >> a >> l >> d;
		a--; // bo indeksujemy od 0

		// jeśli skok jest duży => mało kontenerów do postawienia => symuluj
		if (d > sqr)
			for (int i=a; i<=a+(l-1)*d; i+=d)
				A[i]++;
		else
		{
			S[d][a]++; // początek przedziału na jakim stawiamy kontenery
			if (a+l*d < n) // czy przedział nie wychodzi poza tablice
				S[d][a+l*d]--; // koniec przedzału na jakim stawiamy kontenery
		}
	}

	for (int d=1; d<=sqr; d++) // dla każdego skoku
		for (int i=0; i<n; i++) // dla każdego elementu z ciągu kontenerów
		{
			if (i >= d) S[d][i] += S[d][i-d]; // do obecnego miejsca dodajemy wartość z poprzedniego skoku
			A[i] += S[d][i];
		}

	// wypisz ciąg kontenerów
	for (auto a : A)
		cout << a << " ";
	cout << "\n";

	return 0;
}