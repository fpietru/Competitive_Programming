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

constexpr int MxN = 1e3+3;
constexpr int MxQ = 3e5+5;
constexpr int MOD = 1e9+7;
constexpr int MxW = 17;
int para[MxN][MxN];
int p[MxW][MxN][MxN];
int best[MxN][MxN];
pii queries[MxN];

void solve(int A, int B) {
	cout << best[A][B] << " " << p[best[A][B]][A][B] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int q; cin >> q;
	int mxA = 0, mxB = 0;
	for (int i=1; i<=q; i++) {
		cin >> queries[i].FR >> queries[i].SD;
		// mxA = max(mxA, queries[i].FR);
		// mxB = max(mxB, queries[i].SD);
	}
	mxA = MxN-1;
	mxB = MxN-1;
	for (int a=1; a<=mxA; a++) {
		for (int b=a; b<=mxB; b++) {
			para[a][b] = para[b%a][a] + 1;
			para[b][a] = para[a][b];
		}
	}
	
	p[0][0][0] = 1;
	for (int j=1; j<=mxB; j++)
		for (int k=0; k<MxW; k++)
			p[k][0][j] = ((ll)p[k][0][j-1] + (para[0][j] == k)) % MOD;
	for (int i=1; i<=mxA; i++)
		for (int k=0; k<MxW; k++)
			p[k][i][0] = ((ll)p[k][i-1][0] + (para[i][0] == k)) % MOD;
	for (int i=1; i<=mxA; i++) {
		for (int j=1; j<=mxB; j++) {
			for (int k=0; k<=14; k++) {
				p[k][i][j] = ((ll)p[k][i-1][j] + p[k][i][j-1] - p[k][i-1][j-1] + (para[i][j] == k)) % MOD;
			}
		}
	}
	
	for (int i=1; i<=mxA; i++) {
		for (int j=1; j<=mxB; j++) 
			best[i][j] = max({para[i][j], best[i-1][j], best[i][j-1], best[i-1][j-1]});
	}
	
	/*
	for (int i=0; i<=mxA; i++) {
		for (int j=0; j<=mxB; j++) 
			cout << para[i][j] << " ";
		cout << "\n";
	}
	
	for (int i=0; i<=mxA; i++) {
		for (int j=0; j<=mxB; j++) 
			cout << p[4][i][j] << " ";
		cout << "\n";
	}
	
	cout << "\n";
	for (int i=0; i<=mxA; i++) {
		for (int j=0; j<=mxB; j++) 
			cout << best[i][j] << " ";
		cout << "\n";
	} */
	
	for (int i=1; i<=q; i++)
		solve(queries[i].FR, queries[i].SD);

	return 0;
}
