#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second
/*#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}*/

constexpr int MxN = 1e4+4;
vector<pair<pair<string, pair<int, string>>, pair<string, string>>> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		string s, nazwa = "", liczba = "", rozsz = "";
		cin >> s;
		int m = s.size();
		int j = m-1;
		while (s[j] != '.')
			rozsz += s[j], j--;
		reverse(rozsz.begin(), rozsz.end());
		j--;
		while (j >= 0 && '0' <= s[j] && s[j] <= '9')
			liczba += s[j], j--;
		while (liczba.size() > 0 && liczba.back() == '0')
			liczba.pop_back();
		reverse(liczba.begin(), liczba.end());
		while (j >= 0)
			nazwa += s[j], j--;
		reverse(nazwa.begin(), nazwa.end());
		v.push_back({{nazwa, {liczba.size(), liczba}}, {rozsz, s}});
	}
	
	sort(v.begin(), v.end());
	
	for (auto p : v)
		cout << p.SD.SD << "\n";

    return 0;
}
