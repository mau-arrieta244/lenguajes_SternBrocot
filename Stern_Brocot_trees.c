/*
Proyecto Arboles Stern-Brocot
Lenguajes de programación

Mauricio Arrieta 
Taylor Hernandez
Valeria Prado
Andres Valverde
*/
#include <stdio.h>
#include <stdlib.h>

//para almacenar fracciones
typedef struct
{
    int numerador, denominador;
}fraction;

//recibe un entero, imprime la sucesion de stern-brocot, hasta longitud = n
void sucesion(int n){
    int listaSucesion[n];
    int *ptr = listaSucesion;
    int actual = 0;
    int siguiente = 1;
    
    listaSucesion[0] = 1;
    listaSucesion[1] = 1;

    int i;
    for(i=2;i<=n;i+=2){
        listaSucesion[i] = listaSucesion[actual]+listaSucesion[siguiente];
        listaSucesion[i+1] = listaSucesion[siguiente];
        actual++;
        siguiente++;
    }
    // display
    int a;
    int len = sizeof(listaSucesion)/sizeof(listaSucesion[0]);
    for (int a=0; a<len; a++) {
     printf("%d ", listaSucesion[a]);
  }
  //return ptr;

};

//arreglo lista se pasa como puntero al primer elemento
//recibe una lista de enteros y devuelve fracciones de los elementos sucesivos
//ej: {1,3,4,8} -> {1/3 , 3/4 , 4/8}
void crearFracciones(int lista[],int len){
    fraction listaFracciones[len/2];
    fraction *ptr = listaFracciones;
    int i;
    
    for(i=0;i<len-1;i++){
        printf("%d / %d \n",lista[i],lista[i+1]);
    }
    /*
    for(int k=0;k<len/2;k++){
        fraction f;
        f.numerador = lista[k];
        f.denominador = lista[k+1];
        printf("%d / %d \n",f.numerador,f.denominador);
        listaFracciones[k] = f;
    }*/

}


double calcular_fraccion(fraction b)
{
    return((double)b.numerador / b.denominador);
}

void ordenarFracciones(fraction lista[],int len){   
    
    fraction tmp;

    int f;
    for(f=0;f<len;f++){
        printf("elemento: %d / %d \n",lista[f].numerador,lista[f].denominador);
        
    }
    printf("\n\n-------------------------\n\n");

    int min,j;
    for (int k = 0; k < len; k++)
    {
        min = k;
        for (j = k + 1; j < len; j++)
        {
            if (calcular_fraccion(lista[j]) < calcular_fraccion(lista[min]))
            {
                min = j;
            }
        }
        tmp = lista[k];
        lista[k] = lista[min];
        lista[min] = tmp;
    }

    int z;
    for(z=0;z<len;z++){
        printf("elemento: %d / %d \n",lista[z].numerador,lista[z].denominador);
    }
    
    }



void main(){
    fraction a,b,c;
    a.numerador = 1;
    a.denominador = 3;

    b.numerador=3;
    b.denominador=2;

    c.numerador = 2;
    c.denominador = 3;
    fraction list[] = {a,b,c};
    int n = sizeof(list)/sizeof(list[0]);
    //ordenarFracciones(list,n);
    //sucesion(10);
    
    
};


