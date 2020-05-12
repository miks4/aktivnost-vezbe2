#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"
using namespace std;
enum VRSTA_KARTE{REGULAARNA = 1,SEZONSKA,STUDENSTKA,GRUPNA,POCASNA};
enum DOSTUPNA_SEDISTA{SLOBDONO = 1,REZERVISANO,PRODATO};
class Karta{
private:
    int id;
    VRSTA_KARTE vrstaK;
public:
    Karta(){
        id = 50;
        vrstaK = SEZONSKA;
    }
    Karta(int b,VRSTA_KARTE v){
        id = b;
        vrstaK = v;
    }
    int get_id()const{
        return id;
    }
    VRSTA_KARTE get_vrstaKarte()const{
        return vrstaK;
    }
    friend ostream& operator<<(ostream& out,Karta &k){
        out << "ID karte: " << k.get_id()<<endl;
        out << "Vrsta karte: " << k.get_vrstaKarte()<<endl;
        return out;
    }

};

template<int BROJ_MESTA>
class Pozoriste{
private:
    Karta k[BROJ_MESTA];
    DOSTUPNA_SEDISTA sediste[BROJ_MESTA];
public:
    Pozoriste(){
        for(int i = 0;i < BROJ_MESTA;i++){
            sediste[i+1] = SLOBDONO;
        }
    }
    int get_brojSLobodniSedista()const{
        int br = 0;
        for(int i = 0;i < BROJ_MESTA;i++){
            if(sediste[i+1] == SLOBDONO){
                br++;
            }
        }
        return br;
    }
    bool rezervisiSediste(const Karta& ka, int brSedista){
        for(int i = 0;i < BROJ_MESTA;i++){
            if(k[i+1] == brSedista){
                if(sediste[i+1] == SLOBDONO){
                    sediste[i+1] == REZERVISANO;
                    return true;
                }
            }
        }
        return false;
    }
    int rezervisiSediste1(const Karta &ka){
        for(int i = 0;i < BROJ_MESTA;i++){
            if(sediste[i+1] == SLOBDONO){
                sediste[i+1] = REZERVISANO;
                return i;
            }
        }
        return -1;
    }
    bool prodajSediste(const Karta &ka,int brSedista){
        for(int i = 0;i < BROJ_MESTA;i++){
            if(k[i+1] == brSedista){
                if(sediste[i+1] == SLOBDONO){
                    sediste[i+1] == PRODATO;
                    return true;
                }
            }
        }
        return false;
    }
    int prodajSediste1(const Karta &ka){
        for(int i = 0;i < BROJ_MESTA;i++){
            if(sediste[i+1] == SLOBDONO){
                sediste[i+1] = PRODATO;
                return i;
            }
        }
        return false;
    }
    bool prodajSedisteIdKarte(int idk){
        for(int i = 0;i < BROJ_MESTA;i++){
            if(sediste[i] == REZERVISANO && k.get_id()==idk){
                sediste[i] == PRODATO;
                return true;
            }
        }
        return false;
    }
    bool ponistiSedisteIdKarte(int idk){
        for(int i = 0;i < BROJ_MESTA;i++){
            if(sediste[i] == REZERVISANO && k.get_id()==idk){
                sediste[i] == SLOBDONO;
                return true;
            }
        }
        return false;
    }
    Karta get_karta()const{
        return k[BROJ_MESTA];
    }
};

int main()
{
    Pozoriste<5> p;
    Karta k1(123,REGULAARNA);


    return 0;
}
