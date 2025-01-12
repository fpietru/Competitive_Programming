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

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n = atoi(argv[1]);
	cout << n << " 1 1\n";

    return 0;
}
