#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e3+33;
bool t[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, x, y;
	cin >> n >> x >> y;
	for (int i=0; i<n; i++)
	{
		int a, b; cin >> a >> b;
		for (int j=a; j<=b; j++)
			t[j] = 1;
	}

	vector<int> ans;
	for (int i=min(x,y); i<=max(x,y); i++)
		if (!t[i]) ans.push_back(i);	
	
	if (y > x)
		reverse(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (auto p : ans)
		cout << p << " ";
	cout << "\n";


	return 0;
}