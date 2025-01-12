#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int base = (1<<19);
pii Tree[2*base+10];
int MOD;

void insert(int v, int val, int krot)
{
    v += base;

    while (v && Tree[v].FR <= val)
    {
        if (Tree[v].FR == val)
            Tree[v].SD = ((ll)Tree[v].SD + (ll)krot) % MOD;
        else if (Tree[v].FR < val)
        {
            Tree[v].FR = val;
            Tree[v].SD = krot;
        }
        v >>= 1;
    }
}

pii query(int a, int b)
{
    pii res = {-1, -1};
    a += base - 1;
    b += base + 1;
    
    while ((a>>1) != (b>>1))
    {
        if (!(a&1) && Tree[a+1].FR >= res.FR)
        {
        	if (Tree[a+1].FR == res.FR)
        		res.SD = ((ll)res.SD + (ll)Tree[a+1].SD) % MOD;
        	else
            	res = Tree[a+1];
        }
        if ((b&1) && Tree[b-1].FR >= res.FR)
        {
        	if (Tree[b-1].FR == res.FR)
        		res.SD = ((ll)res.SD + (ll)Tree[b-1].SD) % MOD;
            else
            	res = Tree[b-1];
        }
        a >>= 1;
        b >>= 1;
    }
    
    if (res.FR == 0)
        return {res.FR, 1};
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n; cin >> n >> MOD;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++)
    {
		cin >> a[i];
  		b[i] = a[i];
  	}
  	
  	sort(a.begin(), a.end());
  	
    for (int i=0; i<n; i++)
    {
    	int p = lower_bound(a.begin(), a.end(), b[i]) - a.begin() + 1;
        pii mx = query(0, p-1);
        insert(p, mx.FR+1, mx.SD);
    }
    
    cout << query(0, base-1).SD << "\n";
	
    return 0;
}
