#include <bits/stdc++.h>
using namespace std;

vector<long long int> T{0,0,1,15,168,1700,17220,182406,2055200,24767928,319463100,4403508890};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long int n,m;
    cin>>n>>m;

    cout<<T[n]%m << "\n";



    return 0;
}
