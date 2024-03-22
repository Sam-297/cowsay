#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define ROCKS 2
#define SUCKS 1
#define BYEBYE 0

int stock = 5;
int fitness = 5;

void update() { printf ( "\033[H\033[J" ) ;}
void gotoxy(x , y) { printf ( "\033[%d;%dH",x , y ) ;}

void stock_update(int lunchfood, int crop){
    stock = stock - lunchfood + crop;
    if (stock < 0)
        stock = 0;
    if (stock > 10)
        stock = 10;
}

void fitness_update(int lunchfood,int digestion){
    time_t t;
    srand((unsigned)time(&t));
    
    fitness = fitness + lunchfood - digestion;
}

int update_etat(){
    if (4 <= fitness && fitness <= 6)
        return ROCKS;
    else if (1 <= fitness && fitness <= 3 || 7 <= fitness && fitness <= 9)
        return SUCKS;
    else
        return BYEBYE;
}

void affiche_vache(int etat){
    switch (etat)
    {
    case ROCKS:
         printf("            ^__^\n\
            (^^)\\_______\n\
            (__)\\       )\\/\\\n\
                ||----w |\n\
                ||     ||\n");
        break;
    case BYEBYE:
        printf("               \n\
          ^__^ \\_______\n\
          (xx) \\       )\\/\\\n\
          (__)  ||----w |\n\
            U   ||     ||\n");
        break;
    case SUCKS:
        printf("            ^__^\n\
            (;;)\\_______\n\
            (__)\\       )\\/\\\n\
                ||----w |\n\
                ||     ||\n");
        break;
    }
}


int main(){
    int etat = ROCKS; int crop; int digestion; int lunchfood;
    int duree_de_vie = 0;
    time_t t;
    srand((unsigned) time(&t));
    while (etat != BYEBYE){
        gotoxy(1, 1);
        update();
        duree_de_vie++;
        crop = (rand() % 7) - 3;
        digestion = rand() % 3;
        affiche_vache(etat);
        printf("Stock : %d\n", stock);
        printf("Entrez la quantité de nourriture: ");
        scanf("%d", &lunchfood);
        while (lunchfood > stock || lunchfood < 0){
            printf("Valeur invalide, entrez la quantité de nourriture: ");
            scanf("%d", &lunchfood);
        }
        stock_update(lunchfood, crop);
        fitness_update(lunchfood, digestion);
        etat = update_etat();
    }
    gotoxy(1, 1);
    update();
    affiche_vache(etat);
    if (fitness<=0)
        printf("La vache est morte de faim :( \n");
    else
        printf("La vache est morte suite à un abus de nourriture\n");
    printf("Duree de vie : %d\n", duree_de_vie);
    return 0;
}