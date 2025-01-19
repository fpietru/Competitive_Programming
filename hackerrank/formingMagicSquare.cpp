#include <bits/stdc++.h>
using namespace std;


int formingMagicSquare(vector<vector<int>> s) {
    vector<vector<int>> magic(8);
    magic[0] = {2,7,6,9,5,1,4,3,8};
    magic[1] = {2,9,4,7,5,3,6,1,8};
    magic[2] = {4,3,8,9,5,1,2,7,6};
    magic[3] = {4,9,2,3,5,7,8,1,6};
    magic[4] = {6,1,8,7,5,3,2,9,4};
    magic[5] = {6,7,2,1,5,9,8,3,4};
    magic[6] = {8,1,6,3,5,7,4,9,2};
    magic[7] = {8,3,4,1,5,9,6,7,2};

    int ans = INT_MAX;
    for (int k=0; k<8; k++) {
        int diff = 0;
        int l = 0;
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                diff += abs(magic[k][l++] - s[i][j]);
        ans = min(ans, diff);
    }
    return ans;
}