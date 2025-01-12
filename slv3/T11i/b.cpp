#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e5+15;
int a[MxN], ileA[MxN], ileB[MxN];
set<int> st;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		ileB[a[i]]++;
		st.insert(a[i]);
	}
	
	int A = 0, B = st.size();
	int ans = B;
	for (int k=1; k<=n; k++)
	{
		ileA[a[k]]++;
		ileB[a[k]]--;
		if (ileA[a[k]] == 1)
			B--;
		if (ileB[a[k]] == 0)
			A++;
		ans = min(ans, A+B);
	}
	cout << ans << "\n";
	
	return 0;
}
