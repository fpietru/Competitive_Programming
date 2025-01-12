#include <bits/stdc++.h>
#include "kot.h"
using namespace std;
using pii = pair<int, int>;
#define PB push_back

constexpr int MxN = 2e4+4;
vector<pii> G[MxN];
vector<int> kolor;
string sciezka;
string klucz = "11011011001101100101101";
bool juzsiecofnalem;
bool mammargines;

void dfs0(int v, int p, int col) {
	col++;
	if (col >= 3) col -= 3;
	for (auto [u, id] : G[v])
		if (u != p) {
			kolor[id] = col;
			dfs0(u, v, col);
		}
}

void dfs(int v, int p, int i) {
	if (i >= klucz.size()) i=0;
	for (auto [u, id] : G[v])
		if (u != p) {
			kolor[id] = (klucz[i]-'0');
			dfs(u, v, i+1);
		}
}

vector<int> pokoloruj(int n, int m, int a, int b, vector<int> u, vector<int> v) {
    for (int i=0; i<m; i++) {
    	G[u[i]].PB({v[i], i});
    	G[v[i]].PB({u[i], i});
    }

    
    return kolor;
}

bool jest() {
	int n = sciezka.size();
	int m = klucz.size();
	if (n < m) return false;
	string suff = "";
	for (int i=0; i<m; i++)
		suff += sciezka[n-1-i];
	reverse(suff.begin(), suff.end());
	// cout << "--->" << suff << " " << klucz << "\n";
	return (suff == klucz);
}

int idzA(vector<int> ile) {
	if (ile[0] == 1 && ile[1] == 1 && ile[2] == 0) return 0;
	if (ile[0] == 0 && ile[1] == 1 && ile[2] == 1) return 1;
	if (ile[0] == 1 && ile[1] == 0 && ile[2] == 1) return 2;
	if (ile[0] == 1 && ile[1] == 0 && ile[2] == 0) return 0;
	if (ile[0] == 0 && ile[1] == 1 && ile[2] == 0) return 1;
	if (ile[0] == 0 && ile[1] == 0 && ile[2] == 1) return 2;
	return -1;
}

int idzB(vector<int> ile) {
	int res = -1;
	if (ile[0] == 1 && ile[1] == 0) res = 0;
	else if (ile[0] == 0 && ile[1] == 1) res = 1;
	else if (ile[0] == 1 && ile[1] == 1) res = 1;
	else if (ile[0] == 2 && ile[1] == 0) res = 0;
	else if (ile[0] == 0 && ile[1] == 2) res = 1;
	else if (ile[0] == 0 && ile[1] == 0) {
		res = -1;
		juzsiecofnalem = true;
	}

	if (jest() && juzsiecofnalem == false) {
		juzsiecofnalem = true;
		// cout << "musze sie cofnac!\n";	
		return -1;
	}
	
	sciezka += to_string(res);
	for (auto it : sciezka)
		cout << it;
	cout << "\n";	
		
	return res;
}

void rozpocznij(int a, int b) {
    // cout << "a = " << a << " b = " << b << "\n"; 
	if (b > 0) mammargines = true;
}
