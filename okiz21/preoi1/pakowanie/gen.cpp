#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll rand(ll a, ll b) {
	return a + (ll)rand() % (b-a+1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n = rand(1, 10);
	cout << n << "\n";
	for (int i=1; i<=n; i++)
		cout << rand(1, 99) << " ";
	cout << "\n";
	
	return 0;
}



