/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 * MODUL 8 ¨C TUGAS BESAR
 * Kelompok : 1
 * Hari dan Tanggal : Selasa, 14 April 2020
 * Asisten (NIM) : Berry (13216027)
 * Nama File : animate.c
 * Deskripsi : fungsi untuk menganimasikan pergantian iterasi game of life
 */

#include <stdio.h>
#include <time.h> 

void delay(int milli_seconds) { 
    clock_t start_time = clock();						//menyimpan clock asli
    while (clock() < start_time + milli_seconds); 		//loop selama delay
} 
void animate () {
	int baris,kolom,n,i;
	printf("How many iterations do you want?\n");
	scanf("%d", &n);
	while (n<=0) {
		printf("Iteration must be greater than 0!\n");
		printf("Please input the right number of iteration\n");
		printf("How many iterations do you want?\n");
		scanf("%d", &n);
	}
	for (i=0; i<n; i++) {
		printf("Printing iteration number %d\n\n", i+1);
		tick(GOL, baris, kolom);		//import fungsi tick
		displayArray(GOL, baris, kolom);	//import fungsi print, dihapus kalo udah termasuk di tick
		delay(250);                             //delay 250ms
	}
}

//buat ngetes animate
int main() { 
    animate();
    return 0; 
} 

