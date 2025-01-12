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
	
	string s; cin >> s;
	for (char i='a'; i<='z'; i++)
	{
		int licz = 0;
		for (int j=0; j<s.size(); j++)
			if (s[j] == i)
				licz++;
		if (licz > 0)
		{
			//for (int j=0; j<licz; j++)
			//	cout << i << "";
			cout << i << "\n";
			break;
		}
	}

    return 0;
}
