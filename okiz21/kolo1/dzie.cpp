#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> v;
	for (int i=1; i*i<=n; i++)
	{
		if (n % i == 0)
		{
			if (n/i == i)
				v.push_back(i);
			else
			{
				v.push_back(i);
				v.push_back(n/i);
			}
		}
	}

	sort(v.begin(), v.end());
	for (int p : v)
		cout << p << "\n";
	
	return 0;
}