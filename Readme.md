## Laboratorio N2
# Repaso Lenguaje C
### SOI - FCEFyN - UNC


## Objetivo
Sentar las bases del lenguaje para poder comprender los temas a presentar durante el curso y poder realizar las prácticas de programación propuestas durante el semestre.


## Duración
Los temas que se enlistan a continuación son básicos de programación. Este laboratorio está diseñado para resolverse entre 6 y 8 horas.


## Actividades
1. C-strings
Realice las siguientes actividades:
   1. Obtener la **memoria ram total**, **libre** y **disponible** en *Megabytes*. A partir del archivo */proc/meminfo*. 
   1. Obtener la memoria *swap* **Ocupada**. A partir del archivo */proc/meminfo*.
   1. Crear un programa en C que imprima información referida al CPU, a partir del archivo */proc/cpuinfo*:
       - Modelo de CPU.
       - Cantidad de cores 
       - Cantidad de thread por cores.

3. Arreglos
Lea el archivo */proc/version* y copie las palabras en un arreglo dinámico.
Luego:
   1. Imprima la lista de palabras en mayúscula. 
   2. libere la memoria que haya alocado.
   
4. Estructuras

   1. Conteste las siguientes preguntas:
     - ¿Cómo utilizar typedef junto a struct? ¿Para qué sirve? Ejemplo.

     Respuesta: Sirve para crear un nuevo tipo de dato y en este caso lo vamos a usar 
     para crear un tipo de dato struct. En este caso cailita la lectura y escritura de código
     por ejemplo:
     typedef struct
	  {
   		int var1;
   		int var2;
   		char var3;
	  }tipoNuevo;
		
	  tipoNuevo a; //con esto creas una variable del tipo "tipoNuevo"
     //si no estuviera el typedef arriba, delante de struct debería de poner
     struct tipoNuevo a;

     - ¿Qué es packing and padding ?

     Respuesta: Packing es la manera que tienen de organizarce los datos de distintos tipos y tamaños dentro de una structura. 
     Se le asignan paquetes de un determinado tamaño que generalmente son del tamaño del tipo de dato más grande y se le asigna un puntero y cuando uno guarda
     datos de tamaño dispar, terminan quedando espacios de memoria sin asignar. Esto último se denomina Padding

   2. A partir de los archivos struct.h y lab2.c, asociados a este laboratorio:
     - Genere un binario a partir de dichos archivos
     - Responda las 3 preguntas que aparecen comentadas en el código.

   3. Crear una lista simplemente enlazada. Escribir función que permite agregar un nodo al final de la lista.


## ¿Qué entregar?
- Se debe trabajar en GitHub Classroom. Es necesario subir los archivos de código en C y generar y subir un archivo markdown (.md) para las respuestas.
- Se debe compilar utilizando *gcc -Wall -Werror -Pedantic*.
- Aclaración: No subir binarios ni archivos de proyectos (eg: Eclipse). Solo archivos .h y .c.
- Se recomienda ir haciendo git push incrementales al repositorio a medida que se desarrolla el trabajo.