#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
	return a + rand() % (b-a+1);
}

int main(int argc, char *argv[]) {
	srand(atoi(argv[argc-1]));
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n = rand(1, 10);
	int m = rand(1, 5);
	cout << n << " " << m << "\n";
	for (int i=1; i<=n; i++)
		cout << rand(1, 10) << " ";
	cout << "\n";
	for (int i=1; i<=m; i++) {
		int op = rand(1, 2);
		if (op == 1) {
			cout << "podlej " << rand(1, n) << "\n";
		}
		else {
			int a = rand(1, 10);
			int b = rand(a, 10);
			cout << "zbieraj " << a << " " << b << "\n";
		}
	}
	
	return 0;
}
