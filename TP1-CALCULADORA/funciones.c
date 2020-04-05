#include <stdio.h>// Inclusion de la biblioteca para usar las funciones de la mismaS
#include <stdlib.h>// Inclusion de la biblioteca para usar las funciones de la misma
#include <string.h>// Inclusion de la biblioteca para usar las funciones de la misma
#include "funciones.h"// Inclusion de la biblioteca para usar las funciones de la misma
#include <math.h>// Inclusion de la biblioteca para usar las funciones de la misma

float enterNumber(void) // Funcion para ingresar el numero por teclado
{
    float number; // Declaracion de variable donde vamos a guardar el numero ingrsado
    float status=1; // Bandera de estado indicando que lo que ingreso el usuario es un número
    system("PAUSE"); // Pausamos el programa
    fflush(stdin); // Limpiamos el buffer del teclado
    printf("Ingrese el operando: "); // Mensaje que se muestra solicitando el ingreso de un numero
    status = scanf("%f", &number); // El valor que toma status es dado por el scanf en caso de no haber podido guardar la variable nos devuelve un 0

    system("PAUSE");// Pausamo el programa

    if(status == 0) // En caso de ser 0, indica que no es un numero, por ende entramos en el bucle volviendo a pedirlo
    {
        do
        {
            fflush(stdin);// Limpiamos el buffer del teclado
            printf("Invalido, reingrese un numero: "); // Mensaje mostrado pidiendo reingreso de un numero
            status = scanf("%f", &number); // Nuevo valor que va a tomar status para validar el ingreso de teclado
            fflush(stdin);// Limpiamos el buffer del teclado
        }
        while(status == 0);
    }

    return number; //Valor que devuelve la funcion
}

float add(float number1, float number2) // Funcion que realiza la suma de dos numeros
{
    float sum; // Declaracion de variable donde vamos a guardar la suma
    sum = number1+number2; // Operacion de la suma
    return sum; //Valor que devuelve la funcion
}

float substraction(float number1, float number2) //Funcion que realiza la resta
{
    float substract; // Declaracion de variable donde vamos a guardar la resta
    substract = number1-number2; //Operacion de resta
    return substract; //Valor que devuelve la funcion
}

float multiplication(float number1, float number2) //Funcion que realiza la multiplicacion de dos numeros
{
    float multiply; // Declaracion de variable donde vamos a guardar el resultado de la multiplicacion
    multiply = (float) number1*number2; // Operacion de multiplicacion
    return multiply; //Valor que devuelve la funcion
}

float divition(float number1, float number2) // Funcion que realiza la division de dos numeros
{
    float divide=0; // Declaracion de la variable donde vamos a guardar el resultado de la division

    if(number2 != 0) // Logica aplicada para evitar la division por 0
    {
        divide = (float) number1/number2; // En caso de "number2" distinto a 0 se realiza la division
    }
    else
    {
        divide = 911; // De lo contrario se le asigna el valor 911 que se utiliza como valor de error
    }

    return divide; //Valor que devuelve la funcion
}

float factorial(float number) // Funcion que realiza la factorizacion del numero
{
    int i; // Declaracion de la variable "i" utilizada en el "for"
    float factorize=1; // Declaracion de la variable donde vamos a guardar el factoreo, la inicializamos en 1

    if( number > 0)
    {
        for(i=1; i<=number; i++) // Bucle para realizar el factoreo
        {
            factorize *= i; // Operación de factorizacion
        }
    }
    else
    {
        factorize = -1;// Numero devuelto en caso de que el numero sea menor a 0, -1 es el numero que nos indica error
    }

    return factorize; //Valor que devuelve la funcion
}

