#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second
#define PB push_back

constexpr int MxN = 133;
int winda[MxN][MxN][MxN];
bool vis[MxN][MxN][MxN];
struct pos {
	int z, y, x;
};
ostream& operator<< (ostream &os, pos p) {
	os << "(" << p.z << "," << p.y << "," << p.x << ")";
	return os;
}
vector<vector<pos>> windy;
int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int x, y, z; cin >> x >> y >> z;
	for (int i=1; i<=z; i++)
		for (int j=1; j<=y; j++)
			for (int k=1; k<=x; k++) {
				char c; cin >> c;
				vis[i][j][k] = (c == 'X');
			}
	
	int m; cin >> m;
	for (int i=1; i<=m; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		b = y - b + 1;
		vector<pos> vecwinda;
		for (int p=c; p<=d; p++)
			if (vis[p][b][a] == false) {
				winda[p][b][a] = i;
				vecwinda.PB({p, b, a});
			}
		windy.PB(vecwinda);
	}
	
	pos st, ed;
	cin >> st.x >> st.y >> st.z;
	cin >> ed.x >> ed.y >> ed.z;
	st.y = y - st.y + 1;
	ed.y = y - ed.y + 1;
	
	int ans = -1;
	deque<pair<pos, int>> Q;
	Q.push_front({st, 0});
	vis[st.z][st.y][st.x] = true;
	
	while (!Q.empty()) {
		pair<pos, int> p = Q.front();
		Q.pop_front();
		pos v = p.FR;
		int d = p.SD;
		
		if (v.z == ed.z && v.y == ed.y && v.x == ed.x) {
			ans = d;
			break;
		}
		
		if (winda[v.z][v.y][v.x])
			for (auto &it : windy[winda[v.z][v.y][v.x]-1]) {
				if (vis[it.z][it.y][it.x] == false) {
					Q.push_front({it, d});
					vis[it.z][it.y][it.x] = true;
				}
				winda[it.z][it.y][it.x] = 0;
			}
		
		for (int k=0; k<4; k++) {
			int ny = v.y + dy[k];
			int nx = v.x + dx[k];
			if (ny < 1 || ny > y || nx < 1 || nx > x) continue;
			if (vis[v.z][ny][nx] == false) {
				Q.push_back({{v.z, ny, nx}, d+1});
				vis[v.z][ny][nx] = true;
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
