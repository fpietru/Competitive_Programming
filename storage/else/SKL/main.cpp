/*
	Zadanie "Sklep" z I OIG, etap III 
*/
#include <bits/stdc++.h>

using namespace std;

const int mxS = 1e6+7;
int pri[mxS];
map<int, int> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    int j=0;
    while (n--)
    {
        int a, b;
        cin>>a>>b;

        mp[a] += b;

        if (mp[a] == b)
            pri[j] = a, j++;
    }

    cout<<mp.size()<<"\n";
    for (int i=0; i<j; i++)
        cout<<pri[i]<<" "<<mp[pri[i]]<<"\n";


    return 0;
}
