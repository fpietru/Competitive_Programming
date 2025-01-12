/*
	Link: https://atcoder.jp/contests/arc101/tasks/arc101_b
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

constexpr int MxN = 1e5+5;
constexpr int INF = 1e9+7;
int tab[MxN], p[MxN], tmp[MxN];
int n; ll inwersje;

void merge(int st, int md, int ed);
void mergesort(int st, int ed) {
	if (st == ed) return;
	int md = (st + ed) >> 1;
	mergesort(st, md);
	mergesort(md+1, ed);
	merge(st, md, ed);
}

void merge(int st, int md, int ed) {
	int i=st, k=st, j = md+1;
	while (i<=md && j<=ed) {
		if (p[i] > p[j]) {
			inwersje += (ll)(md - i + 1);
			tmp[k++] = p[j++];
		}
		else tmp[k++] = p[i++];
	}
	while (i<=md) tmp[k++] = p[i++];
	while (j<=ed) tmp[k++] = p[j++];
	for (int x=st; x<=ed; x++) p[x] = tmp[x];
}

bool check(int k) {
	p[0] = 0;
	for (int i=1; i<=n; i++)
		p[i] = p[i-1] + (tab[i] < k ? -1 : 1);
	inwersje = 0LL;
	mergesort(0, n);
	ll wszystkie = 1LL*n*(n+1);
	ll zle = (wszystkie >> 1) - inwersje;
	return (4*zle >= wszystkie);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int low = INF, high = -INF;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> tab[i];
		low = min(low, tab[i]);
		high = max(high, tab[i]);
	}
	high++;
	while (low < high) {
		int mid = (1LL*low + high) >> 1;
		if (check(mid)) low = mid + 1;
		else high = mid;
	}
	cout << low-1 << "\n";

	return 0;
}
