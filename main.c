#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\Usuario\Desktop\Practica_28deEnero_Pila\header.h"
//#include "PilaEst.h"
typedef struct{
   char nombre[20];
   int dni;
} templeado;

int main()
{
    char palabras[][10]={"Hola","adios","hello","goodbye"};
    templeado emps[3]={{"Maria Belen",1245},{"Sofia Micaela",235},{"Maitena Lena",928}},
                *pemp=emps;
    templeado buff;
    tpila pila;
   // char buffer[10];
    int i,r;

    crearPilaEstatica(&pila);
    for(i=0;i<3;i++){
        r=ponerEnPila(&pila, pemp,sizeof(templeado));
        if(r==-1){
            printf("NO SE PUDO EN LINEA %d",i+1);
        break;
        }
        pemp++;
    }


    for(i=0;i<4;i++){
        r=sacardePila(&pila, &buff, sizeof(buff));
        if(r){
        printf("%s %d ",buff.nombre,buff.dni);
        }
        else
            printf("  VACIA DESDE %d",i+1);
    }

    printf("\n");


    for(i=0;i<sizeof(palabras)/10;i++){
    printf("%s ",palabras[i]);

    }
   pemp=emps;
    for(i=0;i<3;i++){
        r=ponerEnPila(&pila, pemp,sizeof(templeado));
        if(r==-1){
            printf("NO SE PUDO EN LINEA %d",i+1);
        break;
        }
        pemp++;
    }

    r=verTope(&pila, &buff,sizeof(templeado));
     printf("\n");
     if(r)
     printf("\nEL TOPE ES: %s %d", buff.nombre,buff.dni);

//      printf("\nSACAR DE PILA");
//       for(i=0;i<4;i++){
//        r=sacardePila(&pila, &buff, sizeof(buff));
//        if(r){
//        printf("%s %d ",buff.nombre,buff.dni);
//        }
//        else
//            printf("  VACIA DESDE %d",i+1);
//    }

    vaciarpila(&pila);
    r=verTope(&pila, &buff,sizeof(templeado));
     printf("\n");
     if(!r){
        printf("PILA SE VACIO CON EXITO");
     }

    return 0;
}
