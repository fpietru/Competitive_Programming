/*
	Zadanie "Plakatowanie" z XV OI, etap I
	Obserwacja
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int ans = 0;
	stack<int> st;

	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		int s, w; cin >> s >> w;
		while (!st.empty() && st.top() > w)
			st.pop();
		if (st.empty() || w > st.top())
			st.push(w), ans++;
	}

	cout << ans << '\n';
	
	return 0;
}