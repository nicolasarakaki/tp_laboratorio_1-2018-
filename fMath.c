//#include <stdio_ext.h>  //Para Linux
#include <stdio.h>      // Para Windows
#include <stdlib.h>
#include "fMath.h"

float fMath_funcionSuma(float* pNumero1, float* pNumero2)
{
    float resultado;
    resultado = *pNumero1 + *pNumero2;
    printf("\nEl resultado de A+B es: %5.2f", resultado);
    return resultado;
}

float fMath_funcionResta(float* pNumero1, float* pNumero2)
{
    float resultado;
    resultado = *pNumero1 - *pNumero2;
    printf("\nEl resultado de A-B es %5.2f", resultado);
    return resultado;
}

float fMath_funcionDivision(float* pNumero1, float* pNumero2)
{
    float resultado;
    if(*pNumero2==0)
    {
        printf("\nNo es posible la division por cero");
    }
    else
    {
        resultado = *pNumero1 / *pNumero2;
        printf("\nEl resultado de A/B es: %5.2f", resultado);
    }
    return resultado;
}

float fMath_funcionMultiplicacion(float* pNumero1, float* pNumero2)
{
    float resultado;
    resultado = *pNumero1 * *pNumero2;
    printf("\nEl resultado de AxB es: %5.2f", resultado);
    return resultado;
}

static int getEnteroPositivo(float* pResultado);

float fMath_funcionFactorial(float* pNumero)
{
    int resultado;
    int factorial=1;
    int i;

    if(getEnteroPositivo(pNumero)==-1)
    {
        printf("\nNo existe el factorial del numero %.2f, por ser negativo o fraccion", *pNumero);
    }
    else if(*pNumero==0)
    {
        resultado= 1;
        printf("\nEl factorial de %.2f es: %d ", *pNumero , resultado);
    }
    else
    {
       for(i=1; i <= *pNumero; i++)
       {
            factorial = factorial * i;
            resultado = factorial;
       }
       printf("\nEl factorial de %.2f es: %d ", *pNumero , resultado);
    }
    return resultado;
}

static int getEnteroPositivo(float* pResultado)
{
    int retorno;
    int auxResultado = *pResultado;
    float resto = *pResultado - auxResultado;

    if(*pResultado >= 0 && resto==0)
    {
        retorno=0;
    }
    else
    {
        retorno=-1;
    }

    return retorno;
}

