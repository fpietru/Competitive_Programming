#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 5e5, K = 18;
long long st[MAXN][K+1];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	long long n, m;
	cin>>n>>m;
	
	for (long long i=0; i<n; i++)
		cin >> st[i][0];

	for (long long j=1; j<=K; j++)
    	for (long long i = 0; i + (1 << j) <= n; i++)
        	st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

	long long log[MAXN+1];
	log[1] = 0;
	for (long long i=2; i<=MAXN; i++)
		log[i] = log[i/2] + 1; 

    while (m--)
    {
    	long long a, b;
    	cin>>a>>b;
    	
    	a--;
    	b--;
    	
    	long long j = log[b - a + 1];
		long long ans = min(st[a][j], st[b - (1 << j) + 1][j]);

		cout<<ans<<"\n";
    }
    
	return 0;
}