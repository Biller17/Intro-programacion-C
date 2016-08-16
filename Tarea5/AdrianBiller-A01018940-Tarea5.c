//  Tarea5
//
//Adrián Biller A01018940
//

#include <stdio.h>

int factorialdecremental (int f)
/*Esta es una función que crea factoriales ya que la formula de la combinación se necesitan tres tipos de factoriales (esta es la version decremental solo para poner ambos tipos)*/
{
    int fact = 1;//inicio de las variables
    while (f>0)
    {
        fact*= f;
        f--;
    }
    return fact;
}

int factorialincremental (int f)/*Ésta es la version incremental del factorial */
{
    int fact = 1;
    int cont = 1;//se crea un contador para poder contarse y que el while termine
    while (cont<=f)
    {
        fact*=cont;
        cont++;
    }
    return fact;
}

long combinacion (int n, int k)/*Función en la cual se llaman las funciones pasadas para calcular la combinación de dos numeros*/
{
    long fact= factorialincremental(n)/(factorialincremental(k)*factorialincremental(n-k));
    printf("%ld\t", fact);/*se hace una variable en la cual se dividen y multiplican los resultados de las funciones*/
    return fact;
}

void triangulo (int filas, int c, int columnas)
{
    while (c<=filas)//esta funcion es para crear los triangulos con base a tres variables
    {
        while (columnas<=c)
        {
            combinacion (c , columnas);/*se llama la funcion de la combinacion para ir escribiendo los numeros en triangulo*/
            columnas++;
        }
        columnas*=0;
        c++;
        printf("\n");//se imprime un enter para pasar a la siguiente linea
    }
    
}

//*****************************Triangulo Pascal While incremental****************************************


void trianguloPascalWhileincremental(int f)
{
    /*se usan tres variables para usar en tres whiles */
    int filas=1;
    int c = 0;
    int columnas=0;
    
    while (filas<=f)// se usan este while para cambiar de fila
    {
        while (c<=filas)//se usa este while para cambiar de columna
        {
            while (columnas<=c)//se usa este while para cambiar el numero de abajo de las combinaciones
            {
                combinacion (c , columnas);
                columnas++;
            }
            columnas*=0;
            c++;
            printf("\n");
        }
        filas++;
    }
}
//************************Triangulo Pascal While Decremental*************************************

void trianguloPascalWhiledecremental(int f) /*esta es la version decremental, se cambió la condicion de f y filas para acomodarse a un while decremental*/
{
    int filas=f;
    int c = 0;
    int columnas=0;
    
    while (filas>=f)
    {
        triangulo (filas, c, columnas);//esta es la funcion que crea el triangulo basado en las variables que entran
        filas--;
    }
}
//*************************Triangulo Pascal for incremental*********************************************

void trianguloPascalforincremental (int f)
{
    int filas;
    int c;
    int columnas;
    
    for (filas=f; filas<=f; filas ++)//condicion for en donde la variable se define, se condiciona y se incrementa en la misma linea
    {
        for (c=0; c<=filas; c++)
        {
            for (columnas=0;columnas<=c; columnas++)
            {
                combinacion (c , columnas);
            }
            columnas*=0;
            printf("\n");
        }
    }
}


//*************************Triangulo Pascal for decremental*********************************************
void trianguloPascalfordecremental (int f)
{
    int filas;
    int c=0;
    int columnas=0;
    
    for (filas=f; f>=filas; f--)//ciclo for en donde se define la variable se hace la condicional y se decrementa la variable
    {
        triangulo(filas, c, columnas);//se llama la funcion que crea el triangulo basado en las variables de entrada
    }
}


//**************************Triangulo Pascal Do-While incremental******************************************

void trianguloPascalDoWhileincremental (int f)
{
    int filas=1;
    int c = 0;
    int columnas=0;
    
    do
    {
        do//en las condicionales de do se hace primero la instruccion y despues se revisa la condicion
        {
            do
            {
                combinacion (c , columnas);
                columnas++;
            }
            while (columnas<=c);
            columnas*=0;
            c++;
            printf("\n");
        }
        
        while (c<=filas);//se coloca un while despues de la instruccion para revisar la condición
        filas++;
    }
    while (filas<=f);
}


//**************************Triangulo Pascal Do-While decremental******************************************

void trianguloPascalDoWhiledecremental (int f)
{
    int filas=f;
    int c = 0;
    int columnas=0;
    
    do//solo se pone un do y despues se llama la funcion en donde se crea el triangulo basandose en las variables ya definidas en esta funcón
    {
        triangulo(filas, c, columnas);
        filas--;
    }
    while (filas>=f);
}


//***************************Funcion en donde se pide el numero*****************************************
void trianguloPascal(int n)
{
    int filas;
    int c=0;
    int columnas=0;
    int numero;
    
    printf("¿De cuantas filas quieres el triangulo de Pascal? Escoge un número del 1 al 10\n");
    scanf("%d", &numero);
    

    
    for (filas=numero; numero>=filas; numero--)//ciclo for en donde se define la variable se hace la condicional y se decrementa la variable
    {
        triangulo(filas, c, columnas);//se llama la funcion que crea el triangulo basado en las variables de entrada
    }
}


//*********************************************************************************************************
int main ()//funcion principal en donde se llaman todas las funciones de los triangulos de pascal
{
    printf("*******Triangulo Pascal con while incremental*********\n");
    trianguloPascalWhileincremental(10);
    printf("\n");
    printf("******Triangulo Pascal con while decremental************\n");
    trianguloPascalWhiledecremental(10);
    printf("\n");
    printf("****+*Triangulo Pascal con for incremental***********\n");
    trianguloPascalforincremental(10);
    printf("\n");
    printf("****+*Triangulo Pascal con for decremental***********\n");
    trianguloPascalfordecremental(10);
    printf("\n");
    printf("******Triangulo Pascal con do-while incremental***********\n");
    trianguloPascalDoWhileincremental(10);
    printf("\n");
    printf("******Triangulo Pascal con do-while decremental***********\n");
    trianguloPascalDoWhiledecremental(10);
    printf("\n");
    trianguloPascal(1);
    return 1;
}