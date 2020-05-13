#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "AuxEmployees.h"

int findEmpty(Employee* list, int len)
{
    int i; // Declaración de la variable de contol para el "for"
    int flag; // Declaración de variable de control
    for(i=0; i<len; i++) // Estructura "for"
    {
        if(list[i].isEmpty == 1) // En el caso de que el valor "isEmpty =1" significa que tenemos ese lugar en el array libre
        {
            flag = i; // En caso de tener una posición libre la guardamos en la variable "flag"
            break; // Al encontrar un lugar libre detenemos la ejecución del bucle
        }
        else
        {
            flag = -1; // En caso de no encontrar un lugar libre guardamos -1 en la variable "flag", indicando error
        }
    }
    return flag; // Devolvemos el valor de flag
}

int getInt(void)
{
    char number[30]; //Declaramos una variable de tipo char donde vamos a guardar el númoer a ingresar
    int numberI; // Variable donde vamos a guardar la cadena de caracteres para convertirla en entero
    int size; // Longitud de la cadena de caracteres
    int state=0; // variable de control
    int i;// Declaración de la variable de contol para el "for"

    fflush(stdin);// Limpiamos el buffer del teclado
    gets(number); // Ingresamos por teclado una cadena de caracteres en la variable "numero"
    size = strlen(number); // Tomamos la longitud de la palabra ingresada

    do
    {
        if(state !=0 || size >= 30)
        {
            printf("Invalido, reingrese un numero: ");
            gets(number); //  Ingresamos por teclado una cadena de caracteres en la variable "numero"
            size = strlen(number);// Tomamos la longitud de la palabra ingresada
        }
        for(i=0; i<size; i++)
        {
            state = isalpha(number[i]); // Guardamos en la variable "state" lo que nos devuelve la funcion "isalpha", la cual va a recorrer a través del "for" cada uno de los lugares, en el caso de que alguno de estos valores no se numérico guardamos un valor distinto a 0 indicando error

            if(number[i] == '.' || number[i] == ',') // En el caso que alguno de los valores sea un punto o una coma camibamos el state a 1 indicando error
            {
                state =1;
                break;
            }
        }

    }
    while(state !=0); // Bucle en caso de que state sea distinto a 0

    numberI = atoi(number); // Convertimos el valor validad y lo convertimos en entero
    return numberI; // Retornamos el valor convertido en entero
}

void getChar(char string[51])
{
    int state = 1; // Bandera de state
    int state2 = 1; // Bandera de state
    int size; // Variable a guardar la longitud de la cadena agregada
    int i; // Variable de control del bucle "for"

    fflush(stdin); // Limpiamos el buffer del teclado
    gets(string); // Ingresamos por teclado una cadena de caracteres
    size = strlen(string);// Tomamos la longitud de la palabra ingresada

    if(size >= 51)
    {
        state = 0; // En caso de la longitud exceda el tamaño del vector, cambiamos el estado a 0 para indicar error
    }
    else
    {
        state = 1;
    }

    do
    {
        if(state == 0) // En caso de que el state sea igual a 0 ejecuto la siguiente línea de código
        {
            printf("\n\nReingrese la palabra: ");
            gets(string); // Ingresamos por teclado una cadena de caracteres
            size = strlen(string); // Tomamos la longitud de la palabra ingresada
            if(size >= 51)
            {
                state = 0;// En caso de la longitud exceda el tamaño del vector, cambiamos el estado a 0 para indicar error
            }
            else
            {
                state = 1;
            }
        }
        if(state == 1)
        {
            for(i = 0; i < size; i++)// Bucle "for"
            {
                state = isalpha(string[i]); // Si es una letra me da un no cero
            }
            for(i=0; i<size; i++)// Bucle "for"
            {
                state2 = isdigit(string[i]); // Si es un numero me devuelve un no cero;
            }
        }
    }
    while(state == 0 || state2 != 0); // En caso de que "estado" sea igual a 0 indicamos que la cadena es de caracteres y en caso de que estao2 sea distinto a 0 indica que ingresamos un valor numérico
}

int printOneEmployee(Employee* list, int id, int size)
{
    int i; // Declaración de la variable de contol para el "for"
    i = findEmployeeById(list, size, id);// Guardamos en "i", la variable (posición del array) devuelta por la función "findEmployeeById"

    if(i!= -1) // En caso de que el valor sea distinto a -1 imprimimos los datos de ese empleado
    {
        printf("\nID\tNOMBRE\tAPELLIDO\tSALARIO\tSECTOR\n");
        printf("%d\t%s\t%s\t%f\t%d", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector); // Datos del empleado bajo el ID ingresado
    }
    else
    {
        printf("\nID no encontrado"); // En caso de no haber encontrado dicho ID imprimimos el siguiente mensaje de error
    }

    return 0;
}

int modifyEmployee(Employee* list, int len, int id)
{

    int modify; // Variable donde guardamos el dato que se vaya a modificar
    int flag; // Variable de control y retorno
    int index; // Variable donde guardamos la posicion del empleado en el array

    index = findEmployeeById(list, len, id); // Guardamos en la variable "index" la posicion del empleado en el array

    if(index != -1) // En caso de encontrar al empleado ejecutamos la siguiente línea de código
    {
        printOneEmployee(list, id, len); // En caso de haber encontrado a dicho empleado imprimimos sus datos
        printf("\nQue dato desea modificar: \n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n5-Nada");
        scanf("%d", &modify); // Variables donde vamos a guardar la opción del dato a modificar
        system("CLS"); // Limpiamos pantalla
        if(modify == 1) // En caso de la varbiale de modificacion sea igual a 1 ejecutamos la siguiente línea de código
        {

            printf("\nIngrese el nuevo nombre: ");
            getChar(list[index].name); // Llamado a la funcion "getChar" para validar el nuevo valor para la varibale "name"
            flag = 0; // Cambiamos el valor de flag a 0
            system("CLS"); // Limpiamos pantalla
        }
        else if(modify == 2)// En caso de la varbiale de modificacion sea igual a 2 ejecutamos la siguiente línea de código
        {
            printf("\nIngrese el nuevo apellido: ");
            getChar(list[index].lastName);// Llamado a la funcion "getChar" para validar el nuevo valor para la varibale "lastName"
            flag = 0;// Cambiamos el valor de flag a 0
            system("CLS");// Limpiamos pantalla
        }
        else if(modify == 3)// En caso de la varbiale de modificacion sea igual a 3 ejecutamos la siguiente línea de código
        {
            printf("\nIngrese el nuevo salario: ");
            scanf("%f", &list[index].salary);// Llamado a la funcion "getFloat" para validar el nuevo valor para la varibale "salary" // FALTA ACA
            flag = 0;// Cambiamos el valor de flag a 0
            system("CLS");// Limpiamos pantalla
        }
        else if(modify == 4)// En caso de la varbiale de modificacion sea igual a 4 ejecutamos la siguiente línea de código
        {
            printf("\nIngrese el nuevo sector: ");
            list[index].sector = getInt();// Llamado a la funcion "getInt" para validar el nuevo valor para la varibale "name"
            flag = 0;// Cambiamos el valor de flag a 0
            system("CLS");// Limpiamos pantalla
        }
        else if(modify == 5)// En caso de la varbiale de modificacion sea igual a 5 ejecutamos la siguiente línea de código
        {
            flag = -1; // En caso de no querer modificar ningún valor, cambiamos el valor de flag a -1
        }
    }
    else
    {
        printf("\nID no encontrado");
        flag = -1; // En caso de no encontrar el id del usuario en el sistema cambiamos el flag a -1
    }

    return flag; // Retornamos el valor de "flag"
}

int totalAndAverageSalary(Employee* list, int len, float *average, float *acumulator)
{
    int i; // Variable de control del bucle "for"
    int c = 0; // Contador donde guardamos la cantidad de empleados dados de alta
    int d = 0; // Contador dondeguardamos la cantidad de empleados que ganen mas que el promedio

    *acumulator = 0; // Igualamos la variable a 0
    *average = 0;// Igualamos la variable a 0

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0) // En caso de que el empleado este dado de alta ejecutamos la siguiente línea de código
        {
            *acumulator = *acumulator + list[i].salary; // Acumulador donde guardamos la suma de los salarios
            c++; // Contador que aumenta en 1 cada vez que entra al if (encuentra un empleado dado de alta)
        }
    }

    *average = *acumulator/c; // Calculamos el promedio
    for(i=0; i<len; i++)
    {
        if(list[i].salary > *average) // En caso de que el salario del empleado sea mayor al promedio ejecutamos la siguiente línea de código
        {
            d++; // En caso de cumplir la condición del if incrementamos en contador "d" en 1 (Indicando que hay un empleado que gana mas que el promedio)
        }

    }

    return d;
}

float getFloat(void)
{
    char number[30]; //Variable donde vamos a guardar la variable a validar
    int numberF; // Variable donde vamos a guardar la variable validada
    int size; // variable donde vamos aguardar la longitud del valor ingresado
    int state=0; // Variable de control de state
    int i; // Variable de contrl de for

    fflush(stdin); // Limpiamos el buffer del teclado
    gets(number);// Ingresamos por teclado la cadena a validar
    size = strlen(number); // Guardamos la longitud de la cadena de caracteres ingresada

    do
    {
        for(i=0; i<size; i++)
        {
            state = isalpha(number[i]); // En caso de el valor ingresado no ser un número el valor de estado cambia a no cero
        }
        if(state !=0) // En caso de que el estado sea distinto a cero ejecutamos la siguiente línea de código
        {
            printf("Invalido, reingrese un numero valido: ");
            gets(number);// Ingresamos por teclado la cadena a validar
            size = strlen(number);// Guardamos la longitud de la cadena de caracteres ingresada
        }
    }
    while(state !=0); // Ejecutamos esta línea de código mientras el valor de estado sea distinto a cero (el valor ingresado no es numérico)

    numberF = atof(number); // Una vez validado el valor ingresado por teclado, lo convertimos en valor de tipo flotante
    return numberF; // Devolvemos el valor convertido
}
