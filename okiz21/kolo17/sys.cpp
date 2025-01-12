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

ll toINT(char c)
{
	if (c >= '0' && c <= '9')
		return (ll)(c-'0');
	if (c >= 'A' && c <= 'Z')
		return 10LL + (c-'A');
	return -69;
}

ll to10(string x, int base)
{
	ll res = 0, pot = 1LL;
	for (int i=(int)x.size()-1; i>=0; i--)
		res += toINT(x[i])*pot, pot *= base;
	return res;
}

char tochar(int x)
{
	if (x >= 0 && x <= 9)
		return '0' + x;
	if (x >= 10 && x <= 35)
		return 'A' + (x-10);
	return '$';
}

string toZ(ll x, int base)
{
	string res = "";
	while (x)
		res += tochar(x%base), x /= base;
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string x; int y, z; cin >> x >> y >> z;
	cout << toZ(to10(x, y), z) << "\n";

    return 0;
}
