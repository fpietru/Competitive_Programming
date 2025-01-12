#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin>>n>>m;
    vector<vector<int>> vec(n, vector<int> (m, 0));

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin>>vec[i][j];

    vector<vector<int>> pref(n+1, vector<int> (m+1, 0));

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            pref[i+1][j+1] = pref[i][j+1] + pref[i+1][j] - pref[i][j] + vec[i][j];

    int q;
    cin>>q;

    while (q--)
    {
        int a, b, c, d, ans;
        cin>>a>>b>>c>>d;
        a--, b--, c--, d--;
        ans = pref[c+1][d+1] - pref[c+1][b] - pref[a][d+1] + pref[a][b];
        cout<<ans<<"\n";
    }

    return 0;
}
