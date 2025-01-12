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

constexpr int MxN = 1e5+5;
int a[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	
	int i, j;
	if (n % 2 == 0)
		i = n / 2;
	else i = (n+1) / 2;
	
	j = n;
	ll ans = (ll)abs(a[i] - a[j]);
	for (int k=1; k<=n-2; k++)
	{
		if (k % 2 == 1)
			i--;
		else j--;
		ans += (ll)abs(a[i] - a[j]);
	}
	
	ll ans2 = 0LL;
	if (n % 2 == 1)
	{
		i = (n+1) / 2;
		j = 1;
		ans2 = (ll)abs(a[i] - a[j]);
		for (int k=1; k<=n-2; k++)
		{
			if (k % 2 == 1)
				i++;
			else j++;
			ans2 += (ll)abs(a[i] - a[j]);
		}
	}
	
	cout << max(ans, ans2) << "\n";

	return 0;
}
