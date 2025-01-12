#include <bits/stdc++.h>
#define ull unsigned long long int

using namespace std;

const int MAX_N = 1e6;

ull n;
ull m;

ull elem[MAX_N + 10];
ull koszt_p[MAX_N + 10];
ull koszt[MAX_N + 10];

ull pref_elem[MAX_N + 10];
ull pref_koszt[MAX_N + 10];

ull suma_czesciowa(ull a, ull b);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n - 2; ++i) {
        // elementy liczone poprawnie
        elem[i] = (pref_elem[i - 1] + (((n - i) % m) * elem[i - 1] + 1) % m) % m;
        pref_elem[i] = (pref_elem[i - 1] + elem[i]) % m;

        koszt_p[i] = (pref_koszt[i - 1] + ((((n - i) % m) * koszt_p[i - 1]) % m) + ((elem[i - 1] * (suma_czesciowa(i, n - 1) % m)) % m)) % m;
        koszt[i] = (koszt_p[i] + ((elem[i] * (i % m)) % m)) % m;
        pref_koszt[i] = (pref_koszt[i - 1] + koszt[i]) % m;
	}

	ull wart = 0;

	for (int i = 0; i < n; ++i) {
        wart = (wart + ((((i % m) * (pref_elem[n - 2] + 1)) % m) * (((n % m) - 1 + m) % m)) % m) % m;
        wart = (wart + pref_koszt[n - 2]) % m;
	}

	cout << wart << '\n';
}

ull suma_czesciowa(ull a, ull b) {
    return ((b - a + 1) * (a + b)) / 2;
}
