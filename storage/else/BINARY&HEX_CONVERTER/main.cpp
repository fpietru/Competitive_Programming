#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string to_bin(ll n)
{
    if (n == 0)
        return "0";
    else
    {
        string ans = "";
        bool q = 0;
        while (!(q && n == 0))
        {
            if (n%2 == 0) ans.insert(0,"0"), q = 0;
            else ans.insert(0,"1"), q = 1;

            n /= 2;
        }
        return ans;
    }
}

string to_hex(ll n)
{
    string ans = "";
    string b = to_bin(n);
    if (b.size()%4 != 0)
    {
        string a(((4+b.size())-b.size()%4)-b.size(), '0');
        b.insert(0,a);
    }

    for (ll i=0; i<b.size(); i+=4)
    {
        ll p = 8, subans = 0;
        for (ll j=i; j<4+i; j++)
        {
            if (b[j] == '1')
                subans += p;
            p /= 2;
        }
        if (subans <= 9) ans += to_string(subans);
        else ans += (char)subans+55;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;
    //cout<<to_bin(n)<<endl;
    cout<<to_hex(n)<<endl;

    return 0;
}
