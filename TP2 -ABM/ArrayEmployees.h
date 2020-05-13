
struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;

/** \brief Inicializa el array de empleados, pone la bandera(isEmpty = 1), indicando que todas las posiciones están libres
 *
 * \param list Employee* Puntero del array de empleados
 * \param len int Tamaño del array de empleados
 * \return Devuelve 0 en caso de haber inicializado correctamente el vector
 *
 */
int initEmployees(Employee* list, int len);

/** \brief Agrega en una posición libre del array de empleados, los valores recibidos por parametro
 *
 * \param list Employee* Puntero del array de empleados
 * \param len int Tamaño del array de empleados
 * \param id int ID autogenerado por contador indicando el id
 * \param name[] char Nombre del empleado ingresado por teclado
 * \param lastName[] char Apellido del empleado ingresado por teclado
 * \param salary float Salario del empleado ingresado por teclado
 * \param sector int Sector del empleado ingresado por teclado
 * \return int Devuelve 1 en caso de haber cargado los datos correctamente
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector) ;

/** \brief Busca a un empleado en el array a través de su id y en caso de encontrarlo devuelve su posición en el array
 *
 * \param list Employee* Puntero del array de empleados
 * \param len int Tamaño del array de empleados
 * \param id int Parametro ingresado por el usuario indicando un ID de un usuario
 * \return int Devuelve la posición en el array del empleado, en caso de no encotnrarlo devuelve -1
 *
 */
int findEmployeeById(Employee* list, int len, int id);

/** \brief Elimina un usuario de forma lógica (bandera isEmpty = 1)
 *
 * \param list Employee* Puntero del array de empleados
 * \param len int Tamaño del array de empleados
 * \param id int Valor ingresado por teclado, haciendo referencia al ID del empleado a buscar
 * \return int Devuelve 0 si la baja se hizo de forma exitosa, en el caso contrario devuelve -1
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Ordena el array de empleados por sector y por apellido, tanto de forma cresciente como decresciente según lo decida el usuario
 *
 * \param list Employee* Puntero del array de empleados
 * \param len int Tamaño del array de empleados
 * \param order int Valor que recibe la función por parametro, 1 cresciente, 0 decresciente
 * \return int Devuelve un cero si el orden se realiza
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief Imprime el array de empleados que se encuentran dados de alta
 *
 * \param list Employee* Puntero del array de empleados
 * \param int length Tamaño del array de empleados
 * \return int Devuelve un cero cuando termina de imprimir los empleados
 *
 */
int printEmployees(Employee* list, int length);



