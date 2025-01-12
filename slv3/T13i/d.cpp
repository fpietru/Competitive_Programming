#include <bits/stdc++.h>
using namespace std;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int MxN = 4e5+10; // może być za mało pamięci
constexpr int ALFABET = 26;
int Trie[MxN][ALFABET];
bool koniec[MxN];
int licznik = 1;
string words[MxN];
bool valid[ALFABET];
string ans;

void add2Trie(int v, string& s)
{
	for (auto c : s)
	{
		if (Trie[v][c-'a'] == -1)
			Trie[v][c-'a'] = ++licznik;
		
		v = Trie[v][c-'a'];
	}
	koniec[v] = 1;
}

void dfs(int v, string& w)
{
	// deb(v, w);
	
	if (koniec[v] == 1)
	{
		if (ans == "NIE")
			ans = w;
		return;
	}

	for (int i=0; i<ALFABET; i++)
		if (Trie[v][i] != -1 && valid[i])
		{
			w += ((char)('a'+i));
			dfs(Trie[v][i], w);
			w.pop_back();
		}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	// double mem = (sizeof(Trie)+sizeof(koniec)+sizeof(valid)+sizeof(words)) / 1048576.0;
	// cout << mem << "\n";

	memset(Trie, -1, sizeof(Trie));

	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> words[i];
		add2Trie(1, words[i]);
	}

	for (int i=1; i<=n; i++)
	{
		memset(valid, 1, sizeof(valid));
		for (auto c : words[i])
			valid[c-'a'] = 0;
		
		ans = "NIE";
		string empty = "";
		dfs(1, empty);
		cout << ans << "\n";
	}

    return 0;
}
