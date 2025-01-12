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
	
	map<char, int> mp;
	for (char c : s)
		mp[c]++;
	
	int mx = 0;
	for (auto p : mp)
		mx = max(mx, p.second);
		
	if (mx == 3)
	{
		cout << "1\n";
		return 0;
	}
	
	int ans = 6;
	for (auto p : mp)
		ans /= p.second;
	
	cout << ans << "\n";

    return 0;
}
