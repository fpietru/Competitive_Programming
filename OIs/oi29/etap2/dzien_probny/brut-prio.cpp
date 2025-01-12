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
map<pii, bool> vis;

struct cmp
{
	bool operator()(stan const& A, stan const& B)
	{
		if (A.liczba_robotow == B.liczba_robotow)
			return A.koszt <= B.koszt;
		return A.liczba_robotow < B.liczba_robotow; 
	}
};


int bfs()
{
	ll res = 1e18+9;
	priority_queue<stan, vector<stan>, cmp> Q;
	Q.push({0, 1, 0});	
	vis[{1,0}] = 1;
	
	while (!Q.empty())
	{
		stan v = Q.top();
		Q.pop();
		
		deb(v.koszt, v.liczba_robotow, v.pamiec);
		
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

	cin >> n >> a >> b;
	
	cout << bfs() << "\n";

    return 0;
}
