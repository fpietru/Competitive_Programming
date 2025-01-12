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

constexpr int MxN = 3e5+5;
int arr[MxN];

inline int lb(int x) {
	return (31 - __builtin_clz(x));
}

inline int sgn(int x, int p) {
	return (x&(1<<p));
}

struct eliminacja_gaussa {
	int T[31] = {0};
	void dodaj(int x) {
		while (x && T[lb(x)])
			x ^= T[lb(x)];
		if (x != 0)
			T[lb(x)] = x;
	}
	void pokaz() {
		for (int i=30; i>=0; i--)
			cout << i << " " << T[i] << "\n";
	}
	int getmax() {
		int res = 0;
		for (int i=30; i>=0; i--)
			if (sgn(res, i) == 0 && T[i])
				res ^= T[i];
		return res;
	}
	bool szukaj(int x) {
		int res = 0;
		for (int i=30; i>=0; i--)
			if (sgn(x, i) != sgn(res, i))
				res ^= T[i];
		return (res == x);
	}
};

void op1() {
	int a, b, c; cin >> a >> b >> c;
	for (int i=a; i<=b; i++)
		arr[i] = c;
}

int op2() {
	int a, b; cin >> a >> b;
	eliminacja_gaussa g;
	for (int i=a; i<=b; i++)
		g.dodaj(arr[i]);
	return g.getmax();
}

int op3() {
	int a, b, c; cin >> a >> b >> c;
	eliminacja_gaussa g;
	for (int i=a; i<=b; i++)
		g.dodaj(arr[i]);
	return g.szukaj(c);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++)
		cin >> arr[i];
	while (q--) {
		string op; cin >> op;
		if (op == "aktualizacja") op1();
		else if (op == "maksymalizacja")
			cout << op2() << "\n";
		else cout << (op3() ? "TAK\n" : "NIE\n"); 
	}

	return 0;
}
