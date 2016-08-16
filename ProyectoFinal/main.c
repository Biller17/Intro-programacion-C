//Adrián Biller A01018940
//Proyecto
#pragma warning (disable:4996)
#include <stdio.h>
#include <time.h>//libreria que incluye el tiempo para usar numeros aleatorios
#include <stdlib.h>//libreria que incluye las funciones de rand

int deck[52];//se crea un array universal ya que se utiliza en varias funciones
char barajaPalo [52];
int jugador1,jugador2,jugador3,jugador4;
int mano1[5],mano2[5],mano3[5],mano4[5];
char palo1[5],palo2[5],palo3[5],palo4[5];
//*******************************************************************************************************
int definicionPalo (i)//funcion en la que se toman los valores asignados a la baraja de palos y se le asigna un simbolo, sea espadas, corazones, treboles o diamantes
{
    switch (i)
    {
        case 'E'://en cada caso se asigna un simbolo y cada vez que se llama la funcion para las cartas
            printf("de ♠]\n");
            break;
        case 'T':
            printf("de ♣]\n");
            break;
        case 'D':
            printf("de ♦]\n");
            break;
        case 'C':
            printf("de ♥]\n");
            break;
    }
    return 1;
}
//*******************************************************************************************************
int definicionCarta (i)//del 2 al 10 son numeros, sin embargo, se necesita poner el nombre de la carta como Jack, Queen, King y As. Esta funcion se llama en el caso de que sea necesario imprimir las cartas
{
    switch(i)
    {
        case 11:
            printf("[Jack ");
            break;
        case 12:
            printf("[Queen ");
            break;
        case 13:
            printf("[King ");
            break;
        case 14:
            printf("[As    ");
            break;
        default:
            printf("[%d    ",i);
    }
    return 1;
}
//*******************************************************************************************************
int impresionManoPalo(int mano[], char palo[])//funcion que se llama en el caso de que sea necesario imprimir una mano, se llaman las dos funciones que se llamaron anteriormente
{
    int j;
    for (j=0;j<=4;j++)//impresion de las cartas desordenadas con un for
    {
        definicionCarta(mano[j]);
        definicionPalo(palo[j]);
    }
    printf("\n");
    return 1;
}
//*******************************************************************************************************
int genD()//funcion que genera la baraja aleatoria
{
    int a,b,c,d,i; // palo = a, carta = b, posicion aleatoria en la baraja =c,
    char p = 'E';
    for(a=1;a<=4;a++)//Primer for que corre cuatro veces (como los cuatro palos de la baraja)
    {
        switch(a)
        {
            case 1:
                p='E';
                break;
            case 2:
                p='T';
                break;
            case 3:
                p='D';
                break;
            case 4:
                p='C';
                break;
        }
        for (b=2;b<=14;b++)//segundo for que corre 13 veces como las cartas de un palo
        {
            c=rand()%52;//se genera un numero aleatorio el cual sera la posicion en la que se le asignara la carta
            d = 0;
            while(deck[c]>0)//para evitar que se asigne una carta a la misma posicion se usa este if, si la posicion ya tiene una carta...
            {
                c=rand()%52;//...se le asignara un valor aleatorio diferente hasta que este este vacio
                d++;
                if (d>=52)//para evitar entrar a un loop infinito ya que al asignarse el ultimo valor todas las posiciones estan llenas se utiliza este if con un break
                {
                    break;
                }
            }
            deck[c]=b;//se le asigna el valor a la carta dependiendo del segundo for, asi haciendolo de trece en trece evitando que las cartas se repitan
            barajaPalo[c]=p;
        }
    }
    printf("La baraja es:\n");//imprime los valores de las cartas en la baraja
    for (i=0;i<=51;i++)
    {
        printf("%d-- ",i+1);
        definicionCarta(deck[i]);
        definicionPalo(barajaPalo[i]);
    }
    printf("\n");
    return 1;
}

//***********************************Comienzo del lector de manos para jugadas*****************************
int cartaAlta(int a[],char b[])//funcion que define cual es la carta alta de la mano del jugador
{
    int j=a[4];//se toma la ultima carta ya que esto se hace despues de ordenar la mano
    printf("Una carta alta:  ");
    definicionCarta(a[4]);
    definicionPalo(b[4]);
    printf("\n");
    return j;//se regresa un valor que posteriormente servira para definir al ganador
}
int par (int a[],char b[] )//funcion en la que se define si en la mano hay algun par
{
    int i;
    int j=1;
    for (i=0;i<5;i++)
    {
        if (a[i]==a[i+1])
        {
            j+=25;
            printf("Un par de:\n");
            definicionCarta(a[i]);
            definicionPalo(b[i]);
            printf("y\n");
            definicionCarta(a[i+1]);
            definicionPalo(b[i+1]);
            printf("\n");
            
        }
    }
    return j;
}
int tercia(int a[],char b[])//funcion que revisa si hay tres cartas iguales para definir una tercia
{
    int i;
    int j = 1;
    for (i=0;i<5;i++)
    {
        if(a[i]==a[i+1] && a[i]==a[i+2])
        {
            j+=30;
            printf("Una tercia de:\n");
            definicionCarta(a[i]);
            definicionPalo(b[i]);
            printf("y\n");
            definicionCarta(a[i+1]);
            definicionPalo(b[i+1]);
            printf("y\n");
            definicionCarta(a[i+2]);
            definicionPalo(b[i+2]);
            printf("\n");
        }
    }
    return j;
}

int corrida (int a[], char b[])//funcion que define si hay una corrida o no, despues de haberla ordenado
{
    int j=1;
    if(a[0]==a[1]-1)//en el caso de que la mano tenga un numero alto y una corrida
    {
        if (a[1]==a[2]-1)
        {
            if(a[2]==a[3]-1)
            {
                if(a[3]==a[4]-1)
                {
                    j+=45;
                    puts("Una corrida del");
                    definicionCarta(a[0]);
                    definicionPalo(b[0]);
                    puts("al");
                    definicionCarta(a[4]);
                    definicionPalo(b[4]);
                }
            }
        }
    }
    return j;
}
int color (char b[])//funcion en la que entran los palos de la mano para definir si tiene una jugada de color
{
    int j=1;
    if(b[0]==b[1] && b[0]==b[2] && b[0]==b[3] && b[0]==b[4])
    {
        j+=50;
        printf("Color");
    }
    return j;
}

int full (int a[])//funcion que busca un par y una tercia, de las dos maneras dependiendo del orden en busca de un fullhouse
{
    int i=0;
    int j=1;
    if (a[i]==a[i+1])//primero un par
    {
        if (a[i+2]==a[i+3] && a[i]==a[i+4])//despues una tercia
        {
            j+=65;
            printf("Un Full House");
        }
    }
    else if (a[i]==a[i+1] && a[i]==a[i+2])//primero una tercia
    {
        if(a[i+3]==a[i+4])//despues un par
        {
            j+=65;
            printf("Un Full House");
        }
    }
    return j ;
}

int pokar (int a[])//funcion que revisa si 4 de las cartas son iguales para un pokar
{
    int i=0;
    int j=1;
    for(i=0;i>1;i++)
    {
        if (a[i]==a[i+1] && a[i]==a[i+2] && a[i]==a[i+3])
        {
            j+=80;
            printf("Pokar");
        }
    }
    return 1;
}

int escaleraDeColor(int a[] , char b[])//funcion que primero revisa si todas son de color y despues si es corrida
{
    int j=1;
    int i=0;
    if (b[i]==b[i]+1 && b[i]==b[i+2] && b[i]==b[i+3] && b[i]==b[i+4])
        if(a[0]==a[1]-1)//en el caso de que la mano tenga un numero alto y una corrida
            if (a[1]==a[2]-1)
                if(a[2]==a[3]-1)
                    if(a[3]==a[4]-1)
                    {
                        j+=100;
                        puts("Una escalera de color del");
                        definicionCarta(a[0]);
                        definicionPalo(b[0]);
                        puts("al");
                        definicionCarta(a[4]);
                        definicionPalo(b[4]);
                    }
    return j;
}
int royalFlush (int a[], char b[])//funcion que revisa especificamente por la corrida de 10, jack, queen, king  y as en el mismo color
{
    int j=1;
    if(b[0]==b[1] && b[0]==b[2] && b[0]==b[3] && b[0]==b[4])
    {
        if(a[0]==10)
            if(a[1]==11)
                if(a[2]==12)
                    if(a[3]==13)
                        if (a[4]==14)
                        {
                            j+=110;
                            printf("Una Flor Imperial");
                        }
    }
    return j;
}
//*******************************************************************************************************

int sortHand (int mano[],char palo[], int a)//funcion bubblesort que recibe los valores de un nuevo array de cinco cartas para ordenarlas
{
    int n=5;//constante del numero de cartas que se van a sortear
    int i,k,temp,puntos;
    char temp2;
    for (i=0;i<n;i++)//for que entra para poder pasar por todas las cartas
    {
        for (k=1;k<(n-i);k++)//for que va pasando por cartas pero cada vez cambia para ser mas eficiente
        {
            if (mano[k-1]>mano[k])//if al que se entra si las cartas estan en desorden y se deben cambiar
            {
                temp = mano[k-1];//se usan tres variables para poder cambiarlas de lugar
                temp2 = palo[k-1];
                mano[k-1]= mano[k];
                palo[k-1] = palo[k];
                mano[k]=temp;
                palo[k]=temp2;
                
            }
        }
    }
    printf("La mano en orden del jugador %d es:\n", a);
    impresionManoPalo(mano,palo);
    printf("Sus posibles jugadas son:\n");
    puntos= cartaAlta(mano, palo)+//presentacion de las posibles jugadas combinado con la suma de todos los
    par(mano,palo)+               //valores regresados y esa suma se le asignara a una de las variables
    tercia(mano,palo)+            //dependiendo del jugador dueño de la mano que se esta leyendo
    color (palo)+
    full(mano)+
    pokar(mano)+
    corrida(mano, palo)+
    color(palo)+
    full(mano)+
    pokar(mano)+
    escaleraDeColor(mano, palo)+
    royalFlush(mano, palo);
    printf("\n\n");
    return puntos;
}
//*******************************************************************************************************

int cambioDeCartas(int mano[], char palo[], int j)// en el caso de que se quiera cambiar cartas se entra a esta funcion, se utiliza dependiendo del numero de jugadores que quieran cambiar cartas
{
    int numero;
    if(j==1)//si el jugador1 si quiere cambiar cartas entonces se entra en este if y se le pregunta cuantas cartas quiere cambiar
    {
        printf("Cuantas cartas desea cambiar?(recuerda de 1 a 3 cartas)ingrese otro valor si no desea cambiar cartas");
        scanf("%d",&numero);
        switch (numero)
        {
            case 1:
                mano[0]=deck[20];
                palo[0]=barajaPalo[20];
                break;
            case 2:
                mano[0]=deck[20];
                palo[0]=barajaPalo[20];
                mano[1]=deck[21];
                palo[1]=barajaPalo[21];
                break;
            case 3:
                mano[0]=deck[20];
                palo[0]=barajaPalo[20];
                mano[1]=deck[21];
                palo[1]=barajaPalo[21];
                mano[2]=deck[22];
                palo[2]=barajaPalo[22];
                break;
            default:
                printf("Ha escogido no cambiar cartas");
                break;
        }
        jugador1 = sortHand(mano, palo, 1);//se vuelve a llamar la funcion en donde se ordenan y busca las posibles jugadas que tenga la mano del jugador y el valor que regrese se le asigna a la variable del jugador para asi generar un puntaje
    }
    if(j==2)
    {
        printf("Cuantas cartas desea cambiar?(recuerda de 1 a 3 cartas)ingrese otro valor si no desea cambiar cartas");
        scanf("%d",&numero);
        switch (numero)
        {
            case 1:
                mano[0]=deck[23];
                palo[0]=barajaPalo[23];
                break;
            case 2:
                mano[0]=deck[23];
                palo[0]=barajaPalo[23];
                mano[1]=deck[24];
                palo[1]=barajaPalo[24];
                break;
            case 3:
                mano[0]=deck[23];
                palo[0]=barajaPalo[23];
                mano[1]=deck[24];
                palo[1]=barajaPalo[24];
                mano[2]=deck[25];
                palo[2]=barajaPalo[25];
                break;
            default:
                printf("Ha escogido no cambiar cartas");
                break;

        }
        jugador2 = sortHand(mano, palo, 2);
    }
    if(j==3)
    {
        printf("Cuantas cartas desea cambiar? (recuerda de 1 a 3 cartas)ingrese otro valor si no desea cambiar cartas");
        scanf("%d",&numero);
        switch (numero)
        {
            case 1:
                mano[0]=deck[26];
                palo[0]=barajaPalo[26];
                break;
            case 2:
                mano[0]=deck[26];
                palo[0]=barajaPalo[26];
                mano[1]=deck[27];
                palo[1]=barajaPalo[27];
                break;
            case 3:
                mano[0]=deck[26];
                palo[0]=barajaPalo[26];
                mano[1]=deck[27];
                palo[1]=barajaPalo[27];
                mano[2]=deck[28];
                palo[2]=barajaPalo[28];
                break;
            default:
                printf("Ha escogido no cambiar cartas");
                break;

        }
        jugador3 = sortHand(mano, palo, 3);
    }
    
    if(j==4)
    {
        printf("Cuantas cartas desea cambiar? (recuerda de 1 a 3 cartas)ingrese otro valor si no desea cambiar cartas");
        scanf("%d",&numero);
        switch (numero)
        {
            case 1:
                mano4[0]=deck[29];
                palo4[0]=barajaPalo[29];
                break;
            case 2:
                mano4[0]=deck[29];
                palo4[0]=barajaPalo[29];
                mano4[1]=deck[30];
                palo4[1]=barajaPalo[30];
                break;
            case 3:
                mano4[0]=deck[29];
                palo4[0]=barajaPalo[29];
                mano4[1]=deck[30];
                palo4[1]=barajaPalo[30];
                mano4[2]=deck[31];
                palo4[2]=barajaPalo[31];
                break;
            default:
                printf("Ha escogido no cambiar cartas");
                break;

        }
        jugador4 = sortHand(mano, palo, 4);
    }
    return 1;
}

//*********************************************************************************************************
void repartoJugador1 ()
{
    int j=1;
    int respuesta;
    int mano1[5]={deck[0],deck[4],deck[8],deck[12],deck[16]};//se asignan las primeras cinco cartas de la baraja
    char palo1[5]={barajaPalo[0],barajaPalo[4],barajaPalo[8],barajaPalo[12],barajaPalo[16]};
    printf("La mano del jugador 1 es:\n");
    impresionManoPalo(mano1, palo1);
    jugador1 = sortHand(mano1,palo1,j);//desde aqui se llama la funcion para ordenar las cartas y despues se lee para ver si es una corrida
    printf("Desea cambiar de cartas?(si=1/no=2)");
    scanf("%d",&respuesta);
    if (respuesta==1)//si el usuario si desea cambiar cartas entonces entra al if y se llama la funcion en donde se le preguntan cuantas cartas desea cambiar
    {
        cambioDeCartas(mano1, palo1,j);
    }
    
}
void repartoJugador2 ()
{
    int j=2;
    int respuesta;
    int mano2[5]={deck[1],deck[5],deck[9],deck[13],deck[17]};
    char palo2[5]={barajaPalo[1],barajaPalo[5],barajaPalo[9],barajaPalo[13],barajaPalo[17]};
    printf("la mano del jugador 2 es:\n");
    impresionManoPalo(mano2,palo2);
    jugador2 = sortHand(mano2,palo2,j);
    printf("Desea cambiar de cartas?(si=1/no=2)");
    scanf("%d",&respuesta);
    if (respuesta==1)
    {
        cambioDeCartas(mano2, palo2,j);
    }
}
void repartoJugador3 ()
{
    int respuesta;
    int j=3;
    int mano3[5]={deck[2],deck[6],deck[10],deck[14],deck[18]};
    char palo3[5]={barajaPalo[2],barajaPalo[6],barajaPalo[10],barajaPalo[14],barajaPalo[18]};
    printf("la mano del jugador 3 es:\n");
    impresionManoPalo(mano3, palo3);
    jugador3 = sortHand(mano3,palo3,j);
    printf("Desea cambiar de cartas?(si=1/no=2)");
    scanf("%d",&respuesta);
    if (respuesta==1)
    {
        cambioDeCartas(mano3, palo3,j);
    }
}
void repartoJugador4 ()
{
    int respuesta;
    int j=4;
    int mano4[5]={deck[3],deck[7],deck[11],deck[15],deck[19]};
    char palo4[5]={barajaPalo[3],barajaPalo[7],barajaPalo[11],barajaPalo[15],barajaPalo[19]};
    printf("la mano del jugador 4 es:\n");
    impresionManoPalo(mano4, palo4);
    jugador4 = sortHand(mano4,palo4,j);
    printf("Desea cambiar de cartas?(si=1/no=2)");
    scanf("%d",&respuesta);
    if (respuesta==1)
    {
        cambioDeCartas(mano4, palo4,j);
    }
}
//*******************************************************************************************************

void manoJugadores(j)//funcion que toma las primeras cinco cartas de la baraja como un juego verdadero
{
    if (j<3)//dependiendo de la opcion que se elige antes, se reparten las cartas a los jugadores que se eligieron
    {
        repartoJugador1();
        repartoJugador2();
    }
    else if (j<4)
    {
        repartoJugador1();
        repartoJugador2();
        repartoJugador3();
    }
    else
    {
        repartoJugador1();
        repartoJugador2();
        repartoJugador3();
        repartoJugador4();
    }
    printf("\n\n");
}
//*******************************************************************************************************
int definicionGanador()
{
    if(jugador1>jugador2 && jugador1>jugador3 && jugador1> jugador4)
        puts("El jugador 1 es el ganador!");
    else if(jugador2>jugador3 && jugador2>jugador4)
        puts("El jugador 2 es el ganador!");
    else if(jugador3>jugador4)
        puts("El jugador 3 es el ganador!");
    else
        puts("El jugador 4 es el ganador!");
    return 1;
}
//*******************************************************************************************************
void startGame ()//funcion para la interfaz la que le pregunta si desea repetir el juego al usuario
{
    char response;
    int j;
    do//un do while para que se haga la accion y despues si el usuario quiere repetir el juego se repita
    {
        genD();//funcion que genera la baraja
        puts("Cuantos jugadores seran? Minimo dos jugadores");
        scanf("%d",&j);
        if(j<2 && j>4)
        {
            j=0;
            printf("Su respuesta es invalida, escoja entre 2 y 4 jugadores");
            scanf("%d",&j);
        }
        manoJugadores(j);//funcion que toma las cartas y llama otras funciones que las ordenan y luego leen para una corrida
        definicionGanador();
        puts("Desea repetir el juego?(s= si/ n=no)");//pregunta al ususario
        scanf("%s",&response);
        while(response!='s' && response!='n')
        {
            printf("Lo siento, su respuesta es invalida, ingrese \"s\" para repetir o \"n\" para salir ");
            scanf("%s",&response);
        }
    }
    while (response=='s');//condicional del input del usuario para repetir el juego
}

//*******************************************************************************************************
int main()
{
    srand(time(0));//generador semilla de los numeros aleatorios
    startGame();//se manda a llamar la variable del juego en donde se llaman las otras variables
    return 1;
}