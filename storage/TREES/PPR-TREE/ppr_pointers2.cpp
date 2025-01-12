/*
	Dynamiczne drzewo przedziałowe (+, suma)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
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

constexpr int LIM = (1<<30)-1;

struct drzewo {
	struct node {
		ll wart;
		node *prawy, *lewy;
		node() {
			wart = 0LL;
			prawy = lewy = nullptr;
		}
		~node() {
			delete prawy;
			delete lewy;
		}
	} root;
	void update(int pos, ll val) {
		int st = 0, ed = LIM;
		node *v = &root;
		while (true) {
			v->wart += val;
			if (st == ed) break;
			int md = (st + ed) >> 1;
			if (pos <= md) {
				if (v->lewy == nullptr) v->lewy = new node();
				v = v->lewy;
				ed = md;
			}
			else {
				if (v->prawy == nullptr) v->prawy = new node();
				v = v->prawy;
				st = md+1;
			}
		}
	}
	ll query(const node *v, int st, int ed, int L, int R) const {
		if (v == nullptr || ed < L || st > R) return 0LL;
		if (L <= st && ed <= R) return v->wart;
		int md = (st + ed) >> 1;
		ll lson = query(v->lewy, st, md, L, R);
		ll rson = query(v->prawy, md+1, ed, L, R);
		return lson + rson;
	}
	ll query(int a, int b) const {
		return query(&root, 0, LIM-1, a, b);
	}
} Tree;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	return 0;
}
