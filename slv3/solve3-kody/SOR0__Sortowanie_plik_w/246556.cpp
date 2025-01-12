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
	string nazwa;
	string liczba;
	string rozsz;
	string wszystko;
	
	bool operator<(const pakiet& p) const
	{
		if (liczba.size() > 0 && p.liczba.size() > 0)
		{
			if (nazwa < p.nazwa)
				return 1;
			else if (nazwa > p.nazwa)
				return 0;
			else
			{
				if (liczba.size() < p.liczba.size())
					return 1;
				else if (liczba.size() > p.liczba.size())
					return 0;
				else
				{
					if (liczba < p.liczba)
						return 1;
					else if (liczba > p.liczba)
						return 0;
					else
					{
						if (rozsz < p.rozsz)
							return 1;
						else if (rozsz > p.rozsz)
							return 0;
						else
						{
							return (wszystko < p.wszystko);
						}
					}
				}
			}
		}
		else
		{
			return (wszystko < p.wszystko);
		}
	}
};
constexpr int MxN = 1e4+4;
pakiet pakiety[MxN];
string oryginal[MxN];

/*
bool cmp(pakiet a, pakiet b)
{
	pair<pair<string, string>, pair<string, string>> A = {{a.nazwa, a.liczba}, {a.rozsz, oryginal[a.id]}};
	pair<pair<string, string>, pair<string, string>> B = {{b.nazwa, b.liczba}, {b.rozsz, oryginal[b.id]}};
	return A < B;
}*/

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		string s; cin >> s;
		pakiety[i].wszystko = s;
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
	
	sort(pakiety+1, pakiety+n+1);
	
	for (int i=1; i<=n; i++)
	{
		// deb(pakiety[i].nazwa, pakiety[i].liczba, pakiety[i].rozsz);
		cout << pakiety[i].wszystko << "\n";
	}

    return 0;
}
