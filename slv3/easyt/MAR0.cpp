#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e3+33;
int t[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int p = 0;
	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		t[i] = x;
	}
	for (int i=0; i<q; i++)
	{
		int a, b; cin >> a >> b;
		set<int> st;
		for (int j=a; j<=b; j++)
			st.insert(t[j]);
		cout << st.size() << "\n";
	}
	
	return 0;
}