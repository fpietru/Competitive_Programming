/*
	Zadanie "Test Stefana" z MPSŚPZ 2021 OPEN
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 2e5+55;
int a[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k, odds = 0, sum = 0;
	cin >> n >> k;
	for (int i=0; i<n; i++)
	{
		int x; cin >> x;
		a[i] = x&1;
		sum += a[i];
		if (a[i] == 1) odds++;
	}

	if (sum&1)
	{
		cout << "0\n";
		return 0;
	}

	int R = 0;
	bool flag = 0;
	for (int i=0; i<n; i++)
	{
		if (a[i] == 0 && flag == 0)
			R++;

		if (a[i] == 1)
		{
			if (flag == 1) R++;
			flag ^= 1;
		}
	}

	cout << min(R + k, n - odds/2) << "\n";
	
	return 0;
}