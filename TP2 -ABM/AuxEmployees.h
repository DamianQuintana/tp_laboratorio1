

/** \brief Busca en el array de empleado la primer posicion libre
 *
 * \param list Employee* Puntero al array de empleados
 * \param len int Tamaño del array de empleados
 * \return int Devuelve la primer posición de memoria libre
 *
 */
int findEmpty(Employee* list, int len);

/** \brief Busca en el array de empleados un empleado por ID
 *
 * \param list Employee* Puntero al array de empleados
 * \param id int ID a buscar
 * \param size int Tamaño del array de empleados
 * \return int Devuelve 0 en caso de OK
 *
 */
int printOneEmployee(Employee* list, int id, int size);

/** \brief Busca un ID en el array de empleados en caso de encontrarlo permite modificar sus parametros
 *
 * \param list Employee* Puntero al array de empleados
 * \param len int Tamaño del array de empleados
 * \param id int ID a buscaar
 * \return int Devuelve 0 en caso de haber modificado algo, -1 en caso de error (No se modifico, no se dio de baja)
 *
 */
int modifyEmployee(Employee* list, int len, int id);

/** \brief Calcula el total, promedio y cantidad de empleados que ganen mas que el promedio
 *
 * \param list Employee* Puntero al array de empleados
 * \param len int Tamaño del array de empleados
 * \return int Devuelvo la cantidad de empleados que ganan mas que el promedio
 *
 */
int totalAndAverageSalary(Employee* list, int len, float *average, float *acumulator);

/** \brief Valida una cadena de caracteres para que solo se ingresen numeros y luego la transforma en un entero
 *
 * \param void No toma nada
 * \return int Devuelve la conversión de caracter a entero
 *
 */
int getInt(void);

/** \brief Toma una cadena de caracteres y la valida para que solamente se ingresen letras
 *
 * \param palabra[30] char Cadena de caracteres a recibir
 * \return void No devuelve nada
 *
 */
void getChar(char palabra[51]);

/** \brief Valida una cadena de caracteres y lo devuelve como un valor de tipo "float"
 *
 * \param void
 * \return float Devuelve el valor del string convertido en float
 *
 */
float getFloat(void);
