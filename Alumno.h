#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre [128];
    int nota1;
    int nota2;
    int notaFinal;
}eAlumno;

/// ALUMNO ///

/** \brief Asigna espacio en memoria para el nuevo alumno
 *
 * \return eAlumno* Puntero a la estructura alumno
 *
 */
eAlumno* nuevoAlumno ();

eAlumno* parametrosAlumno (char*, char*, char*, char*, char*);

/// ID ///

int setIdAlumno (eAlumno*,int);

int getIdAlumno (eAlumno*, int*);

/// NOMBRE ///

int setNombreAlumno (eAlumno*, char*);

int getNombreAlumno (eAlumno*, char*);

/// NOTA 1 ///
int setNota1 (eAlumno*, int);

int getNota1 (eAlumno*, int*);

/// NOTA 2 ///

int setNota2 (eAlumno*, int);

int getNota2 (eAlumno*, int*);


/// NOTA FINAL ///

int setNotaFinal (eAlumno*, int);

int getNotaFinal (eAlumno*, int*);

void calcularNotasAlumnos(LinkedList*);

void calcularNotaFinal(eAlumno* elemento);

/// ORDENAR ///

int compararAlumnos (void* eAlumnoA, void* eAlumnoB);

int ordenarPorNombre (LinkedList*);

/// PARSER ///

int parserFromText(FILE*, LinkedList*);

/// CONTROLLER ///

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param char*
 * \param LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char*, LinkedList*);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param char*
 * \param LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char*, LinkedList*);

/// LISTAR ///

int listarAlumnos (LinkedList* this);


/// PROMEDIO ///

int filtrarPromedio(void* elemento, int aux);
