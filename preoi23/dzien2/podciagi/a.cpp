#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 5e5+5;
constexpr int MxW = 1e6+6;
constexpr int MOD = 1e9+7;
int dp[MxN], tab[MxW], wart[MxN];

inline int odejm(int a, int b) {
	return (a - b + MOD) % MOD;
}

inline int mult(int a, int b) {
	return (1LL * a * b) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> wart[i];
		
	dp[n+1] = 1;
	for (int i=n; i>=1; i--) {
		dp[i] = odejm(mult(2, dp[i+1]), tab[wart[i]]);
		tab[wart[i]] = dp[i+1];
	}
	cout << dp[1] << "\n";
	
	return 0;
}
