#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
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
 
typedef long long T;
struct pt {
	T x, y;
	pt operator+ (pt p) { return {x+p.x, y+p.y}; }
	pt operator- (pt p) { return {x-p.x, y-p.y}; }
	pt operator* (T k) { return {k*x, k*y}; }
};
 
bool operator== (pt a, pt b) { return (a.x == b.x && a.y == b.y); }
bool operator!= (pt a, pt b) { return !(a == b); }
istream& operator>> (istream &in, pt &p) { return in >> p.x >> p.y; }
ostream& operator<< (ostream &os, pt p) { return os << "(" << p.x << "," << p.y << ")"; }
T sq(pt p) { return p.x*p.x + p.y*p.y; }
ld dl(pt p) { return sqrt(sq(p)); }
T dot(pt a, pt b) { return a.x*b.x + a.y*b.y; }
T cross(pt a, pt b) { return a.x*b.y - a.y*b.x; }
T orient(pt a, pt b, pt c) {
	T x = cross(a-b, a-c);
	return x >= 0 ? x ? 1 : 0 : -1;
} 

bool wspoliniowe(T a, T b, T c, T d) {
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	return max(a, c) <= min(b, d);
}

bool przeciecie(pt a, pt b, pt c, pt d) {
	if (orient(a, b, c) == 0 && orient(a, b, d) == 0) return wspoliniowe(a.x, b.x, c.x, d.x) && wspoliniowe(a.y, b.y, c.y, d.y);
	return orient(a, b, c)*orient(a, b, d) <= 0 && orient(c, d, a)*orient(c, d, b) <= 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	pt a, b, c, d; cin >> a >> b >> c >> d;
	cout << (przeciecie(a, b, c, d) ? "TAK\n" : "NIE\n");
 
	return 0;
}
