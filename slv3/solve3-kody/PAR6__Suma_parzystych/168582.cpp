#include <iostream>

using namespace std;

int main()
{
    int a,b,ans=0;
    cin>>a>>b;

    for (int i=a; i<=b; i++)
        if (i%2 == 0) ans += i;

    cout<<ans<<"\n";

    return 0;
}
