#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"
using namespace std;

class Varijabla{
private:
    DinString tip;
    DinString naziv;
    int duzina;
public:
    Varijabla(){
        tip = "string";
        naziv = "lol";
        duzina = 3;
    }
    Varijabla(DinString t,DinString n,int d){
        tip = t;
        naziv = n;
        duzina = d;
    }
    Varijabla(const Varijabla& v){
        tip = v.tip;
        naziv = v.naziv;
        duzina = v.duzina;
    }
    DinString get_tip()const{
        return tip;
    }
    DinString get_naziv()const{
        return naziv;
    }
    int get_duzina()const{
        return duzina;
    }
    friend ostream& operator<<(ostream& out, Varijabla& v){
        out << "Tip" << v.get_tip()<< endl<< "naziv: "<< v.get_naziv() << endl << "duzina: " <<v.get_duzina()<<endl;
        return out;
    }
};

template<class T,int D>
class Stack{
private:
    typedef struct pod{
        int duzina[D];
        T el;
    }podatak;
    int maxi;
public:
    Stack(){
        D = 0;
        maxi = 90;
    }
    bool isEmpty()const{
        if(D = 0){
            return true;
        }
        else{return false;}
    }
    bool isFull()const{
        if(D == maxi){
            return true;
        }
        else{
            return false;
        }
    }
    int sizeS()const{
        return D;
    }
//    T* top(){
//        if(D == 0){
//            return NULL;
//        }
//        for(int i = D; i>=0;i--){
//
//        }
//    }
    bool push(const T& t){
        if(D == maxi){
            return false;
        }
        else{
            for(int i = 0;i <=D;i++){
                if(i == D){
                    el = t;
                    D++;
                    return true;
                }
            }
        }
    }

};

int main()
{

    return 0;
}
