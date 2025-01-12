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
istream& operator>> (istream &is, pt &p) { return is >> p.x >> p.y; }
ostream& operator<< (ostream &os, pt p) { return os << "(" << p.x << "," << p.y << ")"; }
T dot(pt a, pt b) { return a.x*b.x + a.y*b.y; }
T cross(pt a, pt b) { return a.x*b.y - a.y*b.x; }
T dl(pt p) { return p.x*p.x + p.y*p.y; }
T orient(pt a, pt b, pt c) { 
	T x = cross(b-a, c-a);
	return (x >= 0 ? x > 0 ? 1 : 0 : -1);
}

vector<pt> otoczka;
pt p0;
bool cmp(pt a, pt b) {
	T o = orient(p0, a, b);
	if (o == 0) return dl(a-p0) < dl(b-p0);
	return o > 0;
}

void moveB(int &i, pt A, int m) {
	while (true) {
		pt l = otoczka[(i-1+m)%m];
		pt B = otoczka[i];
		pt r = otoczka[(i+1)%m];
		if (dl(l-A) <= dl(B-A) && dl(B-A) >= dl(r-A))
			break;
		else if (dl(l-A) > dl(B-A)) i = (i-1+m)%m;
		else if (dl(r-A) > dl(B-A)) i = (i+1)%m;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	vector<pt> p(n);
	for (int i=0; i<n; i++)
		cin >> p[i];
	
	p0 = *min_element(p.begin(), p.end(), [](pt a, pt b) {
		return make_pair(a.y, a.x) < make_pair(b.y, b.x);
	});	
	sort(p.begin(), p.end(), cmp);

	int wsk = p.size()-1;
	while (wsk >= 0 && orient(p0, p[wsk], p.back()) == 0) wsk--;
	reverse(p.begin()+wsk+1, p.end());

	for (int i=0; i<n; i++) {
		while ((int)otoczka.size() >= 2 && orient(otoczka[otoczka.size()-2], otoczka.back(), p[i]) < 0)
			otoczka.pop_back();
		otoczka.PB(p[i]);
	}

	ld ans = 0.0;
	int m = otoczka.size();
	int posB = 0;
	for (int i=0; i<m; i++) {
		pt A = otoczka[i];
		moveB(posB, A, m);
		pt B = otoczka[posB];
		ans = max(ans, sqrtl(dl(B-A)));
	}
	
	cout << fixed << setprecision(7) << ans << "\n";
	
	return 0;
}
