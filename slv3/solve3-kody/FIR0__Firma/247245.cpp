#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;

constexpr int MxN = 2e5+5;
vector<int> G[MxN];
vector<int> roots;
ll K, k;
ll suma = 0LL;
ll koszt[MxN];
bool flag = 1;

inline void readUI(ll *n)
{
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}

inline void putUI(unsigned int n) {
  
	 if(n>0) {
         putUI(n/10);
         putc_unlocked(n%10+48,stdout);
     }
}

void dfs(int v, int p)
{
	for (auto u : G[v])
		if (u != p)
			dfs(u, v);
			
	ll mx = 0;
	for (auto u : G[v])
		if (u != p)
		 mx = max(mx, koszt[u]);

	koszt[v] = mx + (mx/2) + (mx % 2);

	if (koszt[v] == 0LL)
		koszt[v] = k;
		
	suma += koszt[v];
	if (suma > K)
	{
		flag = 0;
		suma = 0LL;
	}
}

int main()
{
	//cin >> n >> K;
	ll n; readUI(&n);
	readUI(&K);
	
	for (int i=1; i<=n; i++)
	{
		ll x; readUI(&x);
		if (x > 0)
		{
			G[i].push_back(x);
			G[x].push_back(i);
		}
		else
			roots.push_back(i);
	}
	
	ll low = 1;
	ll high = 1e18 / (ll)n + 1LL;
	while (low < high)
	{
		ll mid = (low + high) >> 1;
		k = mid;
		flag = 1;
		suma = 0LL;
		memset(koszt, 0, sizeof(koszt));
		for (auto r : roots)
			dfs(r, r);
		
		if (flag == 1)
			low = mid + 1;
		else high = mid;		
	}
	low--;
	
	if (low > 0)
		putUI(low);
	else
	{
		putchar_unlocked('N');
		putchar_unlocked('I');
		putchar_unlocked('E');
		putchar_unlocked('\n');
	}
	
    return 0;
}
