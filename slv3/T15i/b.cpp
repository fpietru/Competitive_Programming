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

int a[4];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		char x; cin >> x;
		if (x == 'J')
			a[0]++;
		if (x == 'G')
			a[1]++;
		if (x == 'B')
			a[2]++;
	}
	
	sort(a, a+3);
	
	cout << ((a[2] - a[0]) + (a[2] - a[1])) << "\n";
	
    return 0;
}
