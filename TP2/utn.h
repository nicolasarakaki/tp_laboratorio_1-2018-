#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#include <stdio_ext.h>
//#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#define CHARACTERS_NUMBERS 64
#define STRING_MAX 4096
#define EXIT_BUFFER '\0'
#define INIT_INT_ARRAY -200
#define INIT_FLOAT_ARRAY -100.0f

/** \brief
 *  Funcion para obtener un entero por teclado en un rango, con mensajes al usuario.
 *  \param pNumero int* Direccion en memoria del numero a almacenar.
 *  \param reintentos int Cantidad de reintentos al usuario.
 *  \param minimo int Valor minimo a ingresar.
 *  \param maximo int Valor maximo a ingresar.
 *  \param mensaje char* Mensaje personalizado que solicita el dato al usuario.
 *  \param error char* Mensaje personalizado en caso de error.
 *  \return Retorna 0 si obtuvo un entero dentro del rango y -1 si no es un valor valido.
 *
 */
int utn_getInt(int* pNumero, int reintentos, int minimo, int maximo, char* mensaje, char* error);

/** \brief
 *  Funcion para obtener un flotante por teclado en un rango, con mensajes al usuario.
 *  \param pNumero float* Direccion en memoria del numero a almacenar.
 *  \param reintentos int Cantidad de reintentos al usuario.
 *  \param minimo float Valor minimo a ingresar.
 *  \param maximo float Valor maximo a ingresar.
 *  \param mensaje char* Mensaje personalizado que solicita el dato al usuario.
 *  \param error char* Mensaje personalizado en caso de error.
 *  \return Retorna 0 si obtuvo un flotante dentro del rango y -1 si no es un valor valido.
 *
 */
int utn_getFloat(float* pNumero, int reintentos, float minimo, float maximo, char* mensaje, char* error);

/** \brief
 *  Funcion para obtener una cadena de caracteres por teclado con mensajes al usuario.
 *  \param pNombre char* Direccion de memoria a almacenar la cadena ingresada por teclado.
 *  \param limite int Longitud del array de caracteres a ingresar por teclado.
 *  \param reintentos int Cantidad de reintentos al usuario.
 *  \param mensaje char* Mensaje personalizado que solicita el dato al usuario.
 *  \param error char* Mensaje personalizado en caso de error.
 *  \return Retorna 0 si obtuvo la cadena correctamente y -1 si hubo un error.
 *
 */
int utn_getString(char* pNombre, int limite, int reintentos, char* mensaje, char* mensajeError);

#endif //UTN_H_INCLUDED
