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

constexpr int MxN = 505;
char tab[MxN][MxN];
int h[MxN];
int n, m;

void left() {
	for (int i=1; i<=n; i++) h[i] = 1;
	for (int j=1; j<=m; j++)
		for (int i=1; i<=n; i++)
			if (tab[i][j] != '.') {
				tab[i][h[i]] = tab[i][j];
				if (h[i] != j)
					tab[i][j] = '.';
				h[i]++;
			}
}

void right() {
	for (int i=1; i<=n; i++) h[i] = m;
	for (int j=m; j>=1; j--)
		for (int i=1; i<=n; i++)
			if (tab[i][j] != '.') {
				tab[i][h[i]] = tab[i][j];
				if (h[i] != j)
					tab[i][j] = '.';
				h[i]--;
			}
}

void up() {
	for (int j=1; j<=m; j++) h[j] = 1;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (tab[i][j] != '.') {
				tab[h[j]][j] = tab[i][j];
				if (h[j] != i)
					tab[i][j] = '.';					
				h[j]++;
			}
}

void down() {
	for (int j=1; j<=m; j++) h[j] = n;
	for (int i=n; i>=1; i--)
		for (int j=1; j<=m; j++)
			if (tab[i][j] != '.') {
				tab[h[j]][j] = tab[i][j];
				if (h[j] != i)
					tab[i][j] = '.';
				h[j]--;
			}
}

void show() {
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++)
			cout << tab[i][j];
		cout << "\n";
	}
}

int main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			cin >> tab[i][j];

	while (true) {
		char op; cin >> op;
		if (op == 'G') up();
		else if (op == 'D') down();
		else if (op == 'L') left();
		else right();
		show();
	}

	return 0;
}
