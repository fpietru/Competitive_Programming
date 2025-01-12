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
bool zapalone[3][MxN];
int tab[3][MxN];
pii pos[2*MxN];
ll zlicz[11];
int n, k;

int zapalonych(int i, int j) {
	int j1 = (j-1 < 1 ? n : j-1);
	int j2 = (j+1 > n ? 1 : j+1);
	if (i == 1)
		return (zapalone[2][j] + zapalone[1][j1] + zapalone[1][j2]);
	if (i == 2)
		return (zapalone[1][j] + zapalone[2][j1] + zapalone[2][j2]);
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i=1; i<=2; i++)
		for (int j=1; j<=n; j++) {
			cin >> tab[i][j];
			pos[tab[i][j]] = {i, j};
		}
	
	int ciekawosc = 0;
	for (int l=1; l<=2*n; l++) {
		for (int r=l; r<=2*n; r++) {
			zapalone[pos[r].FR][pos[r].SD] = 1;
			if (zapalonych(pos[r].FR, pos[r].SD) && ciekawosc >= 3)
				ciekawosc -= (zapalonych(pos[r].FR, pos[r].SD) - 1);
			else ciekawosc++;
			
			deb(l, r, ciekawosc);
			//if (ciekawosc <= 10)
			//	zlicz[ciekawosc]++;
		}
		if (zapalonych(pos[l].FR, pos[l].SD))
			ciekawosc += (zapalonych(pos[l].FR, pos[l].SD) - 1);
		else ciekawosc--;
		zapalone[pos[l].FR][pos[l].SD] = 0;
	}
	
	for (int i=1; i<=k; i++)
		cout << zlicz[i] << " ";
	cout << "\n";

	return 0;
}
