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

constexpr int MxN = 505;
bool mam[MxN][MxN];
vector<pii> krawedzie;
int n, podzadanie;

int rand(int a, int b) {
	return a + rand() % (b-a+1);
}

void addedge(int a, int b) {
	if (a == b || mam[a][b] || mam[b][a]) return;
	mam[a][b] = mam[b][a] = true;
	krawedzie.PB({a, b});
}

void dodajdogranic(int L, int R) {
	if (L != 0)
		for (int i=L+1; i<R; i++)
			addedge(L, i);	
	if (R != n+1)
		for (int i=L+1; i<R; i++)
			addedge(R, i);
}

void zbuduj(int st, int ed, int B) {
	dodajdogranic(st, ed);
	if (ed - st - 1 <= 3) {
		for (int i=st+1; i<ed-1; i++)
			addedge(i, i+1);
		return;
	}
	vector<int> wyroznione;
	int nB = sqrt(ed-st+1);
	int przed = st;
	for (int i=st+1; i<=ed-1; i++)
		if ((i % B) == 0) {
			zbuduj(przed, i, nB);
			wyroznione.PB(i);
			przed = i;
		}
	zbuduj(przed, ed, nB);
	for (auto it1 : wyroznione)
		for (auto it2 : wyroznione)
			addedge(it1, it2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> podzadanie;
	zbuduj(0, n+1, sqrt(n));
	
	cout << krawedzie.size() << "\n";
	for (auto it : krawedzie)
		cout << it.FR << " " << it.SD << "\n";

	return 0;
}
