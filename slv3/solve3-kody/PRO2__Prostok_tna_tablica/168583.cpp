#include <iostream>

using namespace std;

void sum(long long int** mx, int A1, int A2, int B1, int B2)
{
    long long int ss=0;
    for (int i=A1-1; i<B1; i++)
        for (int j=A2-1; j<B2; j++)
            ss += mx[i][j];
    cout<<ss<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;
    long long int** mx = new long long int*[n];
    for (int i=0; i<n; i++)
        mx[i] = new long long int[m];

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin>>mx[i][j];

    long q;
    cin>>q;
    long long int A1, A2, B1, B2;
    while (q--)
    {
        cin>>A1>>A2>>B1>>B2;
        sum(mx,A1,A2,B1,B2);
    }

    return 0;
}
