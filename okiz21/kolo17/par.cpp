/*
	Zadanie "Liczby Parzystocyfrowe" z XIV OIJ
*/
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

string to5(ll x)
{
	string res = "";
	while (x)
	{
		res += to_string(x%5);
		x /= 5;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	ll n; cin >> n;
	for (auto p : to5(n))
		cout << 2*(p-'0');
	cout << "\n";		

    return 0;
}
