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

constexpr int MxN = 1e2+2;
bool connected[MxN][MxN];
vector<int> G[MxN];

int rand(int a, int b) {
	return a + rand() % (b-a+1);
}

int main(int argc, char *argv[]) {
	srand(atoi(argv[argc-1]));
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n = rand(1, 10);

	vector<pii> edges;
	for (int i=2; i<=n; i++) {
		int r = rand(1, i-1);
		edges.PB({r, i});
		connected[r][i] = connected[i][r] = true;
	}
	
	int q = rand(1, n);
	while (q--) {
		int a = rand(1, n);
		int b = rand(1, n);
		if (a == b || connected[a][b]) q--;
		else {
			edges.PB({a, b});
			connected[a][b] = connected[b][a] = true;
		}
	}
	
	cout << n << " " << (int)edges.size() << "\n";
	for (auto it : edges) {
		cout << it.FR << " " << it.SD << "\n";
		G[it.FR].PB(it.SD); G[it.SD].PB(it.FR);
	}
		
	q = rand(1, 10);
	cout << q << "\n";
	for (int i=1; i<=q; i++) {
		int r = rand(1, 2);
		cout << r << " ";
		if (r == 1) {
			int a = rand(1, n);
			int b = rand(1, n);
			int k1 = rand(1, n);
			int k2 = G[k1].begin();
		}
	}

	return 0;
}
