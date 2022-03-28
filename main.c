    /*Exercice4:
Ceci est un programme qui consiste transformer des chiffres en lettres,et ceux en trois langues malagasy,français,anglais.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int longueur (int nb){
    int len;
    if (nb<10){len=1;}
    else if (nb<100){len=2;}
    else if (nb<1000){len=3;}
    else if (nb<10000){len=4;}
    else if (nb<100000){len=5;}
    else if (nb<1000000){len=6;}
    else if (nb<1000000000){len=7;}
    else if (nb<1000000000000){len=8;}
    else {len=0;}
    return len;
}

//en Malagasy
void tokana(int nb){
    const char *iray[10]={"aotra","ray","roa","telo","efatra","dimy","enina","fito","valo","sivy"};
    printf("%s",iray[nb]);
}
void roa(int nb){
    const char *iray[10]={"","ray","roa","telo","efatra","dimy","enina","fito","valo","sivy"};
    char *lettre;
    const char *diz[10]={"","folo","roapolo","telopolo","efapolo","dimampolo","enimpolo","fitopolo","valopolo","sivy folo"};
    if (nb/10==0){printf("%s",iray[nb]);}
    else if (nb/10==1){
        if (nb==10){printf("folo");}
        else {  printf("%s ",iray[nb-10]);
                printf(" ambin'ny %s",diz[1]);}
        }
    else {
        int x=nb/10;
        int y=nb-(10*x);
        if (y==0){
                    printf(" %s ",diz[x]);
        }
        else{
        tokana(y);
        printf(" amby %s ",diz[x]);
    }
}}
void telo(int nb){
    const char *iray[10]={"","","roan-jato","telon-jato","efa-jato","diman-jato","enin-jato","fiton-jato","valon-jato","sivan-jato"};
    int x=nb/100;
    int y=nb-(100*x);
    if (x==0){roa(nb);}
    else if (x==1){
        if (y==0){printf("zato");}
        else {roa(y);
        printf("amby zato");}
    }
    else if (y==0){
            printf("%s",iray[x]);
    }
    else {  roa(y);
            printf(" sy ");
            printf("%s ",iray[x]);
            }
}
void efatra(int nb){
    const char *iray[10]={"","","roa","telo","efatra","dimy","enina","fito","valo","sivy"};
    int x=nb/1000;
        int y=nb-(1000*x);
    if (x==0){telo(nb);}
    else if(y==0){printf("%s arivo ",iray[x]);}
    else {      telo(y);
                printf(" sy %s arivo ",iray[x]);
            }
}
void dimy(int nb){
    const char *iray[10]={"","ray","roa","telo","efatra","dimy","enina","fito","valo","sivy"};
    int x=nb/10000;
          int y=nb-(10000*x);
    if (x==0){efatra(nb);}
    else if(y==0){printf("%s alina ",iray[x]);}

    else {     efatra(y);
                printf(" sy %s alina ",iray[x]);
            }
}
void enina(int nb){
    const char *iray[10]={"","ray","roa","telo","efatra","dimy","enina","fito","valo","sivy"};
    int x=nb/100000;
              int y=nb-(100000*x);
    if (x==0){dimy(nb);}
        else if(y==0){printf("%s hetsy ",iray[x]);}
    else {     dimy(y);
                printf(" sy %s hetsy ",iray[x]);
            }
}
void fito(int nb){
    const char *iray[10]={"","ray","roa","telo","efatra","dimy","enina","fito","valo","sivy"};
    int x=nb/1000000;
    int y=nb-(1000000*x);
    if (x==0){enina(nb);}
        else if(y==0){printf("%s tapitrisa ",iray[x]);}
    else {  enina(y);
            printf(" sy ");
            telo(x);
            printf(" tapitrisa ");
            }
}
void valo(int nb){
    const char *iray[10]={"","ray","roa","telo","efatra","dimy","enina","fito","valo","sivy"};
    int x=nb/1000000000;
    int y=nb-(1000000000*x);
    if (x==0){fito(nb);}
    else if(y==0){printf("%s lavitrisa ",iray[x]);}
    else {  fito(y);
            printf(" sy ");
            telo(x);
            printf(" lavitrisa ");
            }
}

//en fran�ais
void unite(int nb){
    const char *unit[10]={"zero","un","deux","trois","quatre","cinq","six","sept","huit","neuf"};
    printf("%s",unit[nb]);
}
void dizaine(int nb){
    char *lettre;
    const char *unit[10]={"","un","deux","trois","quatre","cinq","six","sept","huit","neuf"};
    const char *diz_tab[10]={"","onze","douze","treize","quatorze","quinze","seize","dix-sept","dix-huit","dix-neuf"};
    const char *diz[10]={"","","vingt","trente","quarante","cinquante","soicante","","quatrevingt",""};
    if (nb/10==0){printf("%s",unit[nb]);}
    else if (nb/10==1){
        if (nb==10){printf("dix");}
        else {printf("%s",diz_tab[nb-10]);}
        }
    else if ((nb/10)==7 || (nb/10)==9 ){
        int x=(nb/10)-1;
        int y=nb-(10*(x+1));
        if (nb-(10*(x+1))==0){printf("%s dix",diz[x]);}
        else{printf("%s %s",diz[x],diz_tab[y]);}
        }
    else {
        int x=nb/10;
        int y=nb-(10*x);
        printf("%s ",diz[x]);
               unite(y);
    }
}
void centaine(int nb){
    int x=nb/100;
    int y=nb-(100*x);
    if (x==0){dizaine(nb);}
    else if (x==1){
        printf(" cent ");
        dizaine(y);
    }
    else {  unite(x);
            printf(" cent ");
            dizaine(y);}
}
void mille(int nb){
    int x=nb/1000;
    int y=nb-(1000*x);
    if (x==0){centaine(nb);}
    else if (x==1){
        printf(" mille ");
        centaine(y);
    }
    else {
            centaine(x);
            printf(" mille ");
            centaine(y);
    }
}
void million(int nb){
    int x=nb/1000000;
    int y=nb-(1000000*x);
    if (x==0){mille(nb);}
    else {
            centaine(x);
            printf(" million ");
            mille(y);
    }
}
void milliard(int nb){
    int x=nb/1000000000;
    int y=nb-(1000000000*x);
    if (x==0){million(nb);}
    else {
            centaine(x);
            printf(" milliard ");
            million(y);
    }
}

//en Anglais
void unityt(int nb){
    const char *unity[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    printf("%s",unity[nb]);
}
void dizainy(int nb){
    char *lettre;
    int x=nb/10;
    int y=nb-(10*x);
    const char *unity[10]={"","one","two","three","four","five","six","seven","eight","nine"};
    const char *diz_tab[10]={"","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    const char *diz[10]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    if (nb/10==0){printf("%s",unity[nb]);}
    else if (nb/10==1){
        if (nb==10){printf("ten");}
        else {printf("%s",diz_tab[nb-10]);}
        }
    else {

        printf("%s %s",diz[x],unity[y]);
    }

}
void centainy(int nb){
    int x=nb/100;
    int y=nb-(100*x);
    if (x==0){dizainy(nb);}
    else {  unityt(x);
            printf(" hundred ");
            dizainy(y);}
}
void milly(int nb){
    int x=nb/1000;
    int y=nb-(1000*x);
    if (x==0){centainy(nb);}
    else if (x==1){
            printf("one thousand ");
            centainy(y);
    }
    else {
            centainy(x);
            printf(" thousand ");
            centainy(y);
    }
}
void milliony(int nb){
    int x=nb/1000000;
    int y=nb-(1000000*x);
    if (x==0){milly(nb);}
    else if (x==1){
            printf("one million ");
            centainy(y);
    }
    else {
            centainy(x);
            printf(" million ");
            milly(y);
    }
}
void milliardy(int nb){
    int x=nb/1000000000;
    int y=nb-(1000000000*x);
    if (x==0){milliony(nb);}
    else if (x==1){
            printf("one milliard ");
            centainy(y);
    }
    else {
            centainy(x);
            printf(" milliard ");
            milliony(y);
    }
}

int conversion_euro(int nb){
    int ris=nb;
    
    return ris;
    }
int conversion_ariary(int nb){
    int ar=nb;  
    return ar;
    }
    
int conversion_dollar(int nb){
    int ris=nb;
    return ris;
    }

void traducion(int nb){
    
    if (longueur(conversion_euro(nb))==1){unite(conversion_euro(nb));}
    else if (longueur(conversion_euro(nb))==2) {dizaine(conversion_euro(nb));}
    else if (longueur(conversion_euro(nb))==3) {centaine(conversion_euro(nb));}
    else if (longueur(conversion_euro(nb))<=6) {mille(conversion_euro(nb));}
    else if (longueur(conversion_euro(nb))==7) {million(conversion_euro(nb));}
    else if (longueur(conversion_euro(nb))==8) {milliard(conversion_euro(nb));}

    }
void translation(int nb){
    
    if (longueur(conversion_dollar(nb))==1){unityt(conversion_dollar(nb));}
    else if (longueur(conversion_dollar(nb))==2) {dizainy(conversion_dollar(nb));}
    else if (longueur(conversion_dollar(nb))==3) {centainy(conversion_dollar(nb));}
    else if (longueur(conversion_dollar(nb))<=6) {milly(conversion_dollar(nb));}
    else if (longueur(conversion_dollar(nb))==7)  {milliony(conversion_dollar(nb));}
    else if (longueur(conversion_dollar(nb))==8) {milliardy(conversion_dollar(nb));}

    }
void vadika(int nb){
    if (longueur(nb)==1){tokana(nb);}
    else if (longueur(conversion_ariary(nb))==2) {roa(conversion_ariary(nb));}
    else if (longueur(conversion_ariary(nb))==3) {telo(conversion_ariary(nb));}
    else if (longueur(conversion_ariary(nb))==4) {efatra(conversion_ariary(nb));}
    else if (longueur(conversion_ariary(nb))==5) {dimy(conversion_ariary(nb));}
    else if (longueur(conversion_ariary(nb))==6) {enina(conversion_ariary(nb));}
    else if (longueur(conversion_ariary(nb))==7) {fito(conversion_ariary(nb));}
    else if (longueur(conversion_ariary(nb))==8) {valo(conversion_ariary(nb));}
    
    }
int chiffre_lettre(int nb){
 int lan;
    printf("Veuiller saisir votre langue:(1: Malagasy, 2:Francais ,3:Anglais 4:tous) \n>>>>");
    scanf("%d",&lan);
        if (lan==1){
                printf("\n%d\n",conversion_ariary(nb));
                vadika(nb);
            }
        else if(lan==2){
            printf("\n%d\n",conversion_euro(nb));
            traducion(nb);;
        }
        else if(lan==3){
        printf("\n%d\n",conversion_dollar(nb));
        translation(nb);
        printf("Dollar\n");}
        else if(lan==4){
            printf(" En Malagasy:\n");
            printf("\n%d\n" , conversion_ariary(nb));
            vadika(nb);
            printf("\n En Francais: \n");
            printf("\n%d\n",conversion_euro(nb));
            traducion(nb);
            printf("\n En Anglais:  \n");
            printf("\n%d\n",conversion_dollar(nb));
            translation(nb);}
        
        else {
            printf("Cette langue n'est malheureusement pas valide.\n");
            }

return 0;
}


int main(int argc, char *argv[]){
    int nb,rep;
    int i=0;
    int bool=0;
    while(i==0){

    
    printf("Veuillez saisir un chiffre:\n>>>>>>>>");
    scanf("%d",&nb);
    if (nb<0){printf("Desole mais ce nombre est soit  negatif ou trop grand.(entre 0 et 10 000 000 000) \n");}
    else{chiffre_lettre(nb);}
    
    printf(" \n Voulez-vous continuer?(0:oui/1:non): ");
    scanf("%d",&bool);
    if(bool==0){
        i=0;
    }
    else{
        i=1;
    }
}

return 0;
}


