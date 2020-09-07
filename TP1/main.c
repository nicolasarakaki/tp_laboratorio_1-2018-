//#include <stdio_ext.h>  //Para Linux
#include <stdio.h>      // Para Windows
#include <stdlib.h>
#include "tp1.h"

int main()
{
      //HOLA
      float numero1=0, numero2=0, suma, resta, division, multiplicacion, factorialA, factorialB, auxOpcion;
      int getNumero1, getNumero2, respuesta=0, getOpcion, opcion;

      while(respuesta!=5)
      {
          printf("\nElija una de las siguientes opciones: ");
          printf("\n\n1- Ingresar 1er operando (A=%.2f): ", numero1);
          printf("\n2- Ingresar 2do operando (B=%.2f): ", numero2);
          printf("\n3- Calcular todas las operaciones: ");
          printf("\n    Calcular la suma (A+B)");
          printf("\n    Calcular la resta (A-B)");
          printf("\n    Calcular la division (A/B)");
          printf("\n    Calcular la multiplicacion (AxB)");
          printf("\n    Calcular el Factorial(A!) y (B!)");
          printf("\n4- Informar resultados");
          printf("\n5- Salir");
          //__fpurge(stdin); // LINUX
          fflush(stdin);  // Windows

          getOpcion = tp1_getOpcionNum(&auxOpcion, "\n\nOpcion?: ", "\nError. La opcion es incorrecta", 1, 5, 3);
          if (getOpcion==-1)
          {
              printf("Intentelo mas tarde.\n");
              break;
          }
          else
          {
              opcion = auxOpcion;
          }
          switch(opcion)
          {
              case 1:
                //__fpurge(stdin); // LINUX
                fflush(stdin);  // Windows
                getNumero1 = tp1_getNumero(&numero1, "Ingrese el numero (A): ", "\nError, debe ser un numero. ", 3);
                if (getNumero1==-1)
                {
                    printf("Intentelo mas tarde.\n");
                    break;
                }
                break;

              case 2:
                  getNumero2 = tp1_getNumero(&numero2, "Ingrese el numero (B): ", "\nError, debe ser un numero. ", 3);
                  if (getNumero2==-1)
                  {
                      printf("Intentelo mas tarde.\n");
                      break;
                  }
                  break;

              case 3:
                  suma = tp1_funcionSuma(&numero1, &numero2);
                  resta = tp1_funcionResta(&numero1, &numero2);
                  division = tp1_funcionDivision(&numero1, &numero2);
                  multiplicacion = tp1_funcionMultiplicacion(&numero1, &numero2);
                  factorialA = tp1_funcionFactorial(&numero1);
                  factorialB = tp1_funcionFactorial(&numero2);
                  break;

              case 4:
                  printf("\nEl resultado de %5.2f + %5.2f es: %5.2f", numero1, numero2, suma);
                  printf("\nEl resultado de %5.2f - %5.2f es: %5.2f", numero1, numero2, resta);
                  if (division==0 && division==numero2)
                  {
                      printf("\nEl resultado de %5.2f / %5.2f es: No es posible dividir por cero", numero1, numero2);
                  }
                  else
                  {
                      printf("\nEl resultado de %5.2f / %5.2f es: %5.2f", numero1, numero2, division);
                  }

                  printf("\nEl resultado de %5.2f x %5.2f es: %5.2f", numero1, numero2, multiplicacion);

                  if (factorialA==-1)
                  {
                      printf("\nNo existe el factorial del numero %5.2f, por ser negativo o decimal", numero1);
                  }
                  else
                  {
                      printf("\nEl factorial de %5.2f es: %5.2f", numero1, factorialA);
                  }

                  if (factorialB==-1)
                  {
                      printf("\nNo existe el factorial del numero %5.2f, por ser negativo o decimal", numero2);
                  }
                  else
                  {
                      printf("\nEl factorial de %5.2f es: %5.2f\n\n", numero2, factorialB);
                  }
                  break;

              case 5:
                  respuesta=5;
                  break;
          }
      }
      return 0;
}
