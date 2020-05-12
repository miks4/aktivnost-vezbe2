#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"
using namespace std;
enum VELICINA{XS = 1,S,M,L,XL};
enum TIP{MAJICA = 1,PANTALONE};
class Proizvod{
protected:
    int cena;
    DinString naziv;
public:
    Proizvod(){
        cena = 100;
        naziv = "Voda";
    }
    Proizvod(int c,DinString d){
        cena = c;
        naziv = d;
    }
    int get_cena()const{
        return cena;
    }
    DinString get_naziv()const{
        return naziv;
    }
    void set_cena(const int c){
        cena = c;
    }
    void set_naziv(const DinString d){
        naziv = d;
    }
    void ispis(){
        cout << "Naziv prozivoda: "<<naziv<<endl;
        cout << "Cena istog: " << cena <<endl;
    }
    virtual void popust(){}
};

class Voce : Proizvod{
private:
    DinString poreklo;
    int trajanje;
public:
    Voce() : Proizvod(){
        poreklo = "Jamajka";
        trajanje = 7;
    }
    Voce(DinString d,int c,DinString a,int b) : Proizvod(c,d) {
        poreklo = a;
        trajanje = b;
    }
    DinString get_poreklo()const{
        return poreklo;
    }
    int get_trajanje()const{
        return trajanje;
    }
    void set_poreklo(const DinString d){
        poreklo = d;
    }
    void set_trajanje(const int c){
        trajanje = c;
    }
    void popust(){
        if(trajanje > 5){
            cout << "Vas popust je 33%."<<endl;
        }
        else if(0 > trajanje && trajanje < 6){
            cout << "Vas popust je 50%."<<endl;
        }
        else if(trajanje == 0){
            cout << "Vas popust je 100%, dobili ste ga besplatno!"<<endl;
        }
    }
    void ispis(){
        Proizvod::ispis();
        cout << "\tVOCE"<<endl;
        cout << "Zemlja iz koje je doslo: "<<poreklo<<endl<<"Rok trajanja: " << trajanje<<endl;

    }
};

class Odeca : public Proizvod{
private:
    VELICINA velicina;
    TIP vrsta;
    static int broj;
public:
    Odeca() : Proizvod(){
        velicina = M;
        if(velicina == L || velicina == XL){
            broj++;
        }
        vrsta = PANTALONE;
    }
    Odeca(VELICINA v,TIP t,DinString d,int c) : Proizvod(c,d){
        velicina = v;
        vrsta = t;
    }
    ~Odeca(){
        broj--;
    }
    VELICINA get_velicia()const{
        return velicina;
    }
    TIP get_tip()const{
        return vrsta;
    }
    void set_velicina(const VELICINA v){
        velicina = v;
    }
    void set_tip(const TIP t){
        vrsta = t;
    }
    void popust(){
        if(velicina == XS && vrsta == MAJICA){
            cout << "Vas popust je 60%."<<endl;
        }
        else if(vrsta == MAJICA && velicina != XS){
            cout << "Vas popust je 50%."<<endl;
        }
        else if(vrsta == PANTALONE){
            cout << "Vas popust je 33%."<<endl;
        }
    }
    void ispis(){
        Proizvod::ispis();
        cout << "Vrsta odece: " << vrsta << endl << "Velicina: " << velicina << endl;
    }

};

class Prodavnica{
private:
    DinString naziv;
    List<Proizvod> *proizvod;
public:
    Prodavnica() : proizvod(){
        naziv = "Kupi, sta cekas!?";
    }
    Prodavnica(DinString n,List<Proizvod>* p){
        naziv = n;
        proizvod = p;
    }
    DinString get_naziv()const{
        return naziv;
    }
    void set_naziv(const DinString d){
        naziv = d;
    }
    bool dodajProizvod(Proizvod &p){
        Proizvod p1;
        int br = 0;
        for(int i = 1; i<= proizvod->size();i++){
            proizvod->read(i,p1);
            if(p1.get_naziv() == p.get_naziv()){
                br++;
            }
        }
        if(br == 0){
            return proizvod->add(proizvod->size()+1,p);
        }
        else{
            return false;
        }
    }
    bool obrisiProizvod(DinString n){
        Proizvod p;
        for(int i =1;i <= proizvod->size();i++){
            proizvod->read(i,p);
            if(p.get_naziv() == n){
                return proizvod->remove(i);
            }
        }
    }
    bool obrisiProizvod(int n){
        Proizvod p;
        for(int i =1;i <= proizvod->size();i++){
            if(i == n){
                return proizvod->remove(i);
            }
        }
    }
};

int Odeca::broj = 0;
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
