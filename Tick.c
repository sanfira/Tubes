/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 * MODUL 8 ¨C TUGAS BESAR
 * Kelompok : 1
 * Hari dan Tanggal : Jumat, 17 April 2020
 * Asisten (NIM) : Berry (13216027)
 * Nama File : Tick.c
 * Deskripsi : fungsi untuk memajukan iterasi game of life sebanyak 1 iterasi
 */

void Tick(unsigned char *GOL[], int N, int M)
{
    char NEXT[N][M]; //sebuah array 2D temporary untuk menyimpan iterasi baru sementara
    int X,Y,i,j,count; //X,Y,i,j digunakan untuk traversal pada array, count untuk menghitung tetangga yang hidup/terpopulasi
    for(i=0;i<M;i++) //loop secara vertikal dari atas ke bawah
    {
        for(j=0;j<N;j++) //loop secara horizontal dari kiri ke kanan
        {
            count=0; //secara default, tetangga yang hidup=0 untuk semua sel utama yang dievaluasi
            X=j+N; //realisasi toroidal agar nilai negatif tidak muncul
            Y=i+M;
            if (GOL[(X-1)%N][(Y)%M]=='X') //Kiri, mod N dan M agar range tetap dari 0 hingga N dan M
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
                    NEXT[X%N][Y%M]='X'; //sel hidup akan tetap hidup jika ada 2 atau 3 tetangga hidup
                } else {
                    NEXT[X%N][Y%M]='-'; //selain itu, sel akan mati
                }
            }
            if (GOL[X%N][Y%M]=='-')
            {
                if (count==3){
                    NEXT[X%N][Y%M]='X'; //sel mati akan regenerasi jika ada 3 tetangga hidup
                } else {
                    NEXT[X%N][Y%M]='-'; //selain itu, tetap mati
                }
            }
        }
    }

    for(i=0;i<M;i++){ //loop diatas dilakukan kembali
        for(j=0;j<N;j++){
            GOL[j][i]=NEXT[j][i]; //nilai di array temporary dipindahkan ke array GOL
        }
    }
    return;
}
