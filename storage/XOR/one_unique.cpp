/*
    Given vector of unsigned ints. We say element x is in a pair
    if there exists another x in vector.
    There is exactly one elemenent that has no pair. Return it.
*/
#include <bits/stdc++.h>
using namespace std;

unsigned get_unique(const vector<unsigned> &vec) {
    unsigned x = 0;
    for (unsigned elem : vec)
        x ^= elem;
    return x;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<unsigned> vec = {1, 2, 1, 3, 2, 5, 4, 3, 7, 7, 4};
    cout << get_unique(vec) << "\n";

    return 0;
}