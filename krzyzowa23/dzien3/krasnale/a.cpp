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

constexpr int INF = 1e9+7;
set<pair<pii, pii>> st;

inline bool ok(pii a, pii b) {
	if (a.FR >= b.SD || b.FR >= a.SD) return false;
	return true; 
}

int mozna(pair<pii, pii> p, pair<pii, pii> g) {
	pii pokrycie = g.FR;
	pii przeciecie = g.SD;
	if (ok(p.SD, pokrycie) && !ok(p.SD, przeciecie))       return 0;
	if (ok(p.SD, pokrycie) && ok(p.SD, przeciecie))        return 1;
	else if (!ok(p.SD, pokrycie) && !ok(p.SD, przeciecie)) return 2;
	return -1;
}

void dodaj(pair<pii, pii> &p) {
	auto it = st.lower_bound(p);
	if (it != st.begin() && (*it).FR.FR >= p.FR.SD) it--;
	auto it2 = it; it2++;
	bool niewprawo = false;
	if (it == st.end())
		it--, niewprawo = true;
	if (it2 == st.end())
		niewprawo = true;	
		
	if (mozna(p, *it) == 0) {
		cout << "NIE\n";
		return;
	}

	if (it != st.begin()) {
		it--;
		if (mozna(p, *it) != 2) {
			cout << "NIE\n";
			return;
		}
		it++;
	}
	if (!niewprawo) {
		it++;
		if (mozna(p, *it) != 2) {		
			cout << "NIE\n";
			return;
		}
		it--;
	}
	
	if (mozna(p, *it) == 1) {
		cout << "TAK\n";
		pair<pii, pii> g = *it;
		pii pokrycie = g.FR;
		pii przeciecie = g.SD;
		st.erase(it);
		przeciecie.FR = max(przeciecie.FR, p.SD.FR);
		przeciecie.SD = min(przeciecie.SD, p.SD.SD);
		pokrycie.FR = min(pokrycie.FR, p.SD.FR);
		pokrycie.SD = max(pokrycie.SD, p.SD.SD);
		st.insert({pokrycie, przeciecie});		
	}
	else {
		cout << "TAK\n";
		st.insert(p);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	int a, b; cin >> a >> b;
	cout << "TAK\n";
	pair<pii, pii> p = {{a, b}, {a, b}};
	st.insert(p);
	
	for (int i=2; i<=n; i++) {
		cin >> a >> b;
		p = {{a, b}, {a, b}};
		dodaj(p);
	}

	return 0;
}
