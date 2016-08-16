//Adrian Biller A01018940
//Examen parcial 2
//31 de octubre 2014
//respuesta 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable:4996)



int generador ()
{
    int arreglo[10];
    int a,b;
    for (a=0;a<10;a++)
    {
        b=5+rand()%11;
        arreglo[a]=b;
        printf("%d ",arreglo[a]);
    }
    escoger(arreglo);
    return 1;
}

int escoger (int a[])
{
    int num,i;
    printf("Escoja un numero");
    scanf("%d",&num);
    for (i=0;i<=10;i++)
    {
        if (a[i]==num)
            printf("tu numero si esta");
    }
    return 1;
}

int opcion ()
{
    char respuesta;
    do
    {
        generador();
        printf("Desea volver a hacerlo?\n");
        scanf("%s", &respuesta);
    }
    while  (respuesta =='s');
    return 1;
}


int main()
{
    srand (time(0));
    opcion();
    return 1;
}
