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

constexpr ll MOD = 1e9+7;

vector<vector<ll>> mult(vector<vector<ll>> &A, vector<vector<ll>> &B) {
	int n = A.size();
	vector<vector<ll>> C(n, vector<ll>(n));
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			for (int k=0; k<n; k++)
				C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
	return C;
}

vector<vector<ll>> fastpow(vector<vector<ll>> &A, ll b) {
	int n = A.size();
	vector<vector<ll>> res(n, vector<ll>(n));
	for (int i=0; i<n; i++)
		res[i][i] = 1;
	while (b) {
		if (b&1) res = mult(res, A);
		A = mult(A, A);
		b >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	ll k; cin >> k;
	vector<vector<ll>> M(n, vector<ll>(n));
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> M[i][j];
	
	vector<vector<ll>> res = fastpow(M, k);
	ll ans = 0LL;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			ans = (ans + res[i][j]) % MOD;
	
	cout << ans << "\n";
	
	return 0;
}
