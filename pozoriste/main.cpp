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
    int brojSedista;
public:
    Karta(){
        id = 50;
        vrstaK = SEZONSKA;
        brojSedista = 2;
    }
    Karta(int b,VRSTA_KARTE v,int c){
        id = b;
        vrstaK = v;
        brojSedista = c;
    }
    int get_id()const{
        return id;
    }
    VRSTA_KARTE get_vrstaKarte()const{
        return vrstaK;
    }
    int get_brojSedista()const{
        return brojSedista;
    }
    friend ostream& operator<<(ostream& out,Karta &k){
        out << "ID karte: " << k.get_id()<<endl;
        out << "Vrsta karte: " << k.get_vrstaKarte()<<endl;
        out << "Broj sedisa: " << k.get_brojSedista() << endl;
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
            if(ka.get_brojSedista() == brSedista){
                if(sediste[i+1] == SLOBDONO){
                    sediste[i+1] = REZERVISANO;
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
                return i+1;
            }
        }
        return -1;
    }
    bool prodajSediste(const Karta &ka,int brSedista){
        for(int i = 0;i < BROJ_MESTA;i++){
            if(ka.get_brojSedista() == brSedista){
                if(sediste[i+1] == SLOBDONO){
                    sediste[i+1] = PRODATO;
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
                return i+1;
            }
        }
        return false;
    }
    bool prodajSedisteIdKarte(int idk){
        for(int i = 0;i < BROJ_MESTA;i++){
            if(sediste[i+1] == REZERVISANO && k[i+1].get_id()==idk){
                sediste[i+1] = PRODATO;
                return true;
            }
        }
        return false;
    }
    bool ponistiSedisteIdKarte(int idk){
        for(int i = 0;i < BROJ_MESTA;i++){
            if(sediste[i+1] == REZERVISANO && k[i+1].get_id()==idk){
                sediste[i+1] = SLOBDONO;
                return true;
            }
        }
        return false;
    }
    Karta get_karta(int redniBrKarte)const{
        for(int i = 0; i < BROJ_MESTA;i++){
            if((i+1) == redniBrKarte){
                Karta ka;
                ka = k[i+1];
                return ka;
            }
        }
    }

};

int main()
{
    Pozoriste<5> p;
    Karta k1(123,REGULAARNA,2);

    if(p.rezervisiSediste(k1,2)){cout << "Uspesno rezervisano!"<<endl;}
    cout << "Broj rezervisanog sedista: " << p.rezervisiSediste1(k1)<<endl;
    if(p.prodajSediste(k1,2)){cout << "Uspesno prodano!"<<endl;}
    cout << "Broj prodatog sedista: " << p.prodajSediste1(k1)<<endl;
    if(p.prodajSedisteIdKarte(123)){cout << "Prodano sediste pomocu ID-a karte! " << endl;}
    else{
        cout << "NE"<<endl;
    }
    if(p.ponistiSedisteIdKarte(123)){cout << "Ponisteno sediste pomocu ID-a karte" << endl;}
    else{
        cout << "NE"<<endl;
    }
    //cout << p.get_karta(2)<<endl;


    return 0;
}
