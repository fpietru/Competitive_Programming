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

constexpr int MxN = 505;
string s[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, l; cin >> n >> l;
	for (int i=1; i<=n; i++)
		cin >> s[i];
	
	int min_dst = 1e9;
	pii ans;
	
	for (int a=0; a<l; a++)
		for (int b=a; b<l; b++)
		{
			bool flag = 1;
			map<string, int> mp;
			for (int i=1; i<=n; i++)
			{
				string sub = s[i].substr(a, b-a+1);
				if (mp[sub] != 0)
				{
					flag = 0;
					break;
				}
				else
					mp[sub] = i;
			}
			
			if (flag == 0)
				continue;
			
			if (flag)
			{
				vector<int> vec;
				for (auto p : mp)
					vec.push_back(p.SD);
					
				bool flag2 = 1;
				for (int i=0; i<n-1; i++)
				{
					// deb(a, b, vec[i], vec[i+1]);
					if (vec[i] > vec[i+1])
					{
						flag2 = 0;	
						break;
					}
				}
				
				if (flag2 && b-a+1 < min_dst)
				{
					min_dst = b-a+1;
					ans = {a+1, b+1};
				}
			}
		}
		
	cout << ans.FR << " " << ans.SD << "\n";

    return 0;
}
