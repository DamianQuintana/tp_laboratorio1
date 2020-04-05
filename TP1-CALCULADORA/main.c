#include <stdio.h> // Inclusion de la biblioteca para usar las funciones de la misma
#include <stdlib.h> // Inclusion de la biblioteca para usar las funciones de la misma
#include <string.h> // Inclusion de la biblioteca para usar las funciones de la misma
#include <math.h> // Inclusion de la biblioteca para usar las funciones de la misma
#include "funciones.h" // Incluimos la biblioteca creada por nosotros

int main()
{
    int option; // Declaracion de la variable que va a ser parametro del switch
    float number1=0; // Declaracion de la variable del primer operando
    float number2=0; // Declaracion de la variable del segundo operando
    float sum; // Declaracion de la variable donde vamos a guardar el resultado de la suma
    float substract; // Declaracion de la variable donde vamos a guardar el resultado de la resta
    float multiply; // Declaracion de la variable donde vamos a guardar el resultado de multiplicacion
    float divide; // Declaracion de la variable donde vamos a guardar el resultado de division
    float factorizeA; // Declaracion de la variable donde vamos a guardar el resultado de la factorizacion del parametro A
    float factorizeB; // Declaracion de la variable donde vamos a guardar el resultado de factorizacion del parametro B

    do
    {
        printf("\n\t\t\t\tBienvenido al menu de la calculadora\n\n\n"); // Mensaje mostrado por pantalla
        printf("\t\t\t=================================================="); // Mensaje mostrado por pantalla
        printf("\n\t\t\t=   1- Ingrese el primer operando A: %.2f \t = ", number1); // Impresion por pantalla con la variable A
        printf("\n\t\t\t=   2- Ingrese el segundo operando B: %.2f \t =", number2); // Impresion por pantalla con la variable B
        printf("\n\t\t\t=   3- Calcula todas las operaciones \t\t ="); // Mensaje mostrado por pantalla
        printf("\n\t\t\t=   4- Informe de los resultados: \t\t ="); // Mensaje mostrado por pantalla
        printf("\n\t\t\t=   5- Salir \t\t\t\t\t ="); // Mensaje mostrado por pantalla
        printf("\n\t\t\t=================================================="); // Mensaje mostrado por pantalla
        scanf("%d", &option); // Comando que pide el ingreso de la opcion del menu

        switch(option) // Funcion de control de la variable "opcion" del menu
        {
        case 1: // Primer opcion del menu, ingreso del valor A
            system("CLS"); // Limpiamos pantalla
            number1 = enterNumber(); // LLamado de la funcion asignado a la Variable donde vamos a guardar el valor devuelto por la misma

            break; // Sentencia que termina con la ejecucion del programa

        case 2: // Segunda opcion del menu, ingreso del valor B
            system("CLS"); // Limpiamos pantalla
            number2 = enterNumber(); // LLamado de la funcion asignado a la Variable donde vamos a guardar el valor devuelto por la misma
            break; // Sentencia que termina con la ejecucion del programa

        case 3: // Tercera opcion del menu, realizar todas las operaciones
            system("CLS"); // Limpiamos pantalla
            printf("Calculando..."); // Mensaje mostrado al seleccionar la opcion "3"
            system("PAUSE"); // Pausamos la ejecucion del programa
            sum = add(number1, number2); // LLamado de la funcion asignado a la Variable donde vamos a guardar el valor de la suma
            substract = substraction(number1, number2); // LLamado de la funcion asignado a la Variable donde vamos a guardar el valor de la resta
            multiply = multiplication(number1, number2); // LLamado de la funcion asignado a la Variable donde vamos a guardar el valor de la multiplicacion
            divide = divition(number1, number2); // LLamado de la funcion asignado a la Variable donde vamos a guardar el valor de la division
            factorizeA = factorial(number1); // LLamado de la funcion asignado a la Variable donde vamos a guardar el valor del factorial de A
            factorizeB = factorial(number2); // LLamado de la funcion asignado a la Variable donde vamos a guardar el valor del factorial de B
            break; // Sentencia que termina con la ejecucion del programa

        case 4: // Cuarta opcion del menu, mostramos los resultados por pantalla
            system("CLS"); // Limpiamos pantalla
            printf("\n\nEl resultado de la suma de %f + %f es: %f", number1, number2, sum); // Mostramos por pantalla el resultado de la suma
            printf("\n\nEresultado de la resta de %f - %f es: %f", number1, number2, substract); // Mostramos por pantalla el resulado de la resta
            printf("\n\nEl resultado de la multiplicacion de %f * %f es: %.2f", number1, number2, multiply); // Mostramos por pantalla el resultado de la multiplicacion

            if(divide == 911) // Logica aplicada para evitar la division por 0, en caso del valor ser "911" mostramos el mensaje indicando el error
            {
                printf("\n\nNo se puede dividir por 0"); // Mensaje mostrado por pantalla en caso del divisor ser 0
            }
            else
            {
                printf("\n\nEl resultado de la division de %f / %f es: %.2f",number1, number2, divide); // Mostramos por pantalla el resultado de la division
            }

            if(factorizeA == -1) // Logica aplicada para evitar la factorizacion de un numero menor a 0, en caso de la funcion devolver "-1", se muestra el mensaje de error
            {
                printf("\n\nNo se puede realizar el factorial de A\n\n\n"); // Mensaje de error mostrado por pantalla
            }
            else
            {
                printf("\n\nEl factorial de: %.0f es: %.0f", number1, factorizeA); // Mensaje mostrado por pantalla con el resultado de la factorizacion
            }

            if(factorizeB == -1) // Logica aplicada para evitar la factorizacion de un numero menor a 0, en caso de la funcion devolver "-1", se muestra el mensaje de error
            {
                printf("\n\nNo se puede realizar el factorial de B\n\n\n"); // Mensaje de error mostrado por pantalla
            }
            else
            {
                printf("\n\nEl factorial de: %.0f es: %.0f\n\n\n", number2, factorizeB);  // Mensaje mostrado por pantalla con el resultado de la factorizacion
            }
            system("PAUSE"); // Pausamos la ejecucion del programa
            break; // Sentencia que termina con la ejecucion del programa

        case 5: // Quinta opcion del menu, salir del programa
            system("CLS"); // Limpiamos pantalla
            printf("\n\nHasta luego!!!!\n"); // Mensaje de despedida mostrado por pantalla
            system("PAUSE"); // Pausamos la ejecucion del programa
            break;

        }

        system("CLS"); // Limpiamos pantalla
        system("PAUSE"); // Pausamos la ejecucion del programa

    }
    while(option!=5);  // Estructura de iteracion del menu, en caso de ingresar la opcion "5", el programa termina la ejecucion
}

