/*
**  main.c
**  TP2
**
**  Created by Orecchini Alem Stefano Mauricio on 14/08/2021.
**  Copyright © 2021 Orecchini Alem Stefano Mauricio. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFSIZE 1024 //cantidad de caracteres max q va a tener cada renglon
#define CONVERTIR_DE_KB_A_MB 1024//factor de conversion de KB MB 
/*
C-strings Realice las siguientes actividades:

Obtener la memoria ram total, libre y disponible en Megabytes. A partir del archivo /proc/meminfo.
Obtener la memoria swap Ocupada. A partir del archivo /proc/meminfo.
Crear un programa en C que imprima información referida al CPU, a partir del archivo /proc/cpuinfo:
Modelo de CPU.
Cantidad de cores
Cantidad de thread por cores.
*/

void showMemInfo();
void procesarMemInfo(char[]);
void showCpuInfo();
void showProcVersion();


int main()
{
    showMemInfo();
    showCpuInfo();
    showProcVersion();
    
    return 0;
}

void showMemInfo()
{
    printf("\n ----------MemInfo---------- \n");
    int contador=0;
    FILE *fd;
    char renglon1[BUFFSIZE];
    fd = fopen("/proc/meminfo","r");
    while(fgets(renglon1, BUFFSIZE, fd)){ //preguntarle al profe
        if(contador==1||contador==2||contador==3||contador==5){
            //tenes que encontrar el tab, tomas el renglon y recortas dsps del espacio y eso es todo
            procesarMemInfo(renglon1);
            //printf(" %s",renglon1);//%s\n
        }
        contador++;
    }
    
    fclose(fd);
    fflush (fd);
}

void procesarMemInfo(char cadena[])
{
    char delimitador[] = " ";
    
    char *token = strtok(cadena, delimitador);//es el split de Java pero con la diferencia de que no te devuelte el arreglo completo
    //si no que a construyendo el String desde que empieza el string hasta que encuentre un delimitador
    if(token != NULL){
        int contador=0;
        while(token != NULL){
            // Sólo en la primera pasamos la cadena; en las siguientes pasamos NULL
            if(contador==0){
                printf("%s",token);
            }
            if(contador==1){
                float memoria= (float)(atof(token)/CONVERTIR_DE_KB_A_MB);//castio a flotante el valor xq la division par ala conversion va a dar de pto flotante
                printf(" %.4f", memoria);//muestro solamente 4 decimales del float resultante de memoria
                printf(" MB\n");
            }
            token = strtok(NULL, delimitador);//es como si tomara el valor que sigue dsps del delimitador y asi sucesivamente hasta que 
            //encuentra null y listo
            //printf("%s","\nDsps de nullear: ");
            //printf("%s \n",token);
            contador++;
        }
    }
}

void showCpuInfo()
{
    printf("\n----------CpuInfo----------\n");
    int contador=0;
    int contadorDeTrhreads=0;
    int cantidadDeCores=0;
    FILE *fd;//Puntero a variable tipo File
    char renglon1[BUFFSIZE];
    fd = fopen("/proc/cpuinfo","r");
    while(fgets(renglon1, BUFFSIZE, fd)){ //preguntarle al profe
        if(contador==1||contador==4||contador==11){
            printf("%s",renglon1);//%s\n
        }
        if (contador==11)
        {
            cantidadDeCores=atoi(&renglon1[12]);//ya se que está en la posicion 12 entonces tomo el dato de la cant de cpus
        }
        
        contador++;
        if(strstr(renglon1, "initial apicid") != NULL){contadorDeTrhreads++;}//sería el contains de String de Java
    }
    printf("cpu threads     : %d \n",contadorDeTrhreads);//cant de hilos total
    printf("cpu threads/core: %d \n",contadorDeTrhreads/cantidadDeCores);//calculo la cant de hilos por core
    fclose(fd);
    fflush (fd);

}

void showProcVersion()
{
    printf("\n----------ProcInfo----------\n");
    FILE *fd = fopen("/proc/version","rb");
    char *ptr = (char*) malloc(1);
    int i=1;
    while(feof(fd) == 0){
        ptr = realloc(ptr,i);
        ptr[i-1] = fgetc(fd);
        i++;
    }
    fclose(fd);
    for (int j = 0; j < strlen(ptr)-1; ++j) {
        // no me deja utilizar strupr()
        printf("%c",toupper(ptr[j]));
    }
    free(ptr);
}

