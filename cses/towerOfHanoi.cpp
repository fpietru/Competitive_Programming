#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans;

void mv(int stack, int from, int to, int pom) {
    if (stack == 1) {
        ans.push_back({from, to});
    } else {
        mv(stack-1, from, pom, to);
        ans.push_back({from, to});
        mv(stack-1, pom, to, from);
    }
}

int main () {
    int n; cin >> n;

    mv(n, 1, 3, 2);
    
    cout << ans.size() << "\n";
    for (auto p : ans)
        cout << p.first << " " << p.second << "\n";

    return 0;
}