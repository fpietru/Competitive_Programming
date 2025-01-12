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
int h[MxN], L[MxN], R[MxN];
ll p[MxN];
int n, k;

inline ll suma(int a, int b) {
	return p[b] - p[a-1];
}

ll waga(int H) {
	
}

bool check(int H) {
	for (int i=0; i<=n; i++) {
		L[i] = 0;
		R[i] = INF;
	}
	for (int x=1; x<=n; x++) {
		int idx = x + (H - h[x]);
		if (idx <= n) L[idx] = max(L[idx], x); 
	}
	for (int x=n; x>=1; x--) {
		int idx = x - (H - h[x]);
		if (idx >= 1) R[idx] = min(R[idx], x);
	}
	L[0] = 0;
	for (int i=1; i<=n; i++)
		L[i] = max(L[i-1], L[i]);
	R[n+1] = n+1;
	for (int i=n; i>=1; i--)
		R[i] = min(R[i+1], R[i]);
	
	
	
	/*
	cout << "L:\n";
	for (int i=1; i<=n; i++)
		cout << L[i] << " ";
	cout << "\n";
	cout << "R:\n";
	for (int i=1; i<=n; i++)
		cout << R[i] << " ";		
	cout << "\n"; */
		
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int mx = 0; cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> h[i];
		mx = max(mx, h[i]);
	}
	
	check(5);
	
	p[0] = 0;
	for (int i=1; i<=n; i++)
		p[i] = p[i-1] + h[i];

	/*
	int low = mx + 1;
	int high = 1e9+2;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (check(mid)) low = mid + 1;
		else high = low;
	} */


	return 0;
}
