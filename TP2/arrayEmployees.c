#include <stdio_ext.h>//LINUX
//#include <stdio.h>//WINDOWS
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"


/** \brief Genera un numero de ID que es irrepetible.
* \return int Devuelve el valor del numero ID.
*
*/
static int getEmployeeID(void);


int initEmployees(Employee* list, int len)
{
    int i;
    int retorno=-1;
    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            (list+i)->isEmpty= TRUE;
        }
        retorno=0;
    }
    return retorno;
}

int menuOpcion(void)
{
    int auxInt;
    int retorno=-1;

    printf(" MENU DE OPCIONES\n ");
    printf(" 1. Alta de Empleados\n ");
    printf(" 2. Modificar datos de Empleados\n ");
    printf(" 3. Baja de Empleados\n ");
    printf(" 4. Informe\n ");
    printf(" 9. SALIR del programa\n ");
    if(utn_getInt(&auxInt,3,1,9,"\nIndique la Opcion deseada: ","Seleccion no valida. ")==0)
    {
        retorno=auxInt;
    }
    return retorno;
}

int findEmptyIndex(Employee* list, int len)
{
    int retorno=-1;
    int index;
    if(list!=NULL && len>0)
    {
        for(index=0;index<len;index++)
        {
            if(list[index].isEmpty==TRUE)
            {
                retorno = index;
                break;
            }
        }
    }
    return retorno;
}

static int getEmployeeID(void)
{
    static int ID=0;
    ID++;
    return ID;
}

int addEmployee(Employee* list, int index, int len, char name[], char lastName[], int sector, float salary)
{
    int retorno=-1;
    Employee auxList;

    if(list!=NULL && index>=0 && index<len)
    {
        if(utn_getString(auxList.name, 51, 3, "\nEscriba el nombre: ", "Error, intente nuevamente ") == 0
        && utn_getString(auxList.lastName, 51, 3, "Escriba el apellido: ", "Error intente nuevamente") == 0
        && utn_getInt(&auxList.sector, 3, 0, CANT_SECTORES, "Ingrese el numero de sector: ", "Error\n") == 0
        && utn_getFloat(&auxList.salary, 3, 0.1, SALARIO_MAX, "Ingrese el salario: ", "Error\n") == 0)
        {
            list[index] = auxList;
            list[index].id = getEmployeeID();
            list[index].isEmpty = FALSE;
            retorno = 0;
        }
    }
    return retorno;
}

int findEmployeeById(Employee* list, int id, int len)
{
    int i;
    int retorno=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==FALSE && list[i].id==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int editEmployeeData(Employee* list, int index, int len, int option)
{
    int retorno=-1;
    Employee auxList;

    if(list!=NULL && index>=0 && index<len)
    {
        switch(option)
        {
            case 1:
                if(utn_getString(auxList.name, 51, 3, "\nEscriba nuevo nombre: ", "Error, intente nuevamente ") == 0)
                {
                    strcpy(list[index].name, auxList.name);
                    retorno = 0;
                }
                break;

            case 2:
                if(utn_getString(auxList.lastName, 51, 3, "Escriba nuevo apellido: ", "Error intente nuevamente") == 0)
                {
                    strcpy(list[index].lastName, auxList.lastName);
                    retorno = 0;
                }
                break;

            case 3:
                if(utn_getInt(&auxList.sector, 3, 0, CANT_SECTORES, "Ingrese nuevo numero de sector: ", "Error\n") == 0)
                {
                    list[index].sector = auxList.sector;
                    retorno = 0;
                }
                break;

            case 4:
                if(utn_getFloat(&auxList.salary, 3, 0.1, SALARIO_MAX, "Ingrese nuevo salario: ", "Error\n") == 0)
                {
                    list[index].salary = auxList.salary;
                    retorno = 0;
                }
                break;

            default:
                printf("NO EXISTE LA OPCION, Intente nuevamente");
        }
    }
    return retorno;
}

int removeEmployee(Employee* list, int id, int len)
{
    int retorno=-1;
    int index = findEmployeeById(list, id, len);
    if(index == -1)
    {
        printf("No se encontro el ID\n");
    }
    else
    {
        list[index].isEmpty=TRUE;
        retorno=0;
    }
    return retorno;
}

int printEmployees(Employee* list, int index, int len)
{
    int retorno=-1;
    if(list!=NULL && index<len)
    {
        printf("%d\t%s\t\t%s\t\t%d\t$%.2f\t\t%d\n",
               list[index].id, list[index].name, list[index].lastName, list[index].sector, list[index].salary, index);
        retorno=0;
    }
    else
    {
        printf("Error al imprimir los datos de pantalla \n");
    }
    return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
    int retorno=-1;
    Employee auxlist;
    int i,j;
    if(list!=NULL)
    {
        for(i=0; i < len - 1; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                continue;
            }
            for(j=i+1; j < len; j++)
            {
                if(list[j].isEmpty == TRUE)
                {
                    continue;
                }
                if((order==0 && strcmp(list[j].lastName, list[i].lastName)<0)
                    || (order==1 && strcmp(list[j].lastName, list[i].lastName) > 0))
                {
                    auxlist = list[j];
                    list[j] = list[i];
                    list[i] = auxlist;
                }
                else if(strcmp(list[j].lastName, list[i].lastName) == 0)
                {
                    if((order==0 && list[j].sector < list[i].sector) || (order==1 && list[j].sector > list[i].sector))
                    {
                        auxlist = list[j];
                        list[j] = list[i];
                        list[i] = auxlist;
                    }
                }
            }
        }
    retorno = 0;
    }
    return retorno;
}

float getTotalSalary(Employee* list, int len)
{
    int retorno=-1;
    int i;
    float totalSalary=0;
    for(i=0;i < len; i++)
    {
        if(list[i].isEmpty == FALSE)
        {
            totalSalary = totalSalary + list[i].salary;
            retorno = totalSalary;
        }
    }
    return retorno;
}

float getAverageSalary(Employee* list, int len)
{
    int i;
    float totalSalary = 0;
    int activeEmployee = 0;

    for(i=0;i < len; i++)
    {
        if(list[i].isEmpty == FALSE)
        {
            totalSalary = totalSalary + list[i].salary;
            activeEmployee++;
        }
    }
    if(activeEmployee == 0)
    {
        return -1;
    }
    return (totalSalary / (float)activeEmployee);
}
