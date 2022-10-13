#ifndef ACTOR_H_
#define ACTOR_H_

#include "input.h"
#include <stdio.h>

#define TAM 10

#define LIBRE 1
#define OCUPADO 0


typedef struct
{

  int diaInicio;
  int mesInicio;
  int anioInicio;

  int diaFinalizacion;
  int mesFinalizacion;
  int anioFinalizacion;

}FechasActor;

typedef struct
{
 int idRol;
 char descripcion[15];


}eRol;

typedef struct
{

   int codigo;
   char nombre[15];
   char apellido[15];
   char personaje[15];
   int rol;
   FechasActor fechas;
   char pelicula[15]; // FK
   int sueldo;
   int oscar;
   int estado;

}eActor;

int MostrarGestionActor(void);
void ModificarActor(eActor lista[], int size, eRol listaRol[]);
void AltaActor(eActor lista[], int size, eRol listaRol[]);
void GestionDeActores(eActor lista[], int size, eRol listaRol[]);
void inicializarActores(eActor lista[], int size);
void MostrarListaActores(eActor lista[], int size, eRol listaRol[]);
void MostrarUnActor(eActor lista, eRol listaRol);
int subMenuActores();
void ModificarNombre(eActor lista[], int size, int index);
void ModificarPersonaje(eActor lista[], int size, int index);
void ModificarRol(eActor lista[], int size, int index, eRol listaRol[]);
void ModificarSueldo(eActor lista[], int size, int index);
void ModificarOscar(eActor lista[], int size, int index);
void ModificarFechaInicio(eActor lista[], int size, int index);
void ModificarFechaFinalizacion(eActor lista[], int size, int index);
void ModificarPelicula(eActor lista[], int size, int index);
void BajaActor(eActor lista[], int size, eRol listaRol[]);
int VerificadorCodigo(eActor lista[],int size ,int index);
#endif /* ACTOR_H_ */
