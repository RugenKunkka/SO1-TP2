//hace sudo apt-get isntal gcc antes xq no te va a andar nada 
//luego hacer en configurations toca rel usr/bin/cpp y reemplazarlo por usr/bin/gcc y listo
//ctrl+shift+b buildea, luego ejecuta por terminal el ejecutable
#include <stdio.h>
#include "structs.h"

int main()
{
    const BaseData data = {
                .a = 1,
                .b = 3,
                .x = 15,
                .y = 65535,
                .c = 128,
                .z = -1,
                .d = {1,1,1}
    };

    /* Explique a que se debe los tamanios de cada una de las estructuras */

    /*
    Respuesta: Puede ser por varias cosas dependiendo del tipo de dato pero puede ser poque tienen distintas cantidades 
    y tipos de datos cada type y/o puede ser por una cuestión de padding.
    Cabe destacar qu eel tipo BaseDataPacked tiene la palabra clave packed la cual te permite poder aprovechar mejor la memoria haciendo que ocupe menos
    pero... a costa de la velocidad de acceso de la información
    */

    printf("base     struct size  %lu \n", sizeof(BaseData));
    printf("reorder  struct size  %lu \n", sizeof(ReorderData));
    printf("extended struct size  %lu \n", sizeof(ExtendedData));
    printf("packed   struct size  %lu \n\n", sizeof(BaseDataPacked));

    /* explique por que la expresion que calcula  limit y limit_aux generan el mismo resutado */
    /* hint : investigar sobre reglas de aritmetica de punteros */

    /*
    Respuesta:
    Cuando a la direccion de data le sumo el sizeof es lo mismo que hacerle un +1 ya que el +1 isgnifica que estoy 
    diciendo que muevo el puntero a "mas una" direccion de memoria del tipo data
    */
    
    char *limit = ((char *) &data + sizeof(BaseData)); 
    char *limit_aux =(char *) (&data + 1);

    printf("limit     value is %p \n", limit); 
    printf("limit_aux value is %p \n\n", limit_aux); 

    int i = 0;
    /* Explique los valores que se muestran en pantalla en cada iteracion del for */

    /*
    Respuesta:
    -Se va a imprimir en pantalla  la palabra byte + 2 valores por cada iteración
    1ro) El 1er valor es el contador i que tiene un formato indicado como "%02d" que quiere decir que va a imprimir
    con 2 decimales el valor que contenga el contador
    2do) el 2do valor es la impresion del valor de "data" que en realidad lo que se imprime es a lo que apunta un puntero
    que esta inicializado en el 1er valor da la estructura que tiene tamaño de un char y va moviendose mediante el for, byte a byte
    y va iprimiendo el contenido pero con el formato especficado en el printf que es de "%02hhx"
    */

    for (char *c = (char *) &data; c < limit; c++, i++ ){
        printf("byte %02d : 0x%02hhx \n", i, *c);
    }
}
