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
	
	int pam1 = (s[0]-'0')*100+(s[1]-'0')*10+(s[0]-'0');
	int pam2 = (s[2]-'0')*100+(s[1]-'0')*10+(s[2]-'0');
	int licz = (s[0]-'0')*100+(s[1]-'0')*10+(s[2]-'0');

	if (abs(licz-pam1) == 0 || abs(licz-pam2) == 0)
		cout << "TAK\n";
	else if (abs(licz-pam1) == 1 || abs(licz-pam2) == 1)
		cout << "PRAWIE\n";
	else cout << "NIE\n";

    return 0;
}
