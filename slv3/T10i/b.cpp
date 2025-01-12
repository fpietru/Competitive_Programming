#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+6;
int pA[MxN], pB[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	string s; cin >> s;
	int cA = 0, cB = 0;
	for (int i=1; i<=n; i++)
	{
		char c = s[i-1];
		if (c == 'A')
			cA++;
		else
			cB++;
		pA[i] = cA;
		pB[i] = cB;
	}

	int ans = 1e9+7;
	for (int i=0; i<=n-k; i++)
	{
		int sA = pA[i+k] - pA[i];
		int sB = pB[i+k] - pB[i];
		ans = min(ans, abs(sA-sB));
	}

	cout << ans << "\n";
	
	return 0;
}