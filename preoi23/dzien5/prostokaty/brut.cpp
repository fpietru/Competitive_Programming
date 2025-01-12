#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FR first
#define SD second

struct pt {
	ll x, y;
	pt operator+ (pt p) { return {x+p.x, y+p.y}; }
	pt operator- (pt p) { return {x-p.x, y-p.y}; }
	pt operator* (ll k) { return {k*x, k*y}; }
};
istream& operator>> (istream &is, pt &p) { is >> p.x >> p.y; return is; }
ostream& operator<< (ostream &os, pt p) { os << "(" << p.x << "," << p.y << ")"; return os; }
bool operator== (pt a, pt b) { return {a };}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	vector<pt> p(n);
	for (auto &it : vec) cin >> it;
	
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			for (int k=0; k<n; k++)
				for (int l=k; l<n; l++) {
					pt a = p[i];
					pt b = p[j];
					pt c = p[k];
					pt d = p[l];
					if (
				}
		
	
	return 0;
}
