#ifndef TP1_H_INCLUDED
#define TP1_H_INCLUDED

/**
    fMath_funcionSuma : suma 2 numeros ingresados por el usuario
    @param pLetra: puntero a numero1
    @param pLetra: puntero a numero2
    @return : Resultado del calculo
*/
float fMath_funcionSuma(float* pNumero1, float* pNumero2);


/**
    fMath_funcionResta : resta 2 numeros ingresados por el usuario
    @param pLetra: puntero a numero1
    @param pLetra: puntero a numero2
    @return : Resultado del calculo
*/
float fMath_funcionResta(float* pNumero1, float* pNumero2);


/**
    fMath_funcionDivision : divide 2 numeros ingresados por el usuario
    @param pLetra: puntero a numero1
    @param pLetra: puntero a numero2
    @return : Resultado del calculo o un mensaje de error si el divisor es 0
*/
float fMath_funcionDivision(float* pNumero1, float* pNumero2);


/**
    fMath_funcionMultiplicacion : multiplica 2 numeros ingresados por el usuario
    @param pLetra: puntero a numero1
    @param pLetra: puntero a numero2
    @return : Resultado del calculo
*/
float fMath_funcionMultiplicacion(float* pNumero1, float* pNumero2);


/**
    fMath_funcionFactorial : calcula el fatorial de los 2 numeros ingresados por el usuario.
                             Valida si el numero ingresado es un entero positivo.
    @param pLetra: puntero a numero1
    @param pLetra: puntero a numero2
    @return : Resultado del calculo de los numeros por separado
*/
float fMath_funcionFactorial(float* pNumero);


#endif // TP1_H_INCLUDED
