#include <iostream>
using namespace std;

constexpr int MxN = 11200000;
int a[MxN+2];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	
	int ans = 0;
	for (int i=1; i<=n; i++)
	{
		int p = i;
		if (a[p] > 0)
		{
			ans++;
			int st = p;
			while (1)
			{
				a[p] *= -1;
				p = a[p] * (-1);	
				if (p == st)
					break;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}