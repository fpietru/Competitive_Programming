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
constexpr int LOG = 19;
int kmr[MxN][LOG+1];
int lg[MxN];
pair<pii, int> pary[MxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s; cin >> s;
	const int n = s.size();

	lg[1] = 0;
	for (int i=2; i<=n; i++)
		lg[i] = lg[i>>1] + 1;
		
	for (int i=0; i<n; i++)
		kmr[i][0] = (s[i]-'a')+1;
	
	for (int k=1; k<=lg[n]; k++) {
		for (int i=0; i<n; i++) {
			int skok = (1<<(k-1));
			if (i+skok >= n) pary[i] = {{kmr[i][k-1], -1}, i};
			else             pary[i] = {{kmr[i][k-1], kmr[i+skok][k-1]}, i};
		}
		sort(pary, pary+n);
		int licznik = 0;
		pii pom = {-2, -2};
		for (int i=0; i<n; i++) {
			if (pom.FR != pary[i].FR.FR || pom.SD != pary[i].FR.SD) {
				pom = {pary[i].FR.FR, pary[i].FR.SD};
				licznik++;
			}
			kmr[pary[i].SD][k] = licznik;
		}
	}
	
	for (int i=0; i<=LOG; i++) {
		cout << i << ": ";
		for (int j=0; j<n; j++)
			cout << kmr[j][i] << " ";
		cout << "\n";
	}
	

	return 0;
}
