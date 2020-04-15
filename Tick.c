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
