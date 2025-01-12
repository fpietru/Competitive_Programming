/*
	Zadanie: "Płytkie nawiasowania", XXX OI, etap I
	Autor: Franciszek Pietrusiak
*/
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

constexpr int MxN = 1e6+6;
int koniec[MxN];
stack<int> S;
deque<int> Q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, h; cin >> n >> h;
	string s; cin >> s;
	for (int i=0; i<n; i++) {
		if (s[i] == '(') S.push(i);
		else {
			int j = S.top(); S.pop();
			koniec[j] = i;
		}
	}
	int suma = 0, ans = 0;
	for (int i=0; i<n; i++) {
		if (s[i] == '(')  {		
			Q.push_back(i);
			suma++;
			if (suma > h) {
				ans += 2;
				suma -= 2;
				Q.pop_front();
				int j = Q.front();
				Q.pop_front();
				s[i] = ')';
				s[koniec[j]] = '(';
			}
		}
		else {
			Q.pop_back();
			suma--;
		}
	}
	cout << ans << "\n";

	return 0;
}
