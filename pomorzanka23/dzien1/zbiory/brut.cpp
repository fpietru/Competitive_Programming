#include <bits/stdc++.h>
using namespace std;
#define PB push_back

vector<int> A;
bool flag;

void go(int x) {
	if (flag || x < 0) return;
	for (auto ai : A)
		if (x % ai == 0) {
			flag = true;
			return;
		}
	for (auto ai : A)
		go(x-ai);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	vector<int> B;
	for (int i=1; i<=n; i++) {
		int ai; cin >> ai;
		A.PB(ai);
	}
	sort(A.begin(), A.end());
	for (auto ai : A) {
		bool dzieli = false;
		for (auto bi : B) {
			if (ai % bi == 0) {
				dzieli = true;
				break;
			}
		}
		if (dzieli == false)
			B.PB(ai);
	}
	A = B;

	int q; cin >> q;
	for (int i=1; i<=q; i++) {
		int x; cin >> x;
		flag = false;
		go(x);
		cout << (flag ? "TAK\n" : "NIE\n");
	}
	

	return 0;
}
