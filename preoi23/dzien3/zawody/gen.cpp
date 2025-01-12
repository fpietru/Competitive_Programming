#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
	return a + rand() % (b-a+1);
}

int main(int argc, char *argv[]) {
	srand(atoi(argv[argc-1]));
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n = 10;
	cout << n << "\n";
	for (int i=1; i<=n; i++) {
		cout << rand(1, 5) << " " << rand(1, 5) << " " << rand(1, 5) << "\n";
	}

	return 0;
}
