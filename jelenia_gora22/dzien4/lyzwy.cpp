#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define second SD // debugging /*
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k;
	vector<int> lewe, prawe;
	
	for (int i=1; i<=n; i++)
	{
		char op; cin >> op;
		int rozm; cin >> rozm;
		if (op == 'L')
			lewe.push_back(rozm);
		else prawe.push_back(rozm);
	}
	
	if (lewe.size() > prawe.size())
		swap(lewe, prawe);
		
	multiset<int> st;
	for (auto p : prawe)
		st.insert(p);
	
	// deb(st);
	deb(lewe);
	deb(prawe);
	
	vector<int> ans;
	for (auto lewy : lewe)
	{
		auto it = st.find(lewy);
		if (it != st.end())
		{
			ans.push_back(0);
			st.erase(it);
		}
		else
		{
			auto low = st.lower_bound(lewy);
			auto high = st.upper_bound(lewy);
			ans.push_back(min(abs(lewy-*low), abs(lewy-*high)));
		}
	}
	
	deb(ans);

	return 0;
}
