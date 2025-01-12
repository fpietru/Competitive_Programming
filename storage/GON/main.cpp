/*
	Znajdowanie spójnego podciągu o sumie s, takiej że s ≤ k oraz s - k jest jak najmniejsze
	Użycie gąsienicy
	Złożoność czasowa O(n)  	
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin>>n>>k;
    vector<int> N(n);

    for (int i=0; i<n; i++)
        cin>>N[i];

    int kon = 0, sum = 0, r = INT_MAX, wpoc, wkon;
    for (int poc=0; poc<n; poc++)
    {
        sum += N[poc];
        while (sum > k)
        {
            sum -= N[kon];
            kon++;
        }
      
        if (sum == k)
        {
            cout<<kon+1<<" "<<poc+1<<"\n";
            return 0;
        }

        if (k - sum < r)
        {
            wpoc = poc;
            wkon = kon;
            r = k - sum;
        }
    }
    cout<<wkon+1<<" "<<wpoc+1<<"\n";

    return 0;
}
