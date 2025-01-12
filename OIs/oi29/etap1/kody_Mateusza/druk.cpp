#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

int n;
int m;
string maxSzablon = "";

char T[MAX + 2][MAX + 2];
set<int> dzielniki;
int zlicz[26];
vector<int> dlg;

void initT();
void initSet();
bool czyRozneLitery();
bool jestSzablonem(string &s);
string slowo(int i, int k, int d, bool pion);
void znajdzMaxSzablon();
void znajdzDlgPodszablonow();
bool czyDlgPodszablonu(int x);

// debug
void printT() {
    for (int i = 0; i <= n + 1; ++i) {
        for (int k = 0; k <= m + 1; ++k) {
            cout << T[i][k];
        }
        cout << "\n";
    }
}

void printSet() {
    for (auto s : dzielniki) cerr << s << " ";
    cerr << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	initT();
    initSet();

    if (!czyRozneLitery()) {
            //printSet();
        cout << dzielniki.size() << '\n';
        auto it = dzielniki.end();
        it--;
        for (; it != dzielniki.begin(); --it) cout << -(*it) << " ";
        cout << -(*dzielniki.begin());
        return 0;
    }

    znajdzMaxSzablon();

    if (maxSzablon == "") {
        cout << 0;
        return 0;
    }

    znajdzDlgPodszablonow();

    cout << dlg.size() << '\n';
    for (auto a : dlg) cout << a << " ";
}

void initT() {
    cin >> n >> m;
	for (int i = 0; i <= n + 1; ++i) T[i][0] = T[i][m + 1] = '#';
	for (int i = 0; i <= m + 1; ++i) T[0][i] = T[n + 1][i] = '#';

	for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= m; ++k) {
            cin >> T[i][k];
            zlicz[T[i][k] - 97]++;
        }
	}
}

void initSet() {
    dzielniki.insert(-1);
	dzielniki.insert(-n);
	dzielniki.insert(-m);

	int i = 2;
	for (; i * i <= max(n, m); ++i) {
        if (n % i == 0) {
            dzielniki.insert(-i);
            dzielniki.insert(-n / i);
        }
        if (m % i == 0) {
            dzielniki.insert(-i);
            dzielniki.insert(-m / i);
        }
	}
}

bool czyRozneLitery() {
    for (int i = 0; i < 26; ++i) {
        if (zlicz[i] == n * m) return false;
    }
    return true;
}

bool jestSzablonem(string &s) {
    if (!s.size()) return false;
    vector<vector<bool>> uzyta(n + 1, vector<bool>(m + 1, false));

    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= m; ++k) {
            if (uzyta[i][k]) continue;

            if (slowo(i, k, s.size(), false) == s) {
                int stop = k + s.size();
                bool ok = true;

                // sprawdzenie czy same false
                for (int j = k; j < stop; ++j) if (uzyta[i][j]) ok = false;

                if (ok) {
                    for (int j = k; j < stop; ++j) {
                        // if (uzyta[i][j]) // jezeli tu trafie na true, to chce przejsc do drugiego if-a i nie ustawiac zadnego uzyta[i][j] na true
                        uzyta[i][j] = true;
                    }
                    continue;
                }
            }
            if (slowo(i, k, s.size(), true) == s) {
                int stop = i + s.size();
                bool ok = true;

                for (int j = i; j < stop; ++j) if (uzyta[j][k]) ok = false;

                if (ok) {
                    for (int j = i; j < stop; ++j) {
                        // if (uzyta[j][k]) return false;
                        uzyta[j][k] = true;
                    }
                    continue;
                }
            }
            return false;
        }
    }
    return true;
}

string slowo(int i, int k, int d, bool pion) {
    string s = "";
    while (d--) {
        if (T[i][k] == '#') return "";
        s += T[i][k];
        if (pion) i++;
        else k++;
    }
    return s;
}

void znajdzMaxSzablon() {
    for (auto s : dzielniki) {
        string sz;

        sz = slowo(1, 1, -s, false);
        if (jestSzablonem(sz)) {
            maxSzablon = sz;
            break;
        }

        sz = slowo(1, 1, -s, true);
        if (jestSzablonem(sz)) {
            maxSzablon = sz;
            break;
        }
    }
}

void znajdzDlgPodszablonow() {
    dlg.reserve(100);

    // znajdz dlg podszablonow
    int d = maxSzablon.size();
    for (int i = 2; i < d; ++i) {
        if (d % i == 0) {
            if (czyDlgPodszablonu(i)) dlg.push_back(i);
        }
    }

    dlg.push_back(maxSzablon.size());
}

bool czyDlgPodszablonu(int x) {
    for (int i = 0; i < x; ++i) {
        for (int k = i + x; k < maxSzablon.size(); k += x) {
            if (maxSzablon[k] != maxSzablon[k - x]) return false;
        }
    }
    return true;
}
