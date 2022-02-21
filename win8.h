#include <GRAPHICS.H>
#include <DOS.H>
#include <string.h>
#include <MOUSE.H>
#include <FORM.H>
#include <TIME.H>
#include <button.h>

#define ENTER 13
void gudbai();
void crear();
void start();
void barra();
void Board();
void PlayerX();
void PlayerO();
void Player_win();
void check();
void menu();
void help();
void help2();
void help3();
void GameX0();
void menulab();
void endgame();
void endgame1();
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);
void AI();
void crear(void);
void leer(void);
int Con_win = 0;
char ganador[10];
char lectura;
int end1[] = {148,132,459,132,459,164,148,164,148,132};
int end2[] = {148,215,460,215,460,245,148,245,148,215};
int end3[] = {148,283,459,283,459,318,148,318,148,283};
int end4[] = {222,350,383,350,383,384,222,384,222,350};
int equis[] = {623,2,638,2,638,11,623,11,625,2};

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

int help1;
int win=0,wrong_X=0,wrong_O=0,chk=0;
int i,j,q;
int cont_empate = 0;
char xd;
int x, y, click, painting,gb;
int xx,yy;
/*int perder=0;*/
char tecla;
int cont=0;
char name_lab;
int acceso, gameMode, salida;
int isButton;
int gameMode, salida;
button pvp, pvc, re1, helpB, btn, his, exit1, exit3, menu1, exit3, rehelp;

char name_X[10];
char name_O[10];
int pos_for_X[3][3];
int pos_for_O[3][3];
int pos_marked[3][3];

char arr[50];
char ch;


void laberinto(void)
{
 setcolor(2);
 line(136,79,280,79);
 line(295,79,455,79);
 line(455,79,455,399);
 line(455,399,311,399);
 line(295,399,135,399);
 line(135,399,135,79);
 line(231,79,231,95);
 line(231,95,152,95);
 line(151,95,151,111);
 line(167,95,167,111);
 line(151,127,151,143);
 line(151,143,136,143);
 line(215,95,215,111);
 line(247,95,247,143);
 line(247,111,232,111);
 line(231,111,231,127);
 line(231,127,200,127);
 line(199,127,199,111);
 line(199,111,184,111);
 line(183,111,183,127);
 line(183,127,168,127);
 line(167,127,167,143);
 line(168,143,231,143);
 line(231,143,231,159);
 line(232,159,263,159);
 line(263,159,263,95);
 line(264,95,312,95);
 line(264,127,295,127);
 line(279,127,279,111);
 line(295,127,295,142);
 line(295,143,327,143);
 line(311,143,311,159);
 line(327,143,327,127);
 line(327,127,344,127);
 line(295,111,359,111);
 line(311,111,311,127);
 line(343,111,343,95);
 line(327,111,327,79);
 line(359,111,359,143);
 line(359,143,343,143);
 line(407,95,375,95);
 line(375,95,375,207);
 line(375,159,344,159);
 line(343,159,343,223);
 line(327,223,391,223);
 line(327,223,327,239);
 line(391,223,391,207);
 line(375,127,391,127);
 line(376,191,424,191);
 line(359,222,359,175);
 line(407,175,407,239);
 line(407,239,359,239);
 line(407,175,423,175);
 line(423,175,423,127);
 line(423,127,439,127);
 line(439,127,439,95);
 line(439,143,455,143);
 line(423,79,423,111);
 line(423,111,391,111);
 line(407,111,407,159);
 line(407,143,391,143);
 line(391,143,391,175);
 line(439,175,439,238);
 line(455,255,391,255);
 line(391,255,391,286);
 line(391,287,359,287);
 line(359,286,359,239);
 line(375,239,375,271);
 line(439,207,423,207);
 line(423,207,423,270);
 line(423,271,407,271);
 line(407,271,407,334);
 line(407,335,359,335);
 line(359,351,359,303);
 line(343,303,391,303);
 line(343,303,343,271);
 line(343,287,327,287);
 line(375,303,375,319);
 line(391,319,407,319);
 line(439,271,439,287);
 line(439,287,423,287);
 line(423,287,423,319);
 line(423,303,455,303);
 line(439,319,439,351);
 line(439,335,423,335);
 line(423,335,423,366);
 line(407,367,455,367);
 line(407,367,407,351);
 line(407,351,375,351);
 line(375,351,375,383);
 line(375,383,408,383);
 line(391,383,391,367);
 line(375,367,327,367);
 line(327,367,327,383);
 line(343,334,343,383);
 line(359,399,359,383);
 line(423,399,423,383);
 line(424,383,441,383);
 line(311,399,311,207);
 line(311,207,327,207);
 line(327,207,327,191);
 line(311,239,295,239);
 line(295,239,295,159);
 line(280,191,312,191);
 line(311,351,327,351);
 line(295,175,327,175);
 line(327,175,327,159);
 line(295,159,279,159);
 line(279,142,279,175);
 line(279,175,263,175);
 line(295,303,327,303);
 line(327,303,327,335);
 line(327,319,343,319);
 line(312,255,343,255);
 line(343,255,343,238);
 line(327,255,327,271);
 line(295,223,247,223);
 line(247,223,247,159);
 line(247,191,263,191);
 line(263,191,263,207);
 line(264,207,279,207);
 line(247,207,215,207);
 line(215,207,215,223);
 line(151,175,151,159);
 line(151,159,215,159);
 line(215,159,215,175);
 line(215,175,231,175);
 line(231,175,231,191);
 line(183,159,183,175);
 line(183,175,200,175);
 line(200,207,167,207);
 line(167,207,167,239);
 line(231,191,199,191);
 line(199,191,199,239);
 line(183,239,279,239);
 line(231,239,231,221);
 line(183,221,183,287);
 line(183,287,167,287);
 line(167,287,167,319);
 line(167,319,151,319);
 line(152,303,136,303);
 line(136,271,168,271);
 line(151,271,151,287);
 line(183,255,152,255);
 line(151,255,151,191);
 line(151,191,184,191);
 line(167,190,167,175);
 line(215,239,215,255);
 line(279,239,279,271);
 line(279,271,263,271);
 line(279,255,295,255);
 line(295,255,295,287);
 line(295,287,279,287);
 line(279,287,279,319);
 line(279,319,295,319);
 line(295,319,295,399);
 line(295,383,279,383);
 line(264,383,248,383);
 line(247,399,247,335);
 line(247,335,231,335);
 line(231,335,231,383);
 line(231,383,183,383);
 line(215,351,231,351);
 line(167,399,167,351);
 line(167,351,151,351);
 line(167,367,216,367);
 line(199,367,199,335);
 line(199,335,215,335);
 line(215,335,215,302);
 line(215,319,263,319);
 line(263,287,263,367);
 line(263,367,279,367);
 line(279,367,279,334);
 line(263,287,247,287);
 line(247,287,247,255);
 line(264,255,231,255);
 line(231,255,231,303);
 line(231,303,248,303);
 line(215,287,231,287);
 line(231,271,199,271);
 line(199,271,199,255);
 line(135,367,151,367);
 line(151,367,151,383);
 line(135,335,184,335);
 line(183,351,183,303);
 line(183,303,199,303);
 line(199,286,199,319);
 line(491,0,491,47);
 line(491,47,640,47);
 line(491,0,640,0);
 line(640,0,640,47);
}

void circulo(int x, int y)
{
  setcolor(RED);
  setfillstyle(1,12);
  fillellipse(xx,yy,3,3);
}

void borrarrastro(int x,int y)
{
 setcolor(BLACK);
 setfillstyle(SOLID_FILL,BLACK);
 fillellipse(xx,yy,3,3);
}

void labe()
{
    tecla=0;

    xx=287;
	yy=79;

    cleardevice();

	settextstyle(0,0,3);
    setcolor(WHITE);
	outtextxy(100,40,"Laberinto");

    

    settextstyle(0,0,2);
    setcolor(WHITE);
    outtextxy(15,100,"Ingrese el nombre del jugador:");
    rectangle(15,125,300,145);
    

    fflush(stdin);
	gotoxy(5,9);
    gets(name_lab);

    getch();

    cleardevice();




    laberinto();
    circulo(xx,yy);

    setfillstyle(SOLID_FILL, WHITE);
    settextstyle(3, 0, 1);
    setcolor(WHITE);
    outtextxy(503, 13, "SCORE:");

	while (tecla!=27)
    {
        settextstyle(1,0,1);
        setcolor(WHITE);
        gotoxy(74,2);printf("%d",cont);

        tecla=getch();

        switch (tecla)
        {
        case 72:
            if (getpixel(xx,yy - 8) == 2)
            {
                settextstyle(3,0,1);
                outtextxy(470,200,"Fuera de los limites");
                delay(500);
                settextstyle(3,0,1);
                setcolor(BLACK);
                outtextxy(470,200,"Fuera de los limites");
                cont--;
            }
            else
            {
                borrarrastro(xx,yy);
                yy-=8;
                circulo(xx,yy);
                cont++;
            }
            break;
        case 80:
            if (getpixel(xx,yy + 8) == 2)
            {
                settextstyle(3,0,1);
                outtextxy(470,200,"Fuera de los limites");
                delay(500);
                settextstyle(3,0,1);
                setcolor(BLACK);
                outtextxy(470,200,"Fuera de los limites");
                

            }
            else
            {
                borrarrastro(xx,yy);
                yy+=8;
                circulo(xx,yy);
                cont++;
            }
            break;
        case 75:
            if (getpixel(xx - 8,yy) == 2)
            {
                settextstyle(3,0,1);
                outtextxy(470,200,"Fuera de los limites");
                delay(500);
                settextstyle(3,0,1);
                setcolor(BLACK);
                outtextxy(470,200,"Fuera de los limites");
                
            }
            else
            {
                borrarrastro(xx,yy);
                xx-=8;
                circulo(xx,yy);
                cont++;
            }
            break;
        case 77:
            if (getpixel(xx + 8,yy) == 2)
            {
                settextstyle(3,0,1);
                outtextxy(470,200,"Fuera de los limites");
                delay(500);
                settextstyle(3,0,1);
                setcolor(BLACK);
                outtextxy(470,200,"Fuera de los limites");
                
            }
            else
            {
                borrarrastro(xx,yy);
                xx+=8;
                circulo(xx,yy);
                cont++;
            }
            break;
        }
        if (xx == 303 && yy == 399)
        {
            settextstyle(3, 0, 1);
            outtextxy(490, 200, "Ganaste!");
            break;
        }
    }

	/*if (perder==3)
    {
        settextstyle(1, 0, 1);
        outtextxy(490, 200, "Perdiste!");
        outtextxy(464,230,"Presiona una tecla");
        outtextxy(464,260,"para continuar...");
	}*/
    mlimit(1,1,1,640,480);
    
    outtextxy(464,230,"Presiona una tecla");
    outtextxy(464,260,"para continuar...");
    getch();

    cleardevice();
     menulab();

}

void menulab(void)
{
    int pasar = 0;
    int salida = 0;
    button play,exit,his;
    setfillstyle(SOLID_FILL,BLUE);
    bar(0,0,639,479);
    settextstyle(3,0,3);
    setcolor(WHITE);
    outtextxy(260,100,"LABERINTO");
    settextstyle(3,0,1);
    setcolor(WHITE);

	newButton(&play, 283, 200, "  JUGAR   ");
    newButton(&his, 273, 240, "  Historial  ");
    newButton(&exit, 285, 280, "  Salir  ");

    

    do
    {
        mlimit(1,1,1,640,480);
        mver();
		while (mclick() == 0);
		while (mclick() != 0);

		if (limit(mxpos(1), mypos(1), 283, 195, 356, 220))
        {
            mocultar();
            play.effect = PRESS;
            drawButton(&play);
            mver();
            delay(500);
            mocultar();
            play.effect = UNPRESS;
            drawButton(&play);
            labe();
        }

        if (limit(mxpos(1), mypos(1), 265, 235, 385, 260))
        {
            mocultar();
			his.effect = PRESS;
			drawButton(&his);
            mver();
            delay(500);
            mocultar();
			his.effect = UNPRESS;
			drawButton(&his);
            /*funcion historial*/
        }

        if (limit(mxpos(1), mypos(1), 285, 280, 358, 300))
        {
            mocultar();
			exit.effect = PRESS;
			drawButton(&exit);
            mver();
            delay(500);
            mocultar();
            exit.effect = UNPRESS;
			drawButton(&exit);
			salida = 3;
        }

    }while(salida != 3);

}

int lab(void)
{
    int driver=DETECT,modo;
    initgraph(&driver,&modo,"");

	menulab();
    salida=0;
}

void Juego1()
{
	int driver = DETECT,modo;
    int ch,j;
	char ans;

    initgraph(&driver, &modo,"c:\\TC20\\BIN");
    
    setbkcolor(RED);

    start();
    salida=0;
    
}

void start()
{
    cleardevice();
    setcolor(WHITE);
    line(40,320,99,395);
    line(73,296,131,365);
    line(40,375,116,296);
    line(67,393,138,324);

    circle(200,430,15);
    circle(555,138,15);

    line(460,378,552,450);
    line(500,345,575,427);
    line(464,433,572,338);
    line(510,457,589,375);

    line(26,128,92,175);
    line(26,175,81,125);

    settextstyle(0,0,5);
    setcolor(WHITE);
	outtextxy(195,70,"X vs 0");

    newButton(&btn, 283, 200, "  JUGAR   ");
    newButton(&his, 273, 240, "  Historial  ");
    newButton(&exit1, 285, 280, "  Salir  ");
    msituar(1,320,100);
    mlimit(1,1,1,640,480);
    mver();
    do
    {
		while (mclick() == 0);
		while (mclick() != 0);

		if (limit(mxpos(1), mypos(1), 283, 195, 356, 220))
        {
            mocultar();
            btn.effect = PRESS;
            drawButton(&btn);
            mver();
            delay(500);
            mocultar();
            btn.effect = UNPRESS;
            drawButton(&btn);
            menu();
        }

        if (limit(mxpos(1), mypos(1), 265, 235, 385, 260))
        {
            mocultar();
			his.effect = PRESS;
			drawButton(&his);
            mver();
            delay(500);
            mocultar();
			his.effect = UNPRESS;
			drawButton(&his);
            /*funcion historial*/
        }

        if (limit(mxpos(1), mypos(1), 285, 280, 358, 300))
        {
            mocultar();
			exit1.effect = PRESS;
			drawButton(&exit1);
            mver();
            delay(500);
            mocultar();
            exit1.effect = UNPRESS;
			drawButton(&exit1);
			salida=3;
        }
        
    }while(salida!=3);
}

void Board()
{
    int j;
    cleardevice();
    click = mclick();
    x = mxpos(1);
    y = mypos(1);

    setcolor(WHITE);
    line(223,92,223,325);
    line(385,92,385,325);
    line(110,255,485,255);
    line(110,170,485,170);

    line(200,22,400,22);
    line(300,22,300,62);

    settextstyle(0,0,2);
    outtextxy(185,30,name_X);
    outtextxy(305,30,name_O);

    setlinestyle(SOLID_LINE,0,2);
    circle(603,39,15);
    line(29,40,64,71);
    line(29,76,62,34);

    settextstyle(0,0,3);

    for (i = 1; i <= 3; i++)
    {
        
        for (j = 1; j <= 3; j++)
        {

            if (pos_for_X[i][j] == 1)
            {
                
                if (i == 1)
                {
                    if (j == 1)
                    {
                        setcolor(WHITE);
                        outtextxy(150,130,"X");
                    }
                    else if (j == 2)
                    {
                        setcolor(WHITE);
                        outtextxy(285,130,"X");
                    }
                    else if (j == 3)
                    {
                        setcolor(WHITE);
                        outtextxy(420,130,"X");
                    }
                }
                else if (i == 2)
                {
                    if (j == 1)
                    {
                        setcolor(WHITE);
                        outtextxy(150,220,"X");
                    }
                    else if (j == 2)
                    {
                        setcolor(WHITE);
                        outtextxy(285,220,"X");
                    }
                    else if (j == 3)
                    {
                        setcolor(WHITE);
                        outtextxy(420,220,"X");
                    }
                }
                else if (i == 3)
                {
                    if (j == 1)
                    {
                        setcolor(WHITE);
                        outtextxy(150,310,"X");
                    }
                    else if (j == 2)
                    {
                        setcolor(WHITE);
                        outtextxy(285,310,"X");
                    }
                    else if (j == 3)
                    {
                        setcolor(WHITE);
                        outtextxy(420,290,"X");
                    }
                }

            }
            if (pos_for_O[i][j] == 1)
            {
                if (i == 1)
                {
                    if (j == 1)
                    {
                        setcolor(WHITE);
                        circle(160,114,15);
                    }
                    else if (j == 2)
                    {
                        setcolor(WHITE);
                        circle(285,124,15);
                    }
                    else if (j == 3)
                    {
                        setcolor(WHITE);
                        circle(420,110,15);
                    }
                }
                else if (i == 2)
                {
                    if (j == 1)
                    {
                        setcolor(WHITE);
                        circle(150,220,15);
                    }
                    else if (j == 2)
                    {
                        setcolor(WHITE);
                        circle(275,220,15);
                    }
                    else if (j == 3)
                    {
                        setcolor(WHITE);
                        circle(420,220,15);
                    }
                }
                else if (i == 3)
                {
                    if (j == 1)
                    {
                        setcolor(WHITE);
                        circle(150,290,15);
                    }
                    else if (j == 2)
                    {
                        setcolor(WHITE);
                        circle(270,290,15);
                    }
                    else if (j == 3)
                    {
                        setcolor(WHITE);
                        circle(420,290,15);
                    }
                }
            }
        }
    }
    Player_win();
}

void PlayerX()
{
    int row, col;
    if (win == 1)
        return;
    fflush(stdin);
    settextstyle(0,0,1);
    outtextxy(100,340,"Ingrese numero de fila: ");
    fflush(stdin);
    gotoxy(14,23);scanf("%d", &row);
    outtextxy(100,367,"Ingrese numero de columna: ");
    fflush(stdin);
    gotoxy(14,25);scanf("%d", &col);
    if (pos_marked[row][col] == 1 || row < 1 || row > 3 || col < 1 || col > 3)
    {
        outtextxy(100,400,"Posicion Equivocada!! Presione cualquier tecla.....");
        wrong_X = 1;
        getch();
        Board();
    }
    else
    {
        pos_for_X[row][col] = 1;
        pos_marked[row][col] = 1;
        Board();
    }
}

void PlayerO()
{
    int row, col;
    if (win == 1)
        return;
    settextstyle(0,0,1);
    outtextxy(100,340,"Ingrese numero de fila: ");
    fflush(stdin);
    gotoxy(14,23);scanf("%d", &row);
    outtextxy(100,367,"Ingrese numero de columna: ");
    fflush(stdin);
    gotoxy(14,25);scanf("%d", &col);
    if (pos_marked[row][col] == 1 || row < 1 || row > 3 || col < 1 || col > 3)
    {
        outtextxy(100,400,"Posicion Equivocada!! Presione cualquier tecla.....");
        wrong_O = 1;
        getch();
        Board();
    }
    else
    {
        pos_for_O[row][col] = 1;
        pos_marked[row][col] = 1;
        Board();
    }
}

void Player_win()
{
    settextstyle(0,0,2);
    for (i = 1; i <= 3; i++)
    {
        if (pos_for_X[i][1] == 1 && pos_for_X[i][2] == 1 && pos_for_X[i][3] == 1)
        {
            win = 1;
            outtextxy(100,370,name_X);
            outtextxy(160,390,"ha ganado");
            return;
        }
    }
    for (i = 1; i <= 3; i++)
    {
        if (pos_for_X[1][i] == 1 && pos_for_X[2][i] == 1 && pos_for_X[3][i] == 1)
        {
            win = 1;
            outtextxy(100,370,name_X);
            outtextxy(160,390,"ha ganado");
            return;
        }
    }
    if (pos_for_X[1][1] == 1 && pos_for_X[2][2] == 1 && pos_for_X[3][3] == 1)
    {
        win = 1;
        outtextxy(100,370,name_X);
        outtextxy(160,390,"ha ganado");
        return;
    }
    else if (pos_for_X[1][3] == 1 && pos_for_X[2][2] == 1 &&
             pos_for_X[3][1] == 1)
    {
        win = 1;
        outtextxy(100,370,name_X);
        outtextxy(160,390,"ha ganado");
        return;
    }

    for (i = 1; i <= 3; i++)
    {
        if (pos_for_O[i][1] == 1 && pos_for_O[i][2] == 1 && pos_for_O[i][3] == 1)
        {
            win = 1;
            outtextxy(100,370,name_O);
            outtextxy(160,390,"ha ganado");
            return;
        }
    }
    for (i = 1; i <= 3; i++)
    {
        if (pos_for_O[1][i] == 1 && pos_for_O[2][i] == 1 && pos_for_O[3][i] == 1)
        {
            win = 1;
            outtextxy(100,370,name_O);
            outtextxy(160,390,"ha ganado");
            return;
        }
    }
    if (pos_for_O[1][1] == 1 && pos_for_O[2][2] == 1 && pos_for_O[3][3] == 1)
    {
        win = 1;
        outtextxy(100,370,name_O);
        outtextxy(160,390,"ha ganado");
        return;
    }
    else if (pos_for_O[1][3] == 1 && pos_for_O[2][2] == 1 &&
             pos_for_O[3][1] == 1)
    {
        win = 1;
        outtextxy(100,370,name_O);
        outtextxy(160,390,"ha ganado");
        return;
    }
}

void check()
{
    int j;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			if(pos_marked[i][j]==1)
				chk++;
			else
				continue;
		}
	}
}

void menu()
{
    cleardevice();
    
    setlinestyle(SOLID_LINE,0,2);
    settextstyle(0,0,2);
    setfillstyle(SOLID_FILL,BLACK);
    setcolor(WHITE);

    circle(65,387,10);
    circle(359,337,10);
    circle(473,297,10);
    circle(559,371,10);
    circle(550,198,10);

    line(165,378,222,422);
    line(146,390,202,436);
    line(144,422,188,370);
    line(233,383,182,437);

    line(165,378,222,422);
    line(146,390,202,436);

    line(316,375,353,409);
    line(320,410,343,366);

    line(422,375,464,412);
    line(434,416,461,373);

    line(566,267,616,322);
    line(615,260,562,319);

    line(575,114,614,140);
    line(571,144,605,102);

    line(444,64,512,113);
    line(481,36,546,83);
    line(433,98,525,22);
    line(465,121,541,36);

    circle(496,29,6);
    circle(490,76,6);
    circle(490,120,6);

    settextstyle(0,0,3);
    setcolor(WHITE);
	outtextxy(15,40,"Modos de juego");

    newButton(&pvp, 17, 113, " Jugador V Jugador ");
    newButton(&pvc, 17, 165, "   Jugador V  PC   ");
    newButton(&re1, 17, 229, "  Como Jugar   ");
    newButton(&helpB, 17, 302, "    Regresar   ");


    do
    {      
        mver();  
        while (mclick() == 0);
        while (mclick() != 0);

        if(limit(mxpos(1), mypos(1), 15,113,130,128))
        {
            mocultar();
            pvp.effect = PRESS;
            drawButton(&pvp);
            mver();
            delay(500);
            mocultar();
            pvp.effect = UNPRESS;
            drawButton(&pvp);
            GameX0();
        }

        if(limit(mxpos(1), mypos(1), 15, 163, 130, 180))
        {
            mocultar();
            pvc.effect = PRESS;
            drawButton(&pvc);
            mver();
            delay(500);
            mocultar();
            pvc.effect = UNPRESS;
            drawButton(&pvc);
            AI();
        }
        if(limit(mxpos(1), mypos(1), 15, 228, 110, 243))
        {
            mocultar();
            re1.effect = PRESS;
			drawButton(&re1);
            mver();
            delay(500);
            mocultar();
            re1.effect = UNPRESS;
            drawButton(&re1);
            help();
        }

        if(limit(mxpos(1), mypos(1), 15, 301, 110, 318))
        {
            mocultar();
            helpB.effect = PRESS;
            drawButton(&helpB);
            mver();
            delay(500);
            mocultar();
            helpB.effect = UNPRESS;
            drawButton(&helpB);
            cleardevice();
            salida=3;
        }
        
    }while(salida!=3 && salida!=0);
    salida=0;
    start();
}

void GameX0()
{
	int z = 0;
    chk=0;
	win = 0;

    cleardevice();

    mocultar();     

    settextstyle(0,0,3);
    setcolor(WHITE);
	outtextxy(100,40,"Jugador vs Jugador");

    settextstyle(0,0,2);
    setcolor(WHITE);
    outtextxy(15,100,"Ingrese el nombre del jugador 1:");
    rectangle(15,125,300,145);

    fflush(stdin);
	gotoxy(5,9);gets(name_X);
    
    outtextxy(15,165,"Ingrese el nombre del jugador 2:");
    rectangle(15,188,300,210);
    fflush(stdin);
	gotoxy(5,13);gets(name_O);

    cleardevice();

    settextstyle(0,0,3);
    setcolor(WHITE);
    outtextxy(60,40,name_X);
    outtextxy(100,65,"Vs");
    outtextxy(120,90,name_O);

    line(40,320,99,395);
    line(73,296,131,365);
    line(40,375,116,296);
    line(67,393,138,324);

    circle(200,430,15);
    circle(555,138,15);

    line(26,128,92,175);
    line(26,175,81,125);


    for (z = 0; z < 10; z = z++)
    {
        setcolor(WHITE);
        outtextxy(310,400,"Cargando...");
        delay(1000);
        setcolor(RED);
        outtextxy(310,400,"Cargando...");
    }

    cleardevice();

    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            pos_for_X[i][j] = 0;
            pos_for_O[i][j] = 0;
            pos_marked[i][j] = 0;
        }
    }

    Board();

    for(;;)
    {
        if (win == 1)
            break;
        check();
        settextstyle(0,0,1);
        if (chk == 9)
        {
            outtextxy(15,370,"EMPATE");
            cont_empate++;
            break;
        }
        else
            chk = 0;
            settextstyle(0,0,1);
            outtextxy(150,50,"Turno");
            PlayerX();
        do
        {
            if (wrong_X != 1)
                break;
            wrong_X = 0;
            outtextxy(150,50,"Turno");
            PlayerX();
        } while (wrong_X == 1);
        check();
        if (chk == 9)
        {
            outtextxy(15,370,"EMPATE");
            cont_empate++;
            break;
        }
        else
            chk = 0;
            settextstyle(0,0,1);
            outtextxy(355,50,"Turno");
            PlayerO();
        do
        {
            if (wrong_O != 1)
                break;
            wrong_O = 0;
            settextstyle(0,0,1);
            outtextxy(355,50,"Turno");
            PlayerO();
        } while (wrong_O == 1);
    }
    Board();
    if (win != 1)
    {
        outtextxy(15,370,"EMPATE");
        cont_empate++;
    }
   
    delay(400);
    endgame();
}

void endgame()
{

    button rePvp, Gamemode,menu1,exit2;
    cleardevice();
    mver();

    settextstyle(0,0,3);
    setcolor(WHITE);
    outtextxy(60,40,"El juego ha terminado");

    line(26,128,92,175);
    line(26,175,81,125);

    circle(590,176,15);


    settextstyle(0,0,2);
    setcolor(WHITE);
    outtextxy(80,70,"Que hacer ahora?");

    newButton(&rePvp,255,143,"  Jugar de nuevo  ");
    newButton(&Gamemode,255,180,"  Modo de juego   ");
    newButton(&menu1,255,215," Volver al menu  ");
    newButton(&exit2,270,250,"   Salir   ");


    do
    {
        mver();
        while (mclick() == 0);
        while (mclick() != 0);

        if(limit(mxpos(1), mypos(1), 255, 142, 363, 159))
        {
            mocultar();
            rePvp.effect = PRESS;
            drawButton(&rePvp);
            mver();
            delay(500);
            mocultar();
            rePvp.effect = UNPRESS;
            drawButton(&rePvp);
            GameX0();
        }

        if(limit(mxpos(1), mypos(1), 255, 179, 363, 192))
        {
            mocultar();
            Gamemode.effect = PRESS;
            drawButton(&Gamemode);
            mver();
            delay(500);
            mocultar();
            Gamemode.effect = UNPRESS;
            drawButton(&Gamemode);
            menu();
        }

        if(limit(mxpos(1), mypos(1), 255, 214, 357, 230))
        {
            mocultar();
            menu1.effect = PRESS;
            drawButton(&menu1);
            mver();
            delay(500);
            mocultar();
            menu1.effect = UNPRESS;
            drawButton(&menu1);
            start();
        }
        if(limit(mxpos(1), mypos(1), 269, 249, 336, 265))
        {
            mocultar();
            exit2.effect = PRESS;
            drawButton(&exit2);
            mver();
            delay(500);
            mocultar();
            exit2.effect = UNPRESS;
            drawButton(&exit2);
            mver();
            cleardevice();
            salida=3;   
        }
    }while(salida!=3);
    
    start();
}

void AI()
{
    int z;
    char winner = ' ';
    char response = ' ';

    cleardevice();


    settextstyle(0,0,3);
    setcolor(WHITE);
    outtextxy(60,40,"Jugador");
    outtextxy(100,68,"Vs");
    outtextxy(120,90,"Maquina");

    line(40,320,99,395);
    line(73,296,131,365);
    line(40,375,116,296);
    line(67,393,138,324);

    circle(200,430,15);
    circle(555,138,15);

    line(26,128,92,175);
    line(26,175,81,125);



    for (z = 0; z < 10; z = z++)
    {
        setcolor(WHITE);
        outtextxy(310,400,"Cargando...");
        delay(1000);
        setcolor(RED);
        outtextxy(310,400,"Cargando...");
    }

   
   cleardevice();
   do
   {
        winner = ' ';
        response = ' ';
        resetBoard();

        while (winner == ' ' && checkFreeSpaces() != 0)
        {
            printBoard();

            playerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }

            computerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }
        }

        printBoard();
        printWinner(winner);

        printf("\nQuieres jugar denuevo? (Y/N): ");
        scanf("%c");
        scanf("%c", &response);
        response = toupper(response);
    } while (response == 'Y');
    endgame1();
}

void resetBoard()
{
   for(i = 0; i < 3; i++)
   {
      for(j = 0; j < 3; j++)
      {
         board[i][j] = ' ';
      }
   }
}

void printBoard()
{
   cleardevice();
   
   
   gotoxy(35,4);printf("Tic Tac Toe\n\n");
   printf("\n\n\n");
   gotoxy(35,8);printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
   gotoxy(35,9);printf("---|---|---\n");
   gotoxy(35,10);printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
   gotoxy(35,11);printf("---|---|---\n");
   gotoxy(35,12);printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
   
}

int checkFreeSpaces()
{
   int freeSpaces = 9;

   for(i = 0; i < 3; i++)
   {
      for(j = 0; j < 3; j++)
      {
         if(board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}

void playerMove()
{
    playersave:
   do
   {
        gotoxy(10,14);printf("Ingrese # de fila (1-3): ");
        
        do
        {
            gotoxy(14,15);scanf("%d", &x);

        }while(x < 1 || x > 3);
        
        x--;
        gotoxy(10,16);printf("Ingrese # de columna (1-3): ");
        do
        {
            gotoxy(14,17);scanf("%d", &y);

        }while(y < 1 || y > 3);
        y--;

        if(board[x][y] != ' ')
        {
            gotoxy(10,18);printf("Movimiento Invalido!\n");
            goto playersave;
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    }while (board[x][y] != ' ');
   
}

void computerMove()
{
   srand(time(0));

   if(checkFreeSpaces() > 0)
   {
      do
      {
        x = rand() % 3;
        y = rand() % 3;
      }while (board[x][y] != ' ');
      
      board[x][y] = COMPUTER;
   }
   else
   {
      printWinner(' ');
   }
}

char checkWinner()
{
  
   for(i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
        return board[i][0];
      }
   }
   for(i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
        return board[0][i];
      }
   }
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }

   return ' ';
}

void printWinner(char winner)
{
    
   if(winner == PLAYER)
    {    
       settextstyle(8,0,3);
       outtextxy(50,35,"Ganaste!");
    }
   else if(winner == COMPUTER)
    {
        settextstyle(8,0,3);
        outtextxy(50,35,"Perdiste!");
    }
    else
    {
        settextstyle(8,0,3);
        outtextxy(50,35,"Empate!");
    }
}

void endgame1()
{
    button reIA, Gamemode,menu1,exit2;
    cleardevice();

    settextstyle(0,0,3);
    setcolor(WHITE);
    outtextxy(60,40,"El juego ha terminado");

    line(26,128,92,175);
    line(26,175,81,125);

    circle(590,176,15);


    settextstyle(0,0,2);
    setcolor(WHITE);
    outtextxy(80,70,"Que hacer ahora?");

    newButton(&reIA,255,143,"  Jugar de nuevo  ");
    newButton(&Gamemode,255,180,"  Modo de juego   ");
    newButton(&menu1,255,215," Volver al menu  ");
    newButton(&exit2,270,250,"   Salir   ");


    do
    {
        mver();
        while (mclick() == 0);
        while (mclick() != 0);

        if(limit(mxpos(1), mypos(1), 255, 142, 363, 159))
        {
            mocultar();
            reIA.effect = PRESS;
            drawButton(&reIA);
            mver();
            delay(500);
            mocultar();
            reIA.effect = UNPRESS;
            drawButton(&reIA);
            AI();
        }

        if(limit(mxpos(1), mypos(1), 255, 179, 363, 192))
        {
            mocultar();
            Gamemode.effect = PRESS;
            drawButton(&Gamemode);
            mver();
            delay(500);
            mocultar();
            Gamemode.effect = UNPRESS;
            drawButton(&Gamemode);
            menu();
        }

        if(limit(mxpos(1), mypos(1), 255, 214, 357, 230))
        {
            mocultar();
            menu1.effect = PRESS;
            drawButton(&menu1);
            mver();
            delay(500);
            mocultar();
            menu1.effect = UNPRESS;
            drawButton(&menu1);
            start();
        }
        if(limit(mxpos(1), mypos(1), 269, 249, 336, 265))
        {
            mocultar();
            exit2.effect = PRESS;
            drawButton(&exit2);
            mver();
            delay(500);
            mocultar();
            exit2.effect = UNPRESS;
            drawButton(&exit2);
            salida=3;
            mver();
        }
    }while(salida!=3);
    menu();
}

void help()
{
    button exit, next;
    cleardevice();
    mver();

    settextstyle(0,0,3);
    setcolor(WHITE);
    outtextxy(60,40,"Ayuda");

    newButton(&exit,55,450,"   Salir   ");
    newButton(&next,505,450,"   Siguiente   ");

    setcolor(WHITE);
    settextstyle(0,0,2);
    outtextxy(50,70,"Jugador vs Jugador");
    settextstyle(0,0,1);
    outtextxy(50,100,"El juego consiste en un tablero de 3x3, donde cada jugador");
    outtextxy(50,120,"debe colocar sus fichas en las casillas correspondientes");
    outtextxy(50,140,"para ganar.");
    outtextxy(50,160,"Se divide en filas y columnas.");
    outtextxy(50,180,"El jugador en turno debe elegir una fila y una columna");
    outtextxy(50,200,"para colocar su ficha.");
    outtextxy(50,220,"Si la casilla esta ocupada, debera elegir otra.");
    outtextxy(50,240,"Si la casilla esta vacia, podra colocar su ficha.");
    outtextxy(50,260,"El jugador gana colocando sus fichas en fila, columna o diagonal.");
    outtextxy(50,280,"El juego termina cuando un jugador gana o cuando no quedan casillas.");

    do
    {
        while (mclick() == 0);
        while (mclick() != 0);
        
        if(limit(mxpos(1), mypos(1), 55, 450, 115, 470))
        {
            mocultar();
            exit.effect = PRESS;
            drawButton(&exit);
            mver();
            delay(500);
            mocultar();
            exit.effect = UNPRESS;
            drawButton(&exit);
            salida=3;
        }

        if(limit(mxpos(1), mypos(1), 505, 450, 565, 470))
        {
            mocultar();
            next.effect = PRESS;
            drawButton(&next);
            mver();
            delay(500);
            mocultar();
            next.effect = UNPRESS;
            drawButton(&next);
            help2();
        }

    }while(salida!=3);
    menu();
}

void help2()
{
    button exit, next, back;
    cleardevice();

    settextstyle(0,0,3);
    setcolor(WHITE);
    outtextxy(60,40,"Ayuda");

    newButton(&exit,55,450,"   Salir   ");
    newButton(&next,505,450,"   Siguiente   ");
    newButton(&back,255,450,"   Atras   ");

    setcolor(WHITE);
    settextstyle(0,0,2);
    outtextxy(60,70,"Jugador vs Computadora");
    settextstyle(0,0,1);
    outtextxy(60,100,"El juego consiste en un tablero de 3x3, donde cada jugador");
    outtextxy(60,120,"debe colocar sus fichas en las casillas correspondientes");
    outtextxy(60,140,"para ganar.");
    outtextxy(60,160,"Se divide en filas y columnas.");
    outtextxy(60,180,"El jugador debe elegir una fila y una columna");
    outtextxy(60,200,"para colocar su ficha.");
    outtextxy(60,220,"mientras que la computadora elige su casilla de forma aleatoria.");
    outtextxy(60,240,"Si la casilla esta ocupada,se debera elegir otra.");
    outtextxy(60,260,"Si la casilla esta vacia podra colocar su ficha.");
    outtextxy(60,280,"El jugador gana si coloca sus fichas en fila, columna o diagonal.");
    outtextxy(60,300,"El juego termina cuando gana o cuando no quedan casillas.");
    

    do
    {
        mver();
        while (mclick() == 0);
        while (mclick() != 0);
        
        if(limit(mxpos(1), mypos(1), 55, 450, 115, 470))
        {
            mocultar();
            exit.effect = PRESS;
            drawButton(&exit);
            mver();
            delay(500);
            mocultar();
            exit.effect = UNPRESS;
            drawButton(&exit);
            salida=3;
            menu();
        }
        if(limit(mxpos(1), mypos(1), 505, 450, 565, 470))
        {
            mocultar();
            next.effect = PRESS;
            drawButton(&next);
            mver();
            delay(500);
            mocultar();
            next.effect = UNPRESS;
            drawButton(&next);
            help3();
        }
        if(limit(mxpos(1), mypos(1), 255, 450, 315, 470))
        {
            mocultar();
            back.effect = PRESS;
            drawButton(&back);
            mver();
            delay(500);
            mocultar();
            back.effect = UNPRESS;
            drawButton(&back);
            help();
        }


    }while(salida!=3);
    menu();
}

void help3()
{
    button exit, back;
    cleardevice();

    settextstyle(0,0,3);
    setcolor(WHITE);
    outtextxy(60,40,"Ayuda");

    newButton(&exit,55,450,"   Salir   ");
    newButton(&back,255,450,"   Atras   ");

    setcolor(WHITE);
    settextstyle(0,0,2);
    outtextxy(60,70,"Historial");
    settextstyle(0,0,1);
    outtextxy(60,100,"En el historial se muestran los partidos jugados.");
    outtextxy(60,120,"Para ver el historial de juego, se debe seleccionarlo en el menu.");
    outtextxy(60,140,"Se muestra el nombre del jugador, el nombre del oponente");
    outtextxy(60,160,"y el resultado del partido.");
    outtextxy(60,180,"El historial se guarda en un archivo de texto.");



    do
    {
        mver();
        while (mclick() == 0);
        while (mclick() != 0);
        
        if(limit(mxpos(1), mypos(1), 55, 450, 115, 470))
        {
            mocultar();
            exit.effect = PRESS;
            drawButton(&exit);
            mver();
            delay(500);
            mocultar();
            exit.effect = UNPRESS;
            drawButton(&exit);
            salida=3;
        }
        if(limit(mxpos(1), mypos(1), 255, 450, 315, 470))
        {
            mocultar();
            back.effect = PRESS;
            drawButton(&back);
            mver();
            delay(500);
            mocultar();
            back.effect = UNPRESS;
            drawButton(&back);
            help2();
        }
    }while(salida!=3);
    menu();
}