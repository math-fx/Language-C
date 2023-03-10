#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rules(){
    printf("Bienvenue dans le jeu du Mastermind, voici les règles :\n");
    printf("Une combinaison secrète de 4 couleurs est générée aléatoirement, vous avez 10 essais pour trouver la bonne combinaison \n");
    printf("6 couleurs peuvent faire partie de la combinaison, les voici: \n");
    printf("1 = Bleu, 2 = Rouge, 3 = Vert, 4 = Jaune, 5 = Orange, 6 = Noir\n");
}

void init_grille(int grille[10][9]){
    int i, j;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 9; j++){
            grille[i][j] = 0;
        }
    }
}

void afficherGrille(int grille[10][9]){
    int i, j;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 9; j++){
            if (j > 4){
                if(grille[i][j] == 2){
                    printf(".|");
                }
                else if(grille[i][j] == 1){
                    printf("O|");
                }
                else{
                    printf("N|");
                }
            }
            else{
                printf("|%d|", grille[i][j]);
            }
        }
        printf("\n");
    }
}

void code_secret(int tab[4]){
    srand(time(NULL));
    for(int x = 0; x < 4; x++){
        tab[x] = 1 + rand() % 6;
    }
    printf("\n");
}

void saisir(int choix_joueur[4]){
    printf("Saisissez 4 chiffres compris entre 1 et 6\n");
    for (int i = 0; i < 4; i++) {
        int chiffre;
        do {
            printf("Chiffre %d : ", i + 1);
            scanf("%1d", &chiffre);
        } while (chiffre < 1 || chiffre > 6);
        choix_joueur[i] = chiffre;
    }
}

int main(){  

    rules();
    printf("\n");

    int grille[10][9];
    init_grille(grille);
    printf("\n");

    afficherGrille(grille);
    printf("\n");

    int tab[4] = {0, 0, 0, 0};
    code_secret(tab);
    printf("\n");

    int choix_joueur[4];

    int essai = 0;
    int code_temp[4];
    int i = 0;
    while(essai < 10){
        saisir(choix_joueur);

        grille[essai][0] = essai + 1;
        grille[essai][1] = choix_joueur[0];
        grille[essai][2] = choix_joueur[1];
        grille[essai][3] = choix_joueur[2];
        grille[essai][4] = choix_joueur[3];

        int code_temp[4] = {tab[0], tab[1], tab[2], tab[3]};
 
        for(int j = 1; j < 5; j++) {
            if (grille[essai][j] == code_temp[j-1]) {
                code_temp[j-1] = -1;
                grille[essai][j+4] = 2;
            }
        }

        for(int j = 1; j < 5; j++){
            for(int k = 0; k < 4; k++){
                if(grille[essai][j] == code_temp[k] && grille[essai][j+4] != 2 && grille[essai][j+4] != 1){
                    code_temp[k] = -1;
                    grille[essai][j+4] = 1;
                }
            }
        }

        if (grille[essai][5]==2 && grille[essai][6]==2 && grille[essai][7]==2 && grille[essai][8]==2) {
            essai=11;
            afficherGrille(grille);
            printf("GG\n");
        }
        else{
            essai++;
            afficherGrille(grille);
        }
        if (essai==10) {
            printf ("Loser\n");
        }
    }
    system("pause");
    return 0;
}
