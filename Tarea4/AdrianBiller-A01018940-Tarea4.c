//Adrián Biller A01018940

#include <stdio.h>//incluye la libreria

double suma (m)//esta funcion es de la primera parte
{
    int n = 1;//se pone n inicialmente como 1 ya que se tiene que multiplicar
    double sumatoria = 0;//double se pone ya que la variable de sumatoria va a llegar a ser un numero muy grande
    while (n<=m)//el numero que se designe en el main sera el que termine aqui dando por regla que sea menor o igual
    {
        sumatoria += (n*n*n); //esta formula es para calcular la sumatoria de cubos hasta el numero n
        n++;
    }
    return sumatoria;//regresa el valor de la sumatoria
}

double fact (int n, int k)//esta es la función de la segunda parte, comienzo poniendo dos variables n y k
{
	double fact;//esta es la variable del resultado final de la función
	double factn = 1;//esta es la variable del factorial de n
	double factk = 1;//esta es la variable del factorial de k
	double factresta = 1;//esta es la variable del factorial de la resta de n-k
	int resta = n-k;//inmediatamente se resta n y k ya que no es necesario ponerlo dentro del while
	
	while (n>0)//un loop para que corra hasta que n sea cero y termine la función, en este caso la regla es n mayor a cero porque este debe ser más grande que k y la resta de n-k entonces el while termina cuando este es cero.
	{
		factn *= n;//manera mas corta de escribir fact = fact * n
		n--;//manera más corta de escribir n= n - 1
        
		if (k>0)//ya que k debe ser menor o igual a n entonces se coloca despues para no afectar que corra el while pero tambien esta en un if para que cuando llegue a cero ya no se multiplique mas
		{
			factk *= k;//manera mas corta de escribir factk = factk * k
			k--;//manera mas corta de escribir k = k - 1
		}
        
		if (resta>0)//igual con la resta que debe ser menor a n se pone un if para que ya no se toque cuando corra el while de nuevo
		{
			factresta *= resta;//manera mas corta de escribir factresta = factresta * resta
			resta--;//manera más corta de escribir resta = resta - 1
		}
	}
	fact = factn/(factresta*factk);//después de haber conseguido todos los factoriales, se colocan en la formula para conseguir fact.
	return fact;//regresa fact y muestra que no hay errores
}

int main ()
{
    printf("***********Parte uno: Sumatorias del cubo******************\n");
    printf("Resultado de la sumatoria de numeros hasta 5 elevados al cubo: %f\n",suma(5));//imrpimen el restultado y al mismo tiempo llama la funcion asignandole valor a la primera variable
    printf("Resultado de la sumatoria de numeross hasta 33 elevados al cubo: %f\n", suma(33));
    printf("Resultado de la sumatoria de numeros hasta 100 elevados a cubo:%f\n",suma(100));
    printf("Resultado de la sumatoria de numeros hasta 442 elevados al cubo:%f\n",suma(442));
    printf("Resultado de la sumatoria de numeros hasta 3456 elevados al cubo: %f\n",suma(3456));
    
    
    printf("**********************Parte dos: Factoriales*******************\n");
    printf("Resultado de combinaciones de 8 en 10 = %f\n",fact(10,8));//imprimen el resultado de los factoriales y al mismo tiempo llaman la funcion nombrando las dos primeras variables n y k
    printf("Resultado de combinaciones de 8 en 21 = %f\n",fact(21,8));
    printf("Resultado de combinaciones de 8 en 35 = %f\n",fact(35,8));
    printf("Resultado de combinaciones de 8 en 46 = %f\n",fact(46,8));
    printf("Resultado de combinaciones de 8 en 68 = %f\n",fact(68,8));
    
    return 1;//regresa un valor de que no da error
    
}


