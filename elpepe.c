#include <256IMAGE.h>
#include <GRAPHICS.H>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <win8.h>
#include <stdio.h>
#include <stdlib.h>

void Juego1();
void escrito(void);
void iniciowin8();
int juegos(void);
void logo(void);
int lab();
void barra_tarea(void);
void Janfry(void);
void Eva(void);
void presentacion(void);
int pantalla = 0;
int on;
char tecla;

/*Recursos de Llamado de imagen windows*/
int RealDrawColor(int color){
  if (getmaxcolor() > 256)
     setrgbpalette(1024,(color>>10)&31,(color>>5)&31,color&31);
  return(color);
};

int WhitePixel(){
  if (getmaxcolor() > 256)
     return(32767);
  return(15);
}

int huge DetectVGA256(){
    /* 0 = 320x200x256  modo CGA  320(horizontal) con 200(vertical) pixeles(puntos) en 256colores
        1 = 640x400x256  modo ATT400
        2 = 640x480x256  modo VGA
        3 = 800x600x256  modo SVGA
        4 = 1024x768x256; modo XGA
        Todos son los modos graficos estandar  */
  return 2;
}
/* Termina recursos */


/*Inicia programa */

int main(void) {
	int i,j;
	int puntos[2][50] = {  {320,321,323,325,326,327,327,327,327,326,324,322,321,319,317,315,313,312,312,312,312,313,314,316,317,   320,321,323,325,326,327,327,327,327,326,324,322,321,319,317,315,313,312,312,312,312,313,314,316,317},
                            {368,368,369,370,371,373,375,377,379,381,382,383,384,384,383,382,381,379,377,375,373,371,370,369,368,   368,368,369,370,371,373,375,377,379,381,382,383,384,384,383,382,381,379,377,375,373,371,370,369,368}};
int Logo_Windows1[10] = {321,185,   359,185,    359,217,    321,212,    321,185};

int Logo_Windows2 [10]={321,155,   359,149,    359,182,    321,182,    321,155};

int Logo_Windows3 [10]={288,159,   318,155,    318,182,    287,182,    288,159};

int Logo_Windows4 [10]={288,185,   318,185,    318,212,    287,208,    288,185};


	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC20\\BIN");
       logo();
       setcolor(11);
       setfillstyle(SOLID_FILL, 11);
       fillpoly(5,Logo_Windows1);
       setfillstyle(SOLID_FILL, 11);
       fillpoly(5,Logo_Windows2);
	   setfillstyle(SOLID_FILL, 11);
       fillpoly(5,Logo_Windows3);
	   setfillstyle(SOLID_FILL, 11);
       fillpoly(5,Logo_Windows4);
	   
       setcolor(15);
	   for(j=0;j<4;j++)
        for (i=0;i<25;i++)
        {
			setcolor(15);
            putpixel(puntos[0][i+1],puntos[1][i+1],15);
            putpixel(puntos[0][i+3],puntos[1][i+3],15);
            putpixel(puntos[0][i+6],puntos[1][i+6],15);
            putpixel(puntos[0][i+9],puntos[1][i+9],15);

            setcolor(0);
            putpixel(puntos[0][i],puntos[1][i],BLACK);
            putpixel(puntos[0][i+2],puntos[1][i+2],BLACK);
            putpixel(puntos[0][i+5],puntos[1][i+5],BLACK);
            putpixel(puntos[0][i+8],puntos[1][i+8],BLACK);

            if(i>10||i<1)
                delay(200);
            else
                delay(100);
		}
		closegraph();
        iniciowin8();
       getch();
}


void logo(void)
{
  
  int i,a,b,c;
 
    while(!kbhit())
    {
	cleardevice();
	setcolor(BLUE);
	for(i=0;i<=294;i++){
		putpixel(233,i,BLUE);
		a=480-i;
		putpixel(407,a,BLUE);
		delay(1);
	}
	for(i=0;i<=407;i++){
		putpixel(i,294,BLUE);
		a=640-i;
		putpixel(a,186,BLUE);
		delay(1);
	}
	delay(60);
	setfillstyle(WIDE_DOT_FILL,LIGHTBLUE);
	floodfill(250,210,BLUE);
	delay(60);
	setfillstyle(CLOSE_DOT_FILL,LIGHTBLUE);
	floodfill(234,293,BLUE);
	delay(60);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(406,293,BLUE);

	setcolor(WHITE);
	for(i=0;i<=267;i++){
		line(263,i,270,i);
		a=480-i;
		line(369,a,376,a);
		delay(2);
	}
	b=376;
	c=a;
	for(i=270;i<=305;i++){
		line(i,258,i,267);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	for(i=258;i>=214;i--){
		line(298,i,305,i);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	for(i=305;i<=341;i++){
		line(i,214,i,223);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	for(i=223;i<=480;i++){
		line(334,i,341,i);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	setcolor(BLACK);
	for(i=0;i<=267;i++){
		line(263,i,270,i);
		a=480-i;
		line(369,a,376,a);
		delay(2);
	}
	b=376;
	c=a;
	for(i=270;i<=305;i++){
		line(i,258,i,267);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	for(i=258;i>=214;i--){
		line(298,i,305,i);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	for(i=305;i<=341;i++){
		line(i,214,i,223);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	for(i=223;i<=480;i++){
		line(334,i,341,i);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	delay(60);
	setfillstyle(WIDE_DOT_FILL,BLACK);
	floodfill(250,210,RED);
	delay(60);
    }

    getch();
    cleardevice();
    
}


void iniciowin8()
{
	Janfry();
     msituar(1,320,100);
     mlimit(1,1,1,640,480);
	 mver();
	 while(1){
			   click = mclick();
               x = mxpos(1);
               y = mypos(1);
               if (click == 1){
                         if (x >= 34 && x <= 283 && y >=343  && y <= 440){
                              mocultar();
							  closegraph();
							  escrito();
      					
						  }	else if (x >= 31 && x <= 230 && y >= 120 && y <= 281){
                              mocultar();
				              closegraph();
	 						  Juego1();
                              iniciowin8();
	                      }else if (x >= 270 && x <= 444 && y > 124 && y <= 282){
                         	  mocultar();
   				              closegraph();				
							  lab();
                              iniciowin8();
						  }else if (x >= 485 && x <= 607 && y > 295 && y <= 424){
                              mocultar();
							  closegraph();				
							  Eva();
                              iniciowin8();
                          }else if (x >= 555 && x <= 628 && y > 13 && y <= 85){
                              mocultar();
							  presentacion();
                              iniciowin8();
                          }							  
			        }
	    }
    getch();
}

void escrito(void){
	
	
	int modo = DETECT, tarj,TIPOLETRA;
	time_t tiempoahora;
    time(&tiempoahora);
	installuserdriver("Svga256",DetectVGA256);
	TIPOLETRA = installuserfont("LITT.CHR");
	initgraph(&modo,&tarj,"C:\\TC20\\BIN");
    mostrar_imagen(0,0,"C://images//windows.bmp",1);
	setcolor(15);
	outtextxy(480,450, ctime(&tiempoahora));
    msituar(1,320,100);
    mlimit(1,1,1,640,480);
	mver();
	while(1){
		       click = mclick();
               x = mxpos(1);
               y = mypos(1);
               if (click == 1){
                          if (x >=6 && x <= 78 && y >= 9 && y <= 100){
						      mocultar();
							  setcolor(1);
							  setlinestyle(0, 0, 3);		  
							  delay(500);
							  Juego1();
							  escrito();
				
						  }	else if (x >=6 && x <= 79 && y >=118  && y <= 208){
                              mocultar();
							  setcolor(1);
							  setlinestyle(0, 0, 3);		  
			   				  delay(500);		  
                              lab();
							  escrito();
						    
						   }else if (x >=8 && x <= 48 && y >= 440 && y <= 471){
                              mocultar();
							  barra_tarea();
								
							 msituar(1,25,430);
							 mver();
						                 } else if (x >107 && x <= 160 && y >= 252 && y <= 432){
										       mocultar();
										       delay(100);
										       exit(1);
 		             					    	
                            }else if (x >=161 && x <= 640 && y >=0  && y <= 480){
                               mocultar();
							   setlinestyle(0, 0, 3);
                               closegraph();							   
                               escrito();
                               mver();
                            }							   
				}                               				
				
			}
	getch();	
}

void barra_tarea(void){
	int modo = DETECT, tarj,TIPOLETRA;
	time_t tiempoahora;
    time(&tiempoahora);
	installuserdriver("Svga256",DetectVGA256);
	TIPOLETRA = installuserfont("LITT.CHR");
	initgraph(&modo,&tarj,"C:\\TC20\\BIN");
    mostrar_imagen(0,0,"C://images//refresh.bmp",1);
	outtextxy(480,450, ctime(&tiempoahora));
	mlimit(1,1,1,640,480);
	mver();
}

void Janfry(void){
	int modo = DETECT, tarj,TIPOLETRA;
	
	installuserdriver("Svga256",DetectVGA256);
	TIPOLETRA = installuserfont("LITT.CHR");
	initgraph(&modo,&tarj,"C:\\TC20\\BIN");
    mostrar_imagen(0,0,"C://images//janfry.bmp",1);
	mlimit(1,1,1,640,480);
	mver();
}

void Eva(void){
	int modo = DETECT, tarj,TIPOLETRA;
	
	installuserdriver("Svga256",DetectVGA256);
	TIPOLETRA = installuserfont("LITT.CHR");
	initgraph(&modo,&tarj,"C:\\TC20\\BIN");
    mostrar_imagen(0,0,"C://images//Eva.bmp",1);
	getch();
	closegraph();
}

void presentacion(void){
	int modo = DETECT, tarj,TIPOLETRA;

	installuserdriver("Svga256",DetectVGA256);
	TIPOLETRA = installuserfont("LITT.CHR");
	initgraph(&modo,&tarj,"C:\\TC20\\BIN");
    mostrar_imagen(0,0,"C://images//ppp.bmp",1);
	getch();
	closegraph();
}
