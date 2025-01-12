/*
	Zadanie "Sorry, taki mamy klimat" z MPSŚPZ 2021 OPEN
	Drugi sposób na implementacje
*/
#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

struct pal { int h; int pos; int st; };
constexpr int MxN = 5e5+55, INF = 1e9+9;
int d[MxN], h[MxN], range[MxN];
bool operator<(const pal &a, const pal &b) { return a.h < b.h; }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++) cin >> d[i];
	for (int i=0; i<n; i++) cin >> h[i];

	stack<pal> st;
	for (int i=0; i<n; i++)	
	{
		while (!st.empty() && st.top().h < h[i])
		{
			range[st.top().pos] = i - st.top().st;
			st.pop();
		}

		if (st.empty())
			st.push({h[i], i, -INF});
		else
		{
			pal t = st.top();
			st.push({h[i], i, t.pos});
		}
	}

	while (!st.empty())
	{
		range[st.top().pos] = INF - st.top().st;
		st.pop();
	}

	sort(d, d+n);
	sort(range, range+n);

	int i = 0, j = 0, ans = 0;
	while (i < n && j < n)
	{
		if (range[i] > d[j])
			ans++, i++, j++;
		else i++;
	}

	cout << ans << "\n";

	return 0;
}