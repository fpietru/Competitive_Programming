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

constexpr int MxN = 5e5+5;
vector<vector<pii>> grupy;
bool mogedodac = true;

bool check(pii p, vector<pii> &g) {
	int pasuje = 0;
	for (auto it : g) {
		if (it.FR >= p.SD || p.FR >= it.SD)
			continue;
		else pasuje++;
	}
	int m = g.size();
	if (pasuje > 0 && pasuje < m)
		mogedodac = false;
	return (pasuje == m);
}	

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		pii p; cin >> p.FR >> p.SD;
		int doilugrup = 0;
		int g = -1;
		mogedodac = true;
		for (int j=0; j<(int)grupy.size(); j++) {
			if (check(p, grupy[j])) {
				doilugrup++;
				g = j;
			}
		}
		
		if (mogedodac == false) {
			cout << "NIE\n";
			continue;
		}
		
		bool git = false;
		if (doilugrup == 1) {
			grupy[g].PB(p);
			git = true;
		}
		if (doilugrup == 0) {
			vector<pii> nowa;
			nowa.PB(p);
			grupy.PB(nowa);
			git = true;
		}
		
		cout << (git ? "TAK\n" : "NIE\n");
	}

	return 0;
}
