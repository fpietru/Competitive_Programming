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


int zmiana[5];

bool sprawdz(int i, int j, int k)
{
	if ((2*zmiana[1] == i + j) && (2*zmiana[2] == i + k) && (2*zmiana[3] == j + k))
		return 1;
	return 0;
}

void check()
{
	constexpr int limit = 8;
	for (int i=-limit; i<=limit; i++)
		for (int j=-limit; j<=limit; j++)
			for (int k=-limit; k<=limit; k++)
			{
				if (sprawdz(i, j, k))
					cout << " -> " << i << " " << j << " " << k << "\n";
			}
}

void gen()
{
	int limit = 3;
	for (int i=-limit; i<=limit; i++)
		for (int j=-limit; j<=limit; j++)
			for (int k=-limit; k<=limit; k++)
			{
				zmiana[1] = i;
				zmiana[2] = j;
				zmiana[3] = k;
				cout << i << " " << j << " " << k << "\n";
				check();
			}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	gen();

	return 0;
}
