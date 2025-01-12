#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ld = long double;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ld a, b, A, B;
	cin >> a >> b >> A >> B;
	
	ld s1 = A / a;
	ld s2 = B / b;
	
	ld mi = min(s1, s2);
	ld na = round(a * mi);
	ld nb = round(b * mi);
	
	cout << fixed << setprecision(0) << na << " " << nb << "\n"; 
	
    return 0;
}
