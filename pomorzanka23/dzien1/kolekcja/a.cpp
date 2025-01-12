#include <bits/stdc++.h>
using namespace std;

set<int> ans;
void solve(int pozostalo, int st, int suma) {
	ans.insert(suma + pozostalo-1);
	for (int i=st; i*i<=pozostalo; i++)
		if (pozostalo % i == 0)
			solve(pozostalo/i, i, suma+(i-1));
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	solve(n, 2, 0);
	
	cout << ans.size() << "\n";
	for (auto it : ans)
		cout << it << " ";
	cout << "\n";

	return 0;
}
