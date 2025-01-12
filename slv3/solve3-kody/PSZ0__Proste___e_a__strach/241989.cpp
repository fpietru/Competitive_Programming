#include <bits/stdc++.h>
using namespace std;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	if ((n % 2 == 0 && n % 3 != 0) || (n % 7 == 6))
		cout << "TAK\n";
	else cout << "NIE\n";

    return 0;
}
