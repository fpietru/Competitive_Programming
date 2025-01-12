/*
	Link: https://codeforces.com/contest/113/problem/C
*/
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

constexpr int MxSQ = 17321, MxB = 333, MIL = 1e6;
vector<int> pierwsze;
bool zlozona[MxSQ+21], mark[MIL+21];
ll ile[MxB] = {39176,35241,33867,33219,32691,32139,31928,31499,31341,31080,30899,30913,30576,30405,30301,30139,30087,30002,29854,29814,29600,29719,29406,29422,29436,29274,29336,29150,29172,29094,29091,28875,28873,28902,28653,28729,28749,28687,28754,28595,28584,28417,28392,28489,28355,28315,28386,28313,28256,28258,28169,28080,28070,28052,28033,28035,27971,28017,27892,27899,27976,27713,27847,27868,27831,27821,27783,27794,27716,27699,27611,27660,27723,27534,27588,27680,27510,27458,27448,27443,27498,27578,27454,27448,27327,27347,27304,27472,27326,27266,27219,27227,27345,27189,27308,27228,27199,27167,27086,27143,27101,27097,27178,27021,27107,27013,26975,27086,27143,27133,26917,27074,26976,26792,26905,26928,26827,26892,26881,26925,26796,26823,26879,26934,26831,26788,26788,26857,26912,26781,26706,26816,26714,26709,26784,26590,26671,26605,26625,26836,26539,26668,26606,26717,26639,26632,26642,26559,26499,26563,26417,26555,26338,26617,26477,26456,26642,26415,26339,26483,26470,26399,26468,26593,26352,26354,26345,26398,26378,26469,26346,26372,26390,26434,26306,26359,26331,26390,26348,26469,26168,26342,26128,26258,26390,26251,26268,26241,26223,26395,25941,26110,26293,26226,26247,26183,26099,26034,26139,26190,26168,26268,26107,26223,26137,26001,26145,26052,25999,26168,26038,26225,26168,26057,26095,26173,26094,25948,25966,25999,25994,26045,26114,25971,26158,25913,26090,25813,25930,25903,25956,26020,26001,25825,25939,25950,26045,25925,26008,25808,26013,25938,25712,25883,25989,25900,25794,25760,25943,25783,25953,25667,25756,25915,25963,25824,25858,25833,25905,25729,25951,25770,25971,25767,25859,25928,25627,25767,25863,25623,25772,25706,25657,25806,25819,25724,25712,25735,25587,25726,25606,25780,25597,25743,25704,25615,25592,25770,25735,25588,25755,25680,25519,25692,25737,25552,25616,25639,25521,25530};

int naprzedziale(ll a, ll b) {
	memset(mark, 0, sizeof(mark));
	if (a == 1) mark[0] = true;
	for (auto p : pierwsze) {
		if (p*p > b) break;
		ll st = a - (a%p);
		if (st < a) st += p;
		for (ll i=st; i<=b; i+=p)
			if (i != p) mark[i-a] = true;
	}
	int res = 0;
	for (int i=0; i<=b-a; i++) {
		if (mark[i] == 0 && (((a+i) % 4) == 1 || ((a+i) == 2))) {
			res++;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	zlozona[1] = true;
	for (ll i=2; i<=MxSQ; i++)
		if (zlozona[i] == false)
			for (ll j=i*i; j<=MxSQ; j+=i)
				zlozona[j] = true;
	for (int i=1; i<=MxSQ; i++)
		if (zlozona[i] == false)
			pierwsze.PB(i);

	ll a, b; cin >> a >> b;
	ll k1 = a / MIL;
	ll k2 = b / MIL;
	
	if (k1 == k2) cout << naprzedziale(a, b) << "\n";
	else {
		ll ans = naprzedziale(a, MIL*(k1+1)-1) + naprzedziale(MIL*k2, b);
		for (int i=k1+1; i<=k2-1; i++)
			ans += ile[i]; 
		cout << ans << "\n";
	}

	return 0;
}
