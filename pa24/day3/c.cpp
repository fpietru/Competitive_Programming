/*
	Franciszek Pietrusiak
	Zadanie: https://sio2.mimuw.edu.pl/c/pa-2024-1/p/obr/
*/
#include <bits/stdc++.h>
#define PB push_back
#define FR first
#define SD second
using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int MxN = 33;
ll d[MxN];
int n;

ll f(int h, int w, int st) {
	if (h > w) swap(h, w);
	if (h == 0) return 0;
	for (int i=st; i<=n; i++) {
		ll ileh = h / d[i];
		ll ilew = w / d[i];
		ll dh = d[i] * ileh;
		ll dw = d[i] * ilew;
		if (ileh > 0)
			return ileh*ilew + f(h-dh, dw, i+1) + f(dh, w-dw, i+1) + f(h-dh, w-dw, i+1);
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	ll h, w; cin >> h >> w;
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> d[i];
	
	if ((h % d[1]) != 0 || (w % d[1]) != 0) {
		cout << "-1\n";
		return 0;
	}
	
	reverse(d+1, d+1+n);
	cout << f(h, w, 1) << "\n";
	
	return 0;
}
