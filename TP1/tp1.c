//#include <stdio_ext.h>  //Para Linux
#include <stdio.h>      // Para Windows
#include <stdlib.h>
#include "tp1.h"

static int getInt(float* pResultado);

int tp1_getOpcionNum(float* pOpcion, char* mensaje, char* mensajeError, int opcionMin, int opcionMax, int reintentos)
{
    int retorno=-1;
    float auxOpcion;

    for (;reintentos>0;reintentos--)
    {
        printf(mensaje);
        if(getInt(&auxOpcion)==0 && auxOpcion>=opcionMin && auxOpcion<=opcionMax)
        {
            *pOpcion = auxOpcion;
            retorno = *pOpcion;
            break;
        }
        else
        {
            printf(mensajeError);
            //__fpurge(stdin); // LINUX
            fflush(stdin);  // Windows
        }
    }
    return retorno;
}

static int getInt(float* pResultado)
{
    int retorno;
    int auxResultado = *pResultado;
    float resto = *pResultado - auxResultado;

    if(scanf("%f", pResultado)==1 && resto==0)
    {
        retorno=0;
    }
    else
    {
        retorno=-1;
    }

    return retorno;
}



static int getFloat(float* pResultado);

int tp1_getNumero(float* pNumero,char* mensaje, char* mensajeError, int reintentos)
{
    int retorno = -1;
    float auxNumero;

    for (;reintentos>0;reintentos--)
    {
        printf(mensaje);
        if(getFloat(&auxNumero)==0)
        {
            *pNumero = auxNumero;
            retorno = 0;
            break;
        }
        else
        {
            printf(mensajeError);
            //__fpurge(stdin); // LINUX
            fflush(stdin);  // Windows
        }
    }
    return retorno;
}

static int getFloat(float* pResultado)
{
    int retorno;

    if(scanf("%f", pResultado) == 1)
    {
        retorno=0;
    }
    else
    {
        retorno=-1;
    }

    return retorno;
}


float tp1_funcionSuma(float* pNumero1, float* pNumero2)
{
    float resultado;
    resultado = *pNumero1 + *pNumero2;
    return resultado;
}

float tp1_funcionResta(float* pNumero1, float* pNumero2)
{
    float resultado;
    resultado = *pNumero1 - *pNumero2;
    return resultado;
}

float tp1_funcionDivision(float* pNumero1, float* pNumero2)
{
    float resultado;
    if(*pNumero2==0)
    {
        resultado = 0;
    }
    else
    {
        resultado = *pNumero1 / *pNumero2;
    }
    return resultado;
}

float tp1_funcionMultiplicacion(float* pNumero1, float* pNumero2)
{
    float resultado;
    resultado = *pNumero1 * *pNumero2;
    return resultado;
}

static int getEnteroPositivo(float* pResultado);

float tp1_funcionFactorial(float* pNumero)
{
    int resultado;
    int factorial=1;
    int i;

    if(getEnteroPositivo(pNumero)==-1)
    {
        resultado = -1;
    }
    else if(*pNumero==0)
    {
        resultado= 1;
    }
    else
    {
       for(i=1; i <= *pNumero; i++)
       {
            factorial = factorial * i;
            resultado = factorial;
       }
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


