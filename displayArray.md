# Tubes Kelompok 1 Rombongan E
/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 * MODUL 8 – TUGAS BESAR
 * Kelompok : 1
 * Hari dan Tanggal : Rabu, 15 April 2020
 * Asisten (NIM) : Berry (13216027)
 * Nama File : main.c
 * Deskripsi : Menampilkan array
 */

#include <stdio.h>
#include <stdlib.h>

void displayArray()
{
    int i,j,baris,kolom;
    char line[2][5];

    system("cls");
    for(i=0;i<baris;i++)
    {
        for(j=0;j<kolom;j++)
        {
            printf("%c", line);
        }
    printf("\n");
    }
}
