#include <stdio_ext.h>//LINUX
//#include <stdio.h>//WINDOWS
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"

int main()
{
    Employee employee[CANT_EMPLEADOS];
    int indiceBuscado;
    int salirPrograma=FALSE;
    int opcion;
    int opcionCase2;
    int opcionCase4;
    int i;
    int idEmployee;
    int indexEmployee;
    int cantEmpleadosSuperaProm=0;
    float promSalarioTotal;
    float auxSalarioProm;
    float salarioTotal;
    float auxSalarioTotal;

    if(initEmployees(employee, CANT_EMPLEADOS)==0)
    {
        printf("Array de empleados inicializados\n\n");
    }
    else
    {
        printf("Error en inicializacion del array\n");
    }

    do{
        opcion=menuOpcion();
        switch(opcion)
        {
            case 1:
                indiceBuscado=findEmptyIndex(employee, CANT_EMPLEADOS);
                if(indiceBuscado!=-1)
                {
                    if(addEmployee(employee, indiceBuscado, CANT_EMPLEADOS, employee->name, employee->lastName, employee->sector, employee->salary) == 0)
                    {
                        printf("\nDatos del Empleado cargados correctamente en el indice %d\n\n", indiceBuscado);
                    }
                    else
                    {
                        printf("Error de carga\n\n");
                    }
                }
                break;

            case 2:
                //system("cls");//WINDOWS
                system("clear");//LINUX
                if(utn_getInt(&idEmployee, 3, 1, CANT_EMPLEADOS,
                              "\n**MODIFICACION DE DATOS**\n\nIngrese el ID: ", "No existe el numero ingresado")==0)
                {
                    indexEmployee = findEmployeeById(employee, idEmployee, CANT_EMPLEADOS);
                    if(indexEmployee == -1)
                    {
                        printf("No se encontro el ID\n");
                    }
                    else
                    {
                        printf("\n\nID\tNOMBRE\t\tAPELLIDO\tSECTOR\tSALARIO\t\tINDEX\n");
                        printEmployees(employee,indexEmployee,CANT_EMPLEADOS);
                        printf("\nOPCIONES DE MODIFICACION: \n\n\t1. Nombre \n\t2. Apellido \n\t3. Sector \n\t4. Salario\n");
                        if(utn_getInt(&opcionCase2, 3, 1, 4, "\n\tIngrese una opcion: ", "\n\tError")==0
                           && editEmployeeData(employee, indexEmployee, CANT_EMPLEADOS, opcionCase2)==0)
                        {
                            printf("\n\tModificacion exitosa\n");
                        }
                        else
                        {
                            printf("\n\tError en la modificacion\n");
                        }
                    }
                }
                break;

            case 3:
                if(utn_getInt(&idEmployee, 3, 1, CANT_EMPLEADOS,
                            "\n**BORRAR DATOS DE EMPLEADO**\n\nIngrese el ID: ", "No existe el numero ingresado")==0
                            && removeEmployee(employee, idEmployee, CANT_EMPLEADOS)==0)
                {
                    printf("Baja exitosa\n\n");
                }
                else
                {
                    printf("Error en la baja del empleado\n\n");
                }
                break;

            case 4:
                //system("cls");//WINDOWS
                system("clear");//LINUX
                printf("**DATOS DE LOS EMPLEADOS**\n\n");

                printf("INFORME POR:\n\n");
                printf("1. Lista en orden alfabetico\n2. Total / promedio de salarios y Cant de empleados que superan el promedio");
                if(utn_getInt(&opcionCase4, 3, 1, 2, "\n\nIngrese la opcion: ", "No existe la opcion ingresada")==0)
                {
                    switch(opcionCase4)
                    {
                        case 1:
                            if(sortEmployees(employee, CANT_EMPLEADOS, 0)==0)
                            {
                                printf("\n\nID\tNOMBRE\t\tAPELLIDO\tSECTOR\tSALARIO\t\tINDEX\n");
                                for(i=0;i<CANT_EMPLEADOS;i++)
                                {
                                    if(employee[i].isEmpty==FALSE)
                                    {
                                        printEmployees(employee,i,CANT_EMPLEADOS);
                                    }
                                }
                            }
                            else
                            {
                                printf("\n\nNO HAY DATOS CARGADOS");
                            }
                            break;

                        case 2:
                            auxSalarioTotal = getTotalSalary(employee, CANT_EMPLEADOS);
                            if(auxSalarioTotal == -1)
                            {
                                printf("\nNO HAY SALARIOS");
                            }
                            else
                            {
                               salarioTotal = auxSalarioTotal;
                               printf("\nSALARIO TOTAL: $%.2f\n", salarioTotal);
                            }
                            auxSalarioProm = getAverageSalary(employee, CANT_EMPLEADOS);
                            if(auxSalarioProm == -1)
                            {
                                printf("\nNO HAY PROMEDIO\n");
                            }
                            else
                            {
                                promSalarioTotal = auxSalarioProm;
                                printf("PROMEDIO DEL SALARIO TOTAL: $%.2f\n", promSalarioTotal);
                            }
                            for(i=0;i < CANT_EMPLEADOS; i++)
                            {
                                if(employee[i].salary > promSalarioTotal && employee[i].isEmpty == FALSE)
                                {
                                    cantEmpleadosSuperaProm++;
                                }
                            }
                            printf("CANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO DEL SALARIO: %d\n", cantEmpleadosSuperaProm);
                            break;
                    }
                }
                break;
            case 9:
                salirPrograma = TRUE;
                break;

            default:
                printf("\nNO EXISTE LA OPCION, Intente nuevamente\n");
        }
        printf("\n");
        system("pause");
        system("clear");//LINUX
        //system("cls");//WINDOWS
    }while(salirPrograma==FALSE);
    return 0;
}
