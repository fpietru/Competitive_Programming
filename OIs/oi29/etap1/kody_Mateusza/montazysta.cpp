#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500 * 1000;

struct Film {
    int t;
    int d;
    int index;
};

int n;
Film filmy[MAX_N + 10];

void wczytaj();

struct Compare {
    bool operator() (Film &fa, Film &fb) {
        return fa.t < fb.t;
    }
};

// debug
void printFilmy() {
    for (int i = 0; i < n; ++i) cerr << filmy[i].t << " " << filmy[i].d << '\n';
}

void printMontaz(priority_queue<Film, vector<Film>, Compare> q) {
    while (!q.empty()) {
        cout << q.top().t << " " << q.top().d << '\n';
        q.pop();
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    wczytaj();

    sort(filmy, filmy + n, [](Film &fa, Film &fb){ return fa.d < fb.d; });

    priority_queue<Film, vector<Film>, Compare> montaz;

    long long int total_t = 0;
    int liczba_filmow = 0;

    for (int i = 0; i < n; ++i) {
        if (total_t + filmy[i].t <= filmy[i].d) {
            montaz.push(filmy[i]);
            total_t += filmy[i].t;
            liczba_filmow++;
        } else {
            if (montaz.empty()) continue;
            Film obecnieNajdluzszy = montaz.top();
            long long int nowyCzas = total_t - obecnieNajdluzszy.t + filmy[i].t;
            if (nowyCzas <= filmy[i].d) {
                if (nowyCzas <= total_t) {
                    total_t = nowyCzas;
                    montaz.pop();
                    montaz.push(filmy[i]);
                }
            }
        }
    }

    // printMontaz(montaz);

    vector<Film> wynik;
    while (!montaz.empty()) {
        wynik.push_back(montaz.top());
        montaz.pop();
    }

    sort(wynik.begin(), wynik.end(), [](Film &fa, Film &fb){ return fa.d < fb.d; });

    cout << wynik.size() << '\n';
    int dzien = 1;
    for (auto F : wynik) {
        cout << F.index << " " << dzien << '\n';
        dzien += F.t;
    }
}


void wczytaj() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> filmy[i].t >> filmy[i].d;
        filmy[i].index = i + 1;
    }
}
