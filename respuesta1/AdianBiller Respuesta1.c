//Adri·n Biller A01018940
//Examen parcial 2
//31 de octubre 2014
//PREGUNTA NUMERO 1
#include <stdio.h>
#pragma warning (disable:4996)


int ask()
{
    float num1, num2, num3;
    printf("Inserte el primer numero\n");
    scanf("%f", &num1);
    printf("Inserte el segundo numero\n");
    scanf("%f", &num2);
    printf("Inserte el primer numero\n");
    scanf("%f", &num3);
    mayor(num1, num2, num3);
    return 1;
}

int mayor( float n1, float n2,  float n3)
{
    if (n1 > n2)
    {
        if (n1 > n3)
        {
            printf("%f es el numero mas grande!\n", n1);
        }
    }
    if (n2 > n3)
    {
        printf("%f es el numero mas grande!\n", n2);
    }
    else
    {
        printf("%f es el numero mas grande!\n",n3);
    }
    return 1;
}

int main()
{
    ask();
    return 1;
}