/*
	Zadanie "Liczby Ryby" z MPSŚPZ 2021 OPEN
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	if (n <= 2) cout << 0 << " " << 0 << " " << 0 << "\n";
	else cout << n-2 << " " << n-2 << " " << 1 << "\n";
	
	return 0;
}