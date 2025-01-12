/*
	Drzewo przedział-przedział (+, sum)
	na wskaźnikach
	sprawdzenie poprawności: https://www.spoj.com/problems/HORRIBLE/
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back // debugging /*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
	cout << "[ " << vars << " = "; string delim = "";
	(..., (cout << delim << values, delim = ", "));
	cout << " ]\n";
}
/**/

struct node {
	node *lewy, *prawy;
	int L, R;
	ll val;
	ll lazy;
	node() {
		lewy = NULL;
		prawy = NULL;
		L = 0;
		R = (1<<30);
		val = 0LL;
		lazy = 0LL;
	}
	void rozszerz() {
		if (lewy == NULL) {
			int md = (L + R) >> 1;
			lewy = new node();
			prawy = new node();
			lewy->L = L;
			lewy->R = md;
			prawy->L = md+1;
			prawy->R = R;
		}
	}
	void lazypush() {
		lewy->val += (lazy >> 1);
		lewy->lazy += (lazy >> 1);
		prawy->val += (lazy >> 1);
		prawy->lazy += (lazy >> 1);
		lazy = 0LL;
	}
};
node *root;

void update(node *v, int l, int r, int x)
{
	if (r < v->L || v->R < l)
		return;
	else if (l <= v->L && v->R <= r)
	{
		v->val += (v->R - v->L + 1) * (ll)x;
		v->lazy += (v->R - v->L + 1) * (ll)x;
	}
	else
	{
		v->rozszerz();
		v->lazypush();
		update(v->lewy, l, r, x);
		update(v->prawy, l, r, x);
		v->val = v->lewy->val + v->prawy->val;
	}
}

ll query(node *v, int l, int r)
{
	if (r < v->L || v->R < l)
		return 0LL;
	else if (l <= v->L && v->R <= r)
		return v->val;
	else
	{
		v->rozszerz();
		v->lazypush();
		ll Lson = query(v->lewy, l, r);
		ll Rson = query(v->prawy, l, r);
		return Lson + Rson;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		root = new node();
		int n, q; cin >> n >> q;
		while (q--)
		{
			int op; cin >> op;
			if (op == 0)
			{
				int a, b, x; cin >> a >> b >> x;
				update(root, a, b, x);
			}
			else
			{
				int a, b; cin >> a >> b;
				cout << query(root, a, b) << "\n";
			}
		}
	}
	
	return 0;
}
