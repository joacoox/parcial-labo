#include "funciones.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Muestro el menu y retorno una opcion
int MostrarMenu(void){

    int opcion;
	printf("\n\t\t\t\t\tMenu principal\n");
	printf("\t\t\t\t\t--------------\n\n\n");
	printf("\t\t\tOpcion 1: Gestion de Actores.\n");
	printf("\t\t\tOpcion 2: Gestion de Peliculas.\n");
	printf("\t\t\tOpcion 3: Informes.\n");
	printf("\t\t\tOpcion 4: Salir.\n");
	printf("\n\t\tSu opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
// Pido las estructuras y los sizes para despues mendiante el switch mandarselo a otras funciones,
// ademas de tomar la opcion que quiera el usuario no retorna nada
void GestionDePeliculas(ePelicula lista[], int size, eActor listaActor[], int sizeActor){

	int opcion;
	    do{
	      opcion = MostrarGestionPeliculas();

	        switch(opcion){
	           case 1:
	           BajaPelicula(lista, TAMPELICULAS, listaActor);
	           break;
	           case 2:
	        	CalcularRecaudacion(lista, TAMPELICULAS);
	           break;
	        }
	    }
	    while(opcion != 3);
	}
// muestro el submenu gestion de peliculas y retorno la opcion validada
int MostrarGestionPeliculas(void){
	int retorno;



	do {
		printf("         Gestion de Peliculas       \n");
		printf("---------------------------\n");
		printf(
				" 1 - Baja \n 2 - Calcular Recaudacion \n 3 - Salir \n Su opcion: ");
		scanf("%d", &retorno);
	}while(retorno < 1 || retorno > 4);

	return retorno;
}
// no retorno nada, solo calculo las recaudaciones de cada Pelicula
// pido la lista de peliculas y el tamanio del array
void CalcularRecaudacion(ePelicula lista[], int size){

	srand(time(0));

	for(int i = 0; i < size; i++){

		lista[i].recaudacion = (rand() % (750 - 150 + 1) + 150) * 1000000;
	}
}
// no retorno nada, esta funcion es para dar de baja a una pelicula
// pido la lista de pelicula para darle de baja y pido la lista de actores,
// para llamar a otra funcion que le saque el trabajo
void BajaPelicula(ePelicula lista[], int size, eActor listaActor[]){

	int i;
	int index;

	MostrarListaPeliculas(lista, TAMPELICULAS);
    index = getInt("\n Ingrese el codigo a dar de baja: ","\n Error el codigo ingresado supera los limites: ",0,1000);

    for(i =0 ; i < size; i++)
        {
          if(lista[i].codigo == index)
          {
              DesemplearActor(lista, TAM, listaActor, i);
              lista[i].estado = LIBRE;
          }
        }
}
// para no anidar dos for en una funcion uso esta, no retorno nada, pero pido la
// posicion de i para saber que actores se quedan sin trabajo
void DesemplearActor(ePelicula lista[], int size, eActor listaActor[], int index){


	for (int i = 0; i < size; i++){

    	 if(strcmp(listaActor[i].pelicula, lista[index].titulo)==0){
    	      	strcpy(listaActor[i].pelicula, "desempleado");

     }
 }
}
// No retorno nada, solo creo un for que va a mostrar la lista de las
// peliculas
void MostrarListaPeliculas(ePelicula lista[], int size){

	 for(int i=0; i<size; i++)
	    {
	        if(lista[i].estado == OCUPADO)
	        {
	        	MostrarUnaPelicula(lista[i]);
	        }

	    }
}
// muestro una pelicula no retorno nada
void MostrarUnaPelicula(ePelicula lista){


 printf("\n El codigo es: %d " , lista.codigo);
 printf("La pelicula es %s \n", lista.titulo);

 }
// creo un menu de informes para que el usuario eliga que quiere ver
// no retorno nada
void Informes(ePelicula lista[], int size, eActor listaActor[], int sizeActor, eRol listaRol[]){

	int opcion;


    do{
       opcion = subMenuInformes();

        switch(opcion){

           case 1:
        	   ActoresOrdenadosAlfabeticamente(lista, size, listaActor, sizeActor, listaRol); // funciona bien
           break;
           case 2:
        	   ListadoPorValorDelContrato(lista,size, listaActor, sizeActor, listaRol); // ASD
           break;
           case 3:
        	   PremiarActores(lista, listaActor); // ASD
           break;
           case 4:
        	   ListadoDeActoresOscar(lista,size, listaActor, sizeActor, listaRol); // ASD
           break;
           case 5:
        	   PeliculasOrdenadasPorFecha(lista,size, listaActor, sizeActor);// funciona bien
           break;
           case 6:
        	   ActoresOrdenadosPorRol(lista, listaActor, sizeActor, listaRol);// funciona bien
           break;
           case 7:
        	   ListarPeliculasRecaudacionDuracion(lista,size, listaActor, sizeActor); // funciona bien
           break;
           case 8:
        	   CalcularGastos(lista, size, listaActor, sizeActor);// funciona bien
           break;
        }


    }
    while(opcion != 9);

}
// muestro un submenu y el usuario elige una opcion y retorno la opcion
// validada
int subMenuInformes(void){

	int retorno;

		do {printf("\n---------------------------\n");
			printf("         Informes        \n");
			printf("---------------------------\n");
			printf(" 1 Actores ordenados alfabeticamente por pelicula\n 2 Listado por valor de contrato \n 3 Premiar actores \n 4 Actores y Peliculas ganadores del oscar ");
			printf("\n 5 Peliculas ordenadas por fecha de estreno \n 6 Actores ordenados por rol\n 7 Listado de peliculas basado en recaudacion y duracion\n 8 Calcular Ganancias \n 9 SALIR\n Su opcion:");
			scanf("%d", &retorno);
		}while(retorno < 0 || retorno > 9);

		return retorno;

}
// no retorno nada, calculo los gastos de las peliculas
void CalcularGastos (ePelicula lista[], int size, eActor listaActor[], int sizeActor){

	int acumuladorActor = 0;
	float suma;

	for(int j = 0; j < size; j++){

	for(int i = 0; i < sizeActor; i++){

		acumuladorActor += listaActor[i].sueldo;


		}
	suma = lista[j].recaudacion - acumuladorActor;
	if(suma>0){
	printf("Las ganancias totales de %s son %0.f  \n",lista[j].titulo, suma);}
	else{ printf("Las perdidas totales de %s son %0.f  \n",lista[j].titulo, suma); }

	}
}
// por el metodo de burbujeo ordeno los actores alfabeticamente, no hay retorno
void ActoresOrdenadosAlfabeticamente(ePelicula lista[], int size, eActor listaActor[], int sizeActor, eRol listaRol[]){


eActor auxLista;

	for (int i = 0; i < sizeActor - 1; i++) {

		for (int j = i + 1; j < sizeActor; j++) {

			if (strcmp(listaActor[i].pelicula, listaActor[j].pelicula)>0) {

				auxLista = listaActor[i];
				listaActor[i] = listaActor[j];
				listaActor[j] = auxLista;
			}
		}
	}

	MostrarActoresOrdenadosAlfabeticamente(listaActor,sizeActor, listaRol);

}
// muestro los actores que ordene anteriormente no hay retorno
void MostrarActoresOrdenadosAlfabeticamente(eActor listaActor[], int sizeActor, eRol listaRol[]){

	for(int i=0; i< sizeActor ; i++){

		printf("El actor %s %s trabajo en la pelicula %s y su rol fue %s \n",listaActor[i].nombre,listaActor[i].apellido, listaActor[i].pelicula, listaRol[i].descripcion);
	}

}
// ordeno por el metodo de burbujeo por valor del contrato no hay retorno
void ListadoPorValorDelContrato(ePelicula lista[], int size, eActor listaActor[], int sizeActor, eRol listaRol[]){

	eActor auxLista;

	for (int i = 0; i < sizeActor - 1; i++) {

		for (int j = i + 1; j < sizeActor; j++) {

			if (listaActor[i].sueldo > listaActor[j].sueldo) {
				auxLista = listaActor[i];
				listaActor[i] = listaActor[j];
				listaActor[j] = auxLista;
			}
		}
	}
	CalcularGanaciasTotales(listaActor, sizeActor, lista, listaRol);
}
// calculo las ganancias totales y luego las muestro no hay retorno
void CalcularGanaciasTotales(eActor lista[], int size, ePelicula listaPelicula[], eRol listaRol[]){

  int meses;
  int anios;
  int recaudacion;

  for(int i= 0 ; i < size; i++){

  meses = lista[i].fechas.mesFinalizacion - lista[i].fechas.mesInicio;

  anios =lista[i].fechas.anioFinalizacion - lista[i].fechas.anioInicio;

  meses += (anios * 12);

  recaudacion = (lista[i].sueldo * meses);

	 listaPelicula[i].recaudacion -= recaudacion;
	 printf("El actor %s %s gana por mes %d y cuando termine el contrato habra ganado %d ", lista[i].nombre,lista[i].apellido, lista[i].sueldo, recaudacion);
	 printf(" y estaba interpretando a %s con el rol de %s \n", lista[i].personaje, listaRol[i].descripcion);
   }


  }
  // selecciono 5 numeros random, para ver quien gana un oscar
  // no hay retorno y los printeo en la funcion
void PremiarActores(ePelicula lista[], eActor listaActor[]){

    int num[5];
    int i;
    int numAleatorio;
   srand(time(0));

for(i = 0; i < 5; i++)
    {
       numAleatorio =0 + rand() % 9;

       while(NumeroRepetido(num, i, numAleatorio) == 0){

            numAleatorio =0 + rand() % 9;
       }
       num[i] = numAleatorio;
       printf("Felicidades actor %s %s ganaste un oscar!\n", listaActor[numAleatorio].nombre, listaActor[numAleatorio].apellido);
       listaActor[numAleatorio].oscar = 1;
      }

}
// en esta funcion valido si el numero es repetido, si es repetido retorno 0,
// si no es repetido retorno 1
int NumeroRepetido(int array[], int i, int numAleatorio){

	  int retorno = 1;

	    for(i = 0; i < TAM; i++)
	    {
	      if(numAleatorio == array[i]){
	          retorno = 0;
	      }
	    }
	    return retorno;
}
// trabajo con dos for para moverme por las dos estructuras, por la de actores y peliculas,
// muestro a los actores que hayan trabajado en peliculas ganadoras de oscar no hay retorno
void ListadoDeActoresOscar(ePelicula lista[], int size, eActor listaActor[], int sizeActor, eRol listaRol[]){


	for (int i = 0; i < sizeActor; i++){

     for(int j = 0; j < size; j++){

    	 if(strcmp(listaActor[i].pelicula, lista[j].titulo)==0){

    		 if(listaActor[i].oscar == 1 && lista[j].oscar == 1){

    			 printf("El actor %s %s gano un oscar y participo en %s que tambien gano un oscar",listaActor[i].nombre, listaActor[i].apellido,lista[j].titulo);
                 printf(" y cumplia el rol %s \n", listaRol[i].descripcion);
    		 }
    	 }
     }
 }
}
// por el metodo de burbujeo ordeno las peliculas para ver cual recaudo mas
// no hay retorno
void ListarPeliculasRecaudacionDuracion(ePelicula lista[], int size, eActor listaActor[], int sizeActor){

	int auxLista;

	for(int i = 0; i < sizeActor-1; i++)
	    {
	        for(int j = i + 1; j < size; j++)
	        {

	        	if (lista[i].recaudacion < lista[j].recaudacion) {

	        				auxLista = lista[i].recaudacion;
	        				lista[i].recaudacion = lista[j].recaudacion;
	        				lista[j].recaudacion = auxLista;

	         }
	      }
	    }
	MostrarPeliculasRecaudacionDuracion(lista,size);

}
// muestro las peliculas en orden no hay retorno
void MostrarPeliculasRecaudacionDuracion(ePelicula lista[], int size){

	for(int i =0; i<size; i++){

		printf("La pelicula %s recaudo %0.f y dura %d minutos \n",lista[i].titulo,lista[i].recaudacion ,lista[i].duracion);

	}
}
// por metodo de burbujeo ordeno a los actores por rol no hay retorno
void ActoresOrdenadosPorRol(ePelicula lista[], eActor listaActor[], int sizeActor, eRol listaRol[]){


eRol auxLista;

	for (int i = 0; i < sizeActor - 1; i++) {

		for (int j = i + 1; j < sizeActor; j++) {

			if (strcmp(listaRol[i].descripcion, listaRol[j].descripcion)>0) {

				auxLista = listaRol[i];
				listaRol[i] = listaRol[j];
				listaRol[j] = auxLista;
			}
		}
	}

	MostrarActoresOrdenadosPorRol(listaActor,sizeActor, listaRol);

}
// muestro los actores no hay retorno
void MostrarActoresOrdenadosPorRol(eActor listaActor[], int sizeActor, eRol listaRol[]){

	for(int i=0; i< sizeActor ; i++){

		printf("El actor %s %s tuvo el rol de %s en la pelicula %s \n",listaActor[i].nombre,listaActor[i].apellido, listaRol[i].descripcion, listaActor[i].pelicula);

	}
}
// ordeno por metodo de burbujeo las peliculas para ver cual se estrena antes no hay retorno
void PeliculasOrdenadasPorFecha(ePelicula lista[], int size, eActor listaActor[], int sizeActor){

	int auxLista;

	for(int i = 0; i < sizeActor-1; i++)
	    {
	        for(int j = i + 1; j < size; j++)
	        {

	        	if (lista[i].fechas.anio > lista[j].fechas.anio){
	        		if(lista[i].fechas.mes > lista[j].fechas.mes){

	        				auxLista = lista[i].fechas.anio;
	        				lista[i].fechas.anio = lista[j].fechas.anio;
	        				lista[j].fechas.anio = auxLista;

	        				auxLista = lista[i].fechas.mes;
	        				lista[i].fechas.mes = lista[j].fechas.mes;
	        				lista[j].fechas.mes = auxLista;

	        	}
	        }
	       }
	    }
	MostrarOrdenadasPorFecha(lista, size);
}
// muestro las peliculas en el orden deseado no hay retorno
void MostrarOrdenadasPorFecha(ePelicula lista[], int size){

	for(int i =0; i<size; i++){

		printf("La pelicula %s se estreno el %d/%d/%d \n",lista[i].titulo,lista[i].fechas.anio ,lista[i].fechas.mes, lista[i].fechas.dia);

	}
}
