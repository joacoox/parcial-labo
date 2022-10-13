#include "funciones.h"
#include "actor.h"

int main(void) {

	setbuf(stdout, NULL);


	int opcion;

	ePelicula listaPeliculas[TAMPELICULAS]={{1 , "Los vengadores" , 120 , "Michael jordan" ,{ 20 , 5 , 2018 }, 0 , OCUPADO , 1 },
	                               {2 , "Wolverin" , 50 , "jiu jackman" , {11 , 3 , 2015 }, 0 , OCUPADO,  1 },
	                               {3 , "Ironman" , 90 , "messi" , {5 , 11 , 2022 }, 0 , OCUPADO , 1 }};

	eActor listaActores[TAM]={{1,"Joaco","Dominguez","Batman",1,{12,5,2005,15,12,2022},"Ironman",50000,0,OCUPADO},
	                           {2,"Arturo","Vidal","Joker",2,{23,1,2020,15,12,2022},"Los vengadores",45000,0,OCUPADO},
	                           {3,"Juan","Menem","Superman",2,{6,12,2019,15,12,2022},"Los vengadores",22000,0,OCUPADO},
	                            {4,"Roberto","Illia","IronMan",3,{1,8,2018,15,12,2022},"Wolverin",18000,0,OCUPADO},
	                           {5,"JoseFino","Del bosque","hulk",3,{29,4,2017,15,12,2022},"Ironman",20000,0,OCUPADO},
	                           {6,"hernesto","Dominguez","Batman",1,{12,5,2005,15,12,2022},"Ironman",50000,0,OCUPADO},
		                       {7,"montanioso","Vidal","Joker",1,{23,1,2020,15,12,2022},"Los vengadores",45000,0,OCUPADO},
		                       {8,"pepe","Menem","Superman",1,{6,12,2019,15,12,2022},"Los vengadores",22000,0,OCUPADO},
		                       {9,"pickle rick","Illia","IronMan",2,{1,8,2018,15,12,2022},"Wolverin",18000,0,OCUPADO},
		                       {10,"tu papitron","Del bosque","hulk",3,{29,4,2017,15,12,2022},"Ironman",20000,0,OCUPADO}};

    eRol listaRol[TAM]={{1, "Heroe"},
                        {2, "Villano"},
                        {2, "Villano"},
                        {3,"Secundario"},
                        {3,"Secundario"},
                        {1, "Heroe"},
                        {1, "Heroe"},
                        {1, "Heroe"},
                        {2, "Villano"},
                        {3,"Secundario"}};
    // 1 Heroe
    // 2 Villano
    // 3 Secundario


	//  inicializarActores(listaActores, TAM);

	    do{
	        opcion = MostrarMenu();

	        switch(opcion){

	           case 1:
	           GestionDeActores(listaActores, TAM, listaRol);
	           break;
	           case 2:
               GestionDePeliculas(listaPeliculas, TAMPELICULAS, listaActores, TAM);
	           break;
	           case 3:
	        	Informes(listaPeliculas, TAMPELICULAS, listaActores, TAM, listaRol);
	           break;
	        }


	    }
	    while(opcion != 4);

	return EXIT_SUCCESS;
}
