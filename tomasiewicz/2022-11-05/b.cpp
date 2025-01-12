/*
	Link: https://codeforces.com/problemset/problem/160/D
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

struct edge {
	int a, b, w, id;
};
struct node {
	int p, s;
};
constexpr int MxM = 1e5+5;
edge edges[MxM];
vector<edge> edges2[MxM];
vector<int> wagi;
node nodes[MxM];
vector<pii> G[MxM];
int pre[MxM], low[MxM], ans[MxM];
int licznik;

void init(int v) {
	nodes[v].p = v;
	nodes[v].s = 1; 
}

int getL(int v) {
	if (nodes[v].p == v) return v;
	else return nodes[v].p = getL(nodes[v].p);
}

void join(int a, int b) {
	a = getL(a); b = getL(b);
	if (a == b) return;
	if (nodes[a].s < nodes[b].s)
		swap(a, b);
	nodes[a].s += nodes[b].s;
	nodes[b].p = a;
}

void dfs(int v, int p=-1) {
	pre[v] = low[v] = ++licznik;
	for (auto [u, id] : G[v]) {
		if (pre[u] == 0) {
			dfs(u, id);
			low[v] = min(low[v], low[u]);
			if (low[u] > pre[v]) ans[id] = 2;
		}
		else if (id != p)
			low[v] = min(low[v], pre[u]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> edges[i].a >> edges[i].b >> edges[i].w;
		edges[i].id = i;
		wagi.PB(edges[i].w);
	}
	sort(wagi.begin(), wagi.end());
	wagi.erase(unique(wagi.begin(), wagi.end()), wagi.end());
	for (int i=1; i<=m; i++)
		edges2[lower_bound(wagi.begin(), wagi.end(), edges[i].w)-wagi.begin()+1].PB(edges[i]);
	for (int i=1; i<=n; i++)
		init(i);
	for (int i=1; i<=m; i++) {
		for (auto e : edges2[i]) {
			int La = getL(e.a);
			int Lb = getL(e.b);
			if (La != Lb) {
				ans[e.id] = 1;
				G[La].PB({Lb, e.id});
				G[Lb].PB({La, e.id});
			}
		}
		for (auto e : edges2[i])
			join(e.a, e.b);
	}
	
	for (int i=1; i<=n; i++)
		if (!pre[i]) dfs(i);

	for (int i=1; i<=m; i++) {
		if (ans[i] == 2) cout << "any\n";
		else if (ans[i] == 1) cout << "at least one\n";
		else cout << "none\n";
	}

	return 0;
}
