#include <bits/stdc++.h>
using namespace std;

struct Znak{int sn=0;char c;};
enum Type{_impossible=false,_possible=true,_pionowo=-1,_poziomo=-2,_checked=-3};

int maxWymiar=1001;
int n,m;

vector< vector<Znak> > tabela (maxWymiar,vector<Znak> (maxWymiar));
map<char,int> litery;

vector<int> granice(2);
vector<int> rozmiary;
map<int,bool> rozmiaryDoSprawdzenia;
vector<int> wyniki;


void wczytajTabele();
void wczytajSzablon();
void wypiszTabele();
void ustawGraniczneDlugosciSzablonu();


bool sanityCheck();

int nwdLiter();
int NWD(int a, int b);


bool isPossibleVertically(int sn,int wiersz,int kolumna,int dl, int kierunek){


    if(wiersz+dl-1>m)return _impossible;
    else{
        if(kierunek==_pionowo){
            for(int i=0;i<dl;++i) if(tabela[1][i+1].c!=tabela[kolumna][wiersz+i].c || tabela[kolumna][wiersz+i].sn==sn)return _impossible;
            for(int i=0;i<dl;++i)tabela[kolumna][wiersz+i].sn=sn;
        }else {
//          poziomo
            for(int i=0;i<dl;++i) if(tabela[i+1][1].c!=tabela[kolumna][wiersz+i].c || tabela[kolumna][wiersz+i].sn==sn)return _impossible;
            for(int i=0;i<dl;++i)tabela[kolumna][wiersz+i].sn=sn;
        }
    }
    return _possible;
}

bool isPossibleHorizontally(int sn,int wiersz,int kolumna,int dl, int kierunek){
    if(kolumna+dl-1>n)return _impossible;
    else{
        if(kierunek==_pionowo){
            for(int i=0;i<dl;++i) if(tabela[1][i+1].c!=tabela[kolumna+i][wiersz].c || tabela[kolumna+i][wiersz].sn==sn)return _impossible;
            for(int i=0;i<dl;++i)  tabela[kolumna+i][wiersz].sn=sn;
        }else{
//          poziomo
            for(int i=0;i<dl;++i) if(tabela[i+1][1].c!=tabela[kolumna+i][wiersz].c || tabela[kolumna+i][wiersz].sn==sn)return _impossible;
            for(int i=0;i<dl;++i)  tabela[kolumna+i][wiersz].sn=sn;
        }
    }
    return _possible;
}

bool sprawdzSzablon(int sn,int dl, int kierunek){
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;++i){
            if(tabela[i][j].sn!=sn){
                if( isPossibleHorizontally(sn,j,i,dl,kierunek) ) i+=dl-1;
                else if( !isPossibleVertically(sn,j,i,dl,kierunek) ) return _impossible;
            }
        }
    }

    return _possible;
}

void ustawRozmiaryDoSprawdzenia(){
    int s=granice[0],i=1;
    while(s*i<=granice[1]&&s*i<=max(n,m) ){
        if( m%(s*i)==0 || n%(s*i)==0){
            rozmiary.push_back(s*i);
            rozmiaryDoSprawdzenia[s*i]=true;
        }
        ++i;
    }

}



bool czyPalindrom(int dl,int kierunek){
    if(kierunek==_pionowo){
            for(int i=1;i<=dl/2;++i){
                if(tabela[1][i].c!=tabela[1][dl-i+1].c)return _impossible;
            }
    }else if(kierunek==_poziomo){
            for(int i=1;i<=dl/2;++i){
                if(tabela[i][1].c!=tabela[dl-i+1][1].c)return _impossible;
            }
    }
//    cout<<"palindrom\n";
    return _possible;
}

void znajdzDobreSzablony(){

    int pom;
    for(int i=rozmiary.size()-1;i>=0;--i){
        if(rozmiaryDoSprawdzenia[ rozmiary[i] ] ){


            if( sprawdzSzablon(rozmiary[i],rozmiary[i],_pionowo) ){

                pom=rozmiary[i];
                wyniki.push_back(pom);
                rozmiaryDoSprawdzenia[pom]=false;

                while( pom%2==0 && czyPalindrom(pom,_pionowo) && czyPalindrom(pom/2,_pionowo) ){
                    pom/=2;
//                    wyniki.push_back(pom);
                    rozmiaryDoSprawdzenia[pom]=false;
                }

            }
            else if( sprawdzSzablon(-rozmiary[i],rozmiary[i],_poziomo) ){

                pom=rozmiary[i];
                wyniki.push_back(pom);
                rozmiaryDoSprawdzenia[pom]=false;

                while( pom%2==0 && czyPalindrom(pom,_poziomo) && czyPalindrom(pom/2,_poziomo) ){
                    pom/=2;
//                    wyniki.push_back(pom);
                    rozmiaryDoSprawdzenia[pom]=false;
                }

            }


        }else {
            wyniki.push_back( rozmiary[i] );
        }




    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    cin>>m>>n;
    wczytajTabele();

    if( !sanityCheck() ){
        cout<<0<<"\n\n";
        return 0;
    }

    ustawGraniczneDlugosciSzablonu();
    ustawRozmiaryDoSprawdzenia();


    znajdzDobreSzablony();





    int w=wyniki.size();
    if(w==0){
        cout<<0<<"\n\n";
        return 0;
    }
    cout<<w<<"\n";
    for(int i=w-1;i>=0;--i) cout<<wyniki[i]<<" ";





    return 0;
}




void ustawGraniczneDlugosciSzablonu(){
    int nwd=nwdLiter();
    granice[0]=0;
    granice[1]=0;
    for(auto pair : litery){
        granice[0]+=pair.second/nwd;
        granice[1]+=pair.second;
    }
}

bool sanityCheck(){
    for(auto pair : litery){
        if( pair.second%n!=0 && pair.second%m!=0 )return false;
    }
    return true;
}

int nwdLiter(){
    bool isFirst=true;
    int nwd;
    for(auto pair : litery){
        if(isFirst){
            isFirst=false;
            nwd=pair.second;
        }else{
            nwd=NWD(nwd,pair.second);
        }
    }

    return nwd;
}

int NWD(int a, int b){
  if(a == 0)
    return b;
  return NWD(b % a, a);
}



void wypiszTabele(){
    cout<<"\n";
    for(int j=1;j<=m;++j){
        for(int i=1;i<=n;++i){
            cout<<tabela[i][j].c<<" ";
        }
        cout<<"\n";
    }
}


void wczytajTabele(){
    char c;
    for(int j=1;j<=m;++j){
        for(int i=1;i<=n;++i){
            cin>>c;
            tabela[i][j].c=c;
            litery[c]++;
        }
    }
}

