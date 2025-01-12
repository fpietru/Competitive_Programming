#include <bits/stdc++.h>
# define ll long long int

using namespace std;

ll m;

const ll INF = 1e18;
const int FIB_SIZE = 87;
ll FIB[FIB_SIZE + 10];

void createFib();
ll znajdzDlugosc(ll n, int ind);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m;

	createFib();
    ll dlg = znajdzDlugosc(m, FIB_SIZE);

    if (dlg < INF) cout << dlg << '\n';
    else cout << "NIE\n";
}

void createFib() {
    FIB[0] = 1;
    FIB[1] = 1;
    for (int i = 2; i <= FIB_SIZE; ++i) FIB[i] = FIB[i - 1] + FIB[i - 2];
}

ll znajdzDlugosc(ll n, int ind) {
    if (n == 1) return 1;
    for (int i = ind; i > 1; --i) {
        if (n == FIB[i]) return i;
        if (n % FIB[i] == 0) {
            ll d = znajdzDlugosc(n / FIB[i], i);
            if (d < INF) return i + d + 1;
        }
    }
    return INF;
}
