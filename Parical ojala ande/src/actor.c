
#include "actor.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// inicializo a los actores no hay retorno
void inicializarActores(eActor lista[], int size){
	for (int i = 0; i < size; i++) {
		lista[i].estado = LIBRE;
		strcpy(lista[i].pelicula, "desempleado");
	}
}
// muestro el submenu de gestion de actores y retorno
// la opcion validada
int MostrarGestionActor(void){
	int retorno;



	do {
		printf("         Gestion de Actores        \n");
		printf("---------------------------\n");
		printf(
				" 1 - Alta \n 2 - Modificar \n 3 - Baja \n 4 - Salir\n Su opcion: ");
		scanf("%d", &retorno);
	}while(retorno < 1 || retorno > 4);

	return retorno;
}
//Pido las estructuras y los sizes para despues mendiante el switch mandarselo a otras funciones,
// ademas de tomar la opcion que quiera el usuario no retorna nada
void GestionDeActores(eActor lista[], int size, eRol listaRol[]){

int opcion;
    do{
        opcion = MostrarGestionActor();

        switch(opcion){
           case 1:
            AltaActor(lista, TAM, listaRol);
           break;
           case 2:
        	ModificarActor(lista, TAM, listaRol);
           break;
           case 3:
            BajaActor(lista, TAM, listaRol);
           break;
        }
    }
    while(opcion != 4);


}
// pido la lista de actores y el tamanio del array
// no retorno nada pero ingreso a los actores siempre q haya espacio
void AltaActor(eActor lista[], int size, eRol listaRol[]){


    int auxCodigo;
    float auxSueldo;
    int verificador;
    int auxRol;
    int auxDiaInicio;
    int auxMesInicio;
    int auxAnioInicio;
    int auxDiaFinalizacion;
    int auxMesFinalizacion;
    int auxAnioFinalizacion;
    int auxPelicula;
    for(int i = 0;i < size; i++) {
		if (lista[i].estado == LIBRE) {


			auxCodigo =  getInt("Ingrese el codigo: ", "Error, ingrese un codigo valido: ",
								0, 1000);

			fflush(stdin);

		verificador = VerificadorCodigo(lista, TAM , auxCodigo);

	 if(verificador == 1){

		lista[i].codigo = auxCodigo;

		getString(lista[i].nombre, "Ingrese el nombre: ",
					"Error, ingrese un nombre valido: ", 0, 15);
		fflush(stdin);

		getString(lista[i].apellido, "Ingrese el apellido: ",
					"Error, ingrese un apellido valido: ", 0, 15);
		fflush(stdin);

		auxPelicula =  getInt("Ingrese la pelicula en la que trabaja\n 1- Los vengadores\n 2- Wolverin\n 3- Iron man \n Su opcion: ", "Error, ingrese un numero valido: ",
										1, 3);
		switch(auxPelicula){
		case 1:
			strcpy(lista[i].pelicula, "Los vengadores");
		break;
		case 2:
			strcpy(lista[i].pelicula, "Wolverin");
	    break;
		case 3:
			strcpy(lista[i].pelicula, "Ironman");
		break;
		}




		getString(lista[i].personaje, "Ingrese el personaje actuado: ",
					"Error, ingrese un personaje valido: ", 0, 15);
		fflush(stdin);

	//	getString(lista[i].rol, "Ingrese el rol: ",
	//				"Error, ingrese un rol valido: ", 0, 15);
	//	_fpurge(stdin);

	 auxRol = getInt("Ingrese un numero del 1 al 3 \n1- Heroe\n  2-Villano \n 3-Secundario \n Su opcion: ", "Error, dia invalido: ",
				1, 31);

	listaRol[i].idRol = auxRol;

	lista[i].rol = auxRol;

	switch(auxRol){

	    case 1:
	    strcpy(listaRol[i].descripcion, "Heroe");
	    break;
	    case 2:
	    strcpy(listaRol[i].descripcion, "Villano");
	    break;
	    case 3:
	    strcpy(listaRol[i].descripcion, "Secundario");
	    break;
	}

        auxDiaInicio = getInt("Ingrese el dia del inicio del contrato: ", "Error, dia invalido: ",
				1, 31);

        lista[i].fechas.diaInicio = auxDiaInicio;

        auxMesInicio = getInt("Ingrese el mes del inicio del contrato: ", "Error, mes invalido: ",
       				1, 12);

        lista[i].fechas.mesInicio = auxMesInicio;

        auxAnioInicio = getInt("Ingrese el anio del inicio del contrato: ", "Error, anio invalido: ",
              				2000, 2022);

        lista[i].fechas.anioInicio = auxAnioInicio;

        auxDiaFinalizacion = getInt("Ingrese el dia de finalizacion del contrato: ", "Error, dia invalido: ",
				1, 31);

        lista[i].fechas.diaFinalizacion = auxDiaFinalizacion;

        auxMesFinalizacion = getInt("Ingrese el mes de finalizacion del contrato: ", "Error, mes invalido: ",
       				1, 12);

        lista[i].fechas.mesFinalizacion = auxMesFinalizacion;

        auxAnioFinalizacion = getInt("Ingrese el anio de finalizacion del contrato: ", "Error, anio invalido: ",
              				2000, 2050);

        lista[i].fechas.anioFinalizacion = auxAnioFinalizacion;

		auxSueldo = getFloat("Ingrese el valor mensual del contrato: ",
					"Error, ingrese numero valido: ", 0, 999999);

		lista[i].sueldo = auxSueldo;

	//	auxOscar = getInt("Gano un oscar?\n 1-Si\n 2-No\n OPCION: ", "Error, ingrese un numero valido: ",
		//			1, 2);

	//	lista[i].oscar = auxOscar;

		lista[i].estado = OCUPADO;
		break;
		}
	 else{

		 printf("\n ingresaste una id repetida o invalida \n");

		}
      }
    }
}
// no retorno nada, pido la lista de actores y el tamanio de la estructuras
// en esta funcion llamo a otra funcion para que imprima a los actores y tomo el codigo
// del actor que quiera modificar, luego selecciona que cualidad quiere modificar
void ModificarActor(eActor lista[], int size, eRol listaRol[]){

	int opcion;
	int auxId;

	MostrarListaActores(lista, TAM, listaRol);
	auxId = getInt("Ingrese el codigo que quiere modificar: ", "Error, ingrese un codigo valido", 1, 1000);

	do{
		opcion = subMenuActores();
		switch(opcion){

		case 1:
			ModificarNombre(lista, TAM, auxId);
		break;

		case 2:
			ModificarPersonaje(lista, TAM, auxId);
		break;

		case 3:
			ModificarRol(lista, TAM, auxId, listaRol);
		break;

		case 4:
			ModificarSueldo(lista, TAM, auxId);
		break;

		case 5:
			ModificarFechaInicio(lista, TAM, auxId);
		break;
		case 6:
			ModificarFechaFinalizacion(lista, TAM, auxId);
		break;
		case 7:
			ModificarPelicula(lista, TAM, auxId);
		break;
		case 8:
			printf("volviendo al menu \n");
			break;
		}
	}
	while(opcion != 8);

}
// muestro un sub menu de Modificaciones y retorno un numero validado
// dentro de un parametro que yo seteo
int subMenuActores(){

	int retorno;



	do{
		printf("\n         Modificaciones        \n");
		printf("---------------------------\n");
		printf(
				"1- Nombre y apellido \n 2- Personaje \n 3- Rol \n 4- Sueldo \n 5- Modificar fecha de inicio del contrato \n 6- Modificar fecha de finalizacion del contrato\n7- Modificar Pelicula \n8- Salir \n Su opcion:");
		scanf("%d", &retorno);
	}while(retorno < 1 || retorno > 8);

	return retorno;
}
// hago un for donde llamo a una funcion que imprime un solo actor
// pero al estar adentro del for se imprime del tamanio del size de la structre ,
// no retorno nada
void MostrarListaActores(eActor lista[], int size, eRol listaRol[]){

	 for(int i=0; i<size; i++)
	    {
	        if(lista[i].estado == OCUPADO)
	        {
	        	MostrarUnActor(lista[i], listaRol[i]);
	        }

	    }
}
// muestro un actor no retorno nada
void MostrarUnActor(eActor lista, eRol listaRol){


 printf("\n El codigo es: %d \n" , lista.codigo);
 printf("%s %s, su personaje es %s \n y su rol es %s \n", lista.nombre, lista.apellido, lista.personaje, listaRol.descripcion );
 printf("Gana por mes: %d \n", lista.sueldo);
 if(lista.oscar == 1){
	 printf("Gano un oscar \n");
 }else{ printf("No gano un oscar \n"); }
}
// pido la lista de actores, el tamanio de la estrucutra y el id
// no retorno nada, si el id y el codigo son iguales y el estado es igual a OCUPADO
// se pueden modificar la cualidad deseada
void ModificarNombre(eActor lista[], int size, int index){

	char auxNombre[15];
	char auxApellido[15];

	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].codigo == index){

			 getString(auxNombre, "ingrese el nuevo nombre: ",
			                              " nombre muy largo o muy corto", 1, 15);

			      strcpy(lista[i].nombre, auxNombre);
			      printf("\n La modificacion del nombre fue exitosa \n");

		 getString(auxApellido, "ingrese el nuevo apellido: ",
			     			                              " apellido muy largo o muy corto", 1, 15);

			      strcpy(lista[i].apellido, auxApellido);
			      printf("\n La modificacion del apellido fue exitosa \n");
			      break;
		}
	}
}
// pido la lista de actores, el tamanio de la estrucutra y el id
// no retorno nada, si el id y el codigo son iguales y el estado es igual a OCUPADO
// se pueden modificar la cualidad deseada
void ModificarPersonaje(eActor lista[], int size, int index){

	char auxPersonaje[15];

	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].codigo == index){

			 getString(auxPersonaje, "ingrese el nuevo nombre del personaje: ",
			                              " nombre muy largo o muy corto", 1, 15);

			      strcpy(lista[i].personaje, auxPersonaje);
			      printf("\n La modificacion del personaje fue exitosa \n");

			      break;
		}
	}
}
// pido la lista de actores, el tamanio de la estrucutra y el id
// no retorno nada, si el id y el codigo son iguales y el estado es igual a OCUPADO
// se pueden modificar la cualidad deseada
void ModificarRol(eActor lista[], int size, int index, eRol listaRol[]){

	int auxRol;

	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].codigo == index){

	auxRol = getInt("Ingrese un numero del 1 al 3 \n1- Heroe\n  2-Villano \n 3-Secundario \n Su opcion: ", "Error, dia invalido: ",
				1, 31);

	listaRol[i].idRol = auxRol;
	lista[i].rol = auxRol;

	switch(auxRol){

	    case 1:
	    strcpy(listaRol[i].descripcion, "Heroe");
	    break;
	    case 2:
	    strcpy(listaRol[i].descripcion, "Villano");
	    break;
	    case 3:
	    strcpy(listaRol[i].descripcion, "Secundario");
	    break;
	}
		}
	}
}
// pido la lista de actores, el tamanio de la estrucutra y el id
// no retorno nada, si el id y el codigo son iguales y el estado es igual a OCUPADO
// se pueden modificar la cualidad deseada
void ModificarSueldo(eActor lista[], int size, int index){

float auxSueldo;

	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].codigo == index){

			auxSueldo = getFloat("Ingrese el sueldo del actor: ",
			                           "Ingrese un sueldo valido", 1, 999999);

			     lista[i].sueldo = auxSueldo;


			      break;
		}
	}

}
// pido la lista de actores, el tamanio de la estrucutra y el id
// no retorno nada, si el id y el codigo son iguales y el estado es igual a OCUPADO
// se pueden modificar la cualidad deseada
/*void ModificarOscar(eActor lista[], int size, int index){

int auxOscar;

	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].codigo == index){

			auxOscar = getInt("Gano un oscar?\n 1-Si\n 2-No\n OPCION: ", "Error, ingrese un numero valido: ",
								1, 2);

					lista[i].oscar = auxOscar;


			      break;
		}
	}

}*/
// pido la lista de actores, el tamanio de la estrucutra y el id
// no retorno nada, si el id y el codigo son iguales y el estado es igual a OCUPADO
// se pueden modificar la cualidad deseada
void ModificarFechaInicio(eActor lista[], int size, int index){

    int auxDiaInicio;
    int auxMesInicio;
    int auxAnioInicio;
	for (int i = 0; i < size; i++) {

			if(lista[i].estado == OCUPADO && lista[i].codigo == index){


		        auxDiaInicio = getInt("Ingrese el dia del inicio del contrato: ", "Error, dia invalido: ",
						1, 31);

		        lista[i].fechas.diaInicio = auxDiaInicio;

		        auxMesInicio = getInt("Ingrese el mes del inicio del contrato: ", "Error, mes invalido: ",
		       				1, 12);

		        lista[i].fechas.mesInicio = auxMesInicio;

		        auxAnioInicio = getInt("Ingrese el anio del inicio del contrato: ", "Error, anio invalido: ",
		              				2000, 2022);

		        lista[i].fechas.anioInicio = auxAnioInicio;

				      break;
  }
 }
}
// pido la lista de actores, el tamanio de la estrucutra y el id
// no retorno nada, si el id y el codigo son iguales y el estado es igual a OCUPADO
// se pueden modificar la cualidad deseada
void ModificarFechaFinalizacion(eActor lista[], int size, int index){

    int auxDiaFinalizacion;
    int auxMesFinalizacion;
    int auxAnioFinalizacion;

	for (int i = 0; i < size; i++) {

			if(lista[i].estado == OCUPADO && lista[i].codigo == index){

				auxDiaFinalizacion = getInt("Ingrese el dia de finalizacion del contrato: ", "Error, dia invalido: ",
								1, 31);

				lista[i].fechas.diaFinalizacion = auxDiaFinalizacion;

				auxMesFinalizacion = getInt("Ingrese el mes de finalizacion del contrato: ", "Error, mes invalido: ",
				       				1, 12);

				lista[i].fechas.mesFinalizacion = auxMesFinalizacion;

			auxAnioFinalizacion = getInt("Ingrese el anio de finalizacion del contrato: ", "Error, anio invalido: ",
				              				2000, 2050);

	         lista[i].fechas.anioFinalizacion = auxAnioFinalizacion;
				      break;
  }
 }


}
// pido la lista de actores, el tamanio de la estrucutra y el id
// no retorno nada, si el id y el codigo son iguales y el estado es igual a OCUPADO
// se pueden modificar la cualidad deseada
void ModificarPelicula(eActor lista[], int size, int index){

int auxPelicula;

	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].codigo == index){

			auxPelicula =  getInt("Ingrese la pelicula en la que trabaja\n 1- Los vengadores\n 2- Wolverin\n 3- Iron man \n Su opcion: ", "Error, ingrese un numero valido: ",
												1, 3);
				switch(auxPelicula){
				case 1:
					strcpy(lista[i].pelicula, "Los vengadores");
				break;
				case 2:
					strcpy(lista[i].pelicula, "Wolverin");
			    break;
				case 3:
					strcpy(lista[i].pelicula, "Ironman");
				break;
				}
			      break;
		}
	}

}
// pido la lista de actores y el tamanio de la estrucutra,
// no retorno nada, aca doy de baja a los actores
void BajaActor(eActor lista[], int size, eRol listaRol[]){

	int i;
	int index;

	MostrarListaActores(lista, TAM, listaRol);
    index = getInt("\n Ingrese el codigo a dar de baja: ","\n Error el codigo ingresado supera los limites: ",0,1000);

    for(i =0 ; i < size; i++)
        {
          if(lista[i].codigo == index)
          {
              lista[i].estado = LIBRE;
              break;
          }
        }
}
// aca me aseguro que no ingresen ids repetidas asi despues no tengo
// problemas con los actores para darlos de baja o trabajar en algunas cosas
// retorno 1 si no es repetido y -1 si es repetido,
// pido la lista de actores, el tamanio de la estrucutra y el id para verificar
int VerificadorCodigo(eActor lista[] , int size , int index){

	int retorno = 1;

	for (int i = 0; i < size; ++i) {

		if(lista[i].codigo == index){

			retorno = -1 ;
			break;
		}
	}

return retorno;
}
