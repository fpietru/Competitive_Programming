#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e3+16;
set<long double> st;
long double ans[MxN];

void addguy(int ktory)
{
	vector<long double> v;
	for (auto p : st)
		v.push_back(p);

	long double max_dst = 0;
	long double A, B;
	for (int i=0; i<v.size()-1; i++)
	{
		if (v[i+1] - v[i] > max_dst)
		{
			max_dst = v[i+1] - v[i];
			A = v[i];
			B = v[i+1];
		}
	}
	
	long double new_guy = (A+B) / 2;
	ans[ktory] = new_guy;
	
	st.insert(new_guy);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, dl, z;
	cin >> n >> dl >> z;
	for (int i=0; i<n; i++)
	{
		long double x; cin >> x;
		st.insert(x);
	}
	
	for (int i=1; i<MxN; i++)
		addguy(i);
		
	for (int i=0; i<z; i++)
	{
		int x; cin >> x;
		cout << ans[x] << "\n";
	}

	return 0;
}
