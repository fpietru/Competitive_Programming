/*
Zadanie Cukiernia XXVIII OI, etap I  
Autor: Franek Pietrusiak
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FR first
#define SD second

struct element
{
	int val;
	bool red;
};

const int MxN = 3e5+7;
element arr[MxN][3]; // przechowuje wejscie
int redpos[MxN]; // przechowuje w ktorej kolumnie jest max z każdego rzedu
bool changed[MxN]; // przechowuje informacje czy na danym rzedzie były zmieniane maxy
int colsums[3] = {0,0,0}; // przechowuje sume liczb dla kazdej kolumny
ll p[3]; // przechowuje ilosc maxow na kolumne
int n, k=0, tmp_max, tmp_pos; // zmienne pomocnicze
ll sum=0; // wynik

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	// Wczytywanie
	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<3; j++)
		{
			cin >> arr[i][j].val;
			sum += arr[i][j].val;
			colsums[j] += arr[i][j].val;
		}

	// Znajdowanie czerwonych maxow
	for (int i=0; i<n; i++)
	{
		// Znajdowanie maxymalnej wartosci na wiersz
		int rmax_value = -1;
		for (int j=0; j<3; j++)
			rmax_value = max(rmax_value, arr[i][j].val);
	
		// Zaznaczanie w tablicy
		bool done=0;
		for (int j=0; j<3; j++)
		{
			if (arr[i][j].val == rmax_value && done == 0)
			{
				arr[i][j].red = 1;
				done = 1;
				p[j]++; 
				redpos[i] = j;
				sum -= arr[i][j].val;

			}
			else arr[i][j].red = 0;
		}
	}

	for (int k=0; k<3; k++)
	{
		// Sprawdzanie czy jakas kolumna nie ma zadnego maxa czerwonego
		int zero_count = 0, zero_pos = -1;
		for (int i=0; i<3; i++)
			if (p[i] == 0)
			{
				zero_count++;
				zero_pos = i;
			}

		if (zero_count > 0 && colsums[zero_pos] != 0)
		{
			pair<int, int> DELRED, NEWRED;
			int tmp_diff, min_diff = 1e9+12;
			// Szukanie minimalnej roznicy po miedzy maxem a liczba z kolumny, która nie ma żadnego maxa 
			for (int i=0; i<n; i++)
			{
				tmp_diff = arr[i][redpos[i]].val - arr[i][zero_pos].val;
				if (min_diff >= tmp_diff && p[redpos[i]] >= 1 && !changed[i])
				{
					min_diff = tmp_diff;
					DELRED = make_pair(i, redpos[i]);
					NEWRED = make_pair(i, zero_pos);	
				}
			}
			// Zaznaczanie na tablicach i zmienianie wyniku
			if (min_diff != 1e9+12)
			{
				sum += min_diff;

				arr[NEWRED.FR][NEWRED.SD].red = 1;
				arr[DELRED.FR][DELRED.SD].red = 0;
				
				p[DELRED.SD]--;
				p[NEWRED.SD]++;
					
				redpos[NEWRED.FR] = NEWRED.SD;

				changed[NEWRED.FR] = 1;
			}
		}
	}

	cout<<sum<<"\n";

	return 0;
}
