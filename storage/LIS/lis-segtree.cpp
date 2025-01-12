/*
	Znajdowanie LIS'a z użyciem drzewa przedziałowego (punkt|przedział) (+|max)
	Złożoność czasowa: O(n*logn)
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+16, base = (1<<20);
int a[MxN], T[2*base+10];

// funkcja od Damiana do debuggowania
void wypiszDrzewo(){
    int space=1,m=1,levelMax=-1;
    while(space<base+1){
        ++levelMax;
        space*=2;
    }
    --space;
    int level=0;
    while(level<=levelMax){
        space/=2;
        for(int j=1;j<=m;++j){
            for(int i=0;i<=space;++i)
                cout<<" ";

            cout<<T[(1<<level)+j-1];

            for(int i=1;i<=space;++i)
                cout<<" ";
        }
        m*=2;
        ++level;
        cout<<'\n';
    }
}

void update(int v, int x)
{
	v += base;
	T[v] = x;
	while (v)
	{
		v /= 2;
		T[v] = max(T[2*v], T[2*v+1]);
	}
}

int getmx(int a, int b)
{
	int res = 0;
	a += base - 1;
	b += base + 1;
	while (a/2 != b/2)
	{
		if (a % 2 == 0) res = max(res, T[a+1]);
		if (b % 2 != 0) res = max(res, T[b-1]);
		a /= 2, b /= 2;
	}
	return res;
}

int main()
{		
	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int ans = 0;
	for (int i=1; i<=n; i++)
	{
		int mx_pref = getmx(0, a[i]);
		update(a[i]+1, mx_pref+1);
		ans = max(ans, mx_pref+1);
	}
	
	cout << ans << "\n";

	return 0;
}
