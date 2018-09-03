//#include <stdio_ext.h>  //Para Linux
#include <stdio.h>      // Para Windows
#include <stdlib.h>
#include "fMath.h"
#include "tp1.h"

int main()
{
      float numero1, numero2;
      int getNumero1, getNumero2;
      char opcion, respuesta='s';

      while(respuesta!='n')
      {
          //__fpurge(stdin); // LINUX
          fflush(stdin);  // Windows
          getNumero1 = tp1_getNumero(&numero1, "\n\nIngrese primer operando (A): ", "\nError, debe ser un numero. ", 3);
          if (getNumero1==-1)
          {
              printf("Intentelo mas tarde.\n");
              break;
          }
          getNumero2 = tp1_getNumero(&numero2, "\nIngrese segundo operando (B): ", "\nError, debe ser un numero. ", 3);
          if (getNumero2==-1)
          {
              printf("Intentelo mas tarde.\n");
              break;
          }
          printf("\nElija una de las siguientes opciones (en letra minuscula): ");
          printf("\n\nA- Calcular la suma (%5.2f + %5.2f)", numero1, numero2);
          printf("\nB- Calcular la resta (%5.2f - %5.2f)", numero1, numero2);
          printf("\nC- Calcular la division (%5.2f / %5.2f)", numero1, numero2);
          printf("\nD- Calcular la multiplicacion (%5.2f x %5.2f)", numero1, numero2);
          printf("\nE- Calcular el Factorial de %5.2f! y factorial de %5.2f!", numero1, numero2);
          //__fpurge(stdin); // LINUX
          fflush(stdin);  // Windows

          tp1_getLetra(&opcion, "\n\nOpcion: ", "\nError, la opcion es incorrecta", 3);
          switch(opcion)
          {
              case 'a':
                  fMath_funcionSuma(&numero1, &numero2);
                  break;

              case 'b':
                  fMath_funcionResta(&numero1, &numero2);
                  break;

              case 'c':
                  fMath_funcionDivision(&numero1, &numero2);
                  break;

              case 'd':
                  fMath_funcionMultiplicacion(&numero1, &numero2);
                  break;

              case 'e':
                  fMath_funcionFactorial(&numero1);
                  fMath_funcionFactorial(&numero2);
                  break;
          }

          printf("\n\nRepetir el programa? (si = s/ no = n): ");
          //__fpurge(stdin); // LINUX
          fflush(stdin);  // Windows
          scanf("%c", &respuesta);
          switch(respuesta)
          {
              case 's':
                  respuesta = 's';
                  break;

              default:
                  respuesta = 'n';
                  break;
          }
      }
      return 0;
}
