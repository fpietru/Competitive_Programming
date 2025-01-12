#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PB push_back

constexpr ll MOD = 694202137;
constexpr ll p = 127;
constexpr int R = 35;

void wypisz(vector<bool> vec) {
	for (auto it : vec)
		cout << it;
	cout << "\n";
}

ll haszuj(vector<bool> &vec) {
	ll res = 0LL;
	for (auto it : vec)
		res = (res * p + (it+1)) % MOD;
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

vector<bool> zapisz(vector<bool> v) {
	vector<bool> hstr = convert(haszuj(v));
	for (auto it : hstr)
		v.PB(it);
	return v;
}

vector<bool> odczytaj(vector<bool> v) {
	int n = v.size();
	vector<bool> res;
	for (int i=0; i<=n; i++) {
		// wypisz(v);
		vector<bool> pref;
		for (int j=0; j<n-R; j++)
			pref.PB(v[j]);
		ll H = haszuj(pref);
		vector<bool> suff;
		for (int j=n-R; j<n; j++)
			suff.PB(v[j]);
		if (H == wart(suff)) {
			// cout << pref.size() << " " << suff.size() << "\n";
			// cout << "H = " << H << "\n";
			// wypisz(suff);
			// cout << "wart = " << wart(suff) << "\n";
			 
			res = pref;
			break;
		}
		rotate(v.begin(), v.begin()+1, v.end());
	}
	return res;
}
