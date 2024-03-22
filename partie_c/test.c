#include<stdio.h>

void update (){ printf (" \033[ H \033[ J");}
void gotoxy (x,y){ printf (" \033[% d;% dH",x,y);}

int main(){
    printf (" \033[ H \033[ J");
}