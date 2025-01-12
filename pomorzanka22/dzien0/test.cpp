#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ull = unsigned long long;
using ll = long long;
#define FR first
#define SD second
#define MOD srand
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging /*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

const ull mod = 7759751235135804287, mod2 = 4189298803, _max = 2147483648, goal = 147100243658956343;

ull fpow(ull pod, ull wyk)
{
    ull w = 1;
    while (wyk)
    {
        if (wyk & 1)
        {
            w *= pod;
            w %= mod;
        }
        pod *= pod;
        pod %= mod;
        wyk /= 2;
    }
    return w;
}

ull c(ull b, int z)
{
    ull C = fpow(b / ((ull)2 << z), b % ((ull)1 << z));
    ull w = 0;
    while (C /= 2)
        w ^= (C % 2);
    return w;
}

ull solve(ull in) {
	ull s2 = 0;
    if (in != (in % _max)) return -1;
    in *= 123456789;
    in %= mod2;
    for (ull i = 2; i <= 100000000; i++)
    {
        in = ((i % 2) ? in * i : in + i) % mod2;
        if (i % 10000000 == 0)
            s2 ^= in;
    }
    in = s2;
    for (ull i = 2; i <= 100000000; i++)
    {
        in = ((i % 2) ? in * i : in + i) % mod2;
        if (i % 10000000 == 0)
            s2 ^= in;
    }
    (s2 *= s2) % mod2;
    MOD(mod2);
    for (int j = 0; j < 654321; j++)
        for (ull i = 0; i <= 62; i++)
            s2 ^= ((ull)1 << i) * c(s2, i);
    for (int i = 0; i < 100; i++)
        s2 += (ull)rand() * (ull)(rand() % 2 ? 1 : -1);
	return s2;
}

ull rand(ull a, ull b) {
	return a + rand() % (b-a+1);
}

int main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0), cout.tie(0);
	
	map<ull, bool> mp;
	ull best_diff = 7759751235135804287;
	ull best_val = -1;
	while (true) {
		ull r = rand(1, 1e18);
		if (mp[r] == true) continue;
		mp[r] = true;
		ull res = solve(r);
		ull diff = abs((ll)res - (ll)goal);
		if (diff <= best_diff) {
			best_diff = diff;
			best_val = res;
		}
		
		deb(r, res, best_diff, best_val);
	}	

	return 0;
}
