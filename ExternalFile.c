
char ReadFile(char *GOL){
    FILE *seed;
    char filename[10]="";
    char tipe[]=".txt";
    char newline;
    char line[2][5];//jumlah baris dan kolom
    int baris, kolom,i,j;
    unsigned char **GOL =NULL;


    printf("Input Nama File:");
    scanf("%s", &filename);
    strcat(filename, tipe);
    printf("%s\n", filename);
    seed = fopen(filename, "r");
    
    while(seed == NULL){
        printf("Error Opening File\n");
        printf("Input Nama File:");
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

    for(i=0;i<baris;i++){
        for(j=0; j<kolom;j++){
            printf("%c", GOL[i][j]);
        }
        printf("\n");
    }
    
    fclose(seed);
}
