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
	
	int ta = 0;
	int n = 10;
	for (int i=0; i<n; i++)
	{
		int ans = 0;
		for (int j=0; j<n; j++)
		{
			char c; cin >> c;
			if (c == '#')
				ans++;
		}
		if (ans > 0)
		{
			ta = ans;
		}
	}
	
	cout << ta << "\n";

    return 0;
}
