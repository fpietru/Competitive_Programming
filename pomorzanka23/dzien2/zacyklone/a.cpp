#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PB push_back

constexpr ll MOD = 694202137;
constexpr ll p = 127;
constexpr int R = 35;
constexpr int MxN = 2e5+5;
ll ppow[MxN];
bool mampotegi;

void wypisz(vector<bool> vec) {
	for (auto it : vec)
		cout << it;
}

vector<ll> haszuj(vector<bool> &vec) {
	int n = vec.size();
	vector<ll> res(n+1);
	for (int i=1; i<=n; i++)
		res[i] = (res[i-1] * p + (vec[i-1]+1)) % MOD;
	return res;
}

vector<bool> convert(ll x) {
	vector<bool> res;
	while (x) {
		res.PB(x&1);
		x >>= 1;
	}
	while ((int)res.size() < R)
		res.PB(0);
	reverse(res.begin(), res.end());
	return res;
}

ll wart(vector<bool> &vec) {
	ll res = 0LL, podst = 1LL;
	int n = vec.size();
	for (int i=n-1; i>=0; i--) {
		res += podst*vec[i];
		podst <<= 1;
	}
	return res;
} 

void wyznacz() {
	ppow[0] = 1;
	for (int i=1; i<MxN; i++)
		ppow[i] = (ppow[i-1] * p) % MOD;
	mampotegi = true;
}

vector<bool> zapisz(vector<bool> v) {
	if (mampotegi == false)
		wyznacz();

	vector<bool> hstr = convert(haszuj(v).back());
	for (auto it : hstr)
		v.PB(it);
	return v;
}

vector<bool> odczytaj(vector<bool> v) {
	if (mampotegi == false)
		wyznacz();

	vector<bool> dd = v;
	for (auto it : v)
		dd.PB(it);
	v = dd;
	
	wypisz(v);
	cout << "\n";
	
	int n = v.size();
	vector<ll> h = haszuj(v);
	
	int m = n/2-R;
	
	for (int i=0; i<=n-m-R; i++) {
		ll H = (h[i+m] - (h[i+1]*ppow[m]) % MOD + MOD) % MOD;
		vector<bool> pref;
		for (int j=i; j<i+m; j++) pref.PB(v[j]);
		
		vector<bool> suff;
		for (int j=1; j<=R; j++)
			suff.PB(v[i+m-1+j]);
		
		wypisz(pref);
		cout << " ";
		wypisz(suff);
		cout << " " << suff.size() << " " << H << " " << wart(suff) << "\n";
		
			
		if (H == wart(suff)) {
			vector<bool> res;
			for (int j=i; j<i+m; j++)
				res.PB(v[j]);
			return res;
		}
	}
	return v;
}

int rand(int a, int b) {
	return a + rand() % (b-a+1);
}

int main() {
	srand(time(NULL));
	// ios_base::sync_with_stdio(0);
	// cin.tie(0), cout.tie(0);
	
	vector<bool> vec = {1,1,0,1};
	vector<bool> z = zapisz(vec);
	vector<bool> r = odczytaj(z);

	
	/*while (true) {
		vector<bool> vec;
		int n = rand(1, 10);
		for (int i=1; i<=n; i++)
			vec.PB(rand(0,1));
		vector<bool> zap = zapisz(vec);
		vector<bool> zap2 = zap;
		int r = rand(0, n);
		rotate(zap.begin(), zap.begin()+r, zap.end());
		vector<bool> res = odczytaj(zap);
		if (res == vec) {
			cout << "OK\n";
		}
		else {
			wypisz(vec);
			wypisz(res);
			wypisz(zap2);
			wypisz(zap);
			// cout << r << "\n";
			break;
		}
	}*/
	
	
	return 0;
};
