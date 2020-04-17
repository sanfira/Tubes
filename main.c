/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 * MODUL 8 – TUGAS BESAR
 * Kelompok : 1
 * Hari dan Tanggal : Jumat, 17 April 2020
 * Asisten (NIM) : Berry (13216027)
 * Nama File : main.c
 * Deskripsi :
 */

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void Tick(unsigned char *GOL[], int N, int M)
{
    char NEXT[N][M];
    int X,Y,i,j,count;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            count=0;
            X=j+N;
            Y=i+M;
            if (GOL[(X-1)%N][(Y)%M]=='X') //Kiri
                count++;
            if (GOL[(X+1)%N][(Y)%M]=='X') //Kanan
                count++;
            if (GOL[(X)%N][(Y-1)%M]=='X') //Atas
                count++;
            if (GOL[(X)%N][(Y+1)%M]=='X') //Bawah
                count++;
            if (GOL[(X-1)%N][(Y-1)%M]=='X') //Kiri Atas
                count++;
            if (GOL[(X-1)%N][(Y+1)%M]=='X') //Kiri Bawah
                count++;
            if (GOL[(X+1)%N][(Y-1)%M]=='X') //Kanan Atas
                count++;
            if (GOL[(X+1)%N][(Y+1)%M]=='X') //Kanan Bawah
                count++;
            if (GOL[X%N][Y%M]=='X')
            {
                if (count==2||count==3){
                    NEXT[X%N][Y%M]='X';
                } else {
                    NEXT[X%N][Y%M]='-';
                }
            }
            if (GOL[X%N][Y%M]=='-')
            {
                if (count==3){
                    NEXT[X%N][Y%M]='X';
                } else {
                    NEXT[X%N][Y%M]='-';
                }
            }
        }
    }

    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            GOL[j][i]=NEXT[j][i];
        }
    }
}

void delay(int milli_seconds) {                         //buat delay
    clock_t start_time = clock();			//menyimpan clock asli
    while (clock() < start_time + milli_seconds); 	//loop selama delay
} 
void animate () {
	int baris, kolom, n,i;
	printf("How many iterations do you want?\n");
	scanf("%d", &n);
	while (n<=0) {                                 //validasi
		printf("Iteration must be greater than 0!\n");
		printf("Please input the right number of iteration\n");
		printf("How many iterations do you want?\n");
		scanf("%d", &n);
	}
	for (i=0; i<n; i++) {
		printf("Printing iteration number %d\n\n", i+1);
		tick(GOL, baris, kolom);			//import fungsi tick
		displayArray(GOL, baris, kolom);		//import fungsi print, dihapus kalo udah termasuk di tick
		delay(250);                             //delay 250ms
	}
}

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
    printf("--A simulation that automatically iterate--\n");
    printf("--life of cells in a population--\n\n");

    while(load==true){
    printf("Input File Name(Name only, without '.txt'):");
    scanf("%s", &filename);
    strcat(filename, tipe);
    printf("%s\n", filename);
    seed = fopen(filename, "r");
    
    while(seed == NULL){
        printf("Error Opening File\n");
        printf("Input File Name(Name only, without '.txt'):");
        scanf("%s", &filename);
        strcat(filename, tipe);
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
    //seed printarray
	
    quit=false;
    out=false;

    while(quit==false){
        showmenu();
        scanf("%d", &menu);
        if (menu==1){
                printf("Your option was : %d\n", menu);
                printf("\nAnimating...\n\n"); //taroh fungsi animate disini
		animate(GOL,baris, kolom);
        }
        else if (menu==2){
                printf("Your option was : %d\n", menu);
                printf("\nIterating...\n\n"); //taroh fungsi tick disini (ato iterate)
		Tick(GOL,baris,kolom);
		//printarray
        }
        else if (menu==3){
                printf("\nThe simulation has ended\n"); //kalo mau nge-free malloc disini aja, sekalian tutup file
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
