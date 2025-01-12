/*
	Zadanie: "Wyprzedzanie", XXX OI, etap I
	Autor: Franciszek Pietrusiak
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
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

constexpr ld eps = 1.0e-15;
constexpr ld INF = 1e18+7.0;
constexpr int REP = 66;
constexpr int MxN = 1e5+5;
struct func {
	ld a, b;
	inline ld f(ld t) {
		return a*t + b;
	}
	inline ld przeciecie(const func& f) {
		if (fabs(a - f.a) <= eps) return INF;
		else return (f.b - b) / (a - f.a);
	}
};
struct car {
	func przod, tyl;
	ld dl;
	ld frontpos;
	ld backpos;
	void f(ld t) {
		frontpos = przod.f(t);
		backpos = tyl.f(t);
	}
	inline ld kontakt(const car& b) {
		return przod.przeciecie(b.tyl);
	}
};
car samochod[MxN];
int n, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ld D, W, M; cin >> n >> D >> W >> M;
	samochod[0].przod = {W/M, 0.0};
	samochod[0].tyl = {W/M, -D};
	samochod[0].dl = D;
	for (int i=1; i<=n; i++) {
		ld x, d, w, m; cin >> x >> d >> w >> m;
		samochod[i].dl = d;
		samochod[i].przod = {w/m, x};
		samochod[i].tyl = {w/m, x-d};
	}
	
	bool malejacy = false;
	for (int i=n-1; i>=1; i--)
		if (samochod[i].przod.a > samochod[i+1].przod.a) {
			malejacy = true;
			break;
		}
			
	if (malejacy == false) {
		ans = 1;
		for (int i=2; i<=n; i++) {
			ld t = samochod[0].kontakt(samochod[i]);
			samochod[i-1].f(t);
			samochod[i].f(t);
			ld luka = samochod[i].backpos - samochod[i-1].frontpos;
			ld roznica = luka - samochod[0].dl;
			if (roznica >= 0.0 || (roznica < eps && fabs(roznica) < eps))
				ans++;
		}
	}
	else {	
		ld plow = 0.0;
		for (int j=1; j<=n; j++) {
			ld low = plow;
			ld high = samochod[0].kontakt(samochod[j]);;
			for (int r=1; r<=REP; r++) {
				ld t = (low + high) / 2.0;
				samochod[0].f(t);
				samochod[n].f(t);
				for (int i=n-1; i>=max(1, j-1); i--) {
					samochod[i].f(t);
					if (samochod[i+1].backpos - samochod[i].frontpos <= eps) {
						samochod[i].frontpos = samochod[i+1].backpos;
						samochod[i].backpos = samochod[i].frontpos - samochod[i].dl;
					}
				}
				if (samochod[j].backpos >= samochod[0].frontpos) low = t;
				else high = t;
			}
			plow = low;
			ld luka = samochod[j].backpos - samochod[j-1].frontpos;
			ld roznica = luka - samochod[0].dl;
			if (roznica >= 0.0 || (roznica < eps && fabs(roznica) < eps) || j == 1) ans++;
			while (j <= n-1 && samochod[j].frontpos >= samochod[j+1].backpos) j++;
		}
	}

	cout << ans << "\n";

	return 0;
}
