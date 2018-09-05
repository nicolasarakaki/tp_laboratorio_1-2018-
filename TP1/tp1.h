#ifndef TP1_H_INCLUDED
#define TP1_H_INCLUDED

/**
    tp1_getOpcionNum : pide un numero tipo entero al usuario, entre un minimo y un maximo de opciones, y valida.
    @param pOpcion: puntero a Opcion
    @param mensaje: mensaje de solicitud de una opcion
    @param mensajeError: mensaje de error de la opcion ingresada
    @param opcionMin: limite menor de las opciones
    @param opcionMax: limite mayor de las opciones
    @param reintentos: cantidad de reintentos
    @return : numero de la opcion
*/
int tp1_getOpcionNum(float* pOpcion, char* mensaje, char* mensajeError, int opcionMin, int opcionMax, int reintentos);


/**
    tp1_getNumero : pide un entero al usuario y valida
    @param pNumero: puntero a numero
    @param mensaje: mensaje de solicitud del numero
    @param mensajeError: mensaje de error del numero ingresado
    @param reintentos: cantidad de reintentos
    @return : 0 OK, -1 error.
*/
int tp1_getNumero(float* pNumero,char* mensaje, char* mensajeError, int reintentos);

/**
    tp1_funcionSuma : suma 2 numeros ingresados por el usuario
    @param pLetra: puntero a numero1
    @param pLetra: puntero a numero2
    @return : Resultado del calculo
*/
float tp1_funcionSuma(float* pNumero1, float* pNumero2);


/**
    tp1_funcionResta : resta 2 numeros ingresados por el usuario
    @param pLetra: puntero a numero1
    @param pLetra: puntero a numero2
    @return : Resultado del calculo
*/
float tp1_funcionResta(float* pNumero1, float* pNumero2);


/**
    tp1_funcionDivision : divide 2 numeros ingresados por el usuario
    @param pLetra: puntero a numero1
    @param pLetra: puntero a numero2
    @return : Resultado del calculo o un mensaje de error si el divisor es 0
*/
float tp1_funcionDivision(float* pNumero1, float* pNumero2);


/**
    tp1_funcionMultiplicacion : multiplica 2 numeros ingresados por el usuario
    @param pLetra: puntero a numero1
    @param pLetra: puntero a numero2
    @return : Resultado del calculo
*/
float tp1_funcionMultiplicacion(float* pNumero1, float* pNumero2);


/**
    tp1_funcionFactorial : calcula el fatorial de los 2 numeros ingresados por el usuario.
                             Valida si el numero ingresado es un entero positivo.
    @param pLetra: puntero a numero1
    @param pLetra: puntero a numero2
    @return : Resultado del calculo de los numeros por separado
*/
float tp1_funcionFactorial(float* pNumero);

#endif // TP1_H_INCLUDED
