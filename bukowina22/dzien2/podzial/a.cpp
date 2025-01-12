#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging 
/*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

constexpr int MxN = 1e6+6;
constexpr ull M31 = (1ULL<<31)-1;
constexpr ull p = 41;
ull p_pow[MxN];
ull h[MxN];

ull mod(ull x)
{
	x = (x & M31) + (x >> 31);
	x = (x & M31) + (x >> 31);
	return (x == M31 ? 0 : x);
}

ull Hash(int a, int b)
{
	ull A = mod(h[a] * p_pow[b-a+1]);
	return mod(h[b+1] - A + M31);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	p_pow[0] = 1ULL;
	p_pow[1] = p;
	for (int i=2; i<MxN; i++)
		p_pow[i] = mod(p_pow[i-1] * p);

	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		int n = s.size();

		h[0] = 0ULL;
		for (int i=1; i<=n; i++)
			h[i] = mod(h[i-1] * p + (ull)(s[i-1]-'a'+1));

		int ans = 0;
		int i=0, j=n-1;
		int endA = 0;
		int endB = n-1;
		int cover = 0;
		while (i<j)
		{
			if (Hash(endA, i) == Hash(j, endB))
			{
				cover += 2*(i-endA+1);
				ans += 2;
				endA = i+1;
				endB = j-1;
			}
			i++, j--;
		}
		if (cover < n) ans++;
		cout << ans << "\n";
	}

	return 0;
}
