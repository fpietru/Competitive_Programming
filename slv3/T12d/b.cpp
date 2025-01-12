#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
	
	int a, b, c; cin >> a >> b >> c;
	
	if (a == b || a == c || b == c)
	{
		cout << "TAK\n";
		return 0;
	}
	
	int r1 = a - b;
	int r2 = a - c;
	int r3 = b - c;
	
	bool ans = 0;
	if (r1 >= 0)
		ans |= 1;
	if (r2 >= 0 && r2 % 3 == 0)
		ans |= 1;
	if (r3 >= 0 && r3 % 2 == 0)
		ans |= 1;
		
	cout << (ans ? "TAK\n" : "NIE\n");
	
    return 0;
}
