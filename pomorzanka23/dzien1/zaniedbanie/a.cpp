#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second
#define PB push_back

constexpr int INF = 1e9+7;
constexpr int MxN = 20004;
string tab[MxN];
map<char, int> mp;
int zamien[10];
bool bylopocz[10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n = 20000;
	for (int i=1; i<=n; i++) {
		cin >> tab[i];
		for (auto c : tab[i])
			mp[c]++;
		bylopocz[tab[i][0]-'0'] = true;
	}
	
	vector<pii> vec;
	for (auto it : mp) {
		if (bylopocz[it.FR-'0'] == false)
			vec.PB({INF, it.FR-'0'});
		else vec.PB({it.SD, it.FR-'0'});
	}
	sort(vec.begin(), vec.end(), greater<pii>());

	for (int i=0; i<=9; i++) {
		// cout << vec[i].FR << " " << vec[i].SD << " " << bylopocz[vec[i].SD] << "\n";
		zamien[vec[i].SD] = i;
	}
	
	for (int i=1; i<=n; i++) {
		for (auto c : tab[i])
			cout << zamien[c-'0'];
		cout << "\n";
	}

	return 0;
}
