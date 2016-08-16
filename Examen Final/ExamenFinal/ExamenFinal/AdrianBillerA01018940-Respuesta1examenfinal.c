//Examen final
// 28 de Noviembre de 2014
// Adrian Biller Alcántara A01018940
//
            //                              PRIMERA PREGUNTA
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void incisoA ()
{
    puts("1. Pedir al usuario el nivel de la ecuacion a realizar ");
    puts("     1.1 Utilizar la ecuacion correspondiente del nivel pedido ");
    puts("2. Pedir el numero de variables que se desean utilizar dentro de la ecuacion");
    puts("  2.2 Utilizar la ecuacion que utilice el numero de variables que el usuario ha pedido");
    puts("3. Pedir al usuario los valores de la ecuacion a, b, c, d y e dependiendo del numero de valores pedidos anteriormente");
    puts("4. Pedir al usuario la incognita, o X que desea que sea sustituida en su ecuacion ");
    puts("5. Sustituir los valores ya guardados dentro de la ecuacion");
    puts("6. Resolver la ecuacion");
    puts("7. Imprimir el resultado de la ecuacion");
}

void incisoB ()
{
    puts("Inicio");
    puts("      *************************FUNCION********************");
    puts("      If (variables=1)");
    puts("          Utilizar ecuacion seleccionada con 1 variables");
    puts("          Pedir al usuario la variable que desea en su ecuacion");
    puts("      If (variables =2)");
    puts("          Utilizar ecuacion seleccionada con 2 variables");
    puts("          Pedir al usuario las variables que desea en su ecuacion");
    puts("      If (variables=3)");
    puts("          Utilizar ecuacion seleccionada con 3 variables");
    puts("          Pedir al usuario las variables que desea en su ecuacion");
    puts("      If (variables=4)");
    puts("          Utilizar ecuacion seleccionada con 4 variables");
    puts("          Pedir al usuarios la variables que desea en su ecuacion");
    puts("      If (variables=5)");
    puts("          Utilizar ecuacion seleccionada con 5 variables");
    puts("          Pedir al usuario las variables que desea en su ecuacion");
    puts("**************************Fin funcion**********************");
    puts("Que nivel desea que sea su ecuacion?");
    puts("  If (nivel=1)");
    puts("      utilizar ecuacion nivel1 ");
    puts("      print 'Cuantas variables desea en su ecuacion?'  ");
    puts("      FUNCION con el numero de variables ingresadas");
    puts("  if (nivel=2)");
    puts("      utilizar ecuacion nivel 2 ");
    puts("      print 'Cuantas variables desea en su ecuacion?'  ");
    puts("      FUNCION con el numero de variables ingresadas");
    puts("  if (nivel=3)");
    puts("      utilizar ecuacion nivel 3 ");
    puts("      print 'Cuantas variables desea en su ecuacion?'  ");
    puts("      FUNCION con el numero de variables ingresadas");
    puts("  if (nivel=4)");
    puts("      utilizar ecuacion nivel 4 ");
    puts("      print 'Cuantas variables desea en su ecuacion?'  ");
    puts("      FUNCION con el numero de variables ingresadas");
    puts("Sustituir los valores dentro de la ecuacion que ya se ha formado");
    puts("Resolver ecuacion");
    puts("Imprimir resultado de la ecuacion");
}

int nivelEcuacion (int r)
{
    float a,b,c,d,e,x;
    switch(r)
    {
        case 1:
            puts("Ha escogido la ecuacion de primer grado");
            puts("Ingrese los valores de su ecuacion en orden (a,b,x)");
            scanf("%f %f %f",&a,&b, &x);
            printf("su ecuacion es %f(%f)+%f:",a,x,b);
            printf("El resultado es %f", (a*x)+b);
            break;
        case 2:
            puts("Ha escogido la ecuacion de segundo grado");
            puts("Ingrese los valores de su ecuacion en orden (a,b,c,x)");
            scanf("%f %f %f %f",&a,&b,&c,&x);
            printf("su ecuacion es %f(%f)^2+%f(%f)+%f:",a,x,b,x,c);
            printf("El resultado es %f", (pow((a*x),2))+(b*x)+c);
            break;
        case 3:
            puts("Ha escogido la ecuacion de tercer grado");
            puts("Ingrese los valores de su ecuacion en orden (a,b,c,d,x)");
            scanf("%f %f %f %f %f",&a,&b,&c,&d,&x);
            printf("su ecuacion es %f(%f)^3+(%f(%f))^2+%f(%f)+%f:",a,x,b,x,c,x,d);
            printf("El resultado es %f", (pow((a*x),3))+(pow((b*x),2))+(c*x)+d);
            break;
        case 4:
            puts("Ha escogido la ecuacion de cuarto grado");
            puts("Ingrese los valores de su ecuacion en orden (a,b,c,d,e,x)");
            scanf("%f %f %f %f %f %f",&a,&b,&c,&d,&e,&x);
            printf("su ecuacion es (%f(%f))^4+(%f(%f))^3+(%f(%f))^2+(%f(%f)+%f:",a,x,b,x,c,x,d,x,e);
            printf("El resultado es %f", pow((a*x),4)+(pow((b*x),3))+pow((c*x),2)+(d*x)+e);
            break;
        default:
            puts("Lo siento, su respuesta es invalida");
    }
    return 1;
}

void inicio ()
{
    incisoA();
    incisoB();
    int respuesta;
    puts("De que nivel desea que sea su ecuacion? del 1 al 4");
    scanf("%d",&respuesta);
    nivelEcuacion(respuesta);
}


int main ()
{
    inicio();
    return 1;
}