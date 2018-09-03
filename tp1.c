//#include <stdio_ext.h>  //Para Linux
#include <stdio.h>      // Para Windows
#include <stdlib.h>
#include "tp1.h"

static int getFloat(float* pResultado);

int tp1_getNumero(float* pNumero, char* mensaje, char* mensajeError,
                  int reintentos)
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

static int getChar(char* pCaracter);

char tp1_getLetra(char* pLetra, char* mensaje, char* mensajeError, int reintentos)
{
    char auxLetra;
    char retorno;
    for(; reintentos>0; reintentos--)
    {
        printf(mensaje);
        if(getChar(&auxLetra)==0)
        {
            if(auxLetra=='a' || auxLetra=='b' || auxLetra=='c' || auxLetra=='d' || auxLetra=='e')
            {
                *pLetra = auxLetra;
                retorno= *pLetra;
                break;
            }
             else
             {
                printf(mensajeError);
                //__fpurge(stdin); // LINUX
                fflush(stdin);  // Windows
             }
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

static int getChar(char* pCaracter)
{
    int retorno;
    if(scanf("%c", pCaracter) == 1)
    {
        retorno = 0;
    }
    else
    {
        retorno =-1;
    }
    return retorno;
}

