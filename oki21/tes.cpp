/*
	Zadanie "Test na inteligencję" z XVII OI
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	/*początek wczytywania*/
	int n; cin >> n;
	vector<int> ciag(n);
	for (int i=0; i<n; i++) cin >> ciag[i];
	int q; cin >> q;
	vector<int> n_y(q);
	vector<vector<int>> zapytanie(q);
	for (int i=0; i<q; i++)
	{
		cin >> n_y[i];
		for (int j=0; j<n_y[i]; j++)
		{
			int c; cin >> c;
			zapytanie[i].push_back(c);
		}
	}
	/*koniec wczytywania*/
	vector<vector<unsigned int>> indeksy(1e6+3);
	for (int i=0; i<n; i++)
		indeksy[ciag[i]].push_back(i);

	for (int i=0; i<q; i++)
	{
		bool ans = 1;
		int minimum = 0;
		if (indeksy[zapytanie[i][0]].size() > 0)
			minimum = indeksy[zapytanie[i][0]][0];
		else ans = 0/*, cout<<"E1\n"*/;

		if (ans)
		{
			for (int w=1; w<n_y[i]; w++)
			{
				if (indeksy[zapytanie[i][w]].size() > 0)
				{
					if (indeksy[zapytanie[i][w]].back() > minimum)
					{
						if (indeksy[zapytanie[i][w]].size() > 1)
						{
							unsigned int poc = 0, sr, goal;
							unsigned int kon = indeksy[zapytanie[i][w]].size()-1;
							while (poc <= kon)
							{
								sr = (poc + kon) / 2;
								if (sr < 0 || sr >= indeksy[zapytanie[i][w]].size())
									break;
								if (indeksy[zapytanie[i][w]][sr] <= minimum)
									poc = sr + 1;
								else
									goal = sr, kon = sr - 1;
							}
							minimum = indeksy[zapytanie[i][w]][goal];
						}
						else
						{
							if (indeksy[zapytanie[i][w]][0] > minimum)
								minimum = indeksy[zapytanie[i][w]][0];
							else
							{
								ans = 0/*, cout<<"E2\n"*/;
								break;
							}
						}
					}
					else
					{
						ans = 0/*, cout<<"E3\n"*/;
						break;
					}
				}
				else
				{
					ans = 0/*, cout<<"E4\n"*/;
					break;
				}
			}
		}
		cout<<(ans ? "TAK\n" : "NIE\n");
	}

	return 0;
}