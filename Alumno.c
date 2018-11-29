#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"
#include "LinkedList.h"

/// ALUMNO ///

eAlumno* nuevoAlumno ()
{
    eAlumno* pAlumno;

    pAlumno = (eAlumno*)malloc(sizeof(eAlumno));

    return pAlumno;
}

eAlumno* parametrosAlumno (char* idStr, char* nombreStr, char* nota1Str, char* nota2Str, char* notaFinalStr)
{
    eAlumno* pAlumno;

    pAlumno = nuevoAlumno();

    if (pAlumno != NULL)
    {
        setIdAlumno(pAlumno, atoi(idStr));
        setNombreAlumno(pAlumno, nombreStr);
        setNota1(pAlumno, atof(nota1Str));
        setNota2(pAlumno, atof(nota2Str));
        setNotaFinal(pAlumno, atof(notaFinalStr));
    }

    return pAlumno;
}

/// ID ///

int setIdAlumno (eAlumno* this,int id)
{
    int indice = 0;

    if (this != NULL && id > 0)
    {
        this -> id = id;
        indice = 1;
    }

    return indice;
}

int getIdAlumno (eAlumno* this, int* id)
{
    int indice = 0;

    if(this != NULL)
    {
        *id = this -> id;
        indice = 1;
    }

    return indice;
}

/// NOMBRE ///

int setNombreAlumno (eAlumno* this, char* nombre)
{
    int indice = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(this -> nombre, nombre);
        indice = 1;
    }

    return indice;
}

int getNombreAlumno (eAlumno* this, char* nombre)
{
    int indice = 0;

    if(this != NULL)
    {
        strcpy (nombre, this->nombre);
        indice = 1;
    }

    return indice;
}

/// NOTA 1 ///

int setNota1 (eAlumno* this, float nota1)
{
    int indice = 0;

    if(this != NULL)
    {
        this -> nota1 = nota1;
    }

    return indice;
}

int getNota1 (eAlumno* this, float* nota1)
{
    int indice = 0;

    if(this != NULL)
    {
        *nota1 = this -> nota1;
        indice = 1;
    }
    return indice;
}

/// NOTA 2 ///

int setNota2 (eAlumno* this, float nota2)
{
    int indice = 0;

    if(this != NULL)
    {
        this -> nota2 = nota2;
    }

    return indice;
}

int getNota2 (eAlumno* this, float* nota2)
{
    int indice = 0;

    if(this != NULL)
    {
        *nota2 = this -> nota2;
        indice = 1;
    }
    return indice;
}
/// NOTA FINAL ///

int setNotaFinal (eAlumno* this, float notaFinal)
{
    int indice = 0;

    if(this != NULL)
    {
        this -> notaFinal = notaFinal;
    }

    return indice;
}

int getNotaFinal (eAlumno* this, float* notaFinal)
{
    int indice = 0;

    if(this != NULL)
    {
        *notaFinal = this -> notaFinal;
        indice = 1;
    }
    return indice;
}
/// ORDENAR ///

int compararAlumnos (void* eAlumnoA, void* eAlumnoB)
{
    int indice = 0;
    char alumnoA [128];
    char alumnoB [128];

    getNombreAlumno((eAlumno*) eAlumnoA, alumnoA);
    getNombreAlumno((eAlumno*) eAlumnoB, alumnoB);

    if(strcmp(alumnoA, alumnoB) > 0)
    {
        indice = 1;
    }

    return indice;
}

int ordenarPorNombre (LinkedList* this)
{
    eAlumno* alumnoAuxiliar;
    int indice = 0;
    int i;

    if(this != NULL)
    {
        for (i = 0; i < ll_len(this); i++)
        {
            alumnoAuxiliar = (eAlumno*) ll_get(this, i);

            if (alumnoAuxiliar != NULL)
            {
                ll_sort(this, compararAlumnos, 1);
                indice = 1;
            }
        }
    }
    return indice;
}

/// PARSER ///

int parserFromText(FILE* pFile , LinkedList* pListadoAlumnos)
{
    int indice = -1;
    eAlumno* pAlumno;
    int cantidad;
    char id [20];
    char nombre [128];
    char nota1 [5];
    char nota2 [5];
    char notaFinal [5];

    if(pFile != NULL && pListadoAlumnos != NULL)
    {
        cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, nota1, nota2, notaFinal);
        do
        {
            cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, nota1, nota2, notaFinal);
            if(cantidad == 5)
            {
                pAlumno = nuevoAlumno();
                setIdAlumno(pAlumno, atoi(id));
                setNombreAlumno(pAlumno, nombre);
                setNota1(pAlumno, atof(nota1));
                setNota2(pAlumno, atof(nota2));
                setNotaFinal(pAlumno, atof(notaFinal));

                if(pAlumno != NULL)
                {
                    ll_add(pListadoAlumnos, pAlumno);
                }
                else
                {
                    printf("No hay espacio para cargar alumnos");
                }

                indice = 1;

            }
            else
            {
                break;
            }


        }while(!feof(pFile));
    }
    return indice;
}

/// CONTROLLER ///

int controller_loadFromText(char* path , LinkedList* pListadoAlumnos)
{
    FILE* pArchivoTexto;
    int indice = 0;

    if ((pArchivoTexto = fopen(path, "r")) != NULL)
    {
        indice = parserFromText(pArchivoTexto, pListadoAlumnos);
    }

    fclose(pArchivoTexto);

    return indice;
}

/// LISTAR ///

int listarAlumnos(LinkedList* this, eAlumno* alumno)
{
    eAlumno* alumnoAuxiliar;
    int i;
    int* id;
    char nombre[100];
    float* nota1;
    float* nota2;
    float* notaFinal;
    int indice = -1;


    getIdAlumno(alumno,&id);
    getNombreAlumno(alumno,nombre);
    getNota1(alumno,&nota1);
    getNota2(alumno,&nota2);
    getNotaFinal(alumno,&notaFinal);

    printf("ID---Nombre---Nota1--Nota2-- Nota Final\n");

    for(i = 0; i < ll_len(this); i++)
    {
        alumnoAuxiliar = (eAlumno*) ll_get(this, i);

        if(alumnoAuxiliar != NULL)
        {
            printf("%d---%s---%f--%f--%f\n", id, nombre, nota1 ,nota2 ,notaFinal);
            indice = 1;
        }
    }
    return indice;
}
