/*
	Link do zadania: https://atcoder.jp/contests/dp/tasks/dp_a
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e5+55;
int h[MxN], dp[MxN];

/*
	dp[i] = minimalny koszt jaki można uzyskać aby dostać się na pole i
*/

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> h[i];
	
	dp[1] = 0;
	dp[2] = abs(h[2] - h[1]);
	
	for (int i=3; i<=n; i++)
		dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));

	cout << dp[n] << "\n";

	return 0;
}