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

	string s = "";
	
	int n = rand(1, 10);
	for (int i=1; i<=n; i++)
	{
		int r = rand(1, 10);
		if (r <= 2)
			s += "c";
		else if (r > 2 && r <= 4)
			s += "b";
		else
			s += "a";
	}
	
	string p = s.substr(0, rand(1, n));
	random_shuffle(p.begin(), p.end());
	
	cout << p << " " << s << "\n";

    return 0;
}
