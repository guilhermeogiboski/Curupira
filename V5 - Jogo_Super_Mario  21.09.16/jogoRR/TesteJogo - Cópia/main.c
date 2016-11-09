#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "teclado.h"
#include "objetos.h"
#define DRAW_SPRITE_NORMAL 0
#define DRAW_SPRITE_TRANS 1
#define NUM_INIMIGOS 10
#define nNavio 2
#define nGas 1
#define maxX 800
#define maxy 600
#define MAX_TIROS    10
#include <string>  
#include <vector> 
  using namespace std;
   


// prototipos das funcoes utilizadas
void Inicializa();
void Finaliza();
bool fimJogo = FALSE; // flag que indica se o jogo foi ou nao finalizado
int ticks = 0;  // esta variavel ira ser um contador de ticks do clock principal
                // do jogo
                // cada tick a mais significa que um ciclo de logica do jogo
                // foi processado
                
                
// a funcao do timer do tick apenas incrementa o contador
void ticker() {
    ticks++;
}END_OF_FUNCTION(ticker);
int segundos = 0;   // esta variavel ira ser um contador de segundos
                    // a cada segundo passado este contador ira ser incrementado
                    // basicamente eh a chave para fazer um contador de fps
                    // pois se tivermos a quantidade de frames desenhados
                    // e a quantidade de segundos podemos calcular os frames
                    // por segundo

// a funcao do timer do clock apenas incrementa o contador
void clocka() {
    segundos++;
} END_OF_FUNCTION(clocka);// a partir daqui definimos algumas outras variaveis auxiliares



MenuItem

Representa o item de um menu
=======
*/
class MenuItem {
private:
    int x, y;                   // localizacao deste item de menu na tela

    // esta funcao verifica se o cursor do mouse esta em cima (dentro) deste item de menu
    // se estiver, retorna true, caso contrario retorna false
    bool mouseDentro() {
        int x1 = x;
        int y1 = y;
        int x2 = x1 + pic->w;
        int y2 = y1 + pic->h;

        if (mouse_x > x1 && mouse_x < x2 && mouse_y > y1 && mouse_y < y2)
            return true;
        else
            return false;
    }

public:
    BITMAP *pic;                // imagem do item do menu
    BITMAP *picMouseDentro;     // imagem do item do menu (quando o mouse estiver em cima)
    bool isMouseDentro;         // flag que indica se o mouse esta ou nao dentro do menu
    void (*funcao)();           // ponteiro para a funcao que sera executada quando o usuario clicar neste menu

    MenuItem(int posX, int posY, string imagem, string imagemDentro, void (*pFuncao)()) {
        isMouseDentro = false;
        
        // define a posicao
        x = posX;
        y = posY;

        // carrega as figuras do menu
        pic = load_bitmap(imagem.c_str(), NULL);
        picMouseDentro = load_bitmap(imagemDentro.c_str(), NULL);
    
        // se especificou uma funcao, passa ela
        if (pFuncao)
            funcao = pFuncao;
    }
    
    // acao que este item de menu ira realizar
    void realizaAcao() {
        if (funcao != NULL)
            (funcao)(); // chama a funcao
    }

    // atualiza este item de menu
    void atualiza() {
        // se o mouse passar em cima, executa a acao deste menu
        if (mouseDentro()) {
            isMouseDentro = true;
            
            // se clicar realiza a acao
            if (mouse_b & 1) realizaAcao();

        } else {
            isMouseDentro = false;
        }
    }
    
    // desenha este item de menu na tela
    void desenha(BITMAP *bmp) {
        if (isMouseDentro)
            draw_sprite(bmp, picMouseDentro, x, y);
        else
            draw_sprite(bmp, pic, x, y);
    }

    ~MenuItem() {
    }
};

/*
=======
Menu

Classe que gerencia os menus
=======
*/
class Menu {
private:
    vector<MenuItem> items; // representa os itens do menu

public:
    Menu() {}

    // verifica a logica para todos os itens do menu
    void atualiza() {
        int totalItems = items.size();
        for (int i = 0; i < totalItems; i++) {
            items[i].atualiza();
        }
    }
    
    // desenha os itens de menu
    void desenha(BITMAP *bmp) {
        int totalItems = items.size();
        for (int i = 0; i < totalItems; i++) {
            items[i].desenha(bmp);
        }
    }

    // adiciona um item ao menu
    void adicionaItem(MenuItem menuItem) {
        items.push_back(menuItem);
    }

    ~Menu() {
        int totalItems = items.size();
        for (int i = 0; i < totalItems; i++) {
            // desaloca a memoria alocada para este item
            destroy_bitmap(items[i].pic);
            destroy_bitmap(items[i].picMouseDentro);
        }
    }
};


// ===================
// definicao das funcoes dos menus
// ===================

void mnuNewGame() {
}
void mnuOptions() {
}
void mnuHighScores() {
}
void mnuExit() {
    fimJogo = true;
}
                


int max(int a, int b)
{
  if(a >= b)
   return a;
  else
   return b;
}

int min(int a, int b)
{
  if(a <= b)
   return a;
  else
   return b;
}







///--------------------------------------MÉTODO PIXEL PERFECT---------------------------------------------
int pixel_perfect_colision(int x1, int y1, BITMAP* obj1, int x2, int y2, BITMAP* obj2)
{
   int i, j;
   int colisao = FALSE;

   //Se os retângulos estiverem se intersectando
   if(!( (x1 > x2 + obj2->w) || (y1 > y2 + obj2->h) || (x2 > x1 + obj1->w) || (y2 > y1 + obj1->h) ))
   {
     int cima = max(y1, y2);
	 int baixo = min(y1 + obj1->h, y2 + obj2->h);
	 int esquerda = max(x1, x2);
     int direita = min(x1 + obj1->w, x2 + obj2->w);

	 for(i = cima; i < baixo && !colisao; i++)
	 {
		for(j = esquerda; j < direita && !colisao; j++)
		{
		  if(getpixel(obj1, j-x1, i-y1) != makecol(255,0,255) && getpixel(obj2, j-x2, i-y2) != makecol(255,0,255))
           colisao = TRUE;
		}
	 }
   }

   return colisao;
}

///MÉTODO DE CAIXAS DE COLISÃO
int bounding_box_collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
    if( (x1 > x2 + w2) || (y1 > y2 + h2) || (x2 > x1 + w1) || (y2 > y1 + h1) )
     return FALSE;
    else
     return TRUE;
}


//-----------------------------------
    volatile int exit_program ; //evitar certos tipos de otimizaçõe
    void fecha_programa()
{
         exit_program = TRUE;
}      
 END_OF_FUNCTION(fecha_programa) 
 
   volatile int milisegundos;
   void counter()
{
        milisegundos++;
}
END_OF_FUNCTION(counter)

// STRUCTS-------
  
struct Personagem Tiro;
struct NaveEspacial nave;
struct Personagem inimigoClone;
struct Personagem gasolinaM[nGas];
struct Personagem navioM[nNavio];

  
  
 
 //-----------------------------------INT MAIN--------------------------------------//
 
 
 
 
 
 
  int main(){
    allegro_init();
    install_timer();
    install_keyboard();
    set_color_depth(32);// combinações das cores
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800,600,0,0);     // driver de video, RESOLUÇÃO, tela virtual
    set_window_title("Jogo");
    
    exit_program = FALSE;  
    LOCK_FUNCTION(fecha_programa);
    LOCK_VARIABLE(exit_program); 
    set_close_button_callback(fecha_programa);
    
    milisegundos = 0;
    LOCK_FUNCTION(counter);
    LOCK_VARIABLE(milisegundos); 
    install_int_ex(counter, BPS_TO_TIMER(10000));
   
    srand (time(NULL));
    
    
    
    
    
     Menu *menu = new Menu();

    // agora adiciona os itens do menu
    // new game
    MenuItem itemNewGame(187, 51,  "mnuNewGame.bmp", "mnuNewGameM.bmp", mnuNewGame);
    menu->adicionaItem(itemNewGame);

    // options
    MenuItem itemOptions(187, 122, "mnuOptions.bmp", "mnuOptionsM.bmp", mnuOptions);
    menu->adicionaItem(itemOptions);

    // highscores
    MenuItem itemHighScores(187, 199, "mnuHighscores.bmp", "mnuHighscoresM.bmp", mnuHighScores);
    menu->adicionaItem(itemHighScores);

    // exit
    MenuItem itemExit(187, 274, "mnuExit.bmp", "mnuExitM.bmp", mnuExit);
    menu->adicionaItem(itemExit);

   
    
  
    //bitmaps..............................................................................................
    BITMAP* buffer = create_bitmap(SCREEN_W,SCREEN_H);// vriaveis globais de altura e largura
    BITMAP* objeto1 = load_bitmap("objeto.bmp",NULL);
    BITMAP* objeto2 = load_bitmap("fn.bmp",NULL);  
    BITMAP* combustivel = load_bitmap("gas.bmp",NULL);  
    BITMAP* Navio = load_bitmap("navio.bmp",NULL); 
    BITMAP* tr = load_bitmap("tiro.bmp",NULL);
     
 
      float teta = 0.0;
      
  // variáveis..............................................................................................
    float x1 = SCREEN_W/2;
    float y1 = 7*SCREEN_H/8;

    int One = 0;
    int two = 0;
    
    int x2 = 0;
    int y2 = 0;
    int modo = DRAW_SPRITE_NORMAL;
    
    set_color_blender(0,0,0, makecol(60, 200, 10));
    int timer_FPS = milisegundos - 10;
	int qtdTiro = 0;
    
    float deslY = (float)600 - objeto2->h;
  
     //--------STRUCT PERSONAGEM---------------------------//
    

    //struct NaveEspacial nave;
    iniciaNave (&nave,SCREEN_W/2,7*SCREEN_H/8,"objeto.bmp",0);
    
   // struct Personagem Tiro;
    iniciaPersonagem(&Tiro, -10, 0, "tiro.bmp", 0);// img tiro
    Tiro.ativo = 0;
    
    
   // struct Personagem inimigoClone;
    iniciaPersonagem(&inimigoClone, 300, 0, "objeto.bmp", 0);
    

    
    //struct Personagem navioM[nNavio];
    int n;
    srand( (unsigned)time(NULL) );
    for(n = 0; n<nNavio; n++)
    {     iniciaPersonagem(&navioM[n], 0,0, "navio.bmp",0);
          navioM[n].x = rand() % (maxX - navioM[n].tx);         	
    }
    
     srand( (unsigned)time(NULL) );
    for(n = 0; n<nGas; n++)
    {     iniciaPersonagem(&gasolinaM[n], 0,0, "gas.bmp",0);
          gasolinaM[n].x = rand() % (maxX - gasolinaM[n].tx);         	
    }
    
    
  // GAME LOOP............................................................................................ 
        
    while(!exit_program) // condição para fechar
    {
            //rodar a 100 fps 
       if(milisegundos - timer_FPS >100)
        {
     // imput.............................................................................................
     
    
     poll_keyboard();
          
       if(key[KEY_ESC])
         exit_program = TRUE;
         
         
          menu->atualiza();
            
            ticks--;
            
            // limpa a tela com a cor branca
        clear_to_color(bmp, makecol(255, 255, 255));
     
      // movimento.........................................................................................

       if(apertou(KEY_RIGHT)&&(One == 0) && nave.x<750) // chamar a função e passar a tecla como parãmetro
       {
          nave.x = nave.x +50  ;
          One = 1; 
       }
       else if((!apertou(KEY_RIGHT))&&(One == 1) )
            One = 0;
         
       if(apertou(KEY_LEFT)&& (two == 0) && nave.x>35)
        { 
           nave.x = nave.x -50;
           two = 1;
        }
         else if((!apertou(KEY_LEFT))&&(two == 1))
            two = 0;
            
      // ---------------------------------ATIRA---------------------------------------//
       if(key[KEY_SPACE] && ( Tiro.ativo == 0))
	   {
            
          Tiro.x = nave.x;
          Tiro.y = nave.y;
          Tiro.ativo = 1;
	   }
	   
       if(Tiro.ativo == 1)
       {
          Tiro.y = Tiro.y - 2.9;
          if(Tiro.y < 0)
          {
             Tiro.ativo = 0;
             Tiro.x = -Tiro.tx;
          }          
       }
        
		
		//-------------Acelerar--------------------------------------------//
		
		 
		if(key[KEY_UP])
		deslY = deslY+1.5;
		
		if(key[KEY_DOWN])
		deslY = deslY-1.5;
		


	for(n = 0; n<nNavio; n++)
	{
		if(navioM[n].ativo == TRUE)
		{
			navioM[n].y = navioM[n].y + 2.9;
			if(navioM[n].y >= maxy)
			navioM[n].y = -navioM[n].ty;
		}else
		{
			navioM[n].y = -navioM[n].ty;
			navioM[n].x = rand() % (maxX - navioM[n].tx);
			navioM[n].ativo = TRUE;
		}	 
	}
	
	
		for(n = 0; n<nGas; n++)
	{
		if(gasolinaM[n].ativo == TRUE)
		{
			gasolinaM[n].y = gasolinaM[n].y + 2.9;
			if(gasolinaM[n].y >= maxy)
			gasolinaM[n].y = -gasolinaM[n].ty;
		}else
		{
			gasolinaM[n].y = -gasolinaM[n].ty;
			gasolinaM[n].x = rand() % (maxX - gasolinaM[n].tx);
			gasolinaM[n].ativo = TRUE;
		}	 
	}


 //---------------------------------------UPDATE------------------------------------//
     
        
      
         nave.combustivel--;
      
        deslY = deslY + 2.9;
        inimigoClone.y = inimigoClone.y + 2.9;
        //gasolina.y = gasolina.y + 2.9;
        
        
        
       if(pixel_perfect_colision(nave.x, nave.y, objeto1, 0, deslY, objeto2) == TRUE)
      {
          textout_ex(screen,font,"colidiu",20,25,makecol(255,0,0), -1);
          if(nave.x+(nave.tx/2) > 300) nave.x = nave.x-25;
          if(nave.x +(nave.tx/2) < 300) nave.x=nave.x +25;    
          nave.vidas--;
            //if(nave.vidas==0) return 0;   
      }
      
    //-----------COLISÂO COM INIMIGOS---------------//    
    
      if(pixel_perfect_colision(nave.x, nave.y, objeto1, inimigoClone.x, inimigoClone.y, inimigoClone.imagem) == TRUE)
      {
        inimigoClone.ativo = FALSE;
        nave.vidas--;
      }
    
      
        
    
          
    for(n = 0; n<nNavio; n++)
    {     if(pixel_perfect_colision(nave.x, nave.y, objeto1, navioM[n].x, navioM[n].y, navioM[n].imagem) == TRUE)
          {
          nave.vidas --;
          navioM[n].ativo = FALSE;
          }
    }
        

    for(n = 0; n<nNavio; n++)
    {     if(pixel_perfect_colision(Tiro.x, Tiro.y, Tiro.imagem, navioM[n].x, navioM[n].y, navioM[n].imagem) == TRUE)
          {
          Tiro.ativo = FALSE;
          //Tiro.x = -Tiro.tx;
          navioM[n].ativo = FALSE;
          nave.pontos++;
          break;
          }
    }
    
            
    for(n = 0; n<nGas; n++)
    {     if(pixel_perfect_colision(nave.x, nave.y, combustivel, gasolinaM[n].x, gasolinaM[n].y, gasolinaM[n].imagem) == TRUE)
          {
          nave.combustivel = nave.combustivel+50 ;
          gasolinaM[n].ativo = FALSE;
          }
    }
       
      
        
     //---------------------------DESENHA-----------------------------------------//
   
   
   
   

   draw_sprite(buffer,objeto2,0, (int)deslY);//desenhar no buffer
  
   if(inimigoClone.ativo == TRUE)
   draw_sprite(buffer,inimigoClone.imagem,inimigoClone.x, (int)inimigoClone.y);//desenhar no buffer
   

   
   for(n = 0; n<nNavio; n++)
    {
 		 if(navioM[n].ativo == TRUE)
          draw_sprite(buffer, navioM[n].imagem, navioM[n].x, navioM[n].y);
    }
    
    
       for(n = 0; n<nGas; n++)
    {
 		 if(gasolinaM[n].ativo == TRUE)
          draw_sprite(buffer, gasolinaM[n].imagem, gasolinaM[n].x, gasolinaM[n].y);
    }
    
      
      
      
       if(Tiro.ativo == 1)
       {
          draw_sprite(buffer,Tiro.imagem,Tiro.x,Tiro.y);
       }

   draw_sprite(buffer,nave.imagem,nave.x,nave.y);
   

   textprintf_ex(buffer,font,700,550,makecol(0,0,255),-1,"Pontos: %d",nave.pontos);
   textprintf_ex(buffer,font,700,450,makecol(0,0,255),-1,"Vidas: %d",nave.vidas);
    textprintf_ex(buffer,font,650,350,makecol(0,0,255),-1,"Combustivel: %f",nave.combustivel);
   draw_sprite(screen,buffer,0,0); 
   clear_to_color(buffer, makecol(255,255,255));
   clear(buffer);
   
   timer_FPS = milisegundos; // reseta contador
}        
    }
    
    
    
     textprintf(bmp, font, 0, 0, -1, "FPS: %i", fps);

        // desenha o menu
        menu->desenha(bmp);

        // exibe o cursor do mouse na tela
        show_mouse(bmp);
        
        // depois que estiver como frame no bmp, copiamos o conteudo inteiro dele
        // para a tela
        // isto eh realizado pois como esta copia eh feita em memoria, eh muito
        // mais rapido
        blit(bmp, screen, 0, 0, 0, 0, vid_largura, vid_altura);

        // apos a saida concluida, incrementamos o contador de frames, pois
        // temos mais um frame desenhado na tela
        frames++;

        // agora iremos calcular o total de frames por segundo
        // a logica eh a seguinte:

        // se na aplicacao ja passou um segundo
        if (segundos) {
            // calcula o fps sendo que o fps sera a quantidade de frames desenhados
            // dividido pelo numero de segundos passados (no caso 1)
            fps = frames / segundos;
            frames = 0; // como ja calculamos o fps, pode zerar a quantidade de frames desenhados
            segundos = 0; // e zera tambem o numero de segundos, isso garante que o proximo
            // calculo de fps sera executado um segundo depois
        }
    }

    delete menu;

    // executa todas as finalizacoes necessarias
    Finaliza();

    
    
    
    
             
   // finalização bitmap...........................................................................................
   destroy_bitmap(buffer);
   destroy_bitmap(objeto2);
   destroy_bitmap(objeto1);
   



  
            
    return 0;
} 


          
END_OF_MAIN();



/*
=======
Inicializa

Realiza qualquer procedimento necessario para iniciar o jogo
Isto inclui iniciar a janela e deixa-la preparada para ser desenhada, iniciar
o estado do jogo, posicoes iniciais, nivel inicial e tudo o que for necessario
=======
*/
void Inicializa() {
    int res;
    allegro_init();
    set_color_depth(vid_profundidade);
    res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, vid_largura, vid_altura, 0, 0);

    if (res != 0) {
        allegro_message(allegro_error);
        exit(-1);
    }

    install_timer();
    install_keyboard();
    install_mouse();

    // aqui inicializamos o nosso timer de ticks
    // trancando o espaco de memoria da variavel ticks e da funcao timer
    // assim elas nao sofrem alteracoes externas
    // note que a funcao ticker sera chamada 60 vezes por segundo, isto eh,
    // a logica do nosso jogo sera executada 60 vezes em um segundo
    LOCK_VARIABLE(ticks);
    LOCK_FUNCTION(ticker);
    install_int_ex(ticker,BPS_TO_TIMER(60));

    // aqui ocorre o mesmo processo para o timer dos segundos
    // note que o timer sera chamado apenas uma vez por segundo
    LOCK_VARIABLE(segundos);
    LOCK_FUNCTION(clocka);
    install_int_ex(clocka,BPS_TO_TIMER(1));

    // cria um bitmap com uma dimensao grande o suficiente para caber na tela
    bmp = create_bitmap(SCREEN_W,SCREEN_H);
    set_window_title("VSoftGames - Teste de Menus");
}

/*
=======
Finaliza

Realiza qualquer procedimento de limpeza para finalizar o jogo
=======
*/
void Finaliza() {
    clear_keybuf();
    //destroy_bitmap(bmp);

    // neste ponto voce devera adicionar qualquer tipo de finalizacao que for
    // necessario, limpeza, etc.
}

