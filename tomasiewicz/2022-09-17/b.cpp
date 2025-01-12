/*
	Zadanie "Modernizacja autostrady" z XXII OI, etap III
	Link: https://szkopul.edu.pl/problemset/problem/z0rincXf7fi157ycO_Sl0bCb/site/?key=statement
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

constexpr int MxN = 5e5+5;
constexpr int INF = 1e9+7;
vector<int> G[MxN];
int h[MxN], d[MxN], H[MxN], D[MxN], l[2][MxN], lvl[MxN], parent[MxN];
pii k[2][MxN];
struct podzial {
	int v, u;
	int val;
	int dl1;
	int dl2;
	pii koncowka1;
	pii koncowka2;
	inline bool operator < (podzial &p) {
		return val < p.val;
	}
	inline bool operator > (podzial &p) {
		return val > p.val;
	}
};
podzial podzialy[2];

inline int ceildiv(int a) {
	return ((a+1)>>1);
}

void dfs1(int v, int p) {
	lvl[v] = lvl[p] + 1;
	parent[v] = p;
	pii mxh_idx = {0, 0};
	int mxd_idx = 0;
	bool lisc = true;
	for (auto u : G[v])
		if (u != p) {
			lisc = false;
			dfs1(u, v);
			if (h[u] >= h[mxh_idx.FR]) {
				mxh_idx.SD = mxh_idx.FR;
				mxh_idx.FR = u;
			}
			else if (h[u] > h[mxh_idx.SD])
				mxh_idx.SD = u;
			if (d[u] >= d[mxd_idx])
				mxd_idx = u;
		}
	if (!lisc) {
	
		h[v] = h[mxh_idx.FR] + 1;
		l[0][v] = l[0][mxh_idx.FR];

		int op1, op2, op3;
		op1 = h[v];
		op2 = (mxd_idx ? d[mxd_idx] : -1);
		op3 = (mxh_idx.FR && mxh_idx.SD ? h[mxh_idx.FR] + h[mxh_idx.SD] + 2 : -1);
		d[v] = max({op1, op2, op3});
		
		if (d[v] == op1)      k[0][v] = {v, l[0][v]};
		else if (d[v] == op2) k[0][v] = k[0][mxd_idx];
		else                  k[0][v] = {l[0][mxh_idx.FR], l[0][mxh_idx.SD]};
	}
	else {
		l[0][v] = v;
		k[0][v] = {v, v};
	}
}

void dfs2(int v, int p) {
	int idx[3] = {0, 0, 0};
	for (auto u : G[v])
		if (u != p) {
			if (h[u] >= h[idx[0]]) {
				idx[2] = idx[1];
				idx[1] = idx[0];
				idx[0] = u;
			}
			else if (h[u] >= h[idx[1]]) {
				idx[2] = idx[1];
				idx[1] = u;
			}
			else if (h[u] >= h[idx[2]])
				idx[2] = u;
		}
	
	for (auto u : G[v])
		if (u != p) {
			pii mxh_idx = {0, 0};
			int mxd_idx = 0;
			for (int i=0; i<3; i++) {
				if (idx[i] != u && d[idx[i]] >= d[mxd_idx]) mxd_idx = idx[i];
				if (idx[i] != u && h[idx[i]] >= h[mxh_idx.FR]) {
					mxh_idx.SD = mxh_idx.FR;
					mxh_idx.FR = idx[i];
				}
				else if (idx[i] != u && h[idx[i]] >= h[mxh_idx.SD])
					mxh_idx.SD = idx[i];
			}
			
			podzial curr_podzial;
			int op1, op2, op3, op4, op5;
			op1 = 0;
			op2 = H[v] + 1;
			op3 = (mxh_idx.FR ? h[mxh_idx.FR] + 1 : -1);
			H[u] = max({op1, op2, op3});
			
			if (H[u] == op1)      l[1][u] = v;
			else if (H[u] == op2) l[1][u] = l[1][v];
			else                  l[1][u] = l[0][mxh_idx.FR];
			
			op1 = H[u];
			op2 = D[v];
			op3 = (mxh_idx.FR ? H[v] + h[mxh_idx.FR] + 2 : -1);
			op4 = (mxh_idx.FR && mxh_idx.SD ? h[mxh_idx.FR] + h[mxh_idx.SD] + 2 : -1);
			op5 = (mxd_idx ? d[mxd_idx] : -1);
			D[u] = max({op1, op2, op3, op4, op5});
			
			if (D[u] == op1) k[1][u] = {v, l[1][u]};
			else if (D[u] == op2) k[1][u] = k[1][v];
			else if (D[u] == op3) k[1][u] = {l[1][v], l[0][mxh_idx.FR]};
			else if (D[u] == op4) k[1][u] = {l[0][mxh_idx.FR], l[0][mxh_idx.SD]};
			else k[1][u] = k[0][mxd_idx]; 
			
			
			// najmniejszy podział
			op1 = D[u];
			op2 = d[u];
			op3 = ceildiv(D[u]) + ceildiv(d[u]) + 1;
			curr_podzial = {v, u, max({op1, op2, op3}), D[u], d[u], k[1][u], k[0][u]};
			if (curr_podzial < podzialy[0]) podzialy[0] = curr_podzial;
			
			// najwiekszy podział
			op1 = D[u] + d[u] + 1;
			curr_podzial = {v, u, op1, D[u], d[u], k[1][u], k[0][u]};
			if (curr_podzial > podzialy[1]) podzialy[1] = curr_podzial;
			
			dfs2(u, v);
		}
}

int srodek(int a, int b, int dl) {
	if (lvl[a] < lvl[b]) swap(a, b);
	int v = a;
	for (int i=1; i<=ceildiv(dl); i++)
		v = parent[v];
	return v;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n-1; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b); G[b].PB(a);
	}
	
	podzialy[0].val = INF;
	podzialy[1].val = -INF;
	h[0] = d[0] = -INF;
	H[1] = D[1] = -INF;
	dfs1(1, 1);
	dfs2(1, 1);

	for (int i=0; i<2; i++) {
		int val = podzialy[i].val;
		int v = podzialy[i].v;
		int u = podzialy[i].u;
		int dl1 = podzialy[i].dl1;
		int dl2 = podzialy[i].dl2;
		pii k1 = podzialy[i].koncowka1;
		pii k2 = podzialy[i].koncowka2;
		
		if (i == 0) {
			int sr1 = srodek(k1.FR, k1.SD, dl1);
			int sr2 = srodek(k2.FR, k2.SD, dl2);
			cout << val << " " << v << " " << u << " " << sr1 << " " << sr2 << "\n";
		}
		else cout << val << " " << v << " " << u << " " << k1.FR << " " << k2.FR << "\n";
	}
	
	return 0;
}
