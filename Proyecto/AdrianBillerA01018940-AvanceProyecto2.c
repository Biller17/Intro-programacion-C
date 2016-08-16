//Adrián Biller A01018940
//Proyecto
#pragma warning (disable:4996)
#include <stdio.h>
#include <time.h>//libreria que incluye el tiempo para usar numeros aleatorios
#include <stdlib.h>//libreria que incluye las funciones de rand

int deck[52];//se crea un array universal ya que se utiliza en varias funciones
int genD()//funcion que genera la baraja aleatoria
{
    int a,b,c,d,i; // palo = a, carta = b, posicion aleatoria en la baraja =c,
    for(a=1;a<=4;a++)//Primer for que corre cuatro veces (como los cuatro palos de la baraja)
    {
        for (b=1;b<=13;b++)//segundo for que corre 13 veces como las cartas de un palo
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
        }
    }
    printf("La baraja es:\n");//imprime los valores de las cartas en la baraja
    for (i=0;i<=51;i++)
    {
        printf("%d--%d\n",i+1,deck[i]);
    }
    printf("\n");
    return 1;
}

//*******************************************************************************************************


int corrida (int a[])//funcion que define si hay una corrida o no, despues de haberla ordenado
{
    if(a[0]==a[1]-1)//en el caso de que la mano tenga un numero alto y una corrida
    {
        if (a[1]==a[2]-1)
        {
            if(a[2]==a[3]-1)
            {
                printf("Tienes una corrida del %d al %d!\n",a[0],a[3]);
            }
        }
    }
    //en este caso se hacen dos secciones de condicionales para asegurar poder definir las corridas dependiendo del valor de las cartas p
    if(a[1]==a[2]-1)//en el caso de que la mano tenga un numero bajo y una corrida
    {
        if (a[2]==a[3]-1)
        {
            if(a[3]==a[4]-1)
            {
                printf("*********Tienes una corrida del %d al %d!*********\n",a[1],a[4]);
            }
        }
    }

    return 1;
}

//*******************************************************************************************************

int sortHand (int mano[])//funcion bubblesort que recibe los valores de un nuevo array de cinco cartas para ordenarlas
{
    int n=5;//constante del numero de cartas que se van a sortear
    int i,k,temp;
    for (i=0;i<n;i++)//for que entra para poder pasar por todas las cartas
    {
        for (k=1;k<(n-i);k++)//for que va pasando por cartas pero cada vez cambia para ser mas eficiente
        {
            if (mano[k-1]>mano[k])//if al que se entra si las cartas estan en desorden y se deben cambiar
            {
                temp = mano[k-1];//se usan tres variables para poder cambiarlas de lugar
                mano[k-1]=mano[k];
                mano[k]=temp;
            }
        }
    }
    printf("Tu mano ordenada es:");//impresion de las cartas con un for
    for (i = 0; i < n; i++)
    {
        printf("%d  ", mano[i]);
    }
    printf("\n\n");
    return 1;
}

//*******************************************************************************************************

int hand()//funcion que toma las primeras cinco cartas de la baraja como un juego verdadero
{
    int m;
    int mano[5]={deck[0],deck[1],deck[2],deck[3],deck[4]};//se asignan las primeras cinco cartas de la baraja
    printf("Tu mano es:");
    for (m=0;m<=4;m++)//impresion de las cartas desordenadas con un for
    {
        deck[m]=0;
        printf("%d  ",mano[m]);
    }
    printf("\n\n");
    sortHand(mano);//desde aqui se llama la funcion para ordenar las cartas y despues se lee para ver si es una corrida
    corrida(mano);
    return 1;
}

//*******************************************************************************************************

void startGame ()//funcion para la interfaz la que le pregunta si desea repetir el juego al usuario
{
    char response;
    do//un do while para que se haga la accion y despues si el usuario quiere repetir el juego se repita
    {
        genD();//funcion que genera la baraja
        hand();//funcion que toma las cartas y llama otras funciones que las ordenan y luego leen para una corrida
        printf("Desea repetir el juego?(s= si/ cualquier tecla=no)\n");//pregunta al ususario
        scanf("%s",&response);
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