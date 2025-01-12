#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	vector<int> vec(n);
	for (auto &it : vec) cin >> it;
	
	while (m--) {
		sort(vec.begin(), vec.end());
		string op; cin >> op;
		if (op == "podlej") {
			int k; cin >> k;
			for (int i=0; i<k; i++)
				vec[i]++;
		}
		else {
			int a, b; cin >> a >> b;
			int ans = 0;
			for (auto it : vec)
				if (a <= it && it <= b) ans++;
			cout << ans << "\n";
		}
	}

	return 0;
}
