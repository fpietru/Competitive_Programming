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

constexpr int MxN = 2e5+5;
constexpr int INF = 1e9+7;
int h[MxN], R[MxN], L[MxN];
int pos[MxN];
vector<pii> order;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> h[i];
		order.PB({h[i], i});
		pos[h[i]] = i;
	}
	sort(order.begin(), order.end(), greater<pii>());
	h[0] = INF;
	h[n+1] = INF;
	
	stack<pii> st;
	st.push({INF, 0});
	for (int i=1; i<=n; i++) {
		while (!st.empty() && st.top().FR < h[i]) st.pop();
		L[i] = st.top().SD;
		st.push({h[i], i});
	}
	while (!st.empty()) st.pop();
	st.push({INF, n+1});
	for (int i=n; i>=1; i--) {
		while (!st.empty() && st.top().FR < h[i]) st.pop();
		R[i] = st.top().SD;
		st.push({h[i], i});
	}
	
	int ans = 0;
	for (auto it : order) {
		int i = it.SD;
		int polewo = i - (L[i]+1);
		int poprawo = (R[i]-1) - i;
		
		if (polewo <= poprawo) {
			for (int j=L[i]+1; j<i; j++)
				if (pos[h[i]-h[j]] > i && pos[h[i]-h[j]] < R[i])
					ans++;
		}
		else {
			for (int j=i+1; j<R[i]; j++)
				if (pos[h[i]-h[j]] < i && pos[h[i]-h[j]] > L[i])
					ans++;
		}
	}
	
	cout << ans << "\n";

	return 0;
}
