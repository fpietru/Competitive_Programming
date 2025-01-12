#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

class Punkt
{
    float x, y;
    string nazwa;
public:
    void wyswietl()
    {
        cout<<"["<<nazwa<<"] ("<<x<<","<<y<<")\n";
    }
    Punkt(string n="S", float a=0, float b=0)
    {
        nazwa = n;
        x = a;
        y = b;
    }
};

class Kolo :public Punkt
{
protected:
    float r;
    string nazwa;

public:
    void wyswietl()
    {
        cout<<nazwa<<" {\n";
        cout<<"    Sr = ";
        Punkt::wyswietl();
        cout<<"    r = "<<r<<"\n";
        cout<<"    P = "<<M_PI*r*r<<"\n}\n";
    }

    Kolo(string nk="A", string np="S", float ap=0, float bp=0, float rk=0)
    :Punkt(np, ap, bp)
    {
        nazwa = nk;
        r = rk;
    }
};

class Kula :public Kolo
{
    string nazwa;
public:
    Kula(string nku="A", string npku="S", float apku=0, float bpku=0, float rku=0)
    :Kolo(nku, npku, apku, bpku, rku)
    {
        nazwa = nku;
    }

    void wyswietl()
    {
        Kolo::wyswietl();
        cout<<"{ V = "<<4/3*M_PI*r*r*r<<"}\n";
    }
};

int main()
{
    Kula k1("BUBA", "CENTRUM BUBY", 100, 250, 800);
    k1.wyswietl();
    return 0;
}
