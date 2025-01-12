#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define PB push_back
#define FR first
#define SD second

int n, m, ans;

void go(int i, set<int> &wiersze, set<int> &kolumny) {
	if (i > n) {
		ans++;
		if (ans >= m) ans -= m;	
		return;
	}
	set<int> wiersze2 = wiersze;
	set<int> kolumny2 = kolumny; 
	
	for (auto y : wiersze)
		for (auto x : kolumny) {
			if (y == i || x == i) continue;
			wiersze2.erase(y);
			kolumny2.erase(x);
			go(i+1, wiersze2, kolumny2);
			wiersze2.insert(y);
			kolumny2.insert(x);
			
		}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	set<int> wiersze, kolumny;
	for (int i=1; i<=n; i++) {
		wiersze.insert(i);
		kolumny.insert(i);
	}
	
	go(1, wiersze, kolumny);

	cout << ans << "\n";
	
	return 0;
}
