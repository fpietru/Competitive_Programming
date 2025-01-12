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

constexpr int MxN = 16;
ll wsp[MxN][MxN];
ll koszt[(1<<MxN)+10]; // koszt[S] = koszt utworzenia grupy S
ll dp[(1<<MxN)+10]; // dp[S] = wynik, gdzie wszystkie wzięte króliki należą do S

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> wsp[i][j];

	for (int maska=0; maska<(1<<n); maska++)
		for (int i=0; i<n-1; i++)
			for (int j=i+1; j<n; j++)
				if ((maska & (1<<i)) && (maska & (1<<j)))
					koszt[maska] += wsp[i][j];
					
	for (int maska=0; maska<(1<<n); maska++) {
		int dopelnienie = ((1<<n)-1) ^ maska;
		for (int x=dopelnienie; x; x = (x-1) & dopelnienie)
			dp[maska ^ x] = max(dp[maska ^ x], dp[maska] + koszt[x]);
	}

	cout << dp[(1<<n)-1] << "\n";

	return 0;
}
