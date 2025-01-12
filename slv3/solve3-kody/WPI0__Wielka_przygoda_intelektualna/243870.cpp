#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int a, b; cin >> a >> b;
	
	if (a < b)
		swap(a, b);
	
	if ((a - b) % 2 != 0)
		cout << "TAK\n";
	else cout << "NIE\n";

    return 0;
}
