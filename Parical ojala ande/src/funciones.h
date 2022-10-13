#ifndef FUNCIONES_H_
#define FUNCIONES_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "input.h"
#include "actor.h"

// largo pelis

#define TAMPELICULAS 3
// estado

#define LIBRE 1
#define OCUPADO 0
// Titulo


typedef struct
{

   int dia;
   int mes;
   int anio;


}eFechasPelicula;

typedef struct
{

    int codigo;
    char titulo[15]; //PK
    int duracion;
    char director[20];
    eFechasPelicula fechas;
    float recaudacion;
    int estado;
    int oscar;

}ePelicula;


int MostrarMenu(void);
void GestionDePeliculas(ePelicula lista[], int size, eActor listaActor[], int sizeActor);
int MostrarGestionPeliculas(void);
void CalcularRecaudacion(ePelicula lista[], int size);
void MostrarListaPeliculas(ePelicula lista[], int size);
void MostrarUnaPelicula(ePelicula lista);
void BajaPelicula(ePelicula lista[], int size,eActor listaActor[]);
void DesemplearActor(ePelicula lista[], int size, eActor listaActor[], int index); // LAST MODIFICATION
void Informes(ePelicula lista[], int size, eActor listaActor[], int sizeActor, eRol listaRol[]);
int subMenuInformes(void);
void CalcularGastos (ePelicula lista[], int size, eActor listaActor[], int sizeActor);
void ActoresOrdenadosAlfabeticamente(ePelicula lista[], int size, eActor listaActor[], int sizeActor, eRol listaRol[]);
void ListadoPorValorDelContrato(ePelicula lista[], int size, eActor listaActor[], int sizeActor, eRol listaRol[]);
void CalcularGanaciasTotales(eActor lista[], int size, ePelicula listaPelicula[], eRol listaRol[]);
void MostrarActoresOrdenadosAlfabeticamente(eActor listaActor[], int sizeActor, eRol listaRol[]);
void PremiarActores(ePelicula lista[], eActor listaActor[]);
int NumeroRepetido(int array[], int i, int numAleatorio);
void ListadoDeActoresOscar(ePelicula lista[], int size, eActor listaActor[], int sizeActor, eRol listaRol[]);
void ListarPeliculasRecaudacionDuracion(ePelicula lista[], int size, eActor listaActor[], int sizeActor);
void MostrarPeliculasRecaudacionDuracion(ePelicula lista[], int size);
void ActoresOrdenadosPorRol(ePelicula lista[], eActor listaActor[], int sizeActor, eRol listaRol[]);
void MostrarActoresOrdenadosPorRol(eActor listaActor[], int sizeActor, eRol listaRol[]);
void PeliculasOrdenadasPorFecha(ePelicula lista[], int size, eActor listaActor[], int sizeActor);
void MostrarOrdenadasPorFecha(ePelicula lista[], int size);
#endif
