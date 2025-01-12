#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define FR first
#define SD second
#define PB push_back

int rand(int a, int b) {
	return a + rand() % (b-a+1);
}

int main(int argc, char *argv[]) {
	srand(atoi(argv[argc-1]));
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n = 1e5;//rand(1, 1e5);
	cout << n << "\n";
	// int k = atoi(argv[argc-1]);
	
	vector<int> vec;
	for (int i=1; i<=n; i++)
		vec.PB(i);
	
	random_shuffle(vec.begin(), vec.end());
	
	/*
	do {
		k--;
		if (k <= 0)
			break;
	} while (next_permutation(vec.begin(), vec.end())); */ 


	for (auto it : vec)
		cout << it << " ";
	cout << "\n";

	return 0;
}
