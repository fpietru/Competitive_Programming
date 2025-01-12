#include <bits/stdc++.h>
using namespace std;

bool solve(int a, int b)
{
/*
	if (b == 0)
	{
		if (a % 2 == 0) return 0;
		else return 1;
	}
	*/
	if (a % 2 == 1 || b % 2 == 1)
		return 1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int a, b; cin >> a >> b;
	
	if (a < b)
		swap(a, b);
	
	cout << (solve(a, b) ? "TAK\n" : "NIE\n");

    return 0;
}
