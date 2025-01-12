#include <bits/stdc++.h>
using namespace std;
using pii = pair<char, char>;
#define FR first
#define SD second

string rangi = "AKDW098765432";

int poz(char c)
{
	for (int i=0; i<(int)rangi.size(); i++)
		if (c == rangi[i])
			return i;
	return -1;
}

int uklad(pii a, pii b)
{
	int p1 = poz(a.SD);
	int p2 = poz(b.SD);

	if (a.FR == b.FR && abs(p1 - p2) == 1)
		return 5;
	else if (a.FR != b.FR && abs(p1 - p2) == 1)
		return 4;
	else if (p1 == p2)
		return 3;
	else if (a.FR == b.FR && abs(p1 - p2) > 1)
		return 2;
	else return 1;
}

char porownaj_karty(pii a, pii b, pii c, pii d)
{
	if (poz(a.SD) > poz(b.SD)) swap(a, b);
	if (poz(c.SD) > poz(d.SD)) swap(c, d);
	
	if (poz(a.SD) < poz(c.SD))
		return 'A';
	else if (poz(a.SD) > poz(c.SD))
		return 'B';
	else // remis dla dużych
	{
		if (poz(b.SD) < poz(d.SD))
			return 'A';
		else if (poz(b.SD) > poz(d.SD))
			return 'B';
		else return 'R';
	}
}

char runda(pii a, pii b, pii c, pii d)
{
	int uA = uklad(a, b);
	int uB = uklad(c, d);
	
	if (uA > uB)
		return 'A';
	else if (uA < uB)
		return 'B';
	else
		return porownaj_karty(a, b, c, d);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	

	for (int i=1; i<=12; i++)
	{
		string s1, s2, s3, s4;
		cin >> s1 >> s2 >> s3 >> s4;
		pii a = {s1[0], s1[1]};
		pii b = {s2[0], s2[1]};
		pii c = {s3[0], s3[1]};
		pii d = {s4[0], s4[1]};
		
		char ans = runda(a, b, c, d);
		if (ans == 'A')
			cout << "Cyprian\n";
		else if (ans == 'B')
			cout << "Kamil\n";
		else cout << "Remis\n";
	}
	
	

    return 0;
}
