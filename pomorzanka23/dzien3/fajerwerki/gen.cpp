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
	int s = rand(1, 10);
	cout << n << " " << s << "\n";
	for (int i=1; i<=n; i++) {
		cout << rand(-20, 20) << " " << rand(-20, 20) << "\n";
	}
	
	return 0;
}
