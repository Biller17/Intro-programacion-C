//Adrian Biller A01018940
//Eamen segundo parcial
//Respuesta 2

#include <stdio.h>

int inicial ()
{
    int arreglo [1000];
    int i;
    int numero=1;
    for (i=0;i<=999;i++)
    {
        arreglo[i]=numero;
        numero++;
    }
    desplegar(arreglo);
    return 1;
}

int desplegar (int a[])
{
    int i;
    for (i=999;i>=0;i--)
    {
        printf("%d\n",a[i]);
    }
    return 1;
}

int main()
{
    inicial();
}