/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 * MODUL 8 – TUGAS BESAR
 * Kelompok : 1
 * Hari dan Tanggal : Rabu, 15 April 2020
 * Asisten (NIM) : Berry (13216027)
 * Nama File : main.c
 * Deskripsi :
 */

#include <stdio.h>
#include <stdbool.h>

void showmenu(){

    printf("Option :\n");
    printf("1. Animate\n");
    printf("2. Iterate\n");
    printf("3. Quit\n\n");
    printf("Your option : ");

    return;
}

int main(){
    int menu;
    bool quit=false;
    bool load=true;
    bool out=false;
    int ins;
    FILE *seed;
    char filename[10]="";
    char tipe[]=".txt";
    char newline;
    char line[2][5];//jumlah baris dan kolom
    int baris, kolom,i,j;
    unsigned char **GOL =NULL;

    printf("\nWelcome to\n");
    printf("GAME OF LIFE by E-1\n\n");
    printf("--insert deskripsi program here--\n\n");

    while(load==true){
    printf("Input File Name:");
    scanf("%s", &filename);
    strcat(filename, tipe);
    printf("%s\n", filename);
    seed = fopen(filename, "r");
    
    while(seed == NULL){
        printf("Error Opening File\n");
        printf("Input File Name:");
        scanf("%s", &filename);
        strcat(filename, tipe);
        printf("%s", filename);
        seed = fopen(filename, "r");
    } 

    i=0;
    while(i<2){
        fgets(line[i], 5, seed);
        i++;
    }
    baris = atoi(line[0]);
    kolom = atoi(line[1]);
    printf("%d\n", baris);
    printf("%d\n", kolom);
    
    GOL = malloc(baris*sizeof(unsigned char*));
    for(i=0; i<baris; i++){
        GOL[i]=malloc(kolom*sizeof(unsigned char));
    }

    for(i=0;i<baris;i++){
        for(j=0; j<kolom;j++){
            GOL[i][j]=fgetc(seed);
        }
        newline=fgetc(seed);
    }
  
    fclose(seed);
        
    printf("\nloading--\n"); //seed file read
    //seed
    printf("Seed :\n);
    for(i=0;i<baris;i++){
        for(j=0; j<kolom;j++){
            printf("%c", GOL[i][j]);
        }
        printf("\n");
    }
    quit=false;
    out=false;

    while(quit==false){
        showmenu();
        scanf("%d", &menu);
        if (menu==1){
                printf("Your option was : %d\n", menu);
                printf("\nAnimating...\n\n"); //animate
        }
        else if (menu==2){
                printf("Your option was : %d\n", menu);
                printf("\nIterating...\n\n"); //tick
        }
        else if (menu==3){
                printf("\nThe simulation has ended\n"); //unload and clear
                quit=true;
                while(out==false){
                    printf("\nInsert new seed?\n1. Yes\n2. No\n");
                    printf("Your option : ");
                    scanf("%d", &ins);
                    if(ins==1){
                        out=true;
                    }
                    else if(ins==2){
                        printf("\nProgram is quitting--\n");
                        out=true;
                        load=false;
                    }
                    else {
                        printf("\nFalse Input\n");
                    }
                }
        }
        else {
            printf("Your option was : %d\n", menu);
            printf("\nOpsi tidak tersedia\n\n");
        }
    }
    }
    return 0;
}
