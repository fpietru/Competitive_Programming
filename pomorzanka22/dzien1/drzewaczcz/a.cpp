#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging 
/*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

constexpr int MxN = 3e5+5;
pair<int, pii> edges[MxN];
struct node { int p, s; };
node nodes[MxN];

void init(int n) {
	for (int i=1; i<=n; i++) {
		nodes[i].p = i;
		nodes[i].s = 1;
	}
}

int getL(int v) {
	if (nodes[v].p == v) return v;
	return nodes[v].p = getL(nodes[v].p);
}

bool join(int a, int b) {
	a = getL(a); b = getL(b);
	if (a == b) return false;
	if (nodes[a].s < nodes[b].s) swap(a, b);
	nodes[a].s += nodes[b].s;
	nodes[b].p = a;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	init(n);
	for (int i=1; i<=m; i++) {
		int a, b, w; cin >> a >> b >> w;
		edges[i] = {w, {a, b}};
	}
	sort(edges+1, edges+1+m);
	int najmniejszy = 0, najwiekszy = 0;
	for (int i=1; i<=m; i++)
		if (join(edges[i].SD.FR, edges[i].SD.SD))
			najmniejszy += edges[i].FR;
	reverse(edges+1, edges+1+m);
	init(n);
	for (int i=1; i<=m; i++)
		if (join(edges[i].SD.FR, edges[i].SD.SD))
			najwiekszy += edges[i].FR;
			
	cout << najwiekszy - najmniejszy + 1 << "\n";

	return 0;
}
