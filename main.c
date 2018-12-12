#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"
#include "Alumno.h"

int main()
{
    int opcion;
    int control;

    LinkedList* listadoAlumnos = ll_newLinkedList();

    do
    {
        printf("***********************************************************************\n");
        printf("1- Cargar alumnos \n");
        printf("2- Listar alumnos \n");
        printf("3- Asignacion de notas \n");
        printf("4- Guardar datos \n");
        printf("5- Salir\n");
        printf("***********************************************************************\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                control = controller_loadFromText("data.csv", listadoAlumnos);
                if (control)
                {
                    printf("Archivo cargado con exito \n");
                }
                else
                {
                    printf("No se pudo abrir el archivo \n");
                }
                break;
            case 2:
                ordenarPorNombre(listadoAlumnos);

                listarAlumnos(listadoAlumnos);
                break;
            case 3:
                calcularNotasAlumnos(listadoAlumnos);
                 break;
            case 4:
                controller_saveAsText("Final.csv", listadoAlumnos);
                break;
            case 10:
                printf("Gracias por utilizar el programa \n");
                break;
            default:
                printf("Ingrese una opcion del 1 al 5 \n");
        }
        system("pause");
        system("cls");
    }while(opcion != 10);
    return 0;
}
