/*
	Zadanie "Lizak" z XVIII OI
*/
#include <bits/stdc++.h>
using namespace std;

const int Mxp = 2e6+3, Mxn = 1e6+3;
vector<pair<int, int>> przedzial(Mxp);
char smak[Mxn];

void Spamietaj(int l, int r, int k)
{
	przedzial[k] = make_pair(l, r);
	if (k >= 3)
	{
		if (smak[l] == 'T')
			Spamietaj(l+1, r, k-2);
		else if (smak[r] == 'T')
			Spamietaj(l, r-1, k-2);
		else
			Spamietaj(l+1, r-1, k-2);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int cena = 0;
	int n, m; cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		cin >> smak[i];
		if (smak[i] == 'W') cena++;
		else cena += 2; 
	}
	Spamietaj(1,n,cena);
	int l = -1, r = -1;
	for (int i=1; i<=n; i++)
		if (smak[i] == 'W')
		{
			if (l == -1) l = i;
			r = i; 
		}

	if (l != -1 && r < n-l+1)
		Spamietaj(l+1, n, cena-2*l+1);
	else if (r != -1)
		Spamietaj(1, r-1, cena-2*(n-r)-1);

	/*for (int i=1; i<=cena; i++)
		cout<<i<<"| ("<<przedzial[i].first<<", "<<przedzial[i].second<<")\n";*/

	for (int i=1; i<=m; i++)
	{
		int k; cin >> k;
		if (k > 2*n || przedzial[k] == make_pair(0,0)) cout<<"NIE\n";
		else cout<<przedzial[k].first<<" "<<przedzial[k].second<<"\n";
	}
	
	return 0;
}