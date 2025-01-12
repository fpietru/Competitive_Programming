#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int INF = 1e9+7;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int h, w, n; cin >> h >> w >> n;
		pii X = {INF, -INF}, Y = {INF, -INF};
		for (int i=1; i<=n; i++) {
			int y, x; cin >> y >> x;
			Y = {min(Y.FR, y), max(Y.SD, y)};
			X = {min(X.FR, x), max(X.SD, x)};
		}
		int d1 = Y.FR - 1;
		int d2 = h - Y.SD;
		int d3 = X.FR - 1;
		int d4 = w - X.SD;
		cout << ((d1^d2^d3^d4) == 0 ? "Bitek\n" : "Bajtek\n");
	}
	
	return 0;
}
