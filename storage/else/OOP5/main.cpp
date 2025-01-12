#include <iostream>

using namespace std;

class Ksztalt
{
public:
    virtual void oblicz_pole() = 0;
    // czysta funkcja wirtualna
};

class Kolo :public Ksztalt
{
    float r;
public:
    Kolo(float x = 0)
    {
        r = x;
    }
    virtual void oblicz_pole()
    {
        cout<<"Pole kola = "<<3.14*r*r<<"\n";
    }
};

class Kwadrat :public Ksztalt
{
    float a;
public:
    Kwadrat(float x = 0)
    {
        a = x;
    }
    virtual void oblicz_pole()
    {
        cout<<"Pole kwadratu = "<<a*a<<"\n";
    }
};

void obliczenia(Ksztalt *x)
{
    x -> oblicz_pole();
}

int main()
{

    Kolo k(1);
    Kwadrat kw(2);
    Ksztalt *wsk;

    wsk = &k;
    wsk -> oblicz_pole();

    wsk = &kw;
    wsk -> oblicz_pole();

    obliczenia(wsk);

    return 0;
}
