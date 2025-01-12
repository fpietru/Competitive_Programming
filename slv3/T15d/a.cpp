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
	
	bool macyfre = 0;
	bool maspec = 0;
	bool mamala = 0;
	bool mawielka = 0;
	
	for (auto c : s)
	{
		if (c >= '0' && c <= '9')
			macyfre = 1;
		if (c == '@' || c == '$' || c == '#' || c == '*')
			maspec = 1;
		if (c >= 'A' && c <= 'Z')
			mawielka = 1;
		if (c >= 'a' && c <= 'z')
			mamala = 1;
	}
	
	if (s.size() >= 8 && macyfre && maspec && mawielka && mamala)
		cout << "TAK\n";
	else cout << "NIE\n"; 

    return 0;
}
