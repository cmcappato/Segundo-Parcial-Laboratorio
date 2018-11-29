#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"
#include "LinkedList.h"

////////////////////Alumno////////////////////

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
    }

    return pAlumno;
}

//////////////////// ID ////////////////////

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

//////////////////// NOMBRE ////////////////////

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

//////////////////// NOTA 1 ////////////////////

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

//////////////////// NOTA 2 ////////////////////

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
