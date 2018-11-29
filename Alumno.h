typedef struct
{
    int id;
    char nombre [128];
    float nota1;
    float nota2;
    float notaFinal;
}eAlumno;

//////////////////// ALUMNO ////////////////////

/** \brief Asigna espacio en memoria para el nuevo alumno
 *
 * \return eAlumno* Puntero a la estructura alumno
 *
 */
eAlumno* nuevoAlumno ();

eAlumno* parametrosAlumno (char*, char*, char*, char*, char*);

//////////////////// ID ////////////////////

int setIdAlumno (eAlumno*,int);

int getIdAlumno (eAlumno*, int*);

//////////////////// NOMBRE ////////////////////

int setNombreAlumno (eAlumno*, char*);

int getNombreAlumno (eAlumno*, char*);

//////////////////// NOTA 1 ////////////////////

int setNota1 (eAlumno*, float);

int getNota1 (eAlumno*, float*);

//////////////////// NOTA 2 ////////////////////

int setNota2 (eAlumno*, float);

int getNota2 (eAlumno*, float*);

