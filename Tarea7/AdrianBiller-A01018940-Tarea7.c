#include <stdio.h>
#include <math.h>
#pragma warning (disable:4996)
#define PI 3.141592653589793238462643383279502

float num1, num2;//variables que se piden al usuario, son universales para poderlas utilizar en otras funciones
int opciones (char respuesta)//primera funcion de switch, esta incluye las primeras seis opciones
{
    switch (respuesta)//funcion switch en donde se lee la variable en este caso un caracter y se hace la accion que indica el caso
    {
        case 'a'://este es un caso si el caso se cumple para la variable se hace la accion de abajo
            printf("%f\n",num1+num2);
            break;//esto significa que si entra al caso, la funcion termina aqui y no se hacen el resto de las acciones
        case 'b':
            printf("%f\n", num1-num2);
            break;
        case 'c':
            printf("%f\n",num1*num2);
            break;
        case 'd':
            printf("%f\n",num1/num2);
            break;
        case 'e':
            printf("%f\n",pow(num1,num2));
            break;
        case 'f':
            printf("%f", fmodf(num1,num2));//para una variable float cambia la sintaxis para el modulo, en este caso se pone fmodf para sacar el modulo de un numero con el otro.
            break;
    }
    return 1;
}

float rad(float deg)
{
    float rad;
    rad = (PI / 180)*deg;
    return rad;
}

int opciones2 (char respuesta)//segunda funcion de las otras seis opciones de la variable
{
    switch(respuesta)
    {
        case 'g':
            printf("%f\n%f\n",sqrtf(num1),sqrtf(num2));//se utilizan sqrtf, sinf o cosf cuando se habla de una variable float
            break;
        case 'h':
            printf("%f\n%f\n",sinf(rad(num1)),sinf(rad(num2)));//funcion seno dentro de switch, se le cambia a sinf para una variable float
            break;
        case 'i':
            printf("%f\n%f\n",cosf(rad(num1)),cosf(rad(num2)));
            break;
        case 'j':
            printf("%f\n%f\n",tanf(rad(num1)),tanf(rad(num2)));
            break;
        case 'k':
            printf("%f\n%f\n",expf(num1),expf(num2));
            break;
        case'l':
            printf("%f\n%f\n",log10f(num1),log10f(num2));
            break;
        default:
            printf("\n");
            break;
    }
    
    return 1;
}

int numeros ()//funcion de la interface, en esta funcion se piden los numeros
{
    printf("Ingresa un numero menor o igual a 1,000\n");//en ambos scanf se leen los numeros ingresados por el usuario
    scanf("%f", &num1);
    printf("Ingresa otro numero menor o igual a  a 1,000\n");
    scanf("%f", &num2);
    
    if (num1>1000)//en el caso de que los numeros sean mas altos que 1000 entonces dentro de este if se hace saber eso, se borran los numeros ingresados y se piden de nuevo
    {
        printf("Tu numero es muy alto, escoge uno mas pequeño de 1000\n");
        scanf("%f", &num1);
    }
    if (num2>1000)
    {
        printf("Tu segundo numero es muy alto, escoge uno mas pequeño de 1000\n");
        scanf("%f", &num2);
    }
    return 1;
    
}

int respuestacalc()//esta funcion tambien es de la interfaz, aqui se le pide al usuario que escoja la operacion a realizar, se le pide si el usuario quiere repetir alguna operacion y si quiere cambiar de numeros
{
    char cambio;//se inician las variables de caracteres para las respuestas del usuario
    char respuesta;
    char repeticion;
    do//do while para que se hagan primero las instrucciones y despues si es que el usuario quiere volver a hacer alguna operacion entonces se repite el proceso, si es que no quiere entonces se sale del do-while y termina
    {
        printf("Que operación desea hacer?\n");
        printf(" a)Suma\n b)Resta\n c)Multiplicación\n d)Division\n e)Potencia\n f)Módulo\n");
        printf(" g)Raíz Cuadrada\n h)Seno\n i)Coseno\n j)Tangente\n k)Exponencial\n l)Logaritmo\n");
        scanf("%s", &respuesta);
        opciones(respuesta);
        opciones2(respuesta);
        printf("Desea volver a hacer una operacion?\n(si=s/no=cualquier tecla)\n");
        scanf("%s", &repeticion);
        if(repeticion =='s')//despues de preguntar si se quiere repetir la operacion se entra a este if en el cual si la respuesta del usuario es que no quiere hacer mas operaciones entonces no se imrpime si desea cambiar de numeros
        {
            printf("Desea cambiar de numeros?(si=s/no=cualquier tecla)\n");
            scanf("%s",&cambio);
            if(cambio=='s')
            {
                numeros();//si el usuario si quiere cambiar de numeros entonces se llama la funcion en la cual se le piden ingresar los numeros al usuario
            }
        }
    } while (repeticion=='s');//condicion del do-while
    exit(0);
    return 1;
}

int main ()//funcion principal en donde se llaman las funciones
{
    numeros();
    respuestacalc();
    return 1;
}