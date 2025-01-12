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

constexpr int base = (1<<17);
int Tree[2*base];
bool Lazy[2*base];

void update(int v, int l, int r, int L, int R)
{
	if (Lazy[v]) {
		Tree[v] = (r-l+1) - Tree[v];
		if (l != r) {
			Lazy[2*v] ^= 1;
			Lazy[2*v+1] ^= 1;
		}
		Lazy[v] = 0;
	}
	if (r < L || R < l) return;
	else if (L <= l && r <= R) {
		Tree[v] = (l-r+1) - Tree[v];
		if (l != r) {
			Lazy[2*v] ^= 1;
			Lazy[2*v+1] ^= 1;
		}
		return;
	}
	int md = ((l+r) >> 1);
	update(2*v, l, md, L, R);
	update(2*v+1, md+1, r, L, R);
	Tree[v] = Tree[2*v] + Tree[2*v+1];
}

int query(int v, int l, int r, int L, int R)
{
	if (Lazy[v]) {
		Tree[v] = (r-l+1) - Tree[v];
		if (l != r) {
			Lazy[2*v] ^= 1;
			Lazy[2*v+1] ^= 1;
		}
		Lazy[v] = 0;
	}
	if (r < L || R < l) return 0;
	if (L <= l && r <= R) return Tree[v];
	int md = ((l+r) >> 1);
	int Lson = query(2*v, l, md, L, R);
	int Rson = query(2*v+1, md+1, r, L, R);
	return Lson + Rson;
}

void show(int a, int b)
{
	for (int i=a; i<=b; i++)
		cout << query(1, 0, base-1, i, i) << " ";
	cout << "\n";
}

int main()
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(0), cout.tie(0);

	char op;
	while (cin >> op)
	{
		if (op == 'U')
		{
			int a, b; cin >> a >> b;
			update(1, 0, base-1, a, b);
		}
		else if (op == 'Q')
		{
			int a, b; cin >> a >> b;
			cout << query(1, 0, base-1, a, b) << "\n";
		}
		show(0, 7);
	}	

	return 0;
}
