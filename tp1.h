#ifndef TP1_H_INCLUDED
#define TP1_H_INCLUDED

/**
    tp1_getNumero : pide un entero al usuario y valida
    @param pNumero: puntero a numero
    @param mensaje: mensaje de solicitud de un numero
    @param mensajeError: mensaje de error del numero ingresado
    @param reintentos: cantidad de reintentos
    @return : 0 OK, -1 error.
*/
int tp1_getNumero(float* pNumero, char* mensaje, char* mensajeError, int reintentos);


/**
    tp1_getLetra : pide una letra tipo caracter al usuario y valida.
    @param pLetra: puntero a Letra
    @param mensaje: mensaje de solicitud de una letra
    @param mensajeError: mensaje de error de la letra ingresada
    @param reintentos: cantidad de reintentos
    @return : caracter
*/
char tp1_getLetra(char* pLetra, char* mensaje, char* mensajeError, int reintentos);

#endif // TP1_H_INCLUDED
