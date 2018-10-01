#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#define CANT_EMPLEADOS 1000
#define SALARIO_MAX 500000
#define CANT_SECTORES 5

#define TRUE 1
#define FALSE 0

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;


/** \brief Inicializa el programa haciendo que todas las posiciones del array sean vacios,
*           poniendo el valor de isEmpty en TRUE.
* \param list Employee* Puntero del array de Employee.
* \param len int Longitud del array.
* \return int Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL] / (0) si esta OK
*
*/
int initEmployees(Employee* list, int len);


/** \brief Muestra un menu de Opciones y le solicita al usuario una opcion.
* \return int Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL] / (0) si esta OK
*
*/
int menuOpcion(void);


/** \brief Busca una posicion en el array con isEmpty en TRUE, y devuelve el primero que encuentra.
* \param list Employee* Puntero del array de Employee.
* \param len int Longitud del array.
* \return int Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL], o devuelve en numero de la posicion si esta OK
*
*/
int findEmptyIndex(Employee* list, int len);


/** \brief Almacena en el array de Employee los valores que recibe como parametro en la primer posicion vacia.
*          El valor de isEmpty de la posicion se vuelve FALSE.
* \param list Employee* Puntero del array de Employee.
* \param index int Posicion vacia del array.
* \param len int Longitud del array.
* \param name[] char Direccion en memoria del nombre a almacenar.
* \param lastName[] char Direccion en memoria del apellido a almacenar.
* \param sector int Direccion en memoria del numero de sector a almacenar.
* \param salary float Direccion en memoria del valor a almacenar.
* \return int Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL] / (0) si esta OK
*
*/
int addEmployee(Employee* list, int index, int len, char name[], char lastName[], int sector, float salary);


/** \brief Busca en el array por numero de ID, y devuelve la posicion en el array en donde se encuentra el ID.
* \param list Employee* Puntero del array de Employee.
* \param id int Numero de ID que queremos buscar.
* \param len int Longitud del array.
* \return int Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL], o devuelve en numero de la posicion si esta OK
*
*/
int findEmployeeById(Employee* list, int id, int len);


/** \brief Busca un numero de ID y modifica los valores, segun la opcion que se elija.
* \param list Employee* Puntero del array de Employee.
* \param index int Posicion en el array del ID a modificar.
* \param len int Longitud del array.
* \param option int Numero de las opciones de la modificacion a realizar.
* \return int Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL] / (0) si esta OK.
*
*/
int editEmployeeData(Employee* list, int index, int len, int option);


/** \brief Busca el ID que se desea dar de baja, y cambia el valor isEmpty a TRUE.
* \param list Employee* Puntero del array de Employee.
* \param id int Posicion en el array del ID a dar de baja.
* \param len int Longitud del array.
* \return int Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL] / (0) si esta OK.
*
*/
int removeEmployee(Employee* list, int id, int len);


/** \brief Imprime en una lista los valores cargados en el array.
* \param list Employee* Puntero del array de Employee.
* \param index int Posicion en el array.
* \param len int Longitud del array.
* \return int Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL] / (0) si esta OK.
*
*/
int printEmployees(Employee* list, int index, int len);


/** \brief Ordena alfabeticamente y por sector en forma ascendente o descendente, de todos los valores del array.
* \param list Employee* Puntero del array de Employee.
* \param len int Longitud del array.
* \param order int Ascendente = 1  /  Descendente = 0.
* \return int Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL] / (0) si esta OK.
*
*/
int sortEmployees(Employee* list, int len, int order);


/** \brief Suma de todos los salarios cargados en el array de Employee.
* \param list Employee* Puntero del array de Employee.
* \param len int Longitud del array.
* \return int Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL] o devuelve el valor total de la suma si esta OK.
*
*/
float getTotalSalary(Employee* list, int len);


/** \brief Realiza el promedio de la suma de todos los salarios cargados en el array de Employee.
* \param list Employee* Puntero del array de Employee.
* \param len int Longitud del array.
* \return int Devuelve (-1) si es ERROR [Longitud invalida o puntero NULL] o devuelve el valor del promedio si esta OK.
*
*/
float getAverageSalary(Employee* list, int len);

#endif // ARRAYEMPLOYEES_H_INCLUDED
