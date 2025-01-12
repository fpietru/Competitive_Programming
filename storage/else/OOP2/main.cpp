#include <iostream>
#include "event.h"

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    Event w1;
    w1.show();
    w1.load();
    w1.show();

    return 0;
}
