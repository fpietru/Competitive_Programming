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

struct node {
	node *lewy, *prawy;
	int L, R;
	int val;
	node() {
		L = 1;
		R = (1<<21);
		val = 0;
		lewy = NULL;
		prawy = NULL;
	}
	void rozszerz() {
		if (lewy == NULL)
		{
			int md = (L + R) >> 1;
			lewy = new node();
			prawy = new node();
			lewy->L = L;
			lewy->R = md;
			prawy->L = md+1;
			prawy->R = R;
		}
	}	
};
node *root;
struct punkt {
	int x, y, typ, id;
};
constexpr int MxN = 1e6+6;
punkt punkty[MxN];
int ans[MxN];

void update(node *v, int p, int x)
{
	if (v->L == v->R)
		v->val += x;
	else
	{
		int md = (v->L + v->R) >> 1;
		v->rozszerz();
		if (p <= md) update(v->lewy, p, x);
		else         update(v->prawy, p, x);
		v->val = v->lewy->val + v->prawy->val;
	}
}

int query(node *v, int l, int r)
{
	if (v->L > r || v->R < l)
		return 0;
	else if (l <= v->L && v->R <= r)
		return v->val;
	else
	{
		v->rozszerz();
		ll Lson = query(v->lewy, l, r);
		ll Rson = query(v->prawy, l, r);
		return Lson + Rson;
	}
}

bool cmp(punkt a, punkt b) {
	if (a.x == b.x) {
		if (a.typ == b.typ)
			return a.y < b.y;
		return a.typ < b.typ;
	}
	return a.x < b.x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	root = new node();

	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++) {
		int x, y; cin >> x >> y;
		punkty[i] = {x+y, x-y, 1, -1};
	}
	int min_y = 1e9+7;
	for (int i=n+1; i<=n+q; i++) {
		int x, y; cin >> x >> y;
		punkty[i] = {x+y, x-y, 2, i-n};
		min_y = min(min_y, x-y);
	}
	sort(punkty+1, punkty+n+q+1, cmp);
	
	for (int i=1; i<=n+q; i++) {
		punkt p = punkty[i];
		
		p.y += (1 - min_y) + 1;
		
		// cout << p.x << " " << p.y << " " << p.typ << "\n";
		
		if (p.typ == 1) {
			update(root, p.y, 1);
		}
		else {
			ans[p.id] = query(root, 1, p.y);
		}
	}
	
	for (int i=1; i<=q; i++)
		cout << ans[i] << "\n";

	return 0;
}
