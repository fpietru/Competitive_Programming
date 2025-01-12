#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
constexpr int MxL = 2e4+4; 
constexpr int m = 1e9+7, p = 31;
int h[MxN][MxL];
ll p_pow[MxL+10];
string s[MxN];
bool logic[MxN];
bool tozero[MxN];

int Hash(int a, int b, int i)
{
	return ((h[i][b] - ((ll)h[i][a-1] * p_pow[b-a+1])) % m + m) % m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	p_pow[0] = 1;
	for (int i=1; i<=MxL; i++)
		p_pow[i] = ((ll)p_pow[i-1] * p) % m;
	
	int n, l; cin >> n >> l;
	
	if (n == 1)
	{
		cout << "1 1\n";
		return 0;
	}
	
	for (int i=1; i<=n; i++)
	{
		cin >> s[i];
		h[i][0] = 0;
		for (int j=1; j<=l; j++)
			h[i][j] = ((ll)h[i][j-1] * p + (s[i][j-1]-'a'+1)) % m;	
	}
	
	int Rend = -1;
	int Lstart = -1;
	
	// max pref
	int low = 1;
	int high = l;
	
	while (low < high)
	{
		int mid = (low + high) >> 1;
		set<int> st;
		for (int i=1; i<=n; i++)
			st.insert(Hash(1, mid, i));
		
		if ((int)st.size() == 1)
			low = mid+1;
		else
			high = mid;
	}
	
	Lstart = low;
	
	// max suff
	low = 0;
	high = l;
	
	while (low < high)
	{
		int mid = (low + high) >> 1;
		set<int> st;
		for (int i=1; i<=n; i++)
			st.insert(Hash(l-mid+1, l, i));
		
		if ((int)st.size() == 1)
			low = mid+1;
		else
			high = mid;
	}

	Rend = l-low+1;
	
	int min_dst = 1e9;
	pii ans;
	
	for (int a=Lstart-1; a<Rend-1; a++)
		for (int b=Lstart-1; b<Rend-1; b++)
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
				for (auto pointer : mp)
					vec.push_back(pointer.SD);
					
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











