#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 150055;
struct osoba {
	int kto;
	int x, y, z;
};
bool wywal[MxN];
osoba osoby[3][MxN];
ostream& operator<< (ostream &os, osoba o) {
	os << "[" << o.kto << "] (" << o.x << "," << o.y << "," << o.z << ")";
	return os; 
}

inline bool zbalansowana(osoba a, osoba b, osoba c) {
	bool w1 = (a.x > b.x && a.x > c.x);
	bool w2 = (b.y > a.y && b.y > c.y);
	bool w3 = (c.z > a.z && c.z > b.z);
	return (w1 && w2 && w3);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		osoba o; o.kto = i;
		cin >> o.x >> o.y >> o.z;
		osoby[0][i] = osoby[1][i] = osoby[2][i] = o;
	}
	sort(osoby[0]+1, osoby[0]+n+1, [](osoba &a, osoba &b) { return a.x > b.x; });
	sort(osoby[1]+1, osoby[1]+n+1, [](osoba &a, osoba &b) { return a.y > b.y; });
	sort(osoby[2]+1, osoby[2]+n+1, [](osoba &a, osoba &b) { return a.z > b.z; });

	int i0 = 1, i1 = 1, i2 = 1;
	while (i0 <= n && i1 <= n && i2 <= n) {
		osoba a = osoby[0][i0];
		osoba b = osoby[1][i1];
		osoba c = osoby[2][i2];
		// cout << a << " " << b << " " << c << "\n";
		if (zbalansowana(a, b, c)) {
			cout << a.x + b.y + c.z << "\n";
			return 0;
		}
		if (a.y >= b.y || a.z >= c.z) wywal[a.kto] = true, i0++;
		if (b.x >= a.x || b.z >= c.z) wywal[b.kto] = true, i1++;
		if (c.x >= a.x || c.y >= b.y) wywal[c.kto] = true, i2++;
	}
	cout << "-1\n";

	return 0;
}
