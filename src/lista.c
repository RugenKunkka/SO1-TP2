/*  
Lista enlazada
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *siguienteNodo;
} Nodo;

Nodo* crearNodo(int dato);
int insertarDato(Nodo **cabeza, int dato);
void imprimirLista(Nodo *cabeza);


int main()
{
    Nodo *cabeza = NULL;
    int res;

    insertarDato(&cabeza, 1);
    insertarDato(&cabeza, 9);
    insertarDato(&cabeza, 10);
    insertarDato(&cabeza, 12);
    imprimirLista(cabeza);

    return 0;
}

//Permite crear nodos en la lista y la llamás en realidad desde insertarDato, sería del tipo Private este método si tuviermos 
//modificadores de acceso
Nodo* crearNodo(int dato)
{
    Nodo *nuevo = NULL;

    nuevo = (Nodo*)malloc(sizeof(Nodo));
    if( nuevo != NULL)
    {
        nuevo->dato = dato;
        nuevo->siguienteNodo = NULL;
    }

    return nuevo;
}

//Inserto un nodo con un dato al principio de la lista
int insertarDato(Nodo **cabeza, int dato)
{
    Nodo* nuevo = NULL;

    nuevo = crearNodo(dato);
    if( nuevo != NULL )
    {
        nuevo->siguienteNodo = *cabeza;
        *cabeza = nuevo;
        return 1;
    }

    return 0;
}

//Te permite imprimir todos los datos que tiene la lista
void imprimirLista(Nodo *cabeza)
{
    Nodo *nodoAux = cabeza;

    while( nodoAux != NULL)
    {
        printf("%d \n", nodoAux->dato);
        nodoAux = nodoAux->siguienteNodo;
    }
}
