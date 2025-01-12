#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;
    vector<int> prz(n+1, 0);

    int nm = 0, pm = 0;
    while (m--)
    {
        int o;
        cin>>o;

        if (o == n + 1)
            pm = nm;
        else
        {
            prz[o] = max(prz[o], pm) + 1;
            nm = max(nm, prz[o]);
        }
    }

    for (int i=1; i<=n; i++)
    {
        if (prz[i] > pm) cout<<prz[i]<<" ";
        else cout<<pm<<" ";
    }
    cout<<"\n";

    return 0;
}
