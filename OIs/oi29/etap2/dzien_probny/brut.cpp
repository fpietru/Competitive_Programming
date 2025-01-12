#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
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

ll n; int a, b;
struct stan
{
	ll koszt;
	ll liczba_robotow;
	ll pamiec;
};


int bfs()
{
	map<pii, bool> vis;
	ll res = 1e18+9;
	queue<stan> Q;
	Q.push({0, 1, 0});	
	vis[{1,0}] = 1;
	
	while (!Q.empty())
	{
		stan v = Q.front();
		Q.pop();
		
		// deb(v.koszt, v.liczba_robotow, v.pamiec);
		
		if (v.liczba_robotow > n) {
			res = min(res, v.koszt);
		}
		
		if (v.liczba_robotow <= n)
		{			
			// opcja 1: skanujemy
			if (vis[{v.liczba_robotow, v.liczba_robotow}] == 0)
			{
				vis[{v.liczba_robotow, v.liczba_robotow}] = 1;
				Q.push({v.koszt+(ll)a, v.liczba_robotow, v.liczba_robotow});
			}
			
			// opcja 2: drukujemy
			if (vis[{v.liczba_robotow+v.pamiec, v.pamiec}] == 0)
			{
				vis[{v.liczba_robotow+v.pamiec, v.pamiec}] = 1;
				Q.push({v.koszt+(ll)b, v.liczba_robotow+v.pamiec, v.pamiec});
			}
		}
	}
	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	a = 1;
	b = 1;

	map<int, int> mp;
	for (int i=1; i<=1000; i++)
	{
		n = i;
		int res = bfs();
		cout << i << " " << res << "\n";		
		mp[res]++;
	}
	
	for (auto p : mp)
		cout << p.FR << " " << p.SD << "\n";

    return 0;
}
