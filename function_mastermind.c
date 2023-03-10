#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afficher(int tab[4]){
    srand( time( NULL ) );
    for(int x = 0; x < 4; x++){
        tab[x] = 1 + rand() %6;
        printf("%d ", tab[x]);
    }
}

void transform(int tab[4], char tab2[4]){

    for(int x = 0; x < 4; x++){

        if(tab[x] == 1){
            printf("P", tab2[4]);
        }

        if(tab[x] == 2){
            printf("B", tab2[4]);
        }

        if(tab[x] == 3){
            printf("M", tab2[4]);
        }

        if(tab[x] == 4){
            printf("Y", tab2[4]);
        }

        if(tab[x] == 5){
            printf("O", tab2[4]);
        }

        if(tab[x] == 6){
            printf("G", tab2[4]);
        }
    }
}

void saisir(int tab2[4]){
    for(int x = 0; x < 4; x++){
        printf("Saisissez 1 chiffre compris entre 1 et 6\n ");
        scanf("%d", &tab2[x]);
    }
    printf("Voici le code\n ");
    for (int x = 0; x < 4; x++) {
        printf("%d", tab2[x]);
    }
    printf("\n");
}

void rangement(int tab3[4]){
    int x;
    srand( time( NULL ) );
    x = rand() %4;
    for(int x=0; x<4; x++){
        tab3[x] = 9;
    }
    printf("Saisissez 1 chiffre compris entre 0 et 2\n ");
    scanf("%d", &tab3[x]);
    printf("Voici le tableau avec la valeur :\n");
    for(int x=0; x<4; x++){
        if(tab3[x] == 9){
        printf("|-|");
        }
        else{
            printf("%d", tab3[x]);
        }
    }
    printf("\n");
}

void valider(int tab[4]) {
    char transform[3] = {'.', 'W', 'R'}; 
    for(int i = 0; i < 4; i++) {
        int choix;
        do {
            printf("Saisissez 1 chiffre compris entre 0 et 2\n");
            scanf("%d", &choix);
        } while(choix < 0 || choix > 2);
        tab[i] = choix;
    }
    for(int i = 0; i < 4; i++) {
        tab[i] = transform[tab[i]];
    }
}

int main(){    

    int tab[4] = {0, 0, 0, 0};
    afficher(tab);
    printf("\n");

    char tab2[4] = {0, 0, 0, 0};
    transform(tab, tab2);
    printf("%c %c %c %c\n", tab2[0], tab2[1], tab2[2], tab2[3]);
    printf("\n");

    saisir(tab2);
    printf("\n");

    int tab3[4] = {0, 0, 0, 0};
    rangement(tab3);
    
    valider(tab3);
    printf("\n");
    printf("Le tableau validé est : %c %c %c %c\n", tab3[0], tab3[1], tab3[2], tab3[3]);

    system("pause");
    return 0;
}
