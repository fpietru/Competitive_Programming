// DAMIAN TRAFIAŁEK
#include <bits/stdc++.h>
using namespace std;

const int modulo = 1e9+7;
enum Type{
    _undefined = 0,
    _taken = -1,
    _assigned = -2,
    _boundary=-3,
    _impossible = false,
    _possible = true,
};

struct Krasnal{
    int czapka=_undefined;
    int sasiad=_undefined;
};

vector<Krasnal> impreza;
map<int,int> pewniaki;
map<int, bool> odw;


bool wczytajKrasnali(int n)
{

    impreza.resize(n+2);

    impreza[0].sasiad=_boundary;
    impreza[0].czapka=_boundary;
    impreza[n+1].sasiad=_boundary;
    impreza[n+1].czapka=_boundary;

    for(int i=1;i<=n;++i){
        cin>>impreza[i].sasiad;

        if( pewniaki[ impreza[i].sasiad ] == _undefined ) pewniaki[ impreza[i].sasiad ] = i;
        else if( i-pewniaki[ impreza[i].sasiad ] != 2 ) return _impossible;
        else {
            impreza[i-1].czapka=_assigned;
            impreza[i].sasiad=_taken;
            impreza[i-2].sasiad=_taken;
        }
    }

    return _possible;
}


// KIERUNEK +1 TO ROSN¥CO A -1 TO MALEJ¥CO
bool zdeterminujPewniakiCzapki(int i,int kierunek,int n)
{
    while(i>=1 && i<=n){
        if(impreza[i].sasiad!=_taken && (impreza[i-kierunek].czapka==_assigned || impreza[i-kierunek].czapka==_boundary))
        {
            if( impreza[i+kierunek].czapka==_assigned) return _impossible;
            else if(impreza[i+kierunek].czapka==_undefined)
            {
                impreza[i+kierunek].czapka=_assigned;
                impreza[i].sasiad=_taken;
            }
        }

        i+=kierunek;
    }
    return _possible;
}

long long int silnia(long long int n){
    long long int s=1;
    while(n>=2){
        s=(s*n)%modulo;
        --n;
    }

    return s;
}

long long int policzKombinacje(int n)
{
  long long int dlCyklu=0, nCykli=0, pom=0, m=1;

  for(int i=1;i<=n;++i)
  {
      if( !odw[i] && impreza[i].czapka==_undefined )
      {
          nCykli++;
          dlCyklu=0;
          pom=i;
          while( pom<=n && !odw[pom] && impreza[pom].czapka==_undefined )
          {
            odw[pom]=true;
            pom+=2;
            dlCyklu++;
          }
          m= ( (m%modulo)*(dlCyklu%modulo))%modulo;
        }
    }
    m= (m*(silnia(nCykli))%modulo)%modulo;

    return m;
}

void wypiszImpreza()
{
    for(Krasnal el : impreza){
        cout<<" |"<<setw(3)<<el.sasiad;
    }
    cout<<" |\n";

    for(Krasnal el : impreza){
        cout<<" |"<<setw(3)<<el.czapka;
    }
    cout<<" | \n\n";


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n=0;
    long long int m;

    cin>>n;

    bool validFormation = wczytajKrasnali(n);
    if( !validFormation )cout<<_undefined;
    else{

        bool isValidForward = zdeterminujPewniakiCzapki(1,1,n);
        bool isValidBackwards = zdeterminujPewniakiCzapki(n,-1,n);
        if( !isValidForward || !isValidBackwards) cout<<_undefined;
        else {
                m=policzKombinacje(n);
                cout<<m;
        }
    }


    return 0;
}
