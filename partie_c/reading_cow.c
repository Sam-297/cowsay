#include <stdio.h>
#include <string.h>
#include <unistd.h>

void update() { printf ( "\033[H\033[J" ) ;}
void gotoxy(x , y) { printf ( "\033[%d;%dH",x , y ) ;}

void afficher_vache(char *full_word, char current_char, char *tirets){
printf(" %s-\n",tirets);
printf("< %s >\n",full_word);
printf(" %s-\n",tirets);
printf("        \\   ^__^\n\
         \\  (00)\\_______\n\
            (__)\\       )\\/\\\n\
             %c  ||----w |\n\
                ||     ||\n",current_char);
}

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Erreur, la commande prend un seul argument\n");
        return 1;
    }
    FILE *f;
    char c; //charactere a lire
    char tirets[512];
    char full_word[512];
    full_word[0] = '\0';
    int nb_c = 0; // nb characteres lus et afficher
    f = fopen(argv[1], "r");
    if (f == NULL){
        perror(argv[1]);
        return 2;
    }
    fscanf(f,"%c", &c);
    while (!feof(f)){
        gotoxy(1, 1);
        update();
        tirets[nb_c] = '-';
        afficher_vache(full_word, c, tirets);
        sleep(1);
        full_word[nb_c] = c;
        full_word[nb_c + 1] = '\0';
        fscanf(f,"%c", &c);
        nb_c++;
    }
    gotoxy(1, 1);
    update();
    tirets[nb_c] = '-';
    afficher_vache(full_word, ' ', tirets);
    sleep(1);
    nb_c++;

    fclose(f);
    return 0;
}