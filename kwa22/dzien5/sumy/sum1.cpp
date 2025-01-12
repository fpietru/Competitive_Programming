#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

map<int, int> mp; 

bool ispow2(int x)
{
    return (x & (x - 1)) == 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		mp[x]++;
	}
	
	vector<pii> vec;
	for (auto p : mp)
		vec.push_back({p.FR, p.SD});
	
	if (vec.size() == 1)
	{
		if (ispow2(2*vec[0].FR))
		{
			cout << vec[0].SD / 2 << "\n";
			return 0;
		}
		else
		{
			cout << "0\n";
			return 0;
		}
	}
	else
	{
		int ans = 0;
		if (ispow2(vec[0].FR + vec[1].FR))
		{
			int ile = min(vec[0].SD, vec[1].SD);
			ans += ile;
			vec[0].SD -= ile;
			vec[1].SD -= ile; 
		}
			
		if (ispow2(2*vec[0].FR))
			ans += vec[0].SD / 2;
		
		if (ispow2(2*vec[1].FR))
			ans += vec[1].SD / 2;
				
		cout << ans << "\n";
	}
	
    return 0;
}
