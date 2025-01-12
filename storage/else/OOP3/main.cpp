#include <iostream>
#include "przyjaciele.h"

using namespace std;

bool sedzia(Punkt &pkt, Prostokat &prst)
{
    if ((pkt.x >= prst.x && pkt.x <= prst.x + prst.szerokosc) && (pkt.y >= prst.y && pkt.y <= prst.y + prst.wysokosc))
        return 1;
    else
        return 0;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    Punkt pkt("A", -3, -1);
    pkt.wczytaj();

    Prostokat prst("Prostokat", 0, 0, 10, 10);
    prst.wczytaj();

    cout<<(sedzia(pkt, prst) ? "TAK\n" : "NIE\n");

    return 0;
}
