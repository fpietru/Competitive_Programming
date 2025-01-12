//  DAMIAN TRAFIA£EK
#include <bits/stdc++.h>
using namespace std;

int n,cnt=0;
struct Film{
    int cost;
    int deadline;
    int nr;
};
struct Montaz{
    int costMax;
    int deadlineMax;
    int nrMax;
    int kolejnosc;

    bool operator<(const Montaz& element) const{
        return costMax < element.costMax;
    }
};


vector<Film> filmy;
vector<Film> plany;
priority_queue<Montaz> kolejka;


void wczytajFilmy(){
    for(int i=0;i<n;++i){
        cin>>filmy[i].cost>>filmy[i].deadline;
        filmy[i].nr=i+1;
        --filmy[i].cost;
    }
}

void sortujFilmy(){
    sort(filmy.begin(),filmy.end(),[](Film v1, Film v2){ return (v1.deadline==v2.deadline) ? v1.cost<v2.cost : v1.deadline<v2.deadline; });
}

void przygotujPlecak(){
    Montaz pom;
    int day=1;

    for( auto [cost,deadline,nr] : filmy){
        if(day+cost<=deadline){
            kolejka.push({cost,deadline,nr});
            ++cnt;
            day+=cost+1;
        }
        else if(!kolejka.empty()){
            pom = kolejka.top();
            if(cost<pom.costMax){
                kolejka.pop();
                kolejka.push({cost,deadline,nr});
                day+=cost-pom.costMax;
            }
        }
    }
}

void przygotujPlany(){
    Montaz pom;
    while(!kolejka.empty()){
        pom = kolejka.top();
        plany.push_back({pom.costMax,pom.deadlineMax,pom.nrMax});
        kolejka.pop();
    }
}

void posortujPlany(){
    sort(plany.begin(),plany.end(), [](Film v1, Film v2){return v1.deadline < v2.deadline;});
}

void wypiszPlany(){
    int day=1;

    cout<<cnt<<"\n";
    for(auto [cost,deadline,nr] : plany){
        cout<<nr<<" "<<day<<"\n";
        day+=cost+1;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    filmy.resize(n);
    wczytajFilmy();

    sortujFilmy();

    przygotujPlecak();

    przygotujPlany();

    posortujPlany();

    wypiszPlany();

    return 0;
}
