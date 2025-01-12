/*
	Link do zadania: https://www.codechef.com/problems/NPLFLF?tab=statement
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging 
/*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

constexpr int MxN = 1e5+5;
constexpr int ALP = 26;
int trie[MxN][ALP];
int licznik = 1;
map<string, int> res[MxN];
string dodane[MxN];

void dodaj(const string &s) {
	int n = s.size();
	int v = 1;
	string tmp;
	for (int i=0; i<n; i++) {
		tmp += s[i];
		if (trie[v][s[i]-'a'] == -1)
			trie[v][s[i]-'a'] = ++licznik;
		v = trie[v][s[i]-'a'];
		res[i+1][tmp]++;
	}
}

void usun(const string &s) {
	int n = s.size();
	int v = 1;
	string tmp;
	for (int i=0; i<n; i++) {
		tmp += s[i];
		v = trie[v][s[i]-'a'];
		res[i+1][tmp]--;
	}
}

bool check(int k, int l) {
	for (const auto &it : res[l])
		if (it.SD >= k) return true;
	return false; 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	memset(trie, -1, sizeof(trie));

	int q; cin >> q;
	for (int i=1; i<=q; i++) {
		int op; cin >> op;
		if (op == 1) {
			string s; cin >> s;
			reverse(s.begin(), s.end());
			dodaj(s);
			dodane[i] = s;
		}
		else if (op == 2) {
			int k, l; cin >> k >> l;
			cout << (check(k, l) ? "YES\n" : "NO\n");
		}
		else {
			int x; cin >> x;
			if (!dodane[x].empty()) {
				usun(dodane[x]);
				dodane[x].erase();
			}
		}
	}	

	return 0;
}
