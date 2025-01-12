#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ld = long double;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ld pi = M_PI;
	ld R; cin >> R;
	cout << fixed << setprecision(6) << pi * (R * R) << "\n";	

    return 0;
}
