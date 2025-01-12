#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int base = (1<<19);
ll Tree[2*base+10];

ll nwd(ll a, ll b)
{
    return b == 0LL ? a : nwd(b, a % b);   
}

void upd(int v, ll x)
{
	v += base;
	Tree[v] = x;
	while (v)
	{
		v /= 2;
		Tree[v] = nwd(Tree[2*v], Tree[2*v+1]);
	}
}

ll getnwd(int a, int b)
{
	ll res = 0;
	a += base - 1;
	b += base + 1;
	while (a/2 != b/2)
	{
		// deb(a, b, res, Tree[a+1], Tree[b-1]);
		if (a % 2 == 0) res = nwd(res, Tree[a+1]);
		if (b % 2 == 1) res = nwd(res, Tree[b-1]);
		// deb(a, b, res, Tree[a+1], Tree[b-1]);
		// cout << "\n";
		a /= 2, b /= 2;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		ll x; cin >> x;
		upd(i, x);
	}

/*
	for (int i=0; i<n; i++)
		deb(getnwd(i,i));
*/	

	int ans = -1;
	ll mx = 0LL;
	for (int i=0; i<n; i++)
	{
		ll res = 0LL;
		if (i-1 >= 0)
			res = getnwd(0, i-1);
		if (i+1 < n)
			res = nwd(res, getnwd(i+1, n-1));
		// deb(i, getnwd(i,i), res);
		if (res > mx)
		{
			mx = res;
			ans = i+1;
		}
	}

	cout << ans << "\n";	

    return 0;
}
