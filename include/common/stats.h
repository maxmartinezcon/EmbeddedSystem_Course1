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
 * @file <stats.h> 
 * @brief <Se definirán las funciones correspondientes y librerías >
 *
 * <Se van a formar los prototipos de las funciones utilizadas y las librerías, además se van a agregar descripciones de las funciones en cuestión>
 *
 * @author <Maximiliano Martínez>
 * @date <03 - octubre - 2024 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 


/**
 * @brief <Función que nos permite imprimir las medidas estadísticas>
 *
 * <Se le pasará como argumentos las diferentes medidas estadísticas>
 *
 * @param <media> <char sin signo la cual tiene el valor de la media o promedio del arreglo>
 * @param <mediana> <char sin signo la cual  contiene la mediana del  arreglo>
 * @param <valorMinimo> <char sin signo el cual contiene el valor mínimo del arreglo>
 * @param <valorMaximo> <char sin signo el cual contiene el valor maximo del arreglo>
 *
 * @return <None>
 */
void print_statistics(unsigned char media ,unsigned char mediana, unsigned char valorMinimo, unsigned char valorMaximo);

/**
 * @brief <Función que nos permitirá imprimir un arreglo de valores>
 *
 * <Se imprimiran los valores del arreglo uno a uno a traves de un ciclo for>
 *
 * @param <arr> <char sin signo el cual indica el apuntador al arreglo>
 * @param <length> <entero sin signo la cual nos indica el tamaño del arreglo>

 *
 * @return <None>
 */
void print_array(unsigned char *arr, unsigned int length);

/**
 * @brief <Encuentra la mediana del arreglo proporcionado>
 *
 * <Se le proporcionara el apuntador del arreglo para que encuentre la mediana de los datos>
 *
 * @param <arr> <char sin signo el cual indica el apuntador al arreglo>
 * @param <length> <entero sin signo la cual nos indica el tamaño del arreglo>
 *
 * @return <char sin signo que contendrá la mediana>
 */
unsigned char find_median(unsigned char *arr, unsigned int length);

/**
 * @brief <Se encontrará la media o el promedio>
 *
 * <Se usará un ciclo for para realizar la suma de todos los elementos y al final se dividirá entre su longitud>
 *
 * @param <arr> <char sin signo el cual indica el apuntador al arreglo>
 * @param <length> <entero sin signo la cual nos indica el tamaño del arreglo>
 *
 * @return <char sin signo  que tiene el promedio de los valores del arreglo>
 */
unsigned char find_mean(unsigned char *arr, unsigned int length);

/**
 * @brief <Función para encontrar el valor máximo>
 *
 * <Se buscara el valor máximo dado el arreglo>
 *
 * @param <arr> <char sin signo el cual indica el apuntador al arreglo>
 * @param <length> <entero sin signo la cual nos indica el tamaño del arreglo>
 *
 * @return <un char sin signo que será el valor máximo del arreglo>
 */
unsigned char find_maximum(unsigned char *arr, unsigned int length);

/**
 * @brief <Función para encontrar el valor mínimo>
 *
 * <Se buscara el valor mínimo dado el arreglo>
 *
 * @param <arr> <char sin signo el cual indica el apuntador al arreglo>
 * @param <length> <entero sin signo la cual nos indica el tamaño del arreglo>
 *
 * @return <un char sin signo que será el valor mínimo del arreglo>
 */
unsigned char find_minimum(unsigned char *arr, unsigned int length);

/**
 * @brief <Función para ordenar un arreglo de manera descendente>
 *
 * <Se utiliziran dos ciclos for tales que nos permitirán ordenar un arreglo del valor mayor al menor >
 *
 * @param <arr> <char sin signo el cual indica el apuntador al arreglo>
 * @param <length> <entero sin signo la cual nos indica el tamaño del arreglo>
 *
 * @return <None>
 */
void sort_array(unsigned char *arr, unsigned int length);

#endif /* __STATS_H__ */
