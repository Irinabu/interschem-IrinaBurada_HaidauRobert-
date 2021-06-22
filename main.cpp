#include <iostream>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <math.h>
#include <winbgim.h>
#include <fstream>
#include <cstring>

#define INF 10000
#define FUNDAL 8
#define CULOARE 12

using namespace std;
ofstream g("conversie.txt");
//ROBERT
int top1,top2; // varfurile celor doua stive
int c45=705;
const int max_stiva=100;
double Opd[max_stiva]; // stiva operanzilor
char Op[max_stiva]; // stiva operatorilor
char OperatiiBinare[200]="+-*/^<>=#";
char OperatiiUnare[200]="scarel";
char Operatii[200]="+-*/^<>=#scarel";
int var[27]={0},ok=0;
struct punct
{
    int x;
    int y;
};
 int Prioritate(char c)  // prioritate operatorilor //ROBERT
{
    if(c=='(' || c==')')
        return 0;
    if(c=='+' || c=='-')
        return 1;
    if(c=='*' || c=='/')
        return 2;
    if(c=='^')
        return 3;
    if(c=='=' || c=='#' || c=='<' || c=='>')
        return 4;
    if(c=='c' || c=='s' || c=='l' || c=='e' || c=='t' || c=='a' || c=='r')
        return 5;
}

const float pi=3.1415926; // se da sub forma literei q


float Inmultit(float x, float y) //ROBERT
{

        return x*y;
}

float Putere(float x, float y) //ROBERT
{
    // float p;
    if (x==0) return 0;
    else if (y==0) return 1;
    else
        return pow(x,y);
}

float Egal(float x, float y) //ROBERT
{
    return x==y;
}

float Diferit(float x, float y) //ROBERT
{
    return x!=y;
}

float MaiMic(float x, float y) //ROBERT
{
    return x < y;
}

bool MaiMare(float x, float y) //ROBERT
{
    return x > y;
}

float Plus(float x, float y) //ROBERT
{return x+y;
}

float Minus(float x, float y) //ROBERT
{
    return x-y;
}

float Impartit(float x, float y) //ROBERT
{
    return x/y;
}


float Modul(float x) //ROBERT
{
    return fabs(x);
}

bool EsteNumar(char sir) //ROBERT
{
    return strchr("0123456789",sir);
}

struct functie //ROBERT
{
    char expresie[300];  //EXPRESIA TOTALA TREBUIE DUSA AICI
    char vect[221];  //AICI TREBUIE DUSE TOATE CARACTERELE 1 CATE 1
    // vectorul cuprinzand “cuvintele”ce formeaza expresia}
    int lung; // lungimea efectiva a vectorului      F.lung=strlen(F.expresie);
    float a,b; // intervalul de evaluare a functiei
    int n; //numarul de puncte de evaluare
}F;

void depanare() //ROBERT
{
    printf("Stiva operanzilor: ");
    for (int i=1; i<=top1; i++)
        printf("%f,",Opd[i]);
    printf("\nStiva operatorilor: ");
    for (int i=1; i<=top2; i++)
        printf("%c,",Op[i]);
    printf("\n");
}

double ValoareFunctie(functie E) //ROBERT
{
    int i;
    // returneaza valoarea functiei E in punctul x
    double valo,x_1,x_2;
    //calculul expresiei
    for (i=1; i<=max_stiva; i++)
    {
        Opd[i]=0;
        Op[i]='@';
    }
    top1=0;
    top2=1;
    Op[top2]='(';
    i=0;
    while (i<=E.lung && top2>0)
    {    valo=0;
        i++;
        if (EsteNumar(E.vect[i]))
        {while (EsteNumar(E.vect[i]))
        {

            valo=valo*10+E.vect[i]-'0';
            i++;
        }

         top1++;
         Opd[top1]=valo;
        i--;}
       else
            switch (E.vect[i]) {
            /* constanta pi=3.1415926 se da sub forma literei q */
            case 'q': top1++; Opd[top1]=pi; break;
                case 'A': top1++; Opd[top1]=var[0]; break;
                    case 'B': top1++; Opd[top1]=var[1]; break;
                        case 'C': top1++; Opd[top1]=var[2]; break;
                            case 'D': top1++; Opd[top1]=var[3]; break;
                                case 'E': top1++; Opd[top1]=var[4]; break;
                                    case 'F': top1++; Opd[top1]=var[5]; break;
                                        case 'G': top1++; Opd[top1]=var[6]; break;
                                            case 'H': top1++; Opd[top1]=var[7]; break;
                                                case 'I': top1++; Opd[top1]=var[8]; break;
                                                    case 'J': top1++; Opd[top1]=var[9]; break;
                                                        case 'K': top1++; Opd[top1]=var[10]; break;
                                                            case 'L': top1++; Opd[top1]=var[11]; break;
                                                                case 'M': top1++; Opd[top1]=var[12]; break;
                                                                    case 'N': top1++; Opd[top1]=var[13]; break;
                                                                        case 'O': top1++; Opd[top1]=var[14]; break;
                                                                            case 'P': top1++; Opd[top1]=var[15]; break;
                                                                                case 'Q': top1++; Opd[top1]=var[16]; break;
                                                                                    case 'R': top1++; Opd[top1]=var[17]; break;
                                                                                        case 'S': top1++; Opd[top1]=var[18]; break;
                                                                                     case 'T': top1++; Opd[top1]=var[19]; break;
                                                                                 case 'U': top1++; Opd[top1]=var[20]; break;
                                                                         case 'w': top1++; Opd[top1]=var[21]; break;
                                                                     case 'X': top1++; Opd[top1]=var[22]; break;
                                                             case 'Y': top1++; Opd[top1]=var[23]; break;
                                                         case 'Z': top1++; Opd[top1]=var[24]; break;
            case '(': /* inceput de bloc */ top2++; Op[top2]='('; break;
            default:
                /* operatii binare si unare */
               while ((top2>0) && !(strchr("()",Op[top2])) &&
                   Prioritate(Op[top2])>=Prioritate(E.vect[i]))
                {
                    if (top1>1) x_1=Opd[top1-1];
                    x_2=Opd[top1];
                    // depanare();
                    /* functii scrise in OPERATII */
                    switch (Op[top2]) {
                        case '=': valo=Egal(x_1,x_2); break;
                        case '#': valo=Diferit(x_1,x_2); break;
                        case '<': valo=MaiMic(x_1,x_2); break;
                        case '>': valo=MaiMare(x_1,x_2); break;
                        case '+': valo=Plus(x_1,x_2); break;
                        case '-': valo=Minus(x_1,x_2); break;
                        case '*': valo=Inmultit(x_1,x_2); break;
                        case '/': valo=Impartit(x_1,x_2); break;
                        case '^': valo=Putere(x_1,x_2); break;
                        case 'a': valo=Modul(x_2); break;
                    } //operator[top2]
                    if (strchr(OperatiiBinare,Op[top2])) top1--;
                    if (strchr(Operatii,Op[top2])) Opd[top1]=valo;
                    top2--;
                }
            // depanare();
            if (top2>0)
                if ((Op[top2]!='(') || (E.vect[i]!=')'))
                    {
                        top2++; Op[top2] = E.vect[i];
                    }
                else top2--;
            }
    }
    if (top2==0) return Opd[1];
    else return 0;
}
struct variabila
{
    float val;
    char nume[5];

};

struct expresie
{
    float val=-32;
    char text[50]="";

};


struct legatura{
    int bloc1, bloc2; // cele doua noduri ce se leaga
    int punct1, punct2; // punctele de legatura de la cele doua noduri
    int tipLegatura;
};

legatura vecLeg[50];
int nrLeg;

struct bloc
{
    char tip;
    char info[20];
    variabila v;
    expresie e;
    int x, y, latime;
    punct pLeg[3];
    int urm=0, urmA, urmF;

};


bloc b[100]; //schema
int n;

char sir[20];
int c1, c2 = 70;
bool stop, stopLeg;
FILE *fis, *aux;

//IRINA
void initBloc(bloc& B, char text[])
{
    int l, h = 0;
    l = textwidth(text)/2+25;

    if(B.tip == 'D')
    {
         h = textheight(text)/2 + 5;
         B.pLeg[0].x=B.x;
         B.pLeg[0].y=B.y - h;
         B.pLeg[1].x=B.x - l;
         B.pLeg[1].y=B.y + 15;
         B.pLeg[2].x=B.x + l;
         B.pLeg[2].y=B.y + 15;

    }
    else
    {

    B.pLeg[0].x=B.x;
    B.pLeg[0].y=B.y-15;
    B.pLeg[1].x=B.x;
    B.pLeg[1].y=B.y+15;
    }
}

#define YES 1
#define NO 0

  void cursor(int);
  void newLine();
  void getGrString(char *);

void newLine()
{
      moveto(0,gety()+textheight("A"));
}

  void getGrString(char *inputString)
  {

     int inputIndice=0;

     int xVal[255];

     char inputChar, outSir[2];

     int oldColor;

     outSir[1]=0;
     xVal[0] = 1135;
     do
     {
        cursor(YES);
        inputChar=getch();
        cursor(NO);
        if (inputChar==0) getch();
        else
        {
            if (inputChar==8) {
                oldColor=getcolor();
                --inputIndice;

                if (inputIndice<0) inputIndice=0;
                moveto(xVal[inputIndice],gety());
                setcolor(getbkcolor());
                outSir[0]=inputString[inputIndice];
                outtext(outSir);
                moveto(xVal[inputIndice],gety());
                setcolor(oldColor);
            }
            else {
                inputString[inputIndice]=inputChar;
                outSir[0]=inputChar;
                outtext(outSir);
                ++inputIndice;
                xVal[inputIndice]=getx();
            }
         }
     } while(inputChar!=13 && inputChar!=10);

     inputString[inputIndice]=0;
  }

  void cursor(int on) {
      int curX,oldColor;

      char talpica[2] = {'_', 0};

      if (!YES) {
          oldColor=getcolor();
          setcolor(getbkcolor());
      }

      curX=getx();
      outtext(talpica);
      moveto(curX, gety());

      if (!YES) setcolor(oldColor);
  }

void citire_info(int x, int y, char input[])
{

     setbkcolor(FUNDAL);
     setcolor(0);
     moveto(x,y);
     getGrString(input);
     newLine();

}

//IRINA SI ROBERT
void BLOC_CALCUL(int x, int y, int latime, int culoare, char text[])
{
    if(culoare != FUNDAL) setcolor(0);
    else setcolor(culoare);

    setbkcolor(culoare);


    setfillstyle(SOLID_FILL, culoare);

    setfillstyle(SOLID_FILL, culoare);
    line (x-latime/2,y+20,x+latime/2,y+20);
    line (x-latime/2-1,y-20,x-latime/2-1, y+20);
    line (x-latime/2, y-21, x+latime/2, y-21);
    line (x+latime/2, y-20, x+latime/2, y+20);
    bar(x-latime/2, y + 20, x+latime/2, y-20);

    int l, h;
    l = textwidth(text)/2;
    h = textheight(text)/2;
    outtextxy(x - l, y - h, text);


}

void BLOC_OUTPUT(int x, int y, int latime, int culoare, char text[])
{
    if(culoare != FUNDAL) setcolor(0);
    else setcolor(culoare);

    setbkcolor(culoare);

    setfillstyle(SOLID_FILL, culoare);
    int trapez[8] = {x - 80, y + 20, x + 80, y + 20, x + latime/2, y - 20, x - latime/2, y-20};


    line(x - latime/2, y - 20, x + latime/2, y - 20);  //linie sus
    line(x + 80, y + 20, x - 80, y + 20); // linie sus
    line(x + 80, y + 20, x - latime/2, y - 20);   //linie stanga
    line(x - 80, y + 20, x + latime/2, y - 20);    //linie dreapta}
    fillpoly(4, trapez);

    int l, h;
    l = textwidth(text)/2;
    h = textheight(text)/2;
    outtextxy(x - l, y - h, text);

//am lasat 20 de pixeli diferenta fata de sfarsitul celuilalt trapez

}
void BLOC_INPUT(int x, int y, int latime, int culoare, char text[]) //1-stergere, 2-desenare
{
    char sirB2[20];
    if(culoare != FUNDAL) setcolor(0);
    else setcolor(culoare);

    setbkcolor(culoare);

    int trapez[8] = { x - latime/2,  y+20, x + latime/2, y + 20, x + 80, y - 20, x - 80, y - 20};

    setfillstyle(SOLID_FILL, culoare);
    line(x - latime/2, y + 20, x + latime/2, y + 20);  //linie jos
    line(x + 80, y - 20, x - 80, y - 20); // linie sus
    line(x - latime/2, y + 20, x - 80, y - 20);   //linie stanga
    line(x + latime/2, y + 20, x + 80, y - 20);    //linie dreapta
    fillpoly(4, trapez);

    int l, h;
    l = textwidth(text)/2;
    h = textheight(text)/2;
    outtextxy(x - l, y - h, text);

}

//bloc triunghi pentru conditie
void BLOC_CONDITIE(int x, int y, int latime, int culoare, char text[])
{
    if(culoare != FUNDAL) setcolor(0);
    else setcolor(culoare);

    setbkcolor(culoare);
    /* int varia=strlen(b[n].e.text)%20;
        varia++;  */ //ASTA O SA O FOLOSESC CA SA MARESC LATIMEA TRIUNGHIULUI
    int triunghi[7]={x, y - 20, x - latime/2, y + 20, x + latime/2, y + 20};
    setfillstyle(SOLID_FILL, culoare);
    line(x - latime/2, y + 20, x + latime/2, y + 20);
    line(x - latime/2, y + 20, x, y - 20);
    line(x + latime/2, y + 20, x, y - 20);
    fillpoly(3, triunghi);

    int l, h;
    l = textwidth(text)/2;
    h = textheight(text)/2;
    outtextxy(x - l, y, text);

}

// Elipsa 1
void BLOC_START(int x, int y, int culoare)
{
    if(culoare != FUNDAL) setcolor(0);
    else setcolor(culoare);

    setbkcolor(culoare);

    setfillstyle(SOLID_FILL, culoare);
    ellipse(x, y, 0, 360, 40, 27);
    fillellipse(x, y, 40,27);
    int l, h;
    l = textwidth("START")/2;
    h = textheight("START")/2;
    outtextxy(x - l, y-h, "START");
}

// ELIPSA 2
void BLOC_STOP(int x, int y, int culoare)
{
    if(culoare != FUNDAL) setcolor(0);
    else setcolor(culoare);

    setbkcolor(culoare);

    setfillstyle(SOLID_FILL, culoare);
    ellipse(x, y, 0,360,40,27);
    fillellipse(x, y, 40,27);
   int l, h;
    l = textwidth("STOP")/2;
    h = textheight("STOP")/2;
    outtextxy(x - l, y-h, "STOP");
}

void BUTON_SFERA(int x, int y, char text[], int culoare)
{
    setbkcolor(culoare);

    setfillstyle(SOLID_FILL, culoare);
    ellipse(x, y, 0, 360, 80, 27);
    fillellipse(x, y, 80, 27);
    int l, h;
    l = textwidth(text)/2;
    h = textheight(text)/2;
    setcolor(15);
    outtextxy(x - l, y-h, text);

}

bool Apartine_Segment(punct P, punct A, punct B)
{
    if (P.x <= max(A.x, B.x) && P.x >= min(A.x, B.x) &&
        P.y <= max(A.y, B.y) && P.y >= min(A.y, B.y))
       return true;

    return false;
}

int orientation(punct p, punct q, punct r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

bool seIntersecteaza(punct p1, punct q1, punct p2, punct q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && Apartine_Segment(p1, p2, q1)) return true;


    if (o2 == 0 && Apartine_Segment(p1, q2, q1)) return true;


    if (o3 == 0 && Apartine_Segment(p2, p1, q2)) return true;


    if (o4 == 0 && Apartine_Segment(p2, q1, q2)) return true;

    return false;
}

//primul trapez
bool Click_InteriorBloc(punct click, int x, int y, int latime)
{
    punct extreme = {INF, click.y};
    punct trapez[8] = {{x - 50, y - 20},{x + 50, y - 20}, {x + latime/2, y + 20}, {x - latime/2, 20+y}};
    int nr = 0, i = 0;
    do
    {
        int urm = (i+1)%4;
        if (seIntersecteaza(trapez[i], trapez[urm], click, extreme))
        {

            if (orientation(trapez[i], click, trapez[urm]) == 0)
               return Apartine_Segment(trapez[i], click, trapez[urm]);

            nr ++;
        }
        i = urm;
    } while (i != 0);


   if(nr == 1) return true;
   return false;
}

bool Click_Elipsa(punct click, int h, int a, int k) //ROBERT
{
    int b;

    b=27;
    int p=(pow((click.x-h),2)/pow(a,2)+(pow((click.y-k),2)/pow(b,2)));
    if (p<=1)
        return 1;
    else
        return 0;
}

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
bool Click_InteriorBloc5(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{

   float A = area (x1, y1, x2, y2, x3, y3);

   float A1 = area (x, y, x2, y2, x3, y3);

   float A2 = area (x1, y1, x, y, x3, y3);

   float A3 = area (x1, y1, x2, y2, x, y);

   return (A == A1 + A2 + A3);
}

//IRINA
void drawLine(int x1, int y1, int x2, int y2, int culoare);
void deseneaza_Bloc(bloc B, int culoare);

//deseneaza cercurile din bloc de unde se poate trasa legatura
void locLeg(bloc B)
{
    int culoare1 = 15;
    int culoare2 = 0;
    //if(culoare == FUNDAL) culoare1 = culoare2 = FUNDAL;
    if(B.tip == 'D')
    {
       setfillstyle(SOLID_FILL, culoare1);
       circle(B.pLeg[0].x,B.pLeg[0].y,5);
       floodfill(B.pLeg[0].x,B.pLeg[0].y,0);

       setfillstyle(SOLID_FILL, culoare2);
       circle(B.pLeg[1].x,B.pLeg[1].y,5);
       floodfill(B.pLeg[1].x,B.pLeg[1].y,0);

       setfillstyle(SOLID_FILL, culoare2);
       circle(B.pLeg[2].x,B.pLeg[2].y, 5);
       floodfill(B.pLeg[2].x,B.pLeg[2].y,0);

    }
    else
    if(B.tip == 'S')
    {
       setfillstyle(SOLID_FILL, culoare2);
       circle(B.pLeg[1].x,B.pLeg[1].y,5);
       floodfill(B.pLeg[1].x,B.pLeg[1].y,0);

    }
    else
    if(B.tip == 'T')
    {
       setfillstyle(SOLID_FILL, culoare1);
       circle(B.pLeg[0].x,B.pLeg[0].y,5);
       floodfill(B.pLeg[0].x,B.pLeg[0].y,0);
    }
    else
    {

       setfillstyle(SOLID_FILL, culoare1);
       circle(B.pLeg[0].x,B.pLeg[0].y,5);
       floodfill(B.pLeg[0].x,B.pLeg[0].y,0);

       setfillstyle(SOLID_FILL, culoare2);
       circle(B.pLeg[1].x,B.pLeg[1].y,5);
       floodfill(B.pLeg[1].x,B.pLeg[1].y,0);
    }

}

//traseaza legatura dintre doua blocuri care au drept indici: indB si indB2, iar nr legaturii este dat de indLeg
void coord_legatura(int indB, int indB2, int indLeg, int culoare)
{
    int x1, y1, x2, y2, p1, p2;
    //p1 si p2 pot fi 0 sau 1 : punctul 0 sau 1 al blocului
    p1 = vecLeg[indLeg].punct1;
    p2 = vecLeg[indLeg].punct2;
    x1 = b[indB].pLeg[p1].x;
    y1 = b[indB].pLeg[p1].y;
    x2 = b[indB2].pLeg[p2].x;
    y2 = b[indB2].pLeg[p2].y;

    drawLine(x1, y1, x2, y2, culoare);


}

//refacem legatura atunci cand gasim legatura intre blocul cu indB(pe care vrem sa l stergem) si alt bloc(indB2)
void refa_legatura(int indB, int culoare)
{
    int indLeg, indB2, indB3, k;
    for(int j = 0; j < nrLeg; j ++)
         {
                if(vecLeg[j].bloc1 == indB)
                {
                    indB2 = vecLeg[j].bloc2;
                    indLeg = j;
                    coord_legatura(indB, indB2, indLeg, culoare);
                }
                else
                if(vecLeg[j].bloc2 == indB)
                {
                    indB2 = vecLeg[j].bloc1;
                    indLeg = j;
                    coord_legatura(indB2, indB, indLeg, culoare);
                }


        }
}

void deseneaza_Bloc(bloc B, int culoare)
{

    switch (B.tip)
    {


        case 'C' : BLOC_CALCUL(B.x, B.y, B.latime, culoare, B.e.text); break;
        case 'O' : BLOC_OUTPUT(B.x, B.y, B.latime, culoare, B.v.nume); break;
        case 'I' : BLOC_INPUT(B.x, B.y, B.latime, culoare, B.v.nume);break;
        case 'D' : BLOC_CONDITIE(B.x, B.y, B.latime, culoare, B.e.text); break;
        case 'S' : BLOC_START(B.x, B.y, culoare);break;
        case 'T' : BLOC_STOP(B.x, B.y, culoare); break;
    }
}

//verifica in ce bloc se afla click-ul, dupa care apeleaza deseneaza_bloc avand culoare FUNDAL
//copieI va folosi pt a actualiza informatiile despre blocul mutat
void sterge_piesa(int n, punct click, int &copieI)
{
    int j;
    for(int i = 1; i <= n; i ++)
    {

    if(click.x >= b[i].x-b[i].latime/2 && click.x <= b[i].x+b[i].latime/2 && click.y >= b[i].y - 20  && click.y <= b[i].y + 20)
    {
        copieI = i;


        deseneaza_Bloc(b[i], FUNDAL);
        return;
    }
    if(Click_InteriorBloc(click, b[i].x, b[i].y , 160))
    {
        copieI = i;

        deseneaza_Bloc(b[i], FUNDAL);
        return;
    }
    if(Click_InteriorBloc5(b[i].x, b[i].y-20, b[i].x + b[i].latime/2, b[i].y+20, b[i].x - b[i].latime/2, b[i].y + 20, click.x, click.y))
    {
        copieI = i;

        deseneaza_Bloc(b[i], FUNDAL);
        return;
    }
    if(Click_Elipsa(click, b[i].x, 40, 35))
    {
        copieI = i;

        deseneaza_Bloc(b[i], FUNDAL);
        return;
    }
    }
}

//IRINA
void deseneazaLegatura(int &indBloc1, int &p1, int &indBloc2, int &p2);
void legaturi();
void INCARCA_SCHEMA(char nrfis);
void SALVEAZA_SCHEMA();
void CONVERSIE_C();
void poti_muta();
int c3 = 30; // variabila pentru coordonata y pentru text
void adauga_Blocuri()
{
    int indBloc1, indBloc2, p1, p2;
    punct click, B, A;
    c2 = 120; //variabila pentru coordonata y pentru blocuri
    int c1 = 600;

    char input[50];
    do
    {

    if(ismouseclick(WM_LBUTTONDOWN))
    {

       clearmouseclick(WM_LBUTTONDOWN);

       click.x=mousex(); click.y=mousey();
       setbkcolor(FUNDAL);
       setcolor(0);

    if (click.x >= 50 && click.x <= 150 && click.y >= 10&&click.y <= 50)
      {
       n++,
       outtextxy(1135, c3 , "Introdu expresia:"),
       c3+=15;
       citire_info(1135,c3, input),
       strcpy(b[n].e.text, input),
       b[n].latime = textwidth(input)+20,
       BLOC_CALCUL(c1, c2, b[n].latime, CULOARE, input),
         cout << input;
       b[n].tip = 'C', b[n].x = c1, b[n].y = c2,
       initBloc(b[n], b[n].e.text), locLeg(b[n]),
       c2 += 70,
       c3 += 20;
       if(c2  == 680) {c2 = 120; c1 = c1 + 150;}

      }
       else
    if (Click_InteriorBloc(click, 250, 30, 160))
       {
        n++,
        outtextxy(1135, c3, "Variabila pe care programul o va afisa:"),
        c3+=15;
        citire_info(1135,c3, input),
        b[n].latime = textwidth(input)+20,
        strcpy(b[n].v.nume, input),
        BLOC_OUTPUT(c1, c2, b[n].latime, CULOARE, b[n].v.nume),
        b[n].tip = 'O', b[n].x = c1, b[n].y = c2,
        initBloc(b[n], "O"), locLeg(b[n]),
        c2 += 70;
        c3 += 20;
        if(c2  == 680) {c2 = 120; c1 = c1 + 150;}
       }
       else
    if (Click_InteriorBloc(click, 430, 30, 160))
       {
       n++,
       outtextxy(1135, c3, "Trebuie introdusa o litera de la A la Z:"),
       c3+=15;
       citire_info(1135,c3, input),
       b[n].latime = textwidth(input)+20,
       BLOC_INPUT(c1, c2, b[n].latime, CULOARE, input),

       strcpy(b[n].v.nume, input),
       b[n].tip = 'I', b[n].x = c1, b[n].y = c2,
       initBloc(b[n], b[n].v.nume), locLeg(b[n]),
       c2+=70;
       c3+=20;
       if(c2  == 680) {c2 = 120; c1 = c1 + 150;}
       }
       else
    if (Click_Elipsa(click, 600, 40, 35))
       {
        outtextxy(1135, c3 , "Se initiaza programul");
        BLOC_START(c1, c2, CULOARE),
        n ++, b[n].tip = 'S', b[n].x = c1, b[n].y = c2,
        initBloc(b[n], "START"), locLeg(b[n]),
        c2+=70;
        c3+=20;
        if(c2  == 680) {c2 = 120; c1 = c1 + 150;}
       }
       else
    if (Click_Elipsa(click, 720, 40, 35))
       {
        n ++,
        BLOC_STOP(c1, c2, CULOARE),
        b[n].tip = 'T',  b[n].x = c1, b[n].y = c2,
        initBloc(b[n],"STOP"), locLeg(b[n]),
        c2+=70,
        c3+=20,
        stop = true;
        poti_muta();
        legaturi();
        poti_muta();
        if(c2  == 680) {c2 = 120; c1 = c1 + 150;}

       }
       else
    if (Click_InteriorBloc5(770, 50, 930, 50, 850, 10, click.x, click.y))
       {
          n ++,
          outtextxy(1135, c3, "Adauga conditia:"),
          c3+=15;
          citire_info(1135, c3, input),
          strcpy(b[n].e.text, input);
          b[n].latime = textwidth(input)+100,
          BLOC_CONDITIE(c1, c2, b[n].latime, CULOARE, input),
          b[n].tip = 'D', b[n].x = c1, b[n].y = c2,
          initBloc(b[n], b[n].e.text), locLeg(b[n]),
          c2 += 70,
          c3 += 15;
          if(c2  == 680) {c2 = 120; c1 = c1 + 150;}
       }
       else
    if (Click_Elipsa(click, 80, 40, 120))
       {
         outtextxy(1135, 30, "INCARCA SCHEMA: tasteaza numarul schemei");
         outtextxy(1135, 50, "1 - maximul");
         outtextxy(1135, 70, "2 - suma 1_n");
         c3 = 110;
         citire_info(1135, 90, input);
         INCARCA_SCHEMA(input[0]);
           poti_muta();
         stop = true;
       }


    }


    }while(!stop);

}

ofstream fout("schemaNOUA.txt");
void SALVEAZA_SCHEMA() //IRINA
{

    int i = 1;

    while(i <= n)
    {
        fout << char(b[i].tip + 32)<<"\n";
        fout << b[i].x <<" " << b[i].y <<"\n";
        if(b[i].tip == 'D') fout << b[i].urmA <<" "<<b[i].urmF <<"\n";
        else if(b[i].tip != 'T') fout << b[i].urm<<"\n";
        i ++;
    }
    fout.close();
}

void INCARCA_SCHEMA(char nrfis) //IRINA
{
    char lit[7][2]={"s","i", "d", "c", "o", "t"};

    int cif, g = 0, expr = 0, leg = 0, blocCond = 0; ///g, expr, leg sunt niste variabile logice pe care le folosesc
                                       ///pentru a sti care este urmatorul pas(fixarea coord, a expresiei sau a legaturilor)
    nrLeg = 0;
    FILE *fis;
    switch (nrfis)
    {
        case '1': fis = fopen("maximul.txt", "rt"); break;
        case '2': fis = fopen("suma1n.txt", "rt"); break;
    }

    if (fis == NULL)
    {
        cout << "EROARE";
        return;
    }

    char s[50];
    while(!feof(fis))
    {

        fgets (s, 10, fis);

        int len = strlen(s) - 1;

        if(len == 1)
        {
            if(s[0] >= 'A' && s[0] <= 'Z')
            {
                strcpy(b[n].v.nume, s);
                b[n].latime = textwidth(b[n].v.nume)+20,
                initBloc(b[n], b[n].v.nume);
                expr = 0;
                 leg = 1;
            }
            else
            if(s[0] >= '0' && s[0] <= '9')
            {
                cif = s[0]-'0';
                vecLeg[nrLeg].bloc1 = n;
                vecLeg[nrLeg].punct1 = 1;
                vecLeg[nrLeg].bloc2 = cif;
                vecLeg[nrLeg].punct2 = 0;

                if(n  < cif) vecLeg[nrLeg].tipLegatura = 1;
                else vecLeg[nrLeg].tipLegatura = 2;

                nrLeg ++;
                 leg = 0;


            }
        }
        else
        if(len > 2)
        {

            if(s[0] >= 'a' && s[0] <= 'z')
            {

                for(int i = 0; i < 6; i ++)
                if(lit[i][0] == s[0])
                {

                    n ++;
                    b[n].tip = lit[i][0] - 32;

                    g = 1;
                }


            }
            else
            {
                int l = 0, r = 0, i, cif;


                for(i = 0; i < len && s[i] != ' '; i ++)
                {
                    cif =  s[i]-'0';
                    l = l * 10 + cif;
                }
                i++;
                for(; i < len && s[i] != ' '; i ++)
                {
                    cif =  s[i]-'0';
                    r = r * 10 + cif;
                }

                if(g == 1)
                {
                   b[n].x = l;
                   b[n].y = r;
                    if(b[n].tip == 'S') initBloc(b[n], "START");
                    if(b[n].tip == 'T') initBloc(b[n], "STOP");
                   g = 0;
                   expr = 1;
                }
                else
                if(expr == 1)
                {
                    strcpy(b[n].e.text, s);
                    initBloc(b[n], b[n].e.text);
                    if(b[n].tip == 'D') b[n].latime = textwidth(b[n].e.text)+100;
                    else b[n].latime = textwidth(b[n].e.text)+20;
                    expr = 0;
                    leg = 1;
                }
                else
                if(leg == 1)
                {
                    if(b[n].tip == 'D')
                    {
                        blocCond = n;
                        vecLeg[nrLeg].bloc1 = n;
                        vecLeg[nrLeg].punct1 = 1;
                        vecLeg[nrLeg].bloc2 = l;
                        vecLeg[nrLeg].punct2 = 0;
                        if(n  < l) vecLeg[nrLeg].tipLegatura = 1;
                        else vecLeg[nrLeg].tipLegatura = 2;
                        nrLeg ++;
                        vecLeg[nrLeg].bloc1 = n;
                        vecLeg[nrLeg].punct1 = 2;
                        vecLeg[nrLeg].bloc2 = r;
                        vecLeg[nrLeg].punct2 = 0;
                        if(n  < r) vecLeg[nrLeg].tipLegatura = 1;
                        else vecLeg[nrLeg].tipLegatura = 2;
                        nrLeg ++;
                        leg = 0;
                    }
                }
            }

        }

    }
    fclose(fis);
    int i;
    for(i = 0; i < nrLeg; i ++)
        coord_legatura(vecLeg[i].bloc1, vecLeg[i].bloc2, i, 0);

    for(i = 1; i <= n; i ++)
    {
        deseneaza_Bloc(b[i], CULOARE);
        locLeg(b[i]);
    }


}

//IRINA
void drawLine(int x1, int y1, int x2, int y2, int culoare)
{
    setcolor(culoare);
    int mijx, mijy;
    if(x2 > x1) mijx = x1 + (x2 - x1)/2;
    else mijx = x2 + (x1 - x2)/2;

    if(y2 > y1)
    {
        mijy = y1 + (y2 - y1)/2;
        line(x1, y1, x1, mijy);
        line(x1, mijy, x2, mijy);
        line(x2, mijy, x2, y2) ;
    }
    else
    {
        mijy = y2 - 25;

        line(x1, y1, x1, y1 + 25 );
        line(x1, y1 + 25, mijx, y1 + 25);
        line(mijx, y1 + 25, mijx, mijy);
        line(mijx, mijy, x2, mijy);
        line(x2, mijy, x2, y2) ;

    }


    line(x2 - 5, y2 - 10, x2,  y2 - 5);
    line(x2 + 5, y2 - 10, x2,  y2 - 5);

}

void deseneazaLegatura(int &indBloc1, int &p1, int &indBloc2, int &p2)
{
    bool click=false;
    int i, xMouse,yMouse;
    // aleg un punct de legatura (p1) de la nodul 1 (idNod1)
    do {
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            Beep(2000,100);
            clearmouseclick(WM_LBUTTONDOWN);
            xMouse=mousex(); yMouse=mousey();
            for (i = 1; i <= n; i ++)
                if (abs(b[i].pLeg[1].x - xMouse)<=5
                    && abs(b[i].pLeg[1].y - yMouse)<=5)
                    { indBloc1=i; p1=1; click=true; }
                else if (abs(b[i].pLeg[2].x - xMouse)<=5
                    && abs(b[i].pLeg[2].y - yMouse)<=5)
                    { indBloc1=i; p1=2; click=true; }
        }
    } while (!click);
    // aleg un punct de legatura (p2) de la nodul 2 (idNod2)
    // pana aleg, desenez mereu o linie
    click=false;
    int x1,y1,x2,y2;
    x1=b[indBloc1].pLeg[p1].x;
    y1=b[indBloc1].pLeg[p1].y;
    xMouse=mousex(); yMouse=mousey();
    do
    {
        drawLine(x1,y1,xMouse,yMouse, 0);
        delay(50);drawLine(x1,y1,xMouse,yMouse, FUNDAL);
        xMouse=mousex(); yMouse=mousey();
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            Beep(1200,100);
            clearmouseclick(WM_LBUTTONDOWN);
            xMouse=mousex(); yMouse=mousey();
            for (i=1; i<=n; i++)
                if (abs(b[i].pLeg[0].x - xMouse)<=5
                    && abs(b[i].pLeg[0].y - yMouse)<=5)
                    { indBloc2=i; p2=0; click=true; }


        }
    }
    while (!click);
    x2 = b[indBloc2].pLeg[p2].x;
    y2 = b[indBloc2].pLeg[p2].y;
    drawLine(x1,y1,x2,y2, 0);

}

void legaturi()
{
    int indBloc1, indBloc2, p1, p2;
    int cif, i;
    char input[50];
    setcolor(0);
    setbkcolor(FUNDAL);
    c3=c3-15;
    outtextxy(1135, c3, "Introdu numarul de legaturi:");
      c3+=15;

    citire_info(1135, c3, input);
    nrLeg=atoi(input);


    c3+=20;
    i = 0;
    while(i < nrLeg)
    {
        deseneazaLegatura(indBloc1,p1,indBloc2,p2);

        vecLeg[i].bloc1=indBloc1;
        vecLeg[i].bloc2=indBloc2;
        vecLeg[i].punct1=p1;
        vecLeg[i].punct2=p2;
        b[indBloc1].urm=indBloc2;
        if(indBloc1  < indBloc2) vecLeg[i].tipLegatura = 1;
        else vecLeg[i].tipLegatura = 2;

        cout << b[indBloc1].pLeg[p1].x <<" "<<b[indBloc1].pLeg[p1].y<<" ";
        cout << b[indBloc2].pLeg[p2].x <<" "<<b[indBloc2].pLeg[p2].y<<"\n";

        i++;
        for(int j = 1; j <= n; j ++)
        {
            deseneaza_Bloc(b[j], CULOARE);

            locLeg(b[j]);
        }

    }
}

int verificareSpatiu(punct click)
{
    if(click.y <= 660 && click.y >= 110 && click.x >= 125 && click.x >= 240 && click.x <= 1050) return 1;
    return 0;
}

int c;
bool muta;
void poti_muta() //IRINA
{
    muta = false;
    punct click, B;
    do
    {
              if(ismouseclick(WM_LBUTTONDOWN))
              {

                  clearmouseclick(WM_LBUTTONDOWN);
                  click.x = mousex();
                  click.y = mousey();
                  if(Click_Elipsa(click, 1025, 40, 35))
                  {
                      muta = true;


                   BUTON_SFERA(1025, 35, "POTI MUTA", 2);
                  }

              }
    }while(!muta);

    muta = false;
    do
    {

        if(ismouseclick(WM_RBUTTONDOWN))
        {

        c ++;
        clearmouseclick(WM_RBUTTONDOWN);
        B.x = mousex();
        B.y = mousey();



        int i, ind1; //ind1 este indicele blocului pe care il stergem si il obtinem din sterge_piesa


        if(c == 1)
        {

            sterge_piesa(n, B, ind1);
            refa_legatura(ind1, FUNDAL);

        }
        else
        if(c == 2)
        {
            //actualizez informatiile despre blocul mutat

            b[ind1].x = B.x;
            b[ind1].y = B.y;
            if(verificareSpatiu(B))
            {


            switch (b[ind1].tip)
            {
                case 'S': initBloc(b[ind1], "START");  break;
                case 'T': initBloc(b[ind1], "STOP");  break;
                case 'D': initBloc(b[ind1], b[ind1].e.text); break;
                case 'C': initBloc(b[ind1], b[ind1].e.text); break;
                case 'I': initBloc(b[ind1], b[ind1].v.nume); break;
                case 'O': initBloc(b[ind1], b[ind1].v.nume); break;
            }


            //desenez toate legaturile si blocurile din nou
            for(i = 0; i < nrLeg; i ++)
                coord_legatura(vecLeg[i].bloc1, vecLeg[i].bloc2, i, 0);

            for(i = 1; i <= n; i ++)
            {
                deseneaza_Bloc(b[i], CULOARE);
                locLeg(b[i]);
            }
            c = 0;
            }
            else c = 1;



        }
      }
       else
         if(ismouseclick(WM_LBUTTONDOWN))
              {

                  clearmouseclick(WM_LBUTTONDOWN);
                  click.x = mousex();
                  click.y = mousey();
                  if(Click_Elipsa(click, 1025, 40, 35))
                  {
                      muta = true;
                      BUTON_SFERA(1025, 35, "NU POTI MUTA", 4);
                  }
              }

    }while(!muta);
}

void variabile(char i,int j,int ox,int oy) //ROBERT
{

    setcolor(0);


    char msg[50];
    sprintf(msg, "%c",i);
       outtextxy(ox,720+oy,msg);
       outtextxy(ox+10,720+oy,"=");
    int aux=var[j];
    int nrr=0;
    while (aux)
    {
        nrr++;
        aux=aux/10;
    }
    if (var[j]==0)
        outtextxy(ox+20,720+oy,"0");
    while (var[j]>0)
    {
    sprintf(msg, "%d",var[j]);
    outtextxy(ox+20+nrr,720+oy,msg);
     nrr--;
     var[j]=var[j]/10;
    }

}

void startinterschem() //ROBERT
{  punct click;
    while (1)
    {   if(ismouseclick(WM_LBUTTONDOWN))
        { clearmouseclick(WM_LBUTTONDOWN);
            click.x=mousex(); click.y=mousey();
    if (click.x>600&&click.x<900&&click.y>450&&click.y<600)
        return;}}
}

void interfata() //ROBERT
{
    initwindow(1500, 1100, "INTERSCHEM");

        readimagefile("background.jpg",0,0,1500,1100);
        setfillstyle(SOLID_FILL, BLACK);
        bar(400,50,1100,200);
        readimagefile("inter.jpg",401,51,1098,198);
        bar(450,250,1050,300);
        readimagefile("autori.jpg",451,251,1048,298);
        bar(600,450,900,600);
        readimagefile("start.jpg",601,451,898,598);
        startinterschem();
        cleardevice();
        setbkcolor(8);
        cleardevice();
        setbkcolor(0);

    n = 0;
    setcolor(0);
    setlinestyle(0,0,5);
    line(0,75,1130,75);
    line(1130,0,1130,1100);
    line(0,700,1130,700);
    line(1130, 500, 1500, 500);
    line(170,75,170,700);
      setlinestyle(0,0,0);
    setbkcolor(5);
    BUTON_SFERA(80, 120, "INCARCA SCHEMA", 0);
    BUTON_SFERA(1025, 35, "NU POTI MUTA", 4);
    BLOC_CALCUL(80, 30, 100, CULOARE, "CALCULEAZA");
    BLOC_OUTPUT(250,30, 100, CULOARE, "SCRIE");
    BLOC_INPUT(430, 30, 100, CULOARE, "CITESTE");
    BLOC_START(600, 35, CULOARE);
    BLOC_STOP(720, 35, CULOARE);
    BLOC_CONDITIE(850, 30, 160, CULOARE, "CONDITIE");

     setbkcolor(8);
    ok=1;

}

bool bucla = false;
int indWh;

void compilare1() //ROBERT
{

    strcpy(F.vect,"");
    char input[200];
    int nr;
    setbkcolor(8);
    bloc b1,b2;
    for (int i=0;i<nrLeg;i++)
    {
        if (b[vecLeg[i].bloc1].tip!='D')
        {
           if(vecLeg[i].tipLegatura == 2 ) {bucla = true; indWh = vecLeg[i].bloc2;}
           b[vecLeg[i].bloc1].urm=vecLeg[i].bloc2;
        }
        else
        {
            if(vecLeg[i].tipLegatura == 2 ) {bucla = true; indWh = vecLeg[i].bloc2;}

            b[vecLeg[i].bloc1].urmA=vecLeg[i].bloc2;
            i++;
            b[vecLeg[i].bloc1].urmF=vecLeg[i].bloc2;
        }
    }
    int i=1;

    while (b[i].urm!=0||(b[i].urmA!=0&&b[i].urmF!=0))
    {
           if (c3>480)
            {c3=5;
              setcolor(BLACK);
               bar(1134,0,1500,498);
            setfillstyle(SOLID_FILL,DARKGRAY);
            floodfill(1300,250,BLACK);
            }
        switch (b[i].tip)
        {

            case 'I':
        {
            outtextxy(1135, c3 , "Introdu o valoare pentru variabila:"),
            outtextxy(1360, c3 , b[i].v.nume);
           citire_info(1135,c3+15,input);
           nr=0;
           int d=0;
           while (input[0]!='a')
           {
               nr=nr*10+(int(input[d])-int('0'));
               if (!isdigit(input[d+1]))
                input[0]='a';
               else
               d++;
           }

           b[i].v.val=nr;
                   c3=c3+30;

        int aux=0;
        aux=int(b[i].v.nume[0])-int('A');
        var[aux]=b[i].v.val;
        i=b[i].urm;
           break;

        }
  case 'C':
       {  int okc=0;
           if (b[i].e.text[1]=='<'&&b[i].e.text[2]=='-')
           {
               strcpy(F.expresie,b[i].e.text+3);
               okc=1;}
               else
           strcpy(F.expresie,b[i].e.text);

       strcat(F.expresie,")");
            F.lung=strlen(F.expresie);
            F.vect[0]='(';
            int lo=0;
            for (lo=0;lo<strlen(F.expresie);lo++)
            F.vect[lo+1]=F.expresie[lo];
            int calcul=ValoareFunctie(F);
            b[i].e.val=calcul;
         //PARTEA ASTA E PENTRU CONVERSIA DE LA INT LA CHAR;
            char sir[200]={},v[200]={};
            int lk=0,aux=calcul;
        while (aux)
        {
            v[lk++]=(aux%10+'0');
            aux=aux/10;
        }
        v[lk]=NULL;
        int j=0;
        for (int lk=strlen(v)-1;lk>=0;lk--)
            sir[j++]=v[lk];
        sir[j]=NULL;
             if (calcul==0)
        strcpy(sir,"0");
            outtextxy(1135, c3 , "Rezultatul calculului este: ");
           outtextxy(1310, c3, sir);
           if (okc==1)
           {
        var[int(b[i].e.text[0])-int('A')]=calcul;}
           c3=c3+15;
             i=b[i].urm;
            break;
        }
  case 'O':
    {
        int x=var[b[i].v.nume[0]-'A'];
        //PARTEA ASTA E PENTRU CONVERSIA DE LA INT LA CHAR;
         char sir[200]={},v[200]={};
        int lk=0,aux=x;
        while (aux)
        {
            v[lk++]=(aux%10+'0');
            aux=aux/10;
        }
        v[lk]=NULL;
        int j=0;
        for (int lk=strlen(v)-1;lk>=0;lk--)
        sir[j++]=v[lk];

        if (x==0)
        strcpy(sir,"0");
        outtextxy(1135, c3, "Se afiseaza: ");
        outtextxy(1220, c3 ,sir);
        c3=c3+15;
          i=b[i].urm;
        break;
    }
  case 'D':
    {
            strcpy(F.expresie,b[i].e.text);
            strcat(F.expresie,")");
            F.lung=strlen(F.expresie);
            F.vect[0]='(';
            int lo=0;
            for (lo=0;lo<strlen(F.expresie);lo++)
            F.vect[lo+1]=F.expresie[lo];
            int calcul=ValoareFunctie(F);
            if (calcul>0)
            {b[i].e.val=1;
            outtextxy(1135, c3, "Conditia este implinita");
              i=b[i].urmA;}
            else
            {
            outtextxy(1135,c3,"Conditia nu este implinita");
            b[i].e.val=0;
              i=b[i].urmF;}
        c3=c3+15;

        break;
    }
  case 'S':
    {
        i=b[i].urm;
        break;
    }
     break;
        }

        }
    }

int cnou=505;

int indice=0;
int okt=0;
 int intrare = 0;
void conversierecursiva(int i) //ROBERT
{


    if (i==indice&&okt<2)
    {okt++;
        return;}

    if (b[i].urm==0&&(b[i].urmA==0||b[i].urmF==0))
        return;
    switch (b[i].tip)
        {
        case 'I':
            {
                g<<"cin>>"<<b[i].v.nume<<";"<<endl;
                    outtextxy(1135,cnou,"cin>>");
                    outtextxy(1170,cnou,b[i].v.nume);
                    outtextxy(1180,cnou,";");
                       cnou=cnou+20;
                conversierecursiva(b[i].urm);
                break;
            }
        case 'O':
            {
                g<<"cout<<"<<b[i].v.nume<<";"<<endl;
                     outtextxy(1135,cnou,"cout<<");
                    outtextxy(1170,cnou,b[i].v.nume);
                    outtextxy(1185,cnou,";");
                   cnou=cnou+20;
                       conversierecursiva(b[i].urm);
                break;
            }
        case 'C':
            {
                g<<b[i].e.text<<";"<<endl;
                    outtextxy(1135,cnou,b[i].e.text);
                    outtextxy(1180,cnou,";");
                   cnou=cnou+20;
                   conversierecursiva(b[i].urm);
                break;
            }
        case 'D':
            {

                if(i == indWh)
                {

                    intrare ++;

                    if(intrare == 1)
                    {
                      int x = 1135;

                     g<<"while ( ! (  "<<b[i].e.text<<"))"<<endl<<"     {";
                     outtextxy(x,cnou,"while ( ! ( ");
                     x += textwidth("while ( ! ( ");
                     outtextxy(x,cnou,b[i].e.text);
                     x += textwidth(b[i].e.text);
                     outtextxy(x,cnou," ) )");
                     x += textwidth(" ) )");
                     outtextxy(x,cnou,"{");
                     cnou=cnou+20;
                     conversierecursiva(b[i].urmF);

                    }
                    else {

                            g<<"      }"<<endl;
                            outtextxy(1220,cnou-20,"}");
                            conversierecursiva(b[i].urmA);

                         }


                }
                else
                {
                int j=b[i].urmA,k=b[i].urmF;
                int v[50]={0};

                cout << i <<" "<<indWh<<"\n";

                while (b[j].tip!='T')
                {
                    v[j]++;
                    j=b[j].urm;
                }
                v[j]++;
                while (b[k].tip!='T')
                {
                    v[k]++;
                    k=b[k].urm;
                }
                v[k]++;
               int l=0;
               for (l=0;l<=49;l++)
                if (v[l]==2)
               {
                   indice=l;
                   l=50;
               }

                g<<"if ("<<b[i].e.text<<")"<<endl<<"     {";
                outtextxy(1135,cnou,"if (");
                 outtextxy(1165,cnou,b[i].e.text);
                 outtextxy(1200,cnou,")");
                    outtextxy(1230,cnou,"{");
                   cnou=cnou+20;
                   conversierecursiva(b[i].urmA);

                   g<<"      }"<<endl;
            outtextxy(1220,cnou-20,"}");
              g<<"else"<<endl<<"        {"<<endl;
                    outtextxy(1135,cnou,"else  {");
              cnou=cnou+20;
              conversierecursiva(b[i].urmF);

                g<<"      }"<<endl;
  outtextxy(1220,cnou-20,"}");
  conversierecursiva(indice);
                }
  break;
            }
        case 'S':
            {

          conversierecursiva(b[i].urm);}
        break;
        }
}
void conversie() //ROBERT
{

    g<<"#Include <iostream>"<<endl;
    outtextxy(1135,cnou,"#Include <iostream>");
    g<<"#Include <stdlib.h>"<<endl;
    cnou=cnou+20;
       outtextxy(1135,525,"#Include <stdlib.h>");
    g<<"using namespace std;"<<endl;
       cnou=cnou+20;
     outtextxy(1135,545,"using namespace std;");
    g<<"int main()"<<endl;
       cnou=cnou+20;
    outtextxy(1135,565,"int main() {");
       cnou=cnou+20;
    g<<"{";
      for (int i=0;i<nrLeg;i++)
    {
        if (b[vecLeg[i].bloc1].tip!='D')
        {
           b[vecLeg[i].bloc1].urm=vecLeg[i].bloc2;
        }
        else
        {

            b[vecLeg[i].bloc1].urmA=vecLeg[i].bloc2;
            i++;
            b[vecLeg[i].bloc1].urmF=vecLeg[i].bloc2;
        }
    }

    conversierecursiva(1);


      g<<"return 0;";
      outtextxy(1135,cnou,"return 0;");
      outtextxy(1200,cnou,"}");
    g<<"  }";




}

void refa_variabile() //ROBERT
{
    setcolor(0);
    int j=0,ox=10,oy=0;
      for (char i='A';i<='Z';i++)
      {
      variabile(i,j,ox,oy);
      j++; ox=ox+100;
      if (i=='K'||i=='V')
        {oy=oy+50;
         ox=10;}
      }

}

int main()
{
    stop = false;
    stopLeg = false;
    interfata();


    adauga_Blocuri();

    setbkcolor(FUNDAL);
    setcolor(0);
    compilare1();
    SALVEAZA_SCHEMA();

    refa_variabile();
    setcolor(0);
    conversie();
    poti_muta();
    setbkcolor(FUNDAL);




    getch();

    closegraph();
    return 0;
}
