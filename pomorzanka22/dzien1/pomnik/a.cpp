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

constexpr int MxN = 155;
constexpr int INF = 1e9+7;
bool tab[MxN*MxN][MxN], tab2[MxN][MxN][MxN];
int dp[MxN][MxN][MxN];
int L[MxN], R[MxN];
int ans;

void solve(vector<int> &odwiert) {
	const int n = odwiert.size();
	stack<pii> S;
	S.push({-1, -1});
	for (int i=0; i<n; i++) {
		while (!S.empty() && S.top().FR >= odwiert[i]) S.pop();
		L[i] = S.top().SD;
		S.push({odwiert[i], i});
	}
	while (!S.empty()) S.pop();
	S.push({-1, n});
	for (int i=n-1; i>=0; i--) {
		while (!S.empty() && S.top().FR >= odwiert[i]) S.pop();
		R[i] = S.top().SD;
		S.push({odwiert[i], i});
	}
	for (int i=0; i<n; i++)
		ans = max(ans, 4*odwiert[i]*(R[i]-1 - (L[i] + 1) + 1));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int p, q, r; cin >> p >> q >> r;
	for (int i=1; i<=p*q; i++) {
		string s; cin >> s;
		for (int j=1; j<=r; j++) {
			tab[i][j] = (s[j-1] == 'P');
		}
	}
	for (int x=1; x<=p; x++)
		for (int y=1; y<=q; y++)
			for (int z=1; z<=r; z++) {
				tab2[x][y][z] = tab[(y*p+x-p)][z];
			}
			
	for (int x=1; x<=p; x++)
		for (int y=1; y<=q; y++)
			for (int z=1; z<=r; z++) {
				if (tab2[x][y][z] == false) dp[x][y][z] = min({dp[x][y-1][z], dp[x][y][z-1], dp[x][y-1][z-1]}) + 1;
				else                        dp[x][y][z] = 0;
			}
	for (int y=1; y<=q; y++) 
		for (int z=1; z<=r; z++) {
			vector<int> odwiert;
			for (int x=1; x<=p; x++) odwiert.PB(dp[x][y][z]);
			solve(odwiert);
		}
	
	for (int y=1; y<=q; y++)
		for (int x=1; x<=p; x++)
			for (int z=1; z<=r; z++) {
				if (tab2[x][y][z] == false) dp[x][y][z] = min({dp[x-1][y][z], dp[x][y][z-1], dp[x-1][y][z-1]}) + 1;
				else                        dp[x][y][z] = 0;
			}
	for (int x=1; x<=p; x++)
		for (int z=1; z<=r; z++) {
			vector<int> odwiert;
			for (int y=1; y<=q; y++) odwiert.PB(dp[x][y][z]);
			solve(odwiert);
		}

	for (int z=1; z<=r; z++)
		for (int x=1; x<=p; x++)
			for (int y=1; y<=q; y++) {
				if (tab2[x][y][z] == false) dp[x][y][z] = min({dp[x-1][y][z], dp[x][y-1][z], dp[x-1][y-1][z]}) + 1;
				else                        dp[x][y][z] = 0;
			}
	for (int x=1; x<=p; x++)
		for (int y=1; y<=q; y++) {
			vector<int> odwiert;
			for (int z=1; z<=r; z++) odwiert.PB(dp[x][y][z]);
			solve(odwiert);
		}
	
	cout << ans << "\n";

	return 0;
}
