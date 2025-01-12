#include <bits/stdc++.h>
using namespace std;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	if (n == 1)
		cout << 0 << "\n";
	else if (2 <= n && n <= 5)
		cout << 1 << "\n";
	else if (6 <= n && n <= 29)
		cout << 2 << "\n";
	else if (30 <= n && n <= 209)
		cout << 3 << "\n";
	else if (210 <= n && n <= 2309)
		cout << 4 << "\n";
	else if (2310 <= n && n <= 30029)
		cout << 5 << "\n";
	else if (30030 <= n && n <= 100000)
		cout << 6 << "\n";
	
    return 0;
}











