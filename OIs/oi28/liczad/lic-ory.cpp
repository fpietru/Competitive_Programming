#include <bits/stdc++.h>
using namespace std;

int n, z;
string str_w, str_z;
const int MxN = 1e5+3;
int Wewnetrzny[MxN];
int Zewnetrzny[MxN];
int Suma[MxN];

void Sumuj()
{
	int r = 0;
	for (int i=n-1; i>=0; i--)
	{
		int a = Wewnetrzny[i];
		int b = Zewnetrzny[i];
		int c = a + b + r;
		r = c / 10;
		Suma[i] = c % 10;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> z;
	cin >> str_w >> str_z;
	Wewnetrzny[0] = 0;
	Zewnetrzny[0] = 0;
	for (int i=0; i<n-1; i++)
	{
		Wewnetrzny[i+1] = str_w[i] - '0';
		Zewnetrzny[i+1] = str_z[i] - '0';
	}

	char o;
	int p, v;
	bool changed = 1;
	while (z--)
	{
		cin >> o;
		if (o == 'S')
		{
			cin >> p;
			if (changed)
			{
				Sumuj();
				changed = 0;
			}
			cout<<Suma[n-p]<<"\n";
		}
		else if (o == 'W')
		{
			cin >> p >> v;
			Wewnetrzny[n-p] = v;
			changed = 1;
		}
		else
		{
			cin >> p >> v;
			Zewnetrzny[n-p] = v;
			changed = 1;
		}
	}

	return 0;
}