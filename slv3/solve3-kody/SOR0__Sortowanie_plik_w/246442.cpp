#include <bits/stdc++.h>
using namespace std;
/*#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}*/

struct pakiet
{
	// [nazwa][liczba].[rozszerzenie]
	int id;
	string nazwa;
	string liczba;
	string rozsz;
};
constexpr int MxN = 1e4+4;
pakiet pakiety[MxN];
string oryginal[MxN];

bool cmp(pakiet a, pakiet b)
{
	if (a.liczba.size() > 0 && a.liczba.size() > 0)
	{
		if (a.nazwa < b.nazwa)
			return 1;
		else if (a.nazwa < b.nazwa)
			return 0;
		else
		{
			if (a.liczba.size() < b.liczba.size())
				return 1;
			else if (a.liczba.size() > b.liczba.size())
				return 0;
			else // a.liczba.size() == b.liczba.size()
			{
				if (a.liczba < b.liczba)
					return 1;
				else if (a.liczba > b.liczba)
					return 0;
				else
				{
					if (a.rozsz < b.rozsz)
						return 1;
					else if (a.rozsz > b.rozsz)
						return 0;
					else
						return (oryginal[a.id] < oryginal[b.id]);
				}
			}
		}
	}
	else
		return (oryginal[a.id] < oryginal[b.id]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		string s; cin >> s;
		oryginal[i] = s;
		pakiety[i].id = i;
		int m = s.size();
		string tmp = "";
		int j = m-1;
		while (s[j] != '.')
			tmp += s[j], j--;
		reverse(tmp.begin(), tmp.end());
		pakiety[i].rozsz = tmp;
		j--;
		tmp = "";
		while (j >= 0 && '0' <= s[j] && s[j] <= '9')
			tmp += s[j], j--;
		while (tmp.back() == '0')
			tmp.pop_back();
		reverse(tmp.begin(), tmp.end());
		pakiety[i].liczba = tmp;
		tmp = "";
		while (j >= 0)
			tmp += s[j], j--;
		reverse(tmp.begin(), tmp.end());
		pakiety[i].nazwa = tmp;
	}
	
	sort(pakiety+1, pakiety+n+1, cmp);
	
	for (int i=1; i<=n; i++)
	{
		// deb(pakiety[i].nazwa, pakiety[i].liczba, pakiety[i].rozsz);
		cout << oryginal[pakiety[i].id] << "\n";
	}

    return 0;
}
