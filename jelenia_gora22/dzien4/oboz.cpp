#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second // debugging /*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
	cout << "[ " << vars << " = "; string delim = "";
	(..., (cout << delim << values, delim = ", "));
	cout << " ]\n";
}
/**/

constexpr int MxN = 2e5+5;
constexpr int INF = 1e9+7;
int P[19];

bool p2(int x) {
	return ((x&(x-1)) == 0);
}

int toP2(int x) {
	for (int i=0; i<=18; i++)
		if ((1<<i) >= x)
			return (1<<i) - x;
}

void solve()
{
	int n; cin >> n;
	map<int, int> mp;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		mp[x]++;
	}
	vector<int> a;
	for (auto p : mp)
		a.push_back(p.SD);
	n = a.size();
	
	for (int i=0; i<=18; i++)
		for (int j=0; j<=18; j++)
		{
			int k1 = 0;
			int pre = i;
			while (k1 < n && pre-a[k1] >= 0)
				pre -= a[k1++];
			int k2 = n-1;
			int suf = j;
			while (k2 >= 0 && suf-a[k2] >= 0)
				suf -= a[k2--];
			deb(i, j, k1, k2);
		}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i=1; i<=18; i++)
		P[i] = (1<<(i-1));

	int q; cin >> q;
	while (q--)
		solve();

	return 0;
}
