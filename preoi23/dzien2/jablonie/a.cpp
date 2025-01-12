#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9+7;
struct node {
	int Lazy;
	int mi = -INF, mx = -INF;
};
ostream& operator<< (ostream &os, node v) {
	os << "[" << v.mi << "," << v.mx << "] " << v.Lazy;
	return os;
}
constexpr int base = (1<<19);
constexpr int MxN = 5e5+5;
int arr[MxN];
node Tree[2*base];
int n, m;

void lazypush(int v) {
	if (Tree[v].Lazy) {
		Tree[2*v].mi += Tree[v].Lazy;
		Tree[2*v].mx += Tree[v].Lazy;
		Tree[2*v].Lazy += Tree[v].Lazy;
		Tree[2*v+1].mi += Tree[v].Lazy;
		Tree[2*v+1].mx += Tree[v].Lazy;
		Tree[2*v+1].Lazy += Tree[v].Lazy;
		Tree[v].Lazy = 0;	
	}
}

void pull(int v) {
	Tree[v].mi = (Tree[2*v].mi >= 0 ? Tree[2*v].mi : Tree[2*v+1].mi);
	Tree[v].mx = (Tree[2*v+1].mx >= 0 ? Tree[2*v+1].mx : Tree[2*v].mx);
}

void build(int v, int st, int ed, int L, int R) {
	if (R < st || ed < L) return;
	else if (st == ed) {
		Tree[v].mi = Tree[v].mx = arr[st];
	}
	else {
		int md = (st + ed) >> 1;
		build(2*v, st, md, L, R);
		build(2*v+1, md+1, ed, L, R);
		pull(v);
	}
}

void update(int v, int st, int ed, int L, int R) {
	if (R < st || ed < L) return;
	else if (L <= st && ed <= R) {
		Tree[v].mi++;
		Tree[v].mx++;
		Tree[v].Lazy++;
	}
	else {
		lazypush(v);
		int md = (st + ed) >> 1;
		update(2*v, st, md, L, R);
		update(2*v+1, md+1, ed, L, R);
		pull(v);
	}
}

int kty(int v, int st, int ed, int p) {
	if (st == ed)
		return Tree[v].mi;
	else {
		lazypush(v);
		int md = (st + ed) >> 1;
		if (p <= md) return kty(2*v, st, md, p);
		else return kty(2*v+1, md+1, ed, p);
	}
}

int upper(int v, int st, int ed, int x) {
	if (st == ed)
		return st;
	else {
		lazypush(v);
		int md = (st + ed) >> 1;
		if (x >= Tree[2*v+1].mi && Tree[2*v+1].mi >= 0)
			return upper(2*v+1, md+1, ed, x);
		else
			return upper(2*v, st, md, x);
	}
}

int naprzedziale(int a, int b) {
	int p1 = upper(1, 0, base-1, a-1);
	int p2 = upper(1, 0, base-1, b);
	return p2-p1;
}

void pracaupodstaw(int k) {
	int x = kty(1, 0, base-1, k);
	int c = upper(1, 0, base-1, x-1);
	if (c > 0) update(1, 0, base-1, 1, c);
	int f = upper(1, 0, base-1, x);
	update(1, 0, base-1, f-(k-c)+1, f);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> arr[i];
	sort(arr+1, arr+n+1);
	build(1, 0, base-1, 1, n);

	for (int i=1; i<=m; i++) {
		string op; cin >> op;
		if (op == "podlej") {
			int k; cin >> k;
			pracaupodstaw(k);
		}
		else {
			int a, b; cin >> a >> b;
			cout << naprzedziale(a, b) << "\n";
		}
	}	
	
	return 0;
}
