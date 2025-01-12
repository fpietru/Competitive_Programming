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

constexpr int MxN = 1e5+5;
vector<string> slowa;
vector<string> wziete;
map<string, int> po;

// czy w a jest pref b
bool check(string &a, string &b) {
	if (a.size() < b.size()) return false;
	int m = b.size();
	return (a.substr(0, m) == b); 
}

void reduce(string &p) {
	vector<string> nwziete;
	for (auto it : wziete) {
		if (check(it, p) == 0)
			nwziete.PB(it);
	}
	wziete = nwziete;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++) {
		string s; cin >> s;
		slowa.PB(s);
		int m = s.size();
		// deb(s);
		for (int j=1; j<=m; j++) {
			// cout << s.substr(0, j) << "\n";
			po[s.substr(0, j)]++;
		}
	}
	
	/*
	for (auto it : po)
		cout << it.FR << " " << it.SD << "\n"; */
	
	for (int i=0; i<n; i++) {
		string s = slowa[i];
		int m = s.size();
		for (int j=1; j<=m; j++)
			po[s.substr(0, j)]--;

		string p = "";
		for (int j=0; j<m; j++) {
			p += s[j];
			if (po[p] <= 0)
				break;
		}
		// cout << i << " " << p << "\n";
		reduce(p);
		wziete.PB(p);
		// cout << wziete << "\n";
		cout << wziete.size() << "\n";
	}
	

	return 0;
}
