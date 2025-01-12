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

constexpr int base = (1<<19);
constexpr int MOD = 1e9+7;
struct macierz {
	int M[2][2];
	macierz(int a=1, int b=0, int c=0, int d=1) {
		M[0][0] = a; M[0][1] = b;
		M[1][0] = c; M[1][1] = d;
	}
	macierz operator* (macierz m) {
		macierz res(0,0,0,0);
		for (int i=0; i<2; i++)
			for (int j=0; j<2; j++)
				for (int k=0; k<2; k++)
					res.M[i][j] = (1LL * res.M[i][j] + 1LL * M[i][k] * m.M[k][j]) % MOD;
		return res;
	}
};
macierz Tree[2*base];

void update(int v, int st, int ed, int x, int val) {
	if (st == ed) {
		Tree[v].M[0][0] = val;
		Tree[v].M[0][1] = 1;
		Tree[v].M[1][0] = 1;
		Tree[v].M[1][1] = 0;
	}
	else {
		int md = (st + ed) >> 1;
		if (x <= md) update(2*v, st, md, x, val);
		else update(2*v+1, md+1, ed, x, val);
		Tree[v] = Tree[2*v] * Tree[2*v+1];
	}
}

macierz query(int v, int st, int ed, int L, int R) {
	if (R < st || ed < L) {
		macierz empt;
		return empt;
	}
	else if (L <= st && ed <= R)
		return Tree[v];
	else {
		int md = (st + ed) >> 1;
		macierz lson = query(2*v, st, md, L, R);
		macierz rson = query(2*v+1, md+1, ed, L, R);
		return lson * rson;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		update(1, 0, base-1, i, x);
	}
	
	while (q--) {
		int l, r; cin >> l >> r;
		macierz m = query(1, 0, base-1, l, r);
		cout << m.M[0][0] << " " << m.M[1][0] << "\n";
	}

	return 0;
}
