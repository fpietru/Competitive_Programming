/*
	Zadanie: Język Polski[B] z PA2018
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
	Definicja:
		Wyraz właściwy = wyraz w słowie, który ma 3 litery i wszystkie są takie same.
		(111 lub 000)
	Pomysł:
		Dla każdego startu należy znaleźć pierwszy wyraz właściwy.
		Wtedy od tego miejsca jest dokładnie:
		(długość_słowa - index_kończący_wyraz_właściwy) podsłów,
		które zawierają w sobie wyraz właściwy
		Odpowiedź to suma podsłów z każdego startu.

	Przykład:
		k o s t k a = słowo
		0 1 0 0 0 1 = 01słowo
		        4   = pozycja wyrazu właściwego
		2           = 6 - 4 = 2
		  2         = 6 - 4 = 2
		    2       = 6 - 4 = 2
		      0     = nie jesteśmy w stanie znaleść żadnych podsłów, bo już minęliśmy wyraz właściwy
		        0   = nie jesteśmy w stanie znaleść żadnych podsłów, bo już minęliśmy wyraz właściwy
		          0 = nie jesteśmy w stanie znaleść żadnych podsłów, bo już minęliśmy wyraz właściwy
		    		Odpowiedź to 6

	Inny Przykład: 
		1 1 1 0 0 0 1 1 1 0 = 01słowo
            2     5     8   = pozycje wyrazu właściwego
        8 5 5 5 2 2 2 0 0 0 = ile podsłów da się uzyskać z danego początku
*/

bool vowel(char c)
{
	string v = "aeiouy";
	return (v.find(c) != string::npos);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	int n = s.size();
	for (int i=0; i<n; i++)
		s[i] = (vowel(s[i]) ? '1' : '0');

	stack<int> st;
	for (int i=n-1; i>=2; i--)
		if (s[i-2] == s[i-1] && s[i-1] == s[i])
			st.push(i);

	ll ans = 0LL;
	for (int i=0; i<n-2; i++)
	{
		// Jeśli pozycja wyrazu właściwego jest krócej niż za 2 litery,
		// to znaczy, że już minęliśmy / zaraz miniemy dany wyraz właściwy,
		// przez co nie możemy go brać pod uwagę.
		// ...000... lub ...000... 
		//     ^              ^
		while (!st.empty() && i + 2 > st.top())
			st.pop();

		if (st.empty())
			break;
		
		ans += ((ll)n - st.top());
	}

	cout << ans << "\n";

	return 0;
}