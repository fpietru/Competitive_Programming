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

string zliczbuj(string x)
{
	reverse(x.begin(), x.end());
	while (x.size() > 1 && x.back() == '0')
		x.pop_back();
	reverse(x.begin(), x.end());
	return x;
}

struct pakiet
{
	// [nazwa][liczba].[rozszerzenie]
	string nazwa;
	string liczba;
	string rozsz;
	
	bool operator<(const pakiet& p) const
	{
		// deb(nazwa, liczba, rozsz);
		// deb(p.nazwa, p.liczba, p.rozsz);
		if (liczba.size() > 0 && p.liczba.size() > 0)
		{
			if (nazwa < p.nazwa)
				return 1;
			else if (nazwa > p.nazwa)
				return 0;
			else
			{
				string L1 = zliczbuj(liczba);
				string L2 = zliczbuj(p.liczba);
				
				if (L1.size() < L2.size())
					return 1;
				else if (L1.size() > L2.size())
					return 0;
				else
				{
					if (L1 < L2)
						return 1;
					else if (L1 > L2)
						return 0;
					else
					{
						if (rozsz < p.rozsz)
							return 1;
						else if (rozsz > p.rozsz)
							return 0;
						else
						{
							if (nazwa+liczba < p.nazwa+p.liczba)
								return 1;
							else if (nazwa+liczba > p.nazwa+p.liczba)
								return 0;
							else
							{
								return (rozsz < p.rozsz);
							}
						}
					}
				}
			}
		}
		else
		{
			if (nazwa+liczba < p.nazwa+p.liczba)
				return 1;
			else if (nazwa+liczba < p.nazwa+p.liczba)
				return 0;
			else
			{
				return rozsz < p.rozsz;
			}
		}
	}
};
constexpr int MxN = 1e4+4;
pakiet pakiety[MxN];
string oryginal[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		string s; cin >> s;
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
		reverse(tmp.begin(), tmp.end());
		pakiety[i].liczba = tmp;
		tmp = "";
		while (j >= 0)
			tmp += s[j], j--;
		reverse(tmp.begin(), tmp.end());
		pakiety[i].nazwa = tmp;
	}
	
	// for (int i=1; i<=n; i++)
	//	deb(pakiety[i].nazwa, pakiety[i].liczba, pakiety[i].rozsz);
	
	
	sort(pakiety+1, pakiety+n+1);
	
	for (int i=1; i<=n; i++)
	{
		cout << pakiety[i].nazwa << pakiety[i].liczba << "." << pakiety[i].rozsz << "\n";
	}

    return 0;
}
