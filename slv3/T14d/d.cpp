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

	int c, k; cin >> c >> k;
	if (c == k)
		cout << c << "\n";
	else if (c > k)
	{
		int r = c - k;
		cout << r << "+1*0+" << k << "\n";
	}
	else
	{
		if (c == 0)
			cout << "NIE\n";
		else
		{
			int r = k - c;
			cout << "1+0*" << r+1 << "+" << c-1 << "\n";
		}
	}

    return 0;
}
