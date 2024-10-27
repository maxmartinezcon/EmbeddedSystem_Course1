/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <Obtener parámetros estadísticos >
 *
 * <Se obtendrá valor estadísticos como lo son la media, la mediana, el valor mínimo y el valor máximo de una base de datos>
 *
 * @author <Maximiliano Martínez>
 * @date <03 - octubre - 2024 >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {
  
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};                          

  /* Other Variable Declarations Go Here */
  unsigned char media;
  unsigned char mediana;
  unsigned char valorMinimo;
  unsigned char valorMaximo;

  /* Statistics and Printing Functions Go Here */
  printf("Elementos que contiene el arreglo: \n");
  print_array(test, SIZE);
  sort_array(test,SIZE);
  printf("Elementos que contiene el arreglo ordenado de manera descendente: \n");
  print_array(test,SIZE);
  media = find_mean(test, SIZE);
  mediana = find_median(test, SIZE);
  valorMinimo = find_minimum(test, SIZE);
  valorMaximo = find_maximum(test, SIZE);
  print_statistics(media, mediana, valorMinimo, valorMaximo);
}

/* Add other Implementation File Code Here */

void sort_array(unsigned char *arr,unsigned int length){
  int i, j;
  for(i=0;i<length-1;i++){
    for(j=0;j<length-i-1;j++){
      if(arr[j]<arr[j+1]){
        unsigned char temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp; 
      }
    }
  }
}


void print_array(unsigned char *arr, unsigned int length){
  for(int i=0;i<length;i++){
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

unsigned char find_mean(unsigned char *arr, unsigned int length){
  int suma = 0;
  for(int i=0;i<length;i++){
    suma += arr[i];
  }
  return suma/length;
}

unsigned char find_median(unsigned char *arr, unsigned int length){
  int suma;
  if(length % 2 == 0){
    int midPos = length/2;
    suma = arr[midPos - 1] + arr[midPos];
    return suma/2;
  }
  else{
    int midPos = length/2 - 1;
    return arr[midPos];
  }
}

unsigned char find_minimum(unsigned char *arr, unsigned int length){
  unsigned char min = arr[0];
  for(int i=0;i<length;i++){
    if(arr[i]<min){
      min = arr[i];
    }
  }
  return min;
}

unsigned char find_maximum(unsigned char *arr, unsigned int length){
  unsigned char max = arr[0];
  for(int i=0;i<length;i++){
    if(arr[i]>max){
      max = arr[i];
    }
  }
  return max;
}

void print_statistics(unsigned char media ,unsigned char mediana, unsigned char valorMinimo, unsigned char valorMaximo){
  printf("Media: %d\n", media);
  printf("Mediana: %d\n", mediana);
  printf("Valor Mínimo: %d\n", valorMinimo);
  printf("Valor Máximo: %d\n", valorMaximo);
}