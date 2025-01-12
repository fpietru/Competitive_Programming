#include <bits/stdc++.h>
#include <complex>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
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

typedef complex<double> punkt;
#define x real()
#define y imag()
constexpr int MxN = 61;
constexpr int MIL = 1e6;
constexpr double eps = 0.00001;
punkt p[MxN];
vector<punkt> wspolne;
int c[MxN]
int n;

void wyznaczwspolne()
{
	for (int i=1; i<n; i++)
		for (int j=i+1; j<=n; j++)
		{
			double r1 = c[i];
			double r2 = c[j];
			double d = sqrt(norm(p[i] - p[j]));
						
			if ((r1 + r2 - d < 0) || (d - abs(r1 - r2) < 0))
				continue;
			if (r1 + r2 - d <= eps)
			{
				ld iloczyn = r1 / (r1 + r2);
				punkt v(p[j].x - p[i].x,p[j].y - p[i].y);
				v *= ilocznyn;
				przeciecia.PB(p[i] + v);
			}
			
		}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
		
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		double x, y; cin >> x >> y;
		cin >> c[i];
		p[i](x, y);
		// cin >> p[i].x >> p[i].y >> c[i];
		// p[i] *= MIL;
	}
		
	wyznaczwspolne();
	for (auto it : wspolne)
		cout << it << "\n";

	return 0;
}
