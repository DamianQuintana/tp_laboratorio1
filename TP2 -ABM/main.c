#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayEmployees.h" // Inclusion de la librearia creada "ArrayEmployees"
#include "AuxEmployees.h" // Inclusion de la librearia auxiliar creada "AuxEmployees",
#define TAML 1000// Definición del tamaño del vector de empleados


int main()
{
    Employee list[TAML];  // Declaración del array de estructura de empleados
    int position; // Variable utilizada para almacenar la posición de memoria del primer array libre
    int contadorID=0; // Variable utilizada para incremetar cada vez que se de alta un empleado en el sistema
    int id; // Variable que se utiliza para guardar el valor de id ingresado por teclado
    char name[51]; // Variable utilizada para guardar el nombre del empleado
    char lastName[51]; // Variable utilizada para guardar el apellido del empleado
    float salary; // Variable utilizada para guardar el salario del empleado
    int sector; // Variable utilizada para guardar el sector del empleado
    int control; // Variable utilizada como control para guardar el valor devuelto por funciones
    int sort; // Varibale utilizada para guardar la opción de ordenamiento introducida por teclado
    float average = 0; // Variable utilizada para guardar el promedio de los sueldos
    float acumulator = 0; // Variable utilizada para guardar la suma de los sueldos
    int a; // Variable utilizada como control para la inicialización del array
    int menu; // Variable utilizada para guardar la opción correspondiente al menu del sistema
    int d = 0; // Variable para almacenar la cantidad de empleados que ganan mas que el promedio
    int controlMenu = 0; // Variable de estado, si no ingresamos en la primer opción no podemos ingresar en las demás
    a = initEmployees(list, TAML); // Inicialización del array de empleados

    if(a == 0) // En caso de haber inicializado correctamente el vector mostramos el siguiente mensaje
    {
        printf("Inicializando el programa\n"); // Una vez inicializado el vector imprimimos por pantalla el siguiente menasje
        system("PAUSE"); // Pausamos la ejecución del programa
        system("CLS"); // Limpiamos pantalla
    }
    do
    {
        system("PAUSE");// Pausamos la ejecución del programa
        system("CLS");// Limpiamos pantalla
        printf("\nBienvenido al menu de ABM que desea hacer? "); // Impresion por pantalla del mensaje
        printf("\n1-ALTA");// Impresion por pantalla del mensaje
        printf("\n2-MODIFICAR");// Impresion por pantalla del mensaje
        printf("\n3-BAJA");// Impresion por pantalla del mensaje
        printf("\n4-INFORMAR");// Impresion por pantalla del mensaje
        scanf("%d", &menu); // Guardamos el valor ingresado por teclado en la variable "menu"
        switch(menu)
        {
        case 1:
            controlMenu = 1; // Cambiamos el valor de la variable de control a 1
            position = findEmpty(list, TAML); // Llamamos la función "findEmpty", el valor que nos devuelve (primer posición libre del vector) en la variable "position"
            if(position != -1) // Si la función nos devuelve un valor distinto a -1 (error) ejecutamos la siguiente línea de código
            {
                contadorID++; //Incrementamos en 1 el valor de "contadorID"
                id = contadorID; // Guardamos el valor del contador en la variable "id"
                system("CLS");// Limpiamos pantalla
                printf("\nIngrese el nombre del empleado: ");// Impresion por pantalla del mensaje
                getChar(name); // Llamamos al a función "getChar" pasandole como valor la variable "name" para validarla
                //system("CLS");// Limpiamos pantalla
                printf("\nIngrese el apellido del empleado: ");// Impresion por pantalla del mensaje
                getChar(lastName);// Llamamos al a función "getChar" pasandole como valor la variable "lastName" para validar el ingreso de una cadena de caracteres
                system("CLS");// Limpiamos pantalla
                printf("\nIngrese el sueldo del empleado: ");// Impresion por pantalla del mensaje
                salary = getFloat();// Guardamos el valor ingresado por teclado en la variable salary
                system("CLS");// Limpiamos pantalla
                printf("\nIngrese el sector del empleado: ");// Impresion por pantalla del mensaje
                sector = getInt(); // Llamamos a la función "getInt" pasandole la variable "sector" para validar el ingreso de un numero entero
                control = addEmployee(list, TAML, contadorID, name, lastName, salary, sector); // Llamamos a la función "addEmployee" la cual nos devolverá un valor distinto a -1 (error) en caso de haber podido cargar el valor

                if(control != -1 ) // Si la variable control es distinto de -1 ejecutamos el siguiente bloque de código
                {
                    system("CLS");// Limpiamos pantalla
                    printf("\nCarga exitosa\n");// Impresion por pantalla del mensaje
                }
                else
                {
                    system("CLS");// Limpiamos pantalla
                    printf("\nNo se cargo\n");// Impresion por pantalla del mensaje
                }
            }
            else
            {
                system("CLS");// Limpiamos pantalla
                printf("\nNo hay lugar\n");// Impresion por pantalla del mensaje
            }
            break;

        case 2:
            if(controlMenu == 1) // En caso de no haber ingresado en la primer opcion del menu "alta" no ejecutamos el codigo
            {
                printf("\nEn proceso: ");// Impresion por pantalla del mensaje
                system("PAUSE");// Pausamos la ejecución del programa
                system("CLS");// Limpiamos pantalla
                control = printEmployees(list, TAML); // Llamamos a la función "printEmployees" pasandole el array de empleados y el tamaño del mismo, el valor devuelto lo guardamos en la variable "control"
                printf("Ingrese el id que desea modificar: ");// Impresion por pantalla del mensaje
                scanf("%d", &id);// Guardamos el valor ingresado por teclado en la variable id
                system("CLS");// Limpiamos pantalla
                modifyEmployee(list, TAML, id);
            }
            else
            {
                printf("\nNo hay empleados cargados");
            }

            break;

        case 3:
            if(controlMenu == 1)// En caso de no haber ingresado en la primer opcion del menu "alta" no ejecutamos el codigo
            {
                printf("En proceso: ");// Impresion por pantalla del mensaje
                system("PAUSE");// Pausamos la ejecución del programa
                system("CLS");// Limpiamos pantalla
                control = printEmployees(list, TAML); // Llamamos a la funcion "printEmployees" pasandole como valores el array de empleados y el tamaño del mismo, el valor devuelto lo guardamos en la vriable "control"
                if(control != -1) // En caso que el valor de control sea distinto a -1 ejecutamos el sigueinte bloque de código
                {
                    printf("\nIngrese el id que desea dar de baja: ");// Impresion por pantalla del mensaje
                    scanf("%d", &id);// Guardamos el valor ingresado por teclado en la variable id
                    control = removeEmployee(list, TAML, id); // Llamamos a la función "removeEmployee" pasandole como valores el array de empleados, el tamaño del mismo y el id que deseamos eliminar del sistema, el valor devuelto lo guardamos en la variable "control"
                    if(control != -1) // En caso que el valor de control sea distinto a -1 ejecutamos el sigueinte bloque de código
                    {
                        system("CLS");// Limpiamos pantalla
                        printf("Baja exitosa\n");// Impresion por pantalla del mensaje
                    }
                    else
                    {
                        system("CLS");// Limpiamos pantalla
                        printf("No se dio de baja\n");// Impresion por pantalla del mensaje
                    }
                }
            }
            else
            {
                printf("\nNo hay empleados cargados");
            }
            break;

        case 4:
            if(controlMenu == 1)// En caso de no haber ingresado en la primer opcion del menu "alta" no ejecutamos el codigo
            {
                system("CLS");// Limpiamos pantalla
                printf("\nDesea imprimirlos de forma \n1 - Cresciente\n0 - Decresciente");// Impresion por pantalla del mensaje
                scanf("%d", &sort);// Guardamos el valor ingresado por teclado en la variable sort
                system("CLS");// Limpiamos pantalla
                control =  sortEmployees(list, TAML, sort); // Llamamos a la funcion "sortEmployees" para ordenar el array de empleados, el valor devuelto lo guardamos en la variable "control"
                control =  printEmployees(list, TAML); // Llamamos a la funcion "printEmployees" parar imprimir todos los usuarios dados de alta (isEmpty = 0), el valor devuelto lo guardamos en la variable "control"
                d = totalAndAverageSalary(list, TAML, &average, &acumulator); // Llamamos a la función "totalAndAverageSalary" para calcular, el total de los salarios, el promedio y cuantos empleados ganan mas que el promedio
                printf("\nSueldos totales: %f\nPromedio de sueldos: %f\nPersonas que ganan mas que el promedio: %d", acumulator, average, d); // Imprimimos por pantalla los valores
            }
            else
            {
                printf("\nNo hay empleados cargados");
            }
            break;
        }
    }
    while(menu!=10); // Condición para parar la ejecución del "do while"

}
