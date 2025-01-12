#include <bits/stdc++.h>
using namespace std;
#define PB push_back

int rand(int a, int b) {
	return a + rand() % (b-a+1);
}

int main(int argc, char *argv[]) {
	srand(atoi(argv[argc-1]));
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n = 10; //rand(1, 10);
	cout << n << "\n";
	for (int i=1; i<=n; i++)
		cout << rand(1, 50000) << "\n";
	
	int q = 10000; //rand(1, 10);
	cout << q << "\n";
	for (int i=1; i<=q; i++)
		cout << rand(0, 1e9) << "\n";

	return 0;
}
