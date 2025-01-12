/*
	HAD TO USE EDITORIAL
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e5+55;
ll a[MxN], c[MxN];

ll bisearch(ll k, int n)
{
	int low = 0;
	int high = n-1;
	while (low < high)
	{
		int md = (low + high) >> 1;
		if ((ll)c[md] >= k)
			high = md;
		else low = md + 1;
	}
	return low;
}

// dobra liczba to taka, która nie należy do zbioru A
// Przykład: A = {3, 4, 8, 12} => dobre_liczby = {1, 2, 5, 6, 7, 9, 10, 11, 13, 14, ...} 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q;
	for (int i=0; i<n; i++)
		cin >> a[i];

	// dla każdego i znajdź liczbę dobrych liczb mniejszych od a[i]
	for (int i=0; i<n; i++)
		c[i] = a[i] - (i + 1);

	while (q--)
	{
		ll k; cin >> k;

		if (k > c[n-1])
		{
			/*
				Jeśli k > c[n-1], to szukana liczba jest zawsze większa od a[n-1].
				Skoro każda liczba większa od a[n-1] jest dobrą liczbą,
				to odpowiedź a[n-1] + (k - c[n-1]) 
			*/
			cout << a[n-1] + (k - c[n-1]) << "\n";
		}
		else
		{
			/*
				Jeśli k <= c[n-1], to należy znaleźć pierwsze (od lewej) takie i, że
				c[i] >= k. Wtedy szukana liczba jest gdzieś po między a[i-1], a a[i].
				Odpowiedzią będzie c[i] - k elementów przed a[i] - 1
 			*/
			int i = bisearch(k, n);
			cout << (a[i] - 1) - (c[i] - k) << "\n";
		}
	}

	
	return 0;
}