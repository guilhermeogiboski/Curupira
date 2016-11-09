#ifndef FUNçõES_H_INCLUDED
#define FUNçõES_H_INCLUDED



void tela(int x,int y){
int i,j,k,l;
    for(i=0;i<y;i++){

     gotoxy(0,i);
      setcolor(vermelho);
        printf("%c",254);
    }

        for(k=0;k<x;k++){
            gotoxy(k,0);
           setcolor(azulclaro);
            printf("%c",254);

        }

        for(l=0;l<y;l++){
            gotoxy(x,l);
           setcolor(branco);
            printf("%c",254);
        }

        for(j=0;j<=x;j++){
            gotoxy(j,y);
          setcolor(amarelo);
            printf("%c",254);
        }

    //barreira......................................

    for(x=7;x<11;x++){
        setcolor(vermelho);
        gotoxy(20,x);
        printf("%c",219);
    }

}



    int cobra (){



    char tecla='a';
    int opcao;
    int pontos=0;
	int nivel = 1;

        int x,d=2,cx[300]={1,2},cy[300]={7,7},t=1,mx,my,velo=100,velo2=5;
	char niv;

	srand(time(NULL));
    mx=(rand()%49)+1;
    my=(rand()%17)+1;

    velo = 200;

    while(tecla!='s')
    {   while(tecla!='s'&&!(tecla=kbhit()))

        {   for(x=t;x>0;x--)
            {   cx[x]=cx[x-1];
                cy[x]=cy[x-1];
            }

            if(d==0)cx[0]--;
            if(d==1)cy[0]--;
            if(d==2)cx[0]++;
            if(d==3)cy[0]++;
            gotoxy(cx[t],cy[t]);
            printf(" ");
            if(mx==cx[0]&&my==cy[0])
            {   t++;
            	pontos++;
                mx=(rand()%25)+1;
                my=(rand()%17)+1;
                velo-=5;
                velo2+=5;

            }
            gotoxy(cx[0],cy[0]);
            setcolor(amarelo);
            printf("%c",254);

            gotoxy(mx,my);
            setcolor(verde);
            printf("%c",207);
            gotoxy(55,10);

            printf ("Pontos: %d",pontos);
            gotoxy(55,5);
            printf ("Nivel: %d",nivel);
            gotoxy(55,3);
            printf ("Velocidade: %d",velo2);
            gotoxy(3,22);


            Sleep(velo);

            for(x=1;x<t;x++)
            {   if(cx[0]==cx[x] && cy[0]==cy[x])tecla='s'; // ENCOSTAR NELA MESMA
            }
            if(cy[0]==0||cy[0]==18 || cx[0]==0 || cx[0]==50)tecla='s';
            if(cx[0]==20 && cy[0]== 7 || cx[0]==20 && cy[0]== 8 || cx[0]==20 && cy[0]== 9 || cx[0]==20 && cy[0]== 10 || cx[0]==20 && cy[0]== 11 )tecla='s'; // COLISÃO COM BARREIRA

        }
        if(tecla!='s')tecla=getch();
        if(tecla=='K')d=0;
        if(tecla=='H')d=1;
        if(tecla=='M')d=2;
        if(tecla=='P')d=3;
        if(cy[0]==0||cy[0]==18||cx[0]==0||cx[0]==26)tecla='s';

    }return pontos;

    }

    void gameover(){

         system("cls");
    system("pause");

    setcolor(vermelho);
    printf ("\n\n\t GAME OVER\n\n");


    }

    int pontosfinais(int pontos){
    setcolor(verde);
    printf ("\n\n\tVOCE FEZ %d PONTO(S)",pontos);
    printf("\n\n\n\n\n\n");

    }





#endif // FUNçõES_H_INCLUDED
