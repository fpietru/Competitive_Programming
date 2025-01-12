#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int rand(int a, int b) {
	return a + rand() % (b-a+1);
}

int main(int argc, char *argv[]) {
	srand(atoi(argv[argc-1]));
	ios_base::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	
	int mxV = 1e9;
	
	int n = rand(1, 1000);
	int q = rand(1, 1000);
	cout << n << " " << q << "\n";
	for (int i=1; i<=n; i++)
		cout << rand(1, mxV) << " ";
	cout << "\n";
	
	while (q--) {
		int op = rand(1, 3);
		if (op == 1) {
			cout << "aktualizacja ";
			int st = rand(1, n);
			int ed = rand(st, n);
			int val = rand(1, mxV);
			cout << st << " " << ed << " " << val << "\n";
		}
		else if (op == 2) {
			cout << "maksymalizacja ";
			int st = rand(1, n);
			int ed = rand(st, n);
			cout << st << " " << ed << "\n";
		}
		else if (op == 3) {
			cout << "lustracja ";
			int st = rand(1, n);
			int ed = rand(st, n);
			int val = rand(1, mxV);
			cout << st << " " << ed << " " << val << "\n";
		}
	}
	
	return 0;
}
