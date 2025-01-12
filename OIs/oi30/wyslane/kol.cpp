/*
	Zadanie: Kolorowy wąż, XXX OI, etap I
	Autor: Franciszek Pietrusiak
*/
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

constexpr int MxN = 2e3+3;
constexpr int INF = 0x3f3f3f3f;
int fruit[MxN][MxN];
int kiedy[MxN][MxN];
int zjedzonych;
vector<int> waz;
pii glowa;
int moment;

void go(char kierunek) {
	if (kierunek == 'G')      glowa.FR--;
	else if (kierunek == 'D') glowa.FR++;
	else if (kierunek == 'L') glowa.SD--;
	else                      glowa.SD++;
	kiedy[glowa.FR][glowa.SD] = moment;
	if (fruit[glowa.FR][glowa.SD] != -1) {
		waz.PB(fruit[glowa.FR][glowa.SD]);
		zjedzonych++;
		fruit[glowa.FR][glowa.SD] = -1;
	}
}

int zapytanie(int y, int x) {
	int ogon = moment - zjedzonych + 1;
	if (ogon <= kiedy[y][x] && kiedy[y][x] <= moment) {
		int pos = zjedzonych - 1 - (moment - kiedy[y][x]);
		return waz[pos];
	}
	else return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(fruit, -1, sizeof(fruit));
	memset(kiedy, -INF, sizeof(kiedy));

	int n, p, q; cin >> n >> p >> q;
	for (int i=1; i<=p; i++) {
		int y, x, c; cin >> y >> x >> c;
		fruit[y][x] = c;
	}
	
	glowa = {1, 1};
	waz.PB(0);
	kiedy[1][1] = 0;
	zjedzonych = 1;
	
	while (q--) {
		char op; cin >> op;
		if (op == 'Z') {
			int y, x; cin >> y >> x;
			cout << zapytanie(y, x) << "\n";
		}
		else {
			++moment;
			go(op);
		}
	}

	return 0;
}
