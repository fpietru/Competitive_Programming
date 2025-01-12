#include <bits/stdc++.h>
#include "zag.h"
using namespace std;
using pii = pair<int, int>;
#define PB push_back
#define FR first
#define SD second

vector<pii> ruchy;

void gen(int st, int ed, int lvl) {
	if (st > ed) return;
	int md = (st + ed) >> 1;
	ruchy.PB({lvl, md});
	gen(st, md-1, lvl+1);
	gen(md+1, ed, lvl+1);
}

void rozpocznij(int n) {
	gen(1, n, 1);
	sort(ruchy.begin(), ruchy.end());
	
	// for (auto [a, b] : ruchy)
	// 	cout << b << " ";
	// cout << "\n";
	
	int i = 0;
    while (!otworz(ruchy[i].SD)) {
		i++;
		if (i >= n)
			i = 0;
    }
}
