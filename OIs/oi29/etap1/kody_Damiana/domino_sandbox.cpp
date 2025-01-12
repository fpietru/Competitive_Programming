#include <bits/stdc++.h>
using namespace std;

const int fiboLimit=91;
long long int fibo[fiboLimit+1];
map<long long int,int>fiboMap;

queue<long long int> kolejka;

void createFibos(){
    fibo[0]=1; fibo[1]=1;
    fiboMap[1]=1;

    for(int i=2;i<=fiboLimit;++i){
        fibo[i]=fibo[i-1]+fibo[i-2];
        fiboMap[ fibo[i] ]=i;
    }
}

void showFibos(){
    cout<<"\nfibo : \n";
    for(int i=1; i <=fiboLimit ;++i)cout<<i<<" : "<<fibo[i]<<"\n";
    cout<<"\nfiboReverse : \n";
    for(auto pair : fiboMap)cout<<pair.first<<" : "<<pair.second<<"\n";
}

void getPrimeFactors(long long int n,bool addToKolejka,bool showPrimes){
    while (n % 2 == 0){
        if(showPrimes)cout << 2 << " ";

        if(addToKolejka)kolejka.push(2);
        n = n/2;
    }

    for (long long int i = 3; i*i <= n ; i = i + 2){
        while (n % i == 0){
            if(showPrimes)cout << i << " ";
            if(addToKolejka)kolejka.push(i);
            n = n/i;
    }}

    if (n > 2){
        if(showPrimes)cout << n << " ";
        if(addToKolejka)kolejka.push(n);
    }
}

long long int resztaRozkladu(long long int k){
    for(int i=fiboLimit;i>=2;--i)
        while(k%fibo[i]==0)
            k/=fibo[i];

    return k;
}

int zliczDlugosc(long long int k){
    int dl=0;
    for(int i=fiboLimit;i>1;--i)
        while(k%fibo[i]==0)
        {
            dl+=i+1;
            k/=fibo[i];
        }
    return dl-1;
}

int secondaryFunction(long long int r, long long int k, long long int previous);
int myFunction(long long int k,long long int previous);


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    createFibos();
    long long int m,n;


    cin>>m;
    n = myFunction(m,0);
    if(n)cout<<n;
    else cout<<"NIE";

    return 0;
}


int secondaryFunction(long long int r, long long int k, long long int previous){

    getPrimeFactors(r,true,false);
    int total=0, primesLeft=kolejka.size();
    while( !kolejka.empty() )
    {
        long long int prime=kolejka.front();
        kolejka.pop();

        for(int i=1;i<=fiboLimit;++i){
            if(fibo[i]%prime==0 and k%fibo[i]==0)
            {
                k/=fibo[i];
                // +1 JAKO ZE CZARNA KOLUMNA O DLUGOSCI JEDEN ABY PODLACZYC INNE CZYNNIKI Z CIAGU FIBO
                total+=i+1;
                --primesLeft;
                break;
            }
        }
    }

    //  JESLI K = 1 UDALO SIE ROZLOZYC DANA LICZBE WIEC FINITO, BO KOLEJNE PRZEJSCIE PRZEZ FUNKCJE ZWIEKSZY O +1
    if(primesLeft==0 and k!=1)
        //  NIE ODEJMUJE OD TOTAL -1 BO MUSI BYC JAKAS KONTYNUACJA
        return myFunction( k , previous+total);
    else if(primesLeft==0)
        //  W TYMPRZYPADKU POZYTYWNIE ROZLOZYLISMY LICZBE WIEC NIE BEDZIE KONTYNUOWAC Z ROZKLADANIEM WIEC -1 BY POZBYC SIE CZARNEGO BLOKU
        return previous+total-1;


    //  AT THIS POINT THE GIVEN NUMBER CANNOT BE DIVIDED BY ANY REMAINS SO IT'S FALSE
    return 0;
}

int myFunction(long long int k,long long int previous){
    if( fiboMap[k] )
        return previous + fiboMap[k];

    long long int r=resztaRozkladu(k);
    if( r==1 )
        return previous+zliczDlugosc(k);
    else
        return secondaryFunction(r, k, previous);

}
