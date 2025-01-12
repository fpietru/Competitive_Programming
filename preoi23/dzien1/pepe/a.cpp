#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second
#define PB push_back

struct odcinek {
	int a, b, c;
};
struct punkt {
	int x, y;
	int dl; 
	int typ; // 1-poziomy-pocz 2-pionowy(dolny), 3-poziomy-kon
};
ostream& operator<< (ostream& os, punkt p) {
	os << "(" << p.x << "," << p.y << ") " << p.dl << " " << p.typ;
	return os;
}
constexpr int MxN = 1e5+5;
odcinek pionowe[MxN];
odcinek poziome[MxN];
int n, m;

bool cmp(punkt a, punkt b) {
	if (a.x == b.x) return a.typ < b.typ;
	return a.x < b.x;
}

bool jestprzeciecie(int a) {
	vector<punkt> punkty;
	for (int i=1; i<=n; i++) {
		odcinek o = poziome[i];
		int dl = o.b - o.a;		
		if (dl >= 2*a) {
			int x1 = o.a + a;
			int x2 = o.b - a;
			int y = o.c;
			punkt p1 = {x1, y, 0, 1};
			punkt p2 = {x2, y, 0, 3};
			punkty.PB(p1);
			punkty.PB(p2);
		}
	}
	for (int i=1; i<=m; i++) {
		odcinek o = pionowe[i];
		int dl = o.b - o.a;
		if (dl >= 2*a) {
			int y = o.a + a;
			int x = o.c;
			punkt p = {x, y, dl-2*a, 2};
			punkty.PB(p);
		}
	}
	
	sort(punkty.begin(), punkty.end(), cmp);
	
	multiset<int> st;
	for (auto p : punkty) {
		if (p.typ == 1)
			st.insert(p.y);
		else if (p.typ == 2) {
			auto it = st.lower_bound(p.y);
			if (it != st.end() && (*it) <= p.y+p.dl)
				return true;
		}
		else st.erase(st.find(p.y));
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		int x1, x2, y; cin >> x1 >> x2 >> y;
		poziome[i] = {x1, x2, y};
	}
	for (int i=1; i<=m; i++) {
		int y1, y2, x; cin >> y1 >> y2 >> x;
		pionowe[i] = {y1, y2, x};
	}
	
	int low = 0;
	int high = 1e9+7;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (jestprzeciecie(mid))
			low = mid + 1;
		else high = mid;
	}
	
	cout << max(0, low - 1) << "\n";
	
	return 0;
}
