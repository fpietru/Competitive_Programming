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

int rand(int a, int b) {
	return a + rand() % (b-a+1);
}

int main(int argc, char *argv[]) {
	srand(atoi(argv[argc-1]));
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int sz[2];
	for (int k=0; k<2; k++) {
		sz[k] = rand(1, 10);
		cout << sz[k] << "\n";
		for (int i=2; i<=sz[k]; i++)
			cout << rand(1, i-1) << " ";
		cout << "\n";
	}
	
	int d = rand(1, 5);
	cout << d << "\n";
	for (int i=1; i<=d; i++)
		cout << rand(1, sz[0]) << " " << rand(1, sz[1]) << " " << rand(1,1000000000) << "\n";
	
	int q = rand(1, 100);
	cout << q << "\n";
	while (q--) {
		cout << rand(1, sz[0]) << " " << rand(1, sz[1]) << "\n";
	}


	return 0;
}
