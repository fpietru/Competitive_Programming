#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ld = long double;
using ull = unsigned long long;
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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
map<ull, bool> vis;
map<ull, ull> zlicz;
int n, m;

inline int f(int i, int j) {
	return m*i + j;
}

ull encode(vector<vector<char>> &v) {
	ull res = 0;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (v[i][j] == 'O')
				res |= (1ULL<<f(i,j));	
	return res;
}

vector<vector<char>> recover(ull x) {
	vector<vector<char>> res(n, vector<char>(m, '.'));
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (x & (1ULL<<f(i,j)))
				res[i][j] = 'O';
	return res;
}

void dfs(ull x, bool flag) {
	vector<vector<char>> v = recover(x);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (v[i][j] == 'O')
				for (int k=0; k<4; k++) {
					int i2 = i + dy[k];
					int j2 = j + dx[k];
					if (i2 < 0 || i2 >= n || j2 < 0 || j2 >= m || v[i2][j2] == 'O')
						continue;
					ull u = x ^ (1ULL<<f(i,j));
					u |= (1ULL<<f(i2,j2));
					zlicz[u] += flag;
					if (!vis[u]) {
						vis[u] = true;
						dfs(u, !flag);
					}
				}			
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m));
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> v[i][j];
	ull vid = encode(v);
	vis[vid] = true;
	dfs(vid, 0);
	
	ull suma = 0ULL;
	for (auto it : zlicz)
		suma += it.SD;

	vector<vector<char>> w(n, vector<char>(m));
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> w[i][j];
	
	ull wid = encode(w);
	if (zlicz[wid] == 0) cout << "0\n";
	else {
		ld ans = (ld)zlicz[wid] / (ld)suma;
		cout << fixed << setprecision(15) << ans << "\n";
	}

	return 0;
}
