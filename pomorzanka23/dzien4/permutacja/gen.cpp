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
	
	int n = rand(1, 1000);
	cout << n << "\n";
	for (int i=1; i<=n; i++)
		cout << rand(1, 100) << " ";
	cout << "\n";
	int q = rand(1, 100);
	cout << q << "\n";
	for (int i=1; i<=q; i++) {
		int p = rand(1, n);
		int x = rand(1, 100);
		cout << p << " " << x << "\n";
	}
	
	return 0;
}
