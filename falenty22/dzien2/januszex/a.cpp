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

constexpr int base = (1<<2);
ll Tree[2*base+69][10];
int Lazy[2*base+420][10];
ll tmp[10];

void show() {
	for (int i=1; i<2*base; i++) {
		cout << i << ":\n";
		for (int j=0; j<=9; j++)
			cout << "[" << i << "][" << j << "] = " << Tree[i][j] << "\n";
	}
}

void merge(int v) {
	for (int i=0; i<=9; i++)
		Tree[v][i] = Tree[2*v][i] + Tree[2*v+1][i];
}

void lazypush(int v) {
	for (int i=0; i<=9; i++) {
		Lazy[2*v][i] = Lazy[v][Lazy[2*v][i]];
		Lazy[2*v+1][i] = Lazy[v][Lazy[2*v+1][i]];
	}
	for (int i=0; i<=9; i++)
		tmp[Lazy[v][i]] += Tree[2*v][i];
	for (int i=0; i<=9; i++) {
		Tree[2*v][i] = tmp[i];
		tmp[i] = 0LL;
	}
	for (int i=0; i<=9; i++) {
		tmp[Lazy[v][i]] += Tree[2*v+1][i]; 
		Lazy[v][i] = i;
	}
	for (int i=0; i<=9; i++) {
		Tree[2*v+1][i] = tmp[i];
		tmp[i] = 0LL;
	}
}

void update(int v, int st, int ed, int L, int R, int x, int y) {
	if (R < st || ed < L) return;
	else if (L <= st && R <= ed) {
		Tree[v][y] += Tree[v][x];
		Tree[v][x] = 0;
		if (st != ed) {
			Lazy[2*v][x] = y;
			Lazy[2*v+1][x] = y;
		}
	}
	else {
		lazypush(v);
		int md = (st + ed) >> 1;
		update(2*v, st, md, L, R, x, y);
		update(2*v+1, md+1, ed, L, R, x, y);
		merge(v);
	}
}

ll query(int v, int st, int ed, int L, int R) {
	if (R < st || ed < L) return 0LL;
	else if (L <= st && R <= ed) {
		ll res = 0LL;
		for (int i=0; i<=9; i++)
			res += Tree[v][i] * i;
		return res;
	}
	else {
		lazypush(v);
		int md = (st + ed) >> 1;
		ll lson = query(2*v, st, md, L, R);
		ll rson = query(2*v+1, md+1, ed, L, R);
		return lson + rson;
	}
}

void build(int v, int st, int ed, int p, int num) {
	if (st == ed) {
		int pot = 1;
		while (num) {
			Tree[v][num%10] += (ll)pot; 
			pot *= 10;
			num /= 10;
		}
	}
	else {
		int md = (st + ed) >> 1;
		if (p <= md) build(2*v, st, md, p, num);
		else         build(2*v+1, md+1, ed, p, num);
		merge(v);
	}
}


int main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0), cout.tie(0);
	
	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		build(1, 0, base-1, i-1, x);
	}
	
	show();
	
	for (int i=0; i<n; i++)
		cout << query(1, 0, base-1, i, i) << " ";
	cout << "\n";
	
	/*
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int L, R, x, y; cin >> L >> R >> x >> y;
			update(1, 0, base-1, L, R, x, y);
		}
		else {
			int L, R; cin >> L >> R;
			cout << query(1, 0, base-1, L, R) << "\n";
		}
	}*/

	return 0;
}
