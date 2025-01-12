#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    int n, p, ai;
    cin>>n;
    vector<int> abc;
    for (int i=0; i<n; i++)
        cin>>ai, abc.push_back(ai);
    cin>>p;

    vector<int> been;
    int i=0;
    while(true)
    {
        if (i<abc.size())
        {
            if (!count(been.begin(), been.end(), abc[i]))
            {
                cout<<abc[i]<<" ";
                been.push_back(abc[i]);
            }
            else if (count(been.begin(), been.end(), abc[i]) || been.size() == abc.size())
                break;
        }
        else
            i-=abc.size()+p;
        i+=p;
    }

    return 0;
}
