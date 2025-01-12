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
	
	int q; cin >> q;
	string A; cin >> A;
	while (q--)
	{
		string x; cin >> x;
		if (x == "0" && A != "0")
			cout << "NIE\n";
		else if (x == "0" && A == "0")
			cout << "0\n";
		else
		{
			int n = A.size();
			int m = x.size();
			
			if (n >= m)
			{
				for (int i=1; i<=n-m; i++)
					x += "0";
				if (x >= A)
					cout << n-m << "\n";
				else cout << n-m+1 << "\n";
			}
			else
				cout << "0\n";
		}
	}

    return 0;
}
