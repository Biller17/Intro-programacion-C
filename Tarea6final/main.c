//Adrián Biller A01018940
//Tarea 6
#include <stdio.h>
#include <time.h>//manda a llamar otra libreria en donde se encuentra el tiempo que tiene la computadora
#include <stdlib.h>//manda a llamar otra libreria en donde se encuentran las funciones de rand

int a,b,c,d,e,f;//variables universales ya que se utilizan
int jugador1r;//  en todas las funciones haciendo mas fácil que entre una variable a la funcion
int jugador2r;


int jugador1(int a,int b,int c)//funcion en la que entran tres numeros aleatorios generados y los imprime y suma
{
    jugador1r=a+b+c;
    printf("Los dados del jugador1 fueron:\n");
    printf(" Dado1:%d\n Dado2:%d\n Dado3:%d\n",a, b,c);
    printf("La suma de los dados es: %d\n",jugador1r);
    printf("\n");
    return jugador1r;
}

int jugador2(int d, int e ,int f)//misma funcion pero entran otros tres numeros del segundo jugador
{
    jugador2r=d+e+f;
    printf("Los dados del jugador2 fueron\n");
    printf(" Dado1:%d\n Dado2:%d\n Dado3:%d\n",d,e,f);
    printf("La suma de los dados es: %d\n",jugador2r);
    printf("\n");
    return jugador2r;
}

int ganador()//funcion con un if para imprimir que jugador gana con el puntaje mas alto
{
    if(jugador1r>jugador2r)
    {
        printf("***********El jugador1 es el ganador!*************\n");
        printf("\n");
    }
    if(jugador1r<jugador2r)
    {
        printf("***********El jugador2 es el ganador!*************\n");
        printf("\n");
    }
    return 1;
}

void generador ()//funcion base, en esta primero se generan los numeros aleatorios
{//                y despues se llaman tres funciones distintas que suman e imprimen los datos
    //             y finalmente una que toma todos los datos y determina al ganador
    srand(time(0));//semilla de los numeros aleatorios
    a=1+rand()%7;//de la "a" a la "f" se utiliza la funcion rand() para simular el numero de caras del dado
    b=rand()%11;
    c=(-1)+rand()%18;
    d=1+rand()%7;
    e=rand()%11;
    f=(-1)+rand()%18;
    jugador1(a, b, c);//funcion jugador1 que suma dichos numeros del jugador1 e imprime la información
    jugador2(d, e, f);//funcion jugador que hace lo mismo pero para el jugador 2
    ganador();//funcion que toma los resultados finales de ambos jugadores y determina al ganador
}

int jugador1(int a,int b,int c)//funcion en la que entran tres numeros aleatorios generados y los imprime y suma
{
    jugador1r=a+b+c;
    printf("Los dados del jugador1 fueron:\n");
    printf(" Dado1:%d\n Dado2:%d\n Dado3:%d\n",a, b,c);
    printf("La suma de los dados es: %d\n",jugador1r);
    printf("\n");
    return jugador1r;
}

int jugador2(int d, int e ,int f)//misma funcion pero entran otros tres numeros del segundo jugador
{
    jugador2r=d+e+f;
    printf("Los dados del jugador2 fueron\n");
    printf(" Dado1:%d\n Dado2:%d\n Dado3:%d\n",d,e,f);
    printf("La suma de los dados es: %d\n",jugador2r);
    printf("\n");
    return jugador2r;
}

int ganador()//funcion con un if para imprimir que jugador gana con el puntaje mas alto
{
    if(jugador1r>jugador2r)
    {
        printf("***********El jugador1 es el ganador!*************\n");
        printf("\n");
    }
    if(jugador1r<jugador2r)
    {
        printf("***********El jugador2 es el ganador!*************\n");
        printf("\n");
    }
    return 1;
}


int main ()
{
    char respuesta;//variable char para la s que se pone al final para repetir el programa
    do//funcion do-while para que el programa corrra y si despues recibe la respuesta s se repita
    {
        generador();//llama la funcion del generador que dentro estan las demas funciones
        printf("¿Quiere volver a jugar?(s=si/n=no)\n");
        scanf("%s", &respuesta);//funcion scanf que permite al usuario escribir con el teclado, en este caso recibe un caracter que es la s de si
    }
    while( respuesta=='s');//condicion del do while
    return 1;
}