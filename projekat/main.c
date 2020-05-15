 #include <stdio.h>
#include <stdlib.h>

struct takmicar{
    char ime[20];
    float visina;
    float tezina;
    float rasponRuku;
    float visinaSkoka;
    float brzina;
    float BodoviSutiranje;
    float bodoviSkokUVis;
    float bodoviTrcanje;
    float ukupniBodovi;
};


float takmicenjeUSutiranju(float r,float v);
float takmicenjeSkokUVis(float v,float r,float vs);
float takmicenjeUTrcanju(float v,float t,float b);
void sort(struct takmicar t[],int pocetak,int kraj,int smer);
float quickSort(int poc,int krajj,struct takmicar t[],int smer);


int main()
{

    FILE *ulaz = fopen("ulaz.txt","r");
    FILE *izlaz = fopen("izlaz.txt","w");

    if(ulaz == NULL){
        printf("nije se otvorio!");
    }
    if(izlaz == NULL){
        printf("nije se otvorio!");
    }
    int brTakmicara = 0;
    struct takmicar t[20];
    int i = 0;
    while(fscanf(ulaz,"%s %f %f %f %f %f",t[i+1].ime,&t[i+1].visina,&t[i+1].tezina,&t[i+1].rasponRuku,&t[i+1].visinaSkoka,&t[i+1].brzina)!= EOF){
        brTakmicara++;
        i++;
        if(brTakmicara >= 20){
            break;
        }

    }
    printf("U ovom kosarkaskom takmicenju ucestvuje %d takmicara.",brTakmicara);
    for(i = 0;i < brTakmicara;i++){
        t[i+1].BodoviSutiranje = takmicenjeUSutiranju(t[i+1].rasponRuku,t[i+1].visina);
        t[i+1].bodoviSkokUVis = takmicenjeSkokUVis(t[i+1].visina,t[i+1].rasponRuku,t[i+1].visinaSkoka);
        t[i+1].bodoviTrcanje = takmicenjeUTrcanju(t[i+1].visina,t[i+1].tezina,t[i+1].brzina);
        t[i+1].ukupniBodovi = t[i+1].BodoviSutiranje + t[i+1].bodoviSkokUVis + t[i+1].bodoviTrcanje;
        if((i+1) == brTakmicara){

            sort(t,1,brTakmicara,1);
            int j;
            for(j = 0;j < brTakmicara;j++){
                fprintf(izlaz,"%s %.2f %.2f %.2f %.2f\n",t[j+1].ime,t[j+1].BodoviSutiranje,t[j+1].bodoviSkokUVis,t[j+1].bodoviTrcanje,t[j+1].ukupniBodovi);
            }
        }

    }
        /*
        else{
                fprintf(izlaz,"\n%s",ime);
        }
        */


    fclose(ulaz);
    fclose(izlaz);
}
float takmicenjeUSutiranju(float r,float v){
    int pogodjeniSutevi = rand()%30 + 1;
    float k;
    if((v + r) <= 380){
            k = 1;
    }
    else if((v + r) <= 400){
        k = 1.3;
    }
    else{
        k = 1.5;
    }
    return (k * pogodjeniSutevi);

}
float takmicenjeSkokUVis(float v,float r,float vs){
    return (vs * ((v + r) / 1000));
}
float takmicenjeUTrcanju(float v,float t,float b){
    float vremeNaStoMetara = 100 / b;
    float k;
    if((v + t) <= 280){
        k = 1;
    }
    else if(280 < (v + t) && (v + t) <= 300){
        k = 1.3;
    }
    else{
        k = 1.5;
    }
    return ((200 * k) / vremeNaStoMetara);
}
void sort(struct takmicar t[],int pocetak,int kraj,int smer){
    if(pocetak >= kraj){
        return;
    }
    float pivot = quickSort(pocetak,kraj,t,smer);
    sort(t,pocetak,pivot-1,smer);
    sort(t,pivot+1,kraj,smer);
}
float quickSort(int poc,int krajj,struct takmicar t[],int smer){
    float p = t[krajj].ukupniBodovi;
    int a = poc-1;
    int i;
    for(i = poc; i <= krajj;i++){
        if(smer == 0){
            if(t[i].ukupniBodovi < p){
                a++;
                float temp = t[i].ukupniBodovi;
                t[i].ukupniBodovi = t[a].ukupniBodovi;
                t[a].ukupniBodovi = temp;
            }
        }
        else{
            if(t[i].ukupniBodovi > p){
            a++;
            float temp = t[i].ukupniBodovi;
            t[i].ukupniBodovi = t[a].ukupniBodovi;
            t[a].ukupniBodovi = temp;
            }
        }


    }
    t[krajj].ukupniBodovi = t[a+1].ukupniBodovi;
    t[a+1].ukupniBodovi = p;
    return a+1;
}
