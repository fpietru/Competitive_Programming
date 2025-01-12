#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define PB push_back
#define FR first
#define SD second

constexpr int MxN = 2e5+5;
vector<pii> G[2][MxN];
int wart[2][MxN];
int zlicz[2][30];
bool zmienie[30];
vector<int> vec[2];

void dfs(int v, int p, int k) {
    for (auto [u, w] : G[k][v])
        if (u != p) {
            wart[k][u] = wart[k][v] ^ w;
            dfs(u, v, k);   
        }
}

void dfs2(int v, int p, int k) {
	vec[k].PB(wart[k][v]);
	for (int i=0; i<30; i++)
    	zlicz[k][i] += ((wart[k][v]&(1<<i)) != 0);
    for (auto [u, w] : G[k][v])
        if (u != p) dfs2(u, v, k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    for (int i=1; i<=n-1; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        G[0][a].PB({b, c}); G[0][b].PB({a, c});
        G[1][a].PB({b, d}); G[1][b].PB({a, d});
    }
    
    wart[0][1] = wart[1][1] = 0;
    dfs(1, 1, 0); dfs(1, 1, 1);
    dfs2(1, 1, 0); dfs2(1, 1, 1);
    
    for (int i=0; i<30; i++) {
        if (zlicz[0][i] == zlicz[1][i]) continue;
        else if (zlicz[0][i] == n - zlicz[1][i])
        	zmienie[i] = true;
        else {
            cout << "NIE\n";
            return 0;
        }
    }
    
    for (int i=0; i<n; i++)
    	for (int j=0; j<30; j++)
    		if (zmienie[j])
    			vec[0][i] ^= (1<<j);
    			
    sort(vec[0].begin(), vec[0].end());
    sort(vec[1].begin(), vec[1].end());
    
    cout << (vec[0] == vec[1] ? "TAK\n" : "NIE\n");

    return 0;
}
