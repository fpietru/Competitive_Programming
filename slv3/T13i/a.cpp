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
	
	bool ans = 1;
	string s; cin >> s;
	for (int i=0; i<3; i++)
		if (s[i]-'0' >= 5)
			ans = 0;
	cout << (ans ? "TAK\n" : "NIE\n");

    return 0;
}
