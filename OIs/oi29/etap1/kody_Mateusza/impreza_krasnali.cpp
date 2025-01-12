#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;

int n;
int A[SIZE + 10];
int T[SIZE + 10];
int W[SIZE + 10];

bool ustawCzapke(int wys, int pos);

bool ustalZLewej();
bool ustalZPrawej();
bool ustalPary();
bool duplikatyNparPar();

int dlugoscCyklu(int id);

// debug
void printTab(int* x) {
    for (int i = 1; i <= n; ++i) cerr << *(x + i) << " ";
    cerr << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> A[i];

	bool ok = true;
	ok = ok && duplikatyNparPar();
	ok = ok && ustalZLewej();
	ok = ok && ustalZPrawej();
    ok = ok && ustalPary();

    vector<int> cykle;
    cykle.reserve(n);

    for (int i = 1; i <= n; ++i) {
        if (!T[i]) cykle.push_back(dlugoscCyklu(i));
    }

	if (!ok) {
        cout << 0 << '\n';
        return 0;
	}

	long long int wynik = 1;
	for (int d : cykle) {
        wynik *= d;
        wynik %= mod;
	}
	for (int i = 2; i <= cykle.size(); ++i) {
        wynik *= i;
        wynik %= mod;
	}

	cout << wynik << '\n';
	// printTab(T);
	// printTab(W);
}

bool ustawCzapke(int wys, int pos) {
    if (pos <= 0 || pos >= n + 1) return false;

    if (!W[wys] && !T[pos]) {
        T[pos] = wys;
        W[wys] = pos;
        return true;
    }

    if (W[wys]) return W[wys] == pos;
    if (T[pos]) return T[pos] == wys;

    return false;
}

bool ustalZLewej() {
    int i = 1;
    do {
        bool ok = ustawCzapke(A[i], i + 1);
        i += 2;
        if (!ok) return false;
    } while (A[i - 2] != A[i] && i <= n);
    return true;
}

bool ustalZPrawej() {
    int i = n;
    do {
        bool ok = ustawCzapke(A[i], i - 1);
        i -= 2;
        if (!ok) return false;
    } while (A[i + 2] != A[i] && i > 0);
    return true;
}

bool ustalPary() {
    bool ok = true;
    for (int i = 1; i <= n - 2; ++i) {
        if (A[i] == A[i + 2]) ok = ustawCzapke(A[i], i + 1);
        if (!ok) return false;
    }
    return true;
}

bool duplikatyNparPar() {
    vector<int> zlicz(SIZE + 10, 0);
    for (int i = 1; i <= n; i += 2) zlicz[A[i]]++;

    for (int i = 2; i <= n; i += 2) {
        if (zlicz[A[i]]) return false;
    }
    return true;
}

int dlugoscCyklu(int id) {
    int counter = 1;
    int i = id;

    while (!T[i]) {
        T[i] = -10; // T[i] zostalo wziete pod uwage
        if (i >= n) return counter;

        if (W[A[i + 1]]) return counter;
        else {
            W[A[i + 1]] = -10;
        }
        counter++;
        i += 2;
    }
    return counter;
}
