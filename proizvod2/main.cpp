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
    List<Proizvod> get_proizvod(){
        return *proizvod;
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
        return false;
    }
    bool obrisiProizvod(int n){
        Proizvod p;
        for(int i =1;i <= proizvod->size();i++){
            if(i == n){
                return proizvod->remove(i);
            }
        }
        return false;
    }
    void akcija(){
        Proizvod p;
        for(int i = 1;i <= proizvod->size();i++){
            proizvod->read(i,p);
            p.popust();
        }
    }
    float izracunajProsek(){
        Proizvod p;
        float a = 0;
        float b = 0;
        for(int i = 1;i<=proizvod->size();i++){
            proizvod->read(i,p);
            a += p.get_cena();
            b++;
        }
        float prosek = a / b;
        return prosek;
    }
    friend ostream& operator<<(ostream& out,Prodavnica &p){
        out << "NAZIV: " <<p.get_naziv() << endl;
        Proizvod pr;
        for(int i = 1;i <= (p.get_proizvod()).size();i++){
            (p.get_proizvod()).read(i,pr);
            out << "Naziv " << i << ". proizvoda: "<<pr.get_naziv()<<endl;
        }

        return out;
    }
};

class Grad{
private:
    DinString naziv;
    List<Prodavnica> *prodavnica;
public:
    Grad() : prodavnica() {
        naziv = "Srbobran.";
    }
    Grad(DinString n,List<Prodavnica> *p){
        naziv = n;
        prodavnica = p;
    }
    bool dodajProdavnicu(Prodavnica &p){
        return prodavnica->add(prodavnica->size()+1,p);
    }
    void ispisNajjeftiijuProdavnicu(){
        Prodavnica prod;
        Proizvod proi;
        int temp = 0;
        int br = 0;
        float prosek;
        int mini = 100000000;
        for(int i = 1;i<=prodavnica->size();i++){
            for(int j = 1;j <= (prod.get_proizvod()).size();i++){
                (prod.get_proizvod()).read(j,proi);
                temp += proi.get_cena();
                br++;
            }
            prosek = temp / br;
            if(prosek < mini){
                mini = prosek;
            }
        }
        ///cout << "Najjjeftinija prodavnica u gradu ima prosecnu cenu proizvoda: " << mini;
        for(int i = 1;i<=prodavnica->size();i++){
            prodavnica->read(i,prod);
            if(mini == prod.izracunajProsek()){
                cout << "Najeftinija prodavnica u gradu: " << prod<<endl;
            }
        }
    }
};

int Odeca::broj = 0;
int main()
{
    Proizvod p();
    Proizvod p1(60,"aj");

    Voce v();
    Voce v1("voce1",50,"Afrika",4);

    Odeca o();
    Odeca o1(XS,MAJICA,"odeca1",100);

    List<Proizvod> *proi;
    Prodavnica pr();
    Prodavnica pr1("Totot",proi);

    Prodavnica prr;
    prr.dodajProizvod(p1);
    prr.obrisiProizvod("ak");
    prr.obrisiProizvod(4);
    prr.akcija();

    List<Prodavnica> *prod;
    Grad g1();
    Grad g2("Srbobran",prod);
    Grad g;
    g.dodajProdavnicu(pr1);
    g.ispisNajjeftiijuProdavnicu();

    return 0;
}
