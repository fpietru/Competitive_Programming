/*
	Zadanie "Mors Alicja" z Kółḱa Alicji 2019

	Standardowy "Word Break Problem".
*/
#include <bits/stdc++.h>
using namespace std;

// Słownik (w tym przypadku alfabet morse'a)
vector<string> dict = {
	".-",
	"-...",
	"-.-.",
	"-..",
	".",
	"..-.",
	"--.",
	"....",
	"..",
	".---",
	"-.-",
	".-..",
	"--",
	"-.",
	"---",
	".--.",
	"--.-",
	".-.",
	"...",
	"-",
	"..-",
	"...-",
	".--",
	"-..-",
	"-.--",
	"--.."
};

constexpr int MxN = 36;
int dp[MxN];

// WB = Word Break
int WB(string s)
{
	int n = s.size(); // długość słowa
	if (n == 0) // Base case
		return 1;

	// dp[n] = -1 <=> fragment o długości n nie był jeszcze nigdy rozpatrywany
	if (dp[n] == -1)
	{
		dp[n] = 0; // zaznacz, że -//- został już rozpatrzony (nie jest -1)
		for (int i=1; i<=n; i++)
		{
			string pref = s.substr(0, i); // prefix o długości n

			// jeśli dany prefix należy do słownika
			if (find(dict.begin(), dict.end(), pref) != dict.end())
				dp[n] += WB(s.substr(i)); // wywołaj się dla sufixu (całe słowo - prefix)
		}
	}

	// zwraca wartość dla już rozpatrzonych fragmentów o długości n
	return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// wypełnianie tablicy dp z uwzględnieniem base case'a
	dp[0] = 1;
	for (int i=1; i<MxN; i++)
		dp[i] = -1;

	// wyczytywanie słowa
	string s; cin >> s;
	int ans = WB(s);

	// wypisanie odpowiedzi
	cout << ans << "\n";
	
	return 0;
}