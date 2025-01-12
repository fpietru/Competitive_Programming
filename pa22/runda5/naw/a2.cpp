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

int n, k;
string s;
constexpr int MxN = 1e5+5;
constexpr ll INF = 1e18+7;
struct przedzial {
	int st;
	int ed;
	ll ile;
};
bool srodek[MxN];
bool operator < (const przedzial &a, const przedzial &b) {
	ll w1 = a.ile.FR - a.ile.SD;
	ll w2 = b.ile.FR - b.ile.SD;
	return w1 < w2;
}
pair<ll, int> operator + (const pair<ll, int> &a, const pair<ll, int> &b) {
	return {a.FR + b.FR, a.SD + b.SD};
}

pair<ll, int> ilenawiasow(int st, int ed) {
	ll res = 0LL, w = 0LL;
	int centr = 0;
	stack<ll> S;
	for (int i=st; i<=ed; i++) {
		if (s[i] == '(') {
			if (i != n-1 && i != ed && s[i+1] == ')')
				centr++;
			S.push(w+1);
			w = 0LL;
		}
		else {
			if (!S.empty()) {
				w = S.top();
				S.pop();
				res += w; 
			}
			else w = 0LL;
		}
	}
	return {res, centr};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k; k--;
	cin >> s;
	
	for (int i=0; i<n-1; i++)
		if (s[i] == '(' && s[i+1] == ')')
			srodek[i] = true;
	
	priority_queue<przedzial> Q;
	Q.push({0, n-1, ilenawiasow(0, n-1)});
	
	while (k--) {
		przedzial v = Q.top(); Q.pop();
		pair<ll, int> mi = {INF, 1e9+7};
		int mid = v.st;
		for (int i=v.st; i<=v.ed-1; i++)
			if (srodek[i]) {
				pair<ll, int> L = ilenawiasow(v.st, i);
				pair<ll, int> R = ilenawiasow(i+1, v.ed);
				// deb(i, L, R);
				if (L + R <= mi) {
					mi = L + R;
					mid = i;
				}
			}
		// deb(v.st, v.ed, v.ile, mid);
		Q.push({v.st, mid, ilenawiasow(v.st, mid)});
		Q.push({mid+1, v.ed, ilenawiasow(mid+1, v.ed)});
	}
	
	ll ans = 0LL;
	while (!Q.empty()) {
		przedzial v = Q.top(); Q.pop();
		// deb(v.st, v.ed, v.ile);
		ans += v.ile.FR;
	}
	cout << ans << "\n";

	return 0;
}
