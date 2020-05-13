#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "AuxEmployees.h"

int initEmployees(Employee* list, int len)
{
    int i; //Declaracion de variable de control del "for"

    for(i=0; i<len; i++) // Bucle "for", siendo "len" el tamaño del vector de empleados
    {
        list[i].isEmpty = 1; // Pone todas las posiciones del array de empleados del campo "isEmpty" = 1, así indicando que todas las posiciones están libres
    }

    return 0; // Valor devuelto
}
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int i; // Definición de varibale
    int state; // Definicion de variable a devolver (1 OK, -1 ERROR)
    i = findEmpty(list, len); // Guardamos en "i" el valor de la función "findEmpty"
    if(i != -1) // En caso que el valor devuelto por la función sea diferente a -1, ejecutamos la siguiente línea de código
    {
        list[i].id = id; // Guardamos en el campo "id" del array de empleados el valor almacenado en "id"
        strcpy(list[i].name, name); //Copiamos en el campo "name" del array de empleados el valor del string almacenado en "name"
        strcpy(list[i].lastName, lastName); //Copiamos en el campo "lastName" del array de empleados el valor del string almacenado en "lastName"
        list[i].salary = salary; //Copiamos en el campo "salary" del array de empleados el valor del string almacenado en "salary"
        list[i].sector = sector; //Copiamos en el campo "sector" del array de empleados el valor del string almacenado en "sector"
        list[i].isEmpty = 0; // Ponemos la bandera de estado "isEmpty" en 0 indicando que esta posicion (i) está siendo utilizada
        state = 1; // Cambiamos "state" a 1 para indicar que el empleado se cargo correctamente
    }
    else
    {
        state = -1; // En el caso que el array de empleados esté lleno y no se haya podido cargar el empleado cambiamos "state" a -1 (error)
    }

    return state; // Devolvemos el valor de "state"
}
int findEmployeeById(Employee* list, int len,int id)
{
    int i; // Variable de control para la estructura "for"
    int flag; // Variable de estado y retorno
    for(i=0; i<len; i++) // Bucle "for" para recorrer el array de empleados
    {
        if(id == list[i].id && list[i].isEmpty == 0) // En el caso que el id ingresado por el usuario sea igual a alguno de los id almacenados en el array y que esa posición no esté dada de baja, ejecutamos la siguiente línea de código
        {
            flag = i; // Guardamos la posición de memoria en flag
            break; // Una vez encontramos el valor detenemos la ejecución del bucle
        }
        else
        {
            flag = -1; // En el caso que ninguno de los id del array coincidiera con el id ingresado por teclado, cambiamos el estado de "flag" = -1
        }
    }

    return flag; // Retornamos el valor de "flag"
}
int removeEmployee(Employee* list, int len, int id)
{
    int i; // Variable de control para la estructura "for"
    int decition; // Variable de control para la confirmación de baja
    int flag = 0; // Variable de control para indicar si se dió de baja

    i = findEmployeeById(list, len, id); // Llamada de la función la cual nos devuelve la posición en el array sobre dicho ID
    if(i != -1) // En caso de este valor ser diferente a -1 (error) ejecutamos el siguiente bloque
    {
        system("CLS"); // Limpiamos pantalla
        printOneEmployee(list, list[i].id, len); //Imprimimos los datos del usuario a dar de baja del sistema
        printf("\nDesea darlo de baja? \n1-Si\n2-No\nUsted ingreso: "); // Imprimimos por pantalla consultando la reconfirmación
        scanf("%d", &decition); // Tomamos el ingreso por teclado
        if(decition == 1) //En caso de que la opción sea = 1 damos de baja al empleado
        {
            flag = 0; // Indicamos "flag = 0" diciendo que la baja está "OK"
            list[i].isEmpty = 1; // Indicamos el estado en 1 para "lugar libre"
        }
        else
        {
            flag = -1; // En caso de no haberse dado de baja cambiamos el valor de flag a -1
        }
    }
    else
    {
        flag = -1; // En caso de no encontrar dicho ID en sistema cambiamos el valor de flag a -1
        system("CLS"); // Limpiamos pantalla
        printf("No se encontro en el sistema ese ID\n"); //Mostramos por mensaje el error
        system("PAUSE"); // Pausamos la ejecución del programa
    }
    return flag; // Retornamos el valor de flag
}
int sortEmployees(Employee* list, int len, int order)
{
    int i; // Variable de control para la estructura "for"
    int j; // Variable de control para la estructura "for"
    Employee auxEmployee[len]; // Definimos una variable auxiliar de estructuras para el ordenamiento

    for(i=0; i<len-1; i++) // Declaración del for donde vamos a recorrer el vector hasta la anteúltima posición
    {
        for(j=i+1; j<len; j++) // Declaración del segundo for donde vamos a recorrer todo el vector
        {
            if(order == 1) // En caso de que se haya ingresado 1 el orden sera cresciente
            {
                if(list[i].sector>list[j].sector) // Ordenamos los sectores ordenados
                {
                    auxEmployee[i] = list[i]; // Swap de variable
                    list[i] = list[j]; // Swap de variable
                    list[j] = auxEmployee[i]; //Swap de variable
                }
                else if(list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName)>0) // EN caso que los sectores sean iguales, utilizamos el segundo criterio de ordenamiento, por apellido
                {
                    auxEmployee[i] = list[i];// Swap de variable
                    list[i] = list[j];// Swap de variable
                    list[j] = auxEmployee[i];// Swap de variable
                }
            }
            else if(order == 0) // En caso de haber ingresado 0 el orden sera decresciente
            {
                if(list[i].sector<list[j].sector)// Ordenamos los sectores ordenados
                {
                    auxEmployee[i] = list[i];// Swap de variable
                    list[i] = list[j];// Swap de variable
                    list[j] = auxEmployee[i];// Swap de variable
                }
                else if(list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName)<0)// EN caso que los sectores sean iguales, utilizamos el segundo criterio de ordenamiento, por apellido
                {
                    auxEmployee[i] = list[i];// Swap de variable
                    list[i] = list[j];// Swap de variable
                    list[j] = auxEmployee[i];// Swap de variable
                }
            }
        }
    }
    return 0;
}
int printEmployees(Employee* list, int length)
{
    int i; // Variable de control para la estructura "for"

    printf("ID\tNOMBRE\tAPELLIDO\t\tSALARIO\t\tSECTOR\n"); //Imprimo por pantalla los campos del empleado
    for(i=0; i<length; i++) // Definimos la estructura for
    {
        if(list[i].isEmpty == 0) // En el caso de que el valor de la bandera sea 0, indica que hay un valor cargado en esa posición
        {
            printf("%d\t%s\t%s\t\t%.2f\t\t%d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector); // En caso de el valor ser 0 imprimimos los datos del empleado
        }
    }
    return 0; // Al finalizar la ejecución devolvemos un 0 "OK"
}

