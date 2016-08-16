#include <stdio.h>

void arreglos2d ()//********************** ARREGLOS BIDIMENSIONALES*****************************    
{
    int i,j;
    int arreglo1[6] = {1,2,3,4,5,6};
    for (i=0;i<=5;i++)
    {
        printf("%d\n",arreglo1[i]);
    }
    
    int arreglo[3][2] =
    {{7,2},
        {4,6},
        {18,4}};
    for (i=0;i<3;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d\t",arreglo[i][j]);
        }
        printf("\n");
    }
    
    float sum=0;
    int numMasGrande = 0;
    for (i=0;i<3;i++)
    {
        for(j=0;j<2;j++)
        {
            if(arreglo[i][j] > numMasGrande)
            {
                numMasGrande = arreglo[i][j];
            }
            sum+=arreglo[i][j];
            
        }
        
    }
    printf("El promedio es:%.2f\n", sum/6);
    printf("El num mas grande %d\n", numMasGrande);

}


int main ()
{
    //***************************************  BUBBLESORT ***********************************
    int i, temp, j;
    int arreglo [5]={78,12,95,87,6};
    while(j<=5)
    {
        for(i=0;i<5;i++)
        {
            if (arreglo[i]>arreglo [i+1])
            {
                temp=arreglo[i];
                arreglo[i]=arreglo[i+1];
                arreglo[i+1]=temp;
            }
        }
        j++;
    }
    for(i=0;i<5;i++)
    {
        printf("%d\t", arreglo[i]);
    }
    return 1;
}