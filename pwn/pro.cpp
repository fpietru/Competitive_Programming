#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int MxN = 5e5+55;
int w[MxN];
ll p[MxN];

ll areasum(int x, int r, int n)
{
	int a = max(0, x-r);
	int b = min(n-1, x+r);
	return p[b+1] - p[a];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		int x; cin >> x;
		p[i+1] = p[i] + (ll)x;
	}
	for (int i=0; i<n; i++)
		cin >> w[i];

	for (int i=0; i<n; i++)
	{
		if ((ll)w[i] > p[n])
		{
			cout << "-1 ";
			continue;
		}
		int low = 0, high = max(i, n-i-1);
		while (low < high)
		{
			int mid = (low + high) / 2;
			if (areasum(i, mid, n) >= (ll)w[i])
				high = mid;
			else low = mid + 1;
		}
		cout << low << " ";
	}
	cout << "\n";
		
	return 0;
}