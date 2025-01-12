#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+16;
constexpr int ALFABET = 26;
int Trie[MxN][ALFABET];
bool koniec[MxN];
int licznik = 1;

void add2Trie(int v, string s)
{
	for (auto c : s)
	{
		if (Trie[v][c-'a'] == -1)
			Trie[v][c-'a'] = ++licznik;
		
		v = Trie[v][c-'a'];
	}
	koniec[v] = 1;
}

bool checkinTrie(int v, string s)
{
	for (auto c : s)
	{
		if (Trie[v][c-'a'] == -1)
			return 0;
		
		v = Trie[v][c-'a'];
	}
	return (koniec[v]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	memset(Trie, -1, sizeof(Trie));
	
	int n, m; cin >> n >> m;
	
	// tworzenie słownika
	for (int i=0; i<n; i++)
	{
		string s; cin >> s;
		add2Trie(1, s);
	}
	
	// sprawdzanie czy słowo należy do słownika
	for (int i=0; i<m; i++)
	{
		string s; cin >> s;
		cout << (checkinTrie(1, s) ? "TAK\n" : "NIE\n");
	}
	
	for (int i=1; i<=licznik; i++)
	{
		cout << i << ": ";
		for (int j=0; j<26; j++)
			if (Trie[i][j] != -1)
				cout << "[" << (char)(j+'a') << "," << Trie[i][j] << "] ";
		
		cout << koniec[i] << "\n";
	}

	
	return 0;
}
