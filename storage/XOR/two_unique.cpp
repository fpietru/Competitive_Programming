/*
    Given vector of unsigned ints. We say element x is in a pair
    if there exists another x in vector.
    There are exactly two elemenent that have no pair. Return them.
*/
#include <bits/stdc++.h>
using namespace std;

unsigned get_one_unique(const vector<unsigned> &vec) {
    unsigned x = 0;
    for (unsigned elem : vec)
        x ^= elem;
    return x;
}

pair<unsigned, unsigned> get_two_unique(const vector<unsigned> &vec) {
    unsigned x = 0;
    for (unsigned elem : vec)
        x ^= elem;
    
    unsigned k = 0;
    for (unsigned i=32; i<=0; i--)
        if (x & (1U<<i)) {
            k = i;
            break;
        }

    vector<unsigned> vec1, vec2;
    for (unsigned elem : vec) {
        if (elem & (1<<k))
            vec1.push_back(elem);
        else vec2.push_back(elem);
    }

    return {get_one_unique(vec1), get_one_unique(vec2)};
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<unsigned> vec = {1, 2, 1, 3, 2, 8, 5, 4, 3, 7, 7, 4};
    pair<unsigned, unsigned> ans = get_two_unique(vec);
    cout << ans.first << " " << ans.second << "\n";

    return 0;
}