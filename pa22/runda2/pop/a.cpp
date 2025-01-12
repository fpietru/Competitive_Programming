#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging /*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

vector<int> v[22];
int ile[22];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	v[1] = {1};
	ile[1] = 1;
	int top = 1, dododania = 0;
	bool full = true;
	for (int i=2; i<=n; i++) {
		if (full) {
			top++;
			int b = __builtin_popcount(top);
			v[b].PB(top);
			ile[b]++;
			if (b > 1) {			
				ile[b-1]--;
				dododania = b-1;
				full = false;
			}
		}
		else {
			ile[dododania]++;
			if (dododania > 1) {
				ile[dododania-1]--;
				dododania--;				
			}
			else full = true;
		}
	}
	vector<int> ans;
	for (int i=1; i<22; i++) {
		for (int j=0; j<ile[i]; j++)
			ans.PB(v[i][j]);
	}
	sort(ans.begin(), ans.end(), greater<int>());
	cout << ans.size() << "\n";
	for (auto it : ans)
		cout << it << " ";
	cout << "\n";

	return 0;
}
