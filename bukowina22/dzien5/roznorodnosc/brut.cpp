#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging 
/*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

constexpr int MxN = 3e5+5;
int wart[MxN];
pii zap[MxN];

int ileroznych(int i, int j, vector<int> &vec)
{
	set<int> st;
	for (int k=i; k<=j; k++)
		st.insert(vec[k]);
	return st.size();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++)
		cin >> wart[i];
	for (int i=1; i<=q; i++)
		cin >> zap[q].FR >> zap[q].SD;
		
	if (n > 11 || q > 1)
	{
		cout << "XD\n";
		return 0;
	}
	
	vector<int> vec;
	for (int i=1; i<=n; i++)
		vec.PB(wart[i]);
	sort(vec.begin(), vec.end());
	
	ll ans = 0LL;
	do
	{
		ll curr = 0LL;
		for (int i=0; i<n; i++)
			for (int j=i; j<n; j++)
				curr += ileroznych(i, j, vec);
		ans = max(ans, curr);
	} while (next_permutation(vec.begin(), vec.end()));
	cout << ans << "\n";

	return 0;
}
