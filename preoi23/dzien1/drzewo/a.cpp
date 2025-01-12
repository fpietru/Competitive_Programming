#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PB push_back

struct zapytanie {
    ll t, k;
    int id;
};
constexpr int MxN = 2e4+4;
constexpr int base = (1<<16);
int Tree[2*base];
int fabryka[MxN], ile[MxN];
vector<int> G[MxN];
vector<zapytanie> zap[MxN];
ll ans[MxN];
ll n, m;

void update(int v, int x) {
    v += base;
    Tree[v] += x;
    while (v) {
        v >>= 1;
        Tree[v] = Tree[2*v] + Tree[2*v+1];
    }
}

int query(int a, int b) {
    int res = 0;
    a += base - 1;
    b += base + 1;
    while ((a>>1) != (b>>1)) {
        if ((a&1) == 0) res += Tree[a+1];
        if ((b&1) == 1) res += Tree[b-1];
        a >>= 1; b >>= 1;
    }
    return res;
}

void dfs0(int v, int p) {
    ile[v] = fabryka[v];
    for (auto u : G[v]) {
        ile[v] += fabryka[u];
        if (u != p)
            dfs0(u, v);
    }
}

inline __int128 sufit(__int128 a, __int128 b) {
	return ((a-1) / b) + 1;
}

bool check(__int128 s, __int128 t, __int128 k) {
    __int128 C = sufit(2*k, s*(s+1));
    __int128 tylemam = query(C, n);
    return (tylemam >= t);
}

void dfs(int v, int p) {
    update(ile[v], 1);
    for (auto z : zap[v]) {
        ll low = 1;
        ll high = m;
        while (low < high) {
            ll mid = (low + high) >> 1;
            if (check(mid, z.t, z.k) == 0)
                low = mid + 1;
            else high = mid;
        }
        ans[z.id] = (low == m ? -1 : low);
    }
    for (auto u : G[v])
        if (u != p)
            dfs(u, v);
    update(ile[v], -1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> fabryka[i];
    for (int i=1; i<=n-1; i++) {
        int a, b; cin >> a >> b;
        G[a].PB(b); G[b].PB(a);
    }
    dfs0(1, 1);
    
    int q; cin >> q;
    for (int i=1; i<=q; i++) {
        int x; ll t, k; cin >> x >> t >> k;
        zap[x].PB({t, k, i});
    }
    dfs(1, 1);
    
    for (int i=1; i<=q; i++)
        cout << ans[i] << "\n";

    return 0;
}
