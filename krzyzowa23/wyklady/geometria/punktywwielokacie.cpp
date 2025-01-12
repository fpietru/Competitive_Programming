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

typedef long long T;
struct pt {
	T x, y;
	pt operator+ (pt p) { return {x+p.x, y+p.y}; }
	pt operator- (pt p) { return {x-p.x, y-p.y}; }
	pt operator* (T k) { return {k*x, k*y}; }
};
istream& operator>> (istream &is, pt &p) { return is >> p.x >> p.y; }
ostream& operator<< (ostream &os, pt p) { return os << "(" << p.x << "," << p.y << ")"; }
T dot(pt a, pt b) { return a.x*b.x + a.y*b.y; }
T cross(pt a, pt b) { return a.x*b.y - a.y*b.x; }
T orient(pt a, pt b, pt c) { 
	T x = cross(b-a, c-a);
	return (x >= 0 ? x > 0 ? 1 : 0 : -1);
}

// sprawdzam, czy punkt p, należy do trójkąta abc
bool check(pt a, pt b, pt c, pt p) {
	T P = llabs(cross(b-a, c-a));
	T P1 = llabs(cross(a-p, b-p));
	T P2 = llabs(cross(b-p, c-p));
	T P3 = llabs(cross(a-p, c-p));
	return (P == P1 + P2 + P3);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	vector<pt> p(n);
	for (int i=0; i<n; i++)
		cin >> p[i];
	
	int q; cin >> q;
	while (q--) {
		pt a; cin >> a;
		int low = 2;
		int high = n-1;	
		while (low < high) {
			int mid = (low + high) >> 1;
			if (orient(p[0], p[mid], a) >= 0)
				low = mid + 1;
			else high = mid;
		}
		low--;
		bool res = check(p[0], p[low], p[low+1], a);
		cout << (res ? "TAK\n" : "NIE\n");
	}

	return 0;
}
