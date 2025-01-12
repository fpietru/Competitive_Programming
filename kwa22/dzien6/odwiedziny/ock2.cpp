#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int sqr = 31623;
constexpr int MxN = 1e6+6;
map<int, int> A; 
map<int, map<int, int>> mp;
int p[MxN], k[MxN], x[MxN];

struct punkt
{
	int typ;
	int poz;
	int ile;
};

bool cmp(punkt a, punkt b)
{
	if (a.poz == b.poz)
		return a.typ < b.typ;
	return a.poz < b.poz;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int mx = 0;
	bool podzadanie3 = 1;
	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> p[i] >> k[i] >> x[i];
		if (x[i] != 1)
			podzadanie3 = 0;
		
		mx = max(mx, k[i] - p[i]);
	}
	
	if (podzadanie3 && mx > (int)(1e5))
	{
		map<int, int> poczatki;
		map<int, int> konce;
		for (int i=1; i<=n; i++)
			poczatki[p[i]]++;
		for (int i=1; i<=n; i++)
			konce[k[i]+1]++;
		
		vector<punkt> vec;
		for (auto j : poczatki)
			vec.push_back({1, j.FR, j.SD});
		for (auto j : konce)
			vec.push_back({2, j.FR, j.SD});
			
		sort(vec.begin(), vec.end(), cmp);
		int total = 0;
		for (auto j : vec)
		{
			if (j.typ == 1)
				total += j.ile;
			else
				total -= j.ile;
				
			if (total & 1)
			{
				cout << j.poz << " " << total << "\n";
				return 0;
			}
		}
		
		cout << "NIE\n";
		return 0;
	}
	

	for (int i=1; i<=n; i++)
	{
		if (x[i] > sqr)
			for (int j=p[i]; j<k[i]; j+=x[i])
				A[j]++;
		else
		{
			mp[x[i]][p[i]]++;
			mp[x[i]][k[i]+x[i]]--;
		}
	}
	
	for (auto skok : mp)
	{
		//cout << skok.FR << ": ";
		
		int pocz = skok.SD.begin()->FR;
		int kon = skok.SD.rbegin()->FR;
		
		int total = 0;
		for (int i=pocz; i<=kon; i += skok.FR)
		{
			total += skok.SD[i];
			A[i] += total;			
		}
	} 
	
	for (auto a : A)
		if (a.SD & 1)
		{
			cout << a.FR << " " << a.SD << "\n";
			return 0;
		}
		
	cout << "NIE\n";

    return 0;
}
