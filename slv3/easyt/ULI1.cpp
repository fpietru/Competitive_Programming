#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+66;
int add[MxN], del[MxN], t[MxN];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, x, y, mx = 0;
	cin >> n >> x >> y;
	for (int i=0; i<n; i++)
	{
		int a, b; cin >> a >> b;
		add[a]++;
		del[b]++;
		mx = max(mx, b);
	}

	int sum = 0;
	for (int i=1; i<=mx; i++)
	{
		sum += add[i];
		t[i] = sum;
		sum -= del[i];
	}

	vector<int> ans;
	for (int i=min(x,y); i<=max(x,y); i++)
		if (t[i] == 0) ans.push_back(i);	
	
	if (y > x)
		reverse(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (auto p : ans)
		cout << p << " ";
	cout << "\n";

/*	for (int i=1; i<=mx; i++)
		cout << t[i] << " ";
	cout << "\n";*/

	return 0;
}