//2022-09-26
//author: Marcin Rolbiecki
#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5;

long long n, a, b, sum;

pair <long long, int> W [maxN];

int main () {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> a >> b;
	
	for (int i = 0; i < n; i++) {
		cin >> W[i].first;
		W[i].second = i;
	}
		
	sort (W, W + n, greater < pair <long long, int>>());
	
	int l = 0, r = 0;
	while (r < n && sum < a)
		sum += W[r++].first;

	while (sum > b && r < n) {
		
		sum -= W[l++].first;
		sum += W[r++].first;
	}
	
	if (sum > b || sum < a) {
		cout << -1;
		return 0;
	}
	
	cout << r - l << endl;
	
	for (int i = r-1; i >= l; i--)
		cout << W[i].second << ' ';
	
	cout << "\n";
	return 0;
}
