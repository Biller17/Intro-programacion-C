//Respuesta 2
//Adrian Biller A01018940
//Examen final 28 de noviembre de 2014

#include <stdio.h>

int puntosEquipos [10][3]=
        {{11,6,1},
        {4,8,6},
        {8,4,6},
        {4,9,5},
        {10,3,5},
        {3,10,5},
        {12,6,0},
        {9,4,5},
        {6,11,1},
        {6,12,0}};
int a,b,c,d,e,f,g,h,i,j,k;
int equipos [10];
int eq[10]={1,2,3,4,5,6,7,8,9,10};
int lectorEquipo (int i,int j)
{
    switch (i)
    {
        case 0:
            printf("El equipo Dragones tiene %d victorias\n",(puntosEquipos[i][j])+(puntosEquipos[i][j+2]));
            equipos[0]=(puntosEquipos[i][j])+(puntosEquipos[i][j+2]);
        break;
        case 1:
            printf("El equipo Unicornios tiene %d victorias\n",(puntosEquipos[i][j])+(puntosEquipos[i][j+2]));
            equipos[1]=(puntosEquipos[i][j])+(puntosEquipos[i][j+2]);

            break;
        case 2:
            printf("El equipo Hechiceros tiene %d victorias\n",(puntosEquipos[i][j])+(puntosEquipos[i][j+2]));
            equipos[2]=(puntosEquipos[i][j])+(puntosEquipos[i][j+2]);
            break;
        case 3:
            printf("El equipo Trolls tiene %d victorias\n",(puntosEquipos[i][j])+(puntosEquipos[i][j+2]));
            equipos[3]=(puntosEquipos[i][j])+(puntosEquipos[i][j+2]);

            break;
        case 4:
            printf("El equipo Dinosaurios tiene %d victorias\n",(puntosEquipos[i][j])+(puntosEquipos[i][j+2]));
            equipos[4]=(puntosEquipos[i][j])+(puntosEquipos[i][j+2]);
            break;
        case 5:
            printf("El equipo Orcos tiene %d victorias \n",(puntosEquipos[i][j])+(puntosEquipos[i][j+2]));
            equipos[5]=(puntosEquipos[i][j])+(puntosEquipos[i][j+2]);

            break;
        case 6:
            printf("El equipo Elfos tiene %d victorias \n",(puntosEquipos[i][j])+(puntosEquipos[i][j+2]));
            equipos[6]=(puntosEquipos[i][j])+(puntosEquipos[i][j+2]);

            break;
        case 7:
            printf("El equipo Grifos tiene %d victorias\n",(puntosEquipos[i][j])+(puntosEquipos[i][j+2]));
            equipos[7]=(puntosEquipos[i][j])+(puntosEquipos[i][j+2]);

            break;
        case 8:
            printf("El equipo Brujos tiene %d victorias\n",(puntosEquipos[i][j])+(puntosEquipos[i][j+2]));
            equipos[8]=(puntosEquipos[i][j])+(puntosEquipos[i][j+2]);

            break;
        case 9:
            printf("El equipo Quimeras tiene %d victorias\n",(puntosEquipos[i][j])+(puntosEquipos[i][j+2]));
            equipos[9]=(puntosEquipos[i][j])+(puntosEquipos[i][j+2]);
            break;
    }
    return 1;
}
void lectorVictorias ()
{
    int i;
    int j=0;
    for(i=0;i<10;i++)
    {
        lectorEquipo(i,j);
    }
}
void ordenarEquipos ()
{
    int i, temp, j,k;
    while(j<=10)
    {
        for(i=0;i<10;i++)
        {
            if (equipos[i]>equipos [i+1])
            {
                temp=equipos[i];
                k=eq[i];
                equipos[i]=equipos[i+1];
                eq[i]=eq[i+1];
                equipos[i+1]=temp;
                eq[i+1]=k;
                
            }
        }
        j++;
    }
}
int main ()
{
    lectorVictorias();
    return 1;
}