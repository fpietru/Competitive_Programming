#include <iostream>
void f(int n){if (n == 0)return;else{f(n/2);for(int i=0; i<n; i++)printf(":");printf("\n");f(n/2);}}int main(){int n;std::cin >> n;f(n);return 0;}