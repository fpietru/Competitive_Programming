#include <bits/stdc++.h>
using namespace std;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

int rand(int a, int b)
{
	return a + rand() % (b-a+1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n = rand(1, 5);
	int l = rand(1, 5);
	
	set<string> st;
	for (int j=1; j<=n; j++)
	{
		string s = "";
		for (int i=1; i<=l; i++)
		{
			int r = rand(1, 10); 
			if (r == 1)
				s += "b";
			else if (r == 2)
				s += "c";
			else
				s += "a";
		}
		st.insert(s);	
	}
	
	cout << st.size() << " " << l << "\n";
	for (auto p : st)
		cout << p << "\n";
	
    return 0;
}
