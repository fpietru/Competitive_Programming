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
map<int, int> A; 
map<int, map<int, int>> mp;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;

	for (int i=1; i<=n; i++)
	{
		int p, k, x;
		cin >> p >> k >> x;

		if (x > sqr)
			for (int j=p; j<k; j+=x)
				A[j]++;
		else
		{
			mp[x][p]++;
			mp[x][k+x]--;
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
