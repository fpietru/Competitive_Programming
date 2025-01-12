#include <bits/stdc++.h>

int los(int a, int b) {
    return a + std::rand()%(b-a+1);
}

constexpr int W = 10;

// arg1 - seed
// arg2 - n
// arg3 - czy odbicie (0 - nie, 1 - tak)
int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    assert(argc == 4);
    std::srand(std::atoi(argv[1]));

    std::cout << 1 << "\n";
    int n = std::atoi(argv[2]);

    int odbicie = std::atoi(argv[3]);

    std::cout << n << "\n";
    for (int i = 0; i < n; ++i) {
        int u = los(1, 2);
        int d = los(u, 2);
        int l = los(1, W);
        int r = los(l, W);

        if (odbicie) {
            std::cout << u << " " << W + 1 - r << " " << d << " " << W + 1 - l << "\n";
        } else {
            std::cout << u << " " << l << " " << d << " " << r << "\n";
        }
    }

    return 0;
}