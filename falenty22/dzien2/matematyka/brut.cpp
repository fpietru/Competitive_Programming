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
bool pierwsza[MxN+10];
vector<int> primes;
int ans[7][6];

int dzielniki(int x) {
	int res = 0;
	for (int i=1; i*i<=x; i++)
		if (x % i == 0) {
			if (x / i == i) res++;
			else res += 2;
		}
	return res;
}

int najwieksza(int x) {
	for (int i=(int)primes.size()-1; i>=0; i--)
		if (x % primes[i] == 0) return primes[i];
	return 1e9+7;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	memset(pierwsza, 1, sizeof(pierwsza));
	pierwsza[1] = 1;
	for (int i=2; i*i<=MxN; i++)
		if (pierwsza[i])
			for (int j=i*i; j<=MxN; j += i)
				pierwsza[j] = 0;
	
	for (int i=1; i<=100; i++)
		if (pierwsza[i])
			primes.PB(i);
	

	for (int i=1; i<=MxN; i++) {
		int k = dzielniki(i);
		int p = najwieksza(i);

		deb(i, k, p);
		if (k > 6 || p > 5) continue;
		for (int j=p; j<=5; j++) 
			ans[k][j]++;
	}
	
	for (int i=1; i<=6; i++)
		for (int j=1; j<=5; j++)
			deb(i, j, ans[i][j]);
	
	return 0;
}
