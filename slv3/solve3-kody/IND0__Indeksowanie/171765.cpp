#include <iostream>
#define R(x,n)for(int x=0;x<(n);x++)
int main(){
	int n,m;std::cin>>n>>m;
	R(i,n){
		R(j,m) printf("(%d,%d) ",i,j);
		printf("\n");
	} return 0;
}