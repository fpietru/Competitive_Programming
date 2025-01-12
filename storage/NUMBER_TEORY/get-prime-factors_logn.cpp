/*
	Rozkład liczby n na wszystkie czynniki pierwsze.
	Złożoność czasowa: O(sqrt(n))
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> factor(int n)
{
	vector<int> res;
	
	/*
		FAZA I
		Zajmuje się wszystkimi parzystymi czynnikami pierwszymi 
	*/
	while (n % 2 == 0)
		res.push_back(2), n >>= 1;
	
	/*
		Teraz wszystkie czynniki pierwsze, które zostały są nieparzyste
		dlatego i zwiększa się o 2 (i += 2) 

		FAZA II
		Schamat działania:
			a) Znajdź najmniejszy czynnik i
			b) Usuń wszystkie wystąpienia tego czynnika z n poprzez ciągłe dzielenie n przez i
			c) Powtórz a) i b) dla kolejnych czynników pierwszych
	*/
	for (int i=3; i*i<=n; i+=2)
		while (n % i == 0)
			res.push_back(i), n /= i;

	/*
		n jest teraz liczbą pierwszą albo równa się 1

		FAZA III
		jeśli jest liczbą pierwszą:
	*/
	if (n > 2) res.push_back(n);

	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> prime_factors = factor(n);
	
	for (int p : prime_factors)
		cout << p << " ";
	cout << "\n";

	return 0;
}