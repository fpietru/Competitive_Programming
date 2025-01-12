#include <bits/stdc++.h>

// arg0 - nazwa pliku
// arg1 - sciezka do pliku 1
// arg2 - sciezka do pliku 2
int main(int argc, char** argv){
assert(argc == 3);
    std::ifstream f1((std::string(argv[1])));
    std::ifstream f2((std::string(argv[2])));

    long double a, b;
    f1 >> a;
    f2 >> b;

    long double eps = 1e-9;
    long double er = std::abs(a - b);
    if (er <= eps) {
        return 0;
    }
    std::cerr << "Error too large: " << er << std::endl;
    return 1;
}
