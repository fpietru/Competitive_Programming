#include <bits/stdc++.h>
using namespace std;

int tab[10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int ans = 0;
	for (int i=1; i<=100; i++)
		ans += tab[i];
		
	cout << ans << "\n";

	
	return 0;
};
