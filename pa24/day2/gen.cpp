#include <bits/stdc++.h>
#define PB push_back
#define FR first
#define SD second
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n = 30000;
	cout << n << "\n";
	cout << n << "\n";
	for (int i=1; i<=n; i++)
		cout << i << " " << (i+1 <= n ? i+1 : 1) << "\n";
	
	cout << n-1;	
	for (int i=1; i<=n-1; i++)
		cout << i << " " << i+1 << "\n";	

	return 0;
}

