#include <iostream>
#include "dinString.hpp"
#include "list.hpp"
using namespace std;
enum VRSTA{MEDO = 1,ZEKO,KUCA,MACA};

class Igracka{
protected:
    DinString naziv;
    DinString opseGod;
public:
    Igracka(){
        naziv = "brao";
        opseGod = "9-99";
    }
    Igracka(DinString n,DinString o){
        naziv = n;
        opseGod = o;
    }
    DinString get_naziv()const{
        return naziv;
    }
    DinString get_opsegGod()const{
        return opseGod;
    }
    virtual void ispis(){}
};

class PlisanaIgracka : public Igracka{
private:
    VRSTA vrsta;
public:
    PlisanaIgracka(){
        naziv = "Hello kitty";
        opseGod = "2-7";
        vrsta = MACA;
    }
    PlisanaIgracka(DinString n,DinString o,VRSTA v){
        naziv = n;
        opseGod = o;
        vrsta = v;
    }
    void ispis(){
        cout << "Naziv igracke: " << naziv << endl;
        cout << "Opseg godina: " << opseGod << endl;
        cout << "Vrsta plisane igracke: ";
        if(vrsta == 1){
            cout << "Medo.\n";
        }
        else if(vrsta == 2){
            cout << "Zeko.\n";
        }
        else if(vrsta == 3){
            cout << "Kuca.\n";
        }
        else{
            cout << "Maca.\n";
        }
    }
};

class Autic : public Igracka{
private:
    bool struja;
public:
    Autic(){
        naziv = "brmbrm";
        opseGod = "5-15";
        struja = true;
    }
    Autic(DinString n,DinString o,bool a){
        naziv = n;
        opseGod = o;
        struja = a;
    }
    void ispis(){
        cout << "Naziv autica: " << naziv<<endl;
        cout << "Opseg godina: " << opseGod << endl;
        if(struja){
            cout << "Autic je na struju."<<endl;
        }
        else{
            cout << "Autic nije na struju."<<endl;
        }
    }
};

int main()
{   cout << "IGRACKE IGRACKE IGRACKE IGRACKE" << endl<<endl<<endl;
    Igracka i1();
    Igracka i2("brao","9-99");
    cout << "PLISANA IGRACKA" << endl;
    PlisanaIgracka p1();
    PlisanaIgracka p2("Hello Kitty","5-7",MACA);
    PlisanaIgracka p;
    p.ispis();
    cout << "\nAUTIC" << endl;
    Autic a1();
    Autic a2("brmbrm","5-15",true);
    Autic a;
    a.ispis();
    return 0;
}
