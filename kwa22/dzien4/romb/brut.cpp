#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

ll romb(int x)
{
	ll a = (ll)x;
	ll product = 1;
	
	while (x)
	{
		 product *= (ll)(x % 10);
		 x /= 10;
	}
	
	return a * product;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	set<ll> st;

	for (int i=1; i<1000000; i++)
		st.insert(romb(i));

	ll a, b; cin >> a >> b;
	auto U = st.upper_bound(b);
	auto L = st.lower_bound(a);
	
	int posU = distance(st.begin(), U);
	int posL = distance(st.begin(), L);
	
	cout << posU - posL << "\n";

    return 0;
}
