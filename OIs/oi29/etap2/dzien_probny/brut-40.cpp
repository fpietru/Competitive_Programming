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

ll n, a, b;
struct stan
{
	ll koszt;
	ll liczba_robotow;
	ll pamiec;
};

ll bfs()
{
	ll res = 1e18+9;
	queue<stan> Q;
	Q.push({0LL, 1LL, 0LL});
	
	while (!Q.empty())
	{
		stan v = Q.front();
		Q.pop();
		
		// deb(v.koszt, v.liczba_robotow, v.pamiec);
		
		if (v.liczba_robotow > n)
			res = min(res, v.koszt);
		else
		{			
			// opcja 1: skanujemy
			Q.push({v.koszt+a, v.liczba_robotow, v.liczba_robotow});
			
			// opcja 2: drukujemy
			Q.push({v.koszt+b, v.liczba_robotow+v.pamiec, v.pamiec});
		}
	}
	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> a >> b;
	cout << bfs() << "\n";

    return 0;
}
