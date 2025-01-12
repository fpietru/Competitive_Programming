#include "cgdzlib.h"
#include <bits/stdc++.h>
using namespace std;

int n;

int check(int x, int k) {
	for (int i=1; i<=n; i++)
		if (i != x && f(x, i, k)) return i;
	return 0;
}

int main(void) {

	n = inicjuj();
	if (n == 1) {
		odpowiedz(1);
		return 0;
	}
	
	int low = 1;
	int high = n+1;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (check(1, mid)) low = mid + 1;
		else high = mid;
	}

	int pierwszy = check(1, low-1);
	int drugi = check(pierwszy, n-1);

	if (g(pierwszy, drugi)) swap(pierwszy, drugi);
	// cout << pierwszy << " " << drugi << "\n";
	
	odpowiedz(pierwszy);
	
    return 0;
}
