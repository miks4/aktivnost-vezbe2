#include <iostream>
#include "dinString.hpp"
#include "list.hpp"
using namespace std;
class Karta{
protected:
    DinString polazak;
    DinString dolazak;
    float cena;
    float km;
    int indetifikator;
public:
    Karta(){
        polazak = "Beograd";
        dolazak = "Oslo";
        cena = 200;
        km = 5500;
        indetifikator = 321;
    }
    Karta(DinString p,DinString d,float k,float c,int i){
        polazak = p;
        dolazak = d;
        cena = k;
        km = c;
        indetifikator = i;
    }
    DinString get_polazak()const{
        return polazak;
    }
    DinString get_dolazak()const{
        return dolazak;
    }
    float get_cena()const{
        return cena;
    }
    float get_km()const{
        return km;
    }
    int get_indet()const{
        return indetifikator;
    }
    void set_polazak(const DinString p){
        polazak = p;
    }
    void set_dolazak(const DinString d){
        dolazak = d;
    }
    void set_cena(const float k){
        cena = k;
    }
    void set_km(const float c){
        km = c;
    }
    void set_i(const int i){
        indetifikator = i;
    }
    virtual bool jeftinaKarta(){}
};

class AvionskaKarta : public Karta{
public:
    AvionskaKarta() : Karta(){}
    AvionskaKarta(DinString p,DinString d,float k,float c,int i) : Karta(p,d,k,c,i){}
    bool jeftinaKarta(){
        if((km / cena) < 1){
            return false;
        }
        else{return true;}

    }
    void ispisAvionskeKarte(){
        cout << "Mesto polaska: " << polazak <<endl;
        cout << "Mesto dolazak: " << dolazak <<endl;
        cout << "Udaljenost: " << km <<endl;
        cout << "Cena karte: " << cena <<endl;
        cout << "Indetifikator karte: " << indetifikator <<endl;


    }
};

class Putovanje{
private:
    DinString naziv;
    int maxCena;
    List<AvionskaKarta> aKarta;
public:
    Putovanje() : aKarta(){
        naziv = "Idemo malena!";
        maxCena = 300;
    }
    Putovanje(DinString n, int m,List<AvionskaKarta> a){
        naziv = n;
        maxCena = m;
        aKarta = a;
    }
    DinString get_naziv()const{
        return naziv;
    }
    int get_maxCena()const{
        return maxCena;
    }
    void set_naziv(const DinString n){naziv = n;}
    void set_maxCena(const int m){maxCena = m;}
    bool dodajKartu(AvionskaKarta &a){
        if(aKarta.size() == 0){
            return aKarta.add(aKarta.size()+1,a);
        }
        AvionskaKarta b("Madrid","Beograd",350,6000,4);
        aKarta.read(aKarta.size(),b);
        if(b.get_dolazak() == a.get_polazak() && a.get_cena() < maxCena){
            int br = 0;
            for(int i = 1; i <= aKarta.size();i++){

                if(b.get_indet() == a.get_indet()){
                    br++;
                }
            }
            if(br == 0){return aKarta.add(aKarta.size()+1,a);}
        }
        else{return false;}

    }
    bool izbaciKartu(int n){
        AvionskaKarta a;
        for(int i = 1;i <= aKarta.size();i++){
            if(n == a.get_indet()){
                aKarta.remove(n);
                return true;
            }
        }
        return false;
    }
    void ispis(){
        cout << "NAZVI PUTOVANJA: " << naziv << endl;
        cout << "Maksimalna cena kate: " << maxCena << endl;
        int br = 0;
        for(int i = 1;i <= aKarta.size();i++){
            br++;
        }
        cout << "Ukupno putnika na putovanju ima: " << br << endl;
        AvionskaKarta k;
        int br1 = 0;
        int br2 = 0;
        for(int i = 1;i<=aKarta.size();i++){
            if(k.jeftinaKarta() == true){
                br1++;
            }
            else{
                br2++;
            }
        }
        cout << "Jeftinih karata: " << br1 << ", a Skupih karta ima: " << br2 << endl;
    }
};
int main()
{
    Karta k1();
    Karta k2("Beograd","Oslo",200,5500,321);

    AvionskaKarta a2();
    AvionskaKarta a("Beograd","Oslo",200,5500,321);
    AvionskaKarta a1("Oslo","Helsinki",210,5600,123);

    AvionskaKarta av;
    av.ispisAvionskeKarte();

    List<AvionskaKarta> ak;
    Putovanje();
    Putovanje("Idemo malena!",300,ak);
    Putovanje p;

    p.dodajKartu(a);
    p.dodajKartu(a1);
    p.ispis();
    p.izbaciKartu(123);
    p.ispis();
        return 0;
}
