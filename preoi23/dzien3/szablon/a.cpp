#include <bits/stdc++.h>
using namespace std;

#define PB push_back

constexpr int MxN = 1e6+6;
constexpr int MOD = 1e9+7;
int ps[MxN], dp[MxN];

inline int dodaj(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, k; cin >> n >> k;
	string s; cin >> s;
	
	ps[0] = 0;
	for (int i=1; i<n; i++) {
		int t = ps[i-1];
		while (t > 0 && s[t] != s[i])
			t = ps[t-1];
		if (s[t] == s[i]) t++;
		ps[i] = t;
	}
	
	vector<int> prefsuf;
	for (int i=ps[n-1]; i>0; i=ps[i-1])
		prefsuf.PB(i);
		
	dp[n] = 1;
	for (int i=n+1; i<=k; i++) {
		dp[i] = dp[i-n];
		for (auto dl : prefsuf)
			dp[i] = dodaj(dp[i], dp[i-(n-dl)]);
	}
			
	cout << dp[k] << "\n";

	return 0;
}
