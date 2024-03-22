#include <stdio.h>
#include <string.h>
#include <unistd.h>

void update() { printf ( "\033[H\033[J" ) ;}
void gotoxy(x , y) { printf ( "\033[%d;%dH",x , y ) ;}

void affiche_vache(char eyes[],int type){
    switch (type)
    {
    case -1: // animated cow
        for (int i = 0; i < 4;i++){
            

            gotoxy(1, 1);
            update();
            printf("\n\n");
            printf("        \\   ^__^\n");
            printf("         \\  (==)\\_______\n");
            printf("            (__)\\       )\\/\n");
            printf("                ||----w |\n");
            printf("                ||     ||\n");
            sleep(2);

            gotoxy(1, 1);
            update();
            printf("\n");
            printf("            ^__^\n");
            printf("        \\   (^^)\\_______\n");
            printf("         \\  (__)\\       )\\/\n");
            printf("             U   ||----w |\n");
            printf("                 \\\\     \\\\\n\n");
            sleep(1);

            gotoxy(1, 1);
            update();
            printf("\n\n");
            printf("        \\   ^__^\n");
            printf("         \\  (..)\\_______\n");
            printf("            (__)\\       )\\/\n");
            printf("                ||----w |\n");
            printf("                ||     ||\n");
            sleep(1);

            
        }
        break;

    case 0: //default cow
         printf("        \\   ^__^\n\
         \\  (%s)\\_______\n\
            (__)\\       )\\/\\\n\
                ||----w |\n\
                ||     ||\n",eyes);
        break;
    case 1: //fat_cow
        printf("  \\\n   \\\n    A__A\n   ( %s )\\\\_----__\n   (____)\\      )\\/\\\n        ||      |\n        ||`---w||\n",eyes);
        break;
    case 2: //elephant
        printf("  \\\n   \\\n      /  \\~~~/  \\\n     (    %s     )----,\n      \\__     __/      \\\n        )|  /)         |\\\n         | /\\  /___\\   / ^\n          \"-|__|   |__|    \"\n",eyes);
        break;
    case 3: //whale
        printf("   \\\n    \\\n     \\\n        __  / __\n       /  \\ | /  \\\n           \\|/\n       _.---v---.,_\n      /            \\  /\\__/\\\n     /              \\ \\_  _/\n     |__ %c           |_/ /\n      _/                / \n      \\       \\__,     /  \n   ~~~~\\~~~~~~~~~~~~~~`~~~\n",eyes[0]);
        break;
    case 4: //knight
        printf(" \\\n  \\\n  __/\"\"\"\\\\\n ]___ %c  }\n     /   }\n   /~    }\n   \\____/\n   /____\\\n  (______) \n",eyes[0]);
        break;
    case 5: //kitten
        printf("   \\\n    \\\n\n     |\\_/|\n     |%c %c|__\n     --*--__\\\n     C_C_(___) \n",eyes[0],eyes[1]);
        break;
    }
}

int main(int argc, char *argv[]){
    char eyes[3];
    strcpy(eyes, "00");
    int type = 0;
    for (int i = 1; i < argc; i++){
        if (argc >= 3 && (strcmp(argv[i],"-e") == 0 || strcmp(argv[i],"--eyes") == 0)){
            strcpy(eyes,argv[i+1]);
            i++;}
        else if (strcmp(argv[i], "-b") == 0)
            strcpy(eyes, "==");
        else if (strcmp(argv[i],"-g") == 0)
            strcpy(eyes,"$$");
        else if (strcmp(argv[i],"-p") == 0)
            strcpy(eyes,"@@");
        else if (strcmp(argv[i],"-t") == 0)
            strcpy(eyes,"--");
        else if (strcmp(argv[i],"-w") == 0)
            strcpy(eyes,"OO");
        else if (strcmp(argv[i],"-y") == 0)
            strcpy(eyes,"..");
        else if (strcmp(argv[i],"-fat") == 0)
            type = 1;
        else if (strcmp(argv[i],"-elephant") == 0)
            type = 2;
        else if (strcmp(argv[i],"-whale") == 0)
            type = 3;
        else if (strcmp(argv[i],"-knight") == 0)
            type = 4;
        else if (strcmp(argv[i],"-cat") == 0)
            type = 5;
        else if (strcmp(argv[i],"-animated") == 0)
            type = -1;

    }
    affiche_vache(eyes, type);

    return 0;
}