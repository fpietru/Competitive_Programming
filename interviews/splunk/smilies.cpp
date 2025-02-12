#include <bits/stdc++.h>
using namespace std;

bool solve(const string& t) {
    int czysty = 0;
    int brudny = 0;
    for (int i=0; i<(int)t.size(); i++) {
        if (t[i] == '(') {
            brudny++;
            if (i == 0 || t[i] != ':')
                czysty++;
        } else if (t[i] == ')') {
            if (i == 0) return false;
            czysty = max(czysty-1, 0);
            if (t[i-1] != ':') {
                if (brudny == 0) return false;
                brudny--;
            }
        }
    }
    return (czysty == 0);
}

int main () {

    string test1 = "(:)";
    string test2 = "(:))";
    string test3 = "(:)))";
    cout << solve(test1) << "\n";
    cout << solve(test2) << "\n";
    cout << solve(test3) << "\n";

    return 0;
}