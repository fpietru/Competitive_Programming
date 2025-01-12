#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging 
/*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

constexpr int MxN = 505;
constexpr int MxK = 7;
ll wynik[MxN][MxK];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k, ile; cin >> n >> k >> ile;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=k; j++)
			cin >> wynik[i][j];
			
	/* essa */
	vector<ll> suma;
	if (k == 1)
	{
		for (int a=1; a<=n; a++)
		{
			ll druzyna = 0LL;
			for (int i=1; i<=k; i++)
				druzyna += wynik[a][i];
			suma.PB(druzyna);
		}	
	}
	else if (k == 2)
	{
		for (int a=1; a<=n-1; a++)
			for (int b=a+1; b<=n; b++)
			{
				ll druzyna = 0LL;
				for (int i=1; i<=k; i++)
					druzyna += max(wynik[a][i], wynik[b][i]);
				suma.PB(druzyna);
			}
	}
	else if (k == 3)
	{
		for (int a=1; a<=n-2; a++)
			for (int b=a+1; b<=n-1; b++)
				for (int c=b+1; c<=n; c++)
				{
					ll druzyna = 0LL;
					for (int i=1; i<=k; i++)
						druzyna += max({wynik[a][i], wynik[b][i], wynik[c][i]});
					suma.PB(druzyna);
				}
	}
	else if (k == 4)
	{
		for (int a=1; a<=n-3; a++)
			for (int b=a+1; b<=n-2; b++)
				for (int c=b+1; c<=n-1; c++)
					for (int d=c+1; d<=n; d++)
					{
						ll druzyna = 0LL;
						for (int i=1; i<=k; i++)
							druzyna += max({wynik[a][i], wynik[b][i], wynik[c][i], wynik[d][i]});
						suma.PB(druzyna);
					}
	}
	else if (k == 5)
	{
		for (int a=1; a<=n-4; a++)
			for (int b=a+1; b<=n-3; b++)
				for (int c=b+1; c<=n-2; c++)
					for (int d=c+1; d<=n-1; d++)
						for (int e=d+1; e<=n; e++)
						{
							ll druzyna = 0LL;
							for (int i=1; i<=k; i++)
								druzyna += max({wynik[a][i], wynik[b][i], wynik[c][i], wynik[d][i], wynik[e][i]});
							suma.PB(druzyna);
						}		
	}
	else
	{
		for (int a=1; a<=n-5; a++)
			for (int b=a+1; b<=n-4; b++)
				for (int c=b+1; c<=n-3; c++)
					for (int d=c+1; d<=n-2; d++)
						for (int e=d+1; e<=n-1; e++)
							for (int f=e+1; f<=n; f++)
							{
								ll druzyna = 0LL;
								for (int i=1; i<=k; i++)
									druzyna += max({wynik[a][i], wynik[b][i], wynik[c][i], wynik[d][i], wynik[e][i], wynik[f][i]});
								suma.PB(druzyna);
							}			
	}
	
	sort(suma.begin(), suma.end(), greater<ll>());

	cout << suma[ile-1] << "\n";

	return 0;
}
