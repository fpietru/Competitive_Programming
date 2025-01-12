#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging /*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

constexpr int MxS = 2e6+6;
bool nieaktywny[MxS];
bool koniec[MxS];
int ojciec[MxS];
int aktywnychdzieci[MxS];
int iledzieci[MxS];
int trie[MxS][26];
int licznik = 1;
vector<int> aktywuje;

void dodaj(string &s) {
	int v = 1;
	int m = s.size();
	for (int i=0; i<m; i++) {
		if (!trie[v][s[i]-'a']) {
			trie[v][s[i]-'a'] = ++licznik;
			ojciec[licznik] = v;
			iledzieci[v]++;
		}
		v = trie[v][s[i]-'a'];
	}
	nieaktywny[v] = true;
	aktywuje.PB(v);
}

bool check(int v) {
	int o = ojciec[v];
	if (o == 1 || nieaktywny[o])
		return false;
	return (iledzieci[o] == aktywnychdzieci[o]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		string s; cin >> s;
		dodaj(s);
	}
	
	int ans = 0;
	for (auto v : aktywuje) {
		nieaktywny[v] = false;
		ans++;
		
		for (int i=0; i<26; i++)
			if (koniec[trie[v][i]])
				ans--;
		
		aktywnychdzieci[ojciec[v]]++;
		while (check(v)) {
			ans -= iledzieci[ojciec[v]] - 1;
			v = ojciec[v];
			aktywnychdzieci[ojciec[v]]++;
		}
		// if (koniec[v]) ans--;
		koniec[v] = true;
		
		// deb(v);
		
		cout << ans << "\n";
	}

	return 0;
}
