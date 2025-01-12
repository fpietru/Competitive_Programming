/*
	Zadanie "Sorry, taki mamy klimat" z MPSŚPZ 2021 OPEN
*/
#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

constexpr int MxN = 5e5+55, INF = 1e9+9;
int d[MxN], h[MxN], L[MxN], R[MxN];
int space[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++) cin >> d[i];
	for (int i=0; i<n; i++) cin >> h[i];

	// Fajny sposób na znajdowanie najbliższego większego elementu w ciągu po prawo i lewo
	// O(n)
	stack<pair<int, int>> st;
	for (int i=0; i<n; i++)
	{
		while (!st.empty() && st.top().FR <= h[i])
			st.pop();
		if (!st.empty()) L[i] = st.top().SD;
		else L[i] = -INF;
		st.push({h[i], i});
	}
	
	while (!st.empty()) st.pop();
	
	for (int i=n-1; i>=0; i--)
	{
		while (!st.empty() && st.top().FR <= h[i])
			st.pop();
		if (!st.empty()) R[i] = st.top().SD;
		else R[i] = INF;
		st.push({h[i], i});
	}

	for (int i=0; i<n; i++)
		space[i] = R[i] - L[i];

	sort(d, d+n);
	sort(space, space+n);

	int i=0, j=0, ans = 0;
	while (i < n && j < n)
	{
		if (space[i] > d[j]) ans++, i++, j++;
		else i++;
	}

	cout << ans << "\n";

	return 0;
}