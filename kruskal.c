#include"kruskalnuevo.h"

int main(){

    Grafo *grafo = (Grafo*)malloc(sizeof(Grafo)); //RESERVO MEMORIA PARA EL GRAFO Y EL ARBOL

        if(grafo == NULL){

            perror("No reserva memoria"); return -1;
        }

    Grafo *arbol = (Grafo*)malloc(sizeof(Grafo));

        if(arbol == NULL){

            perror("No reserva memoria"); return -1;
        }

    int vertices;  //USUARIO INGRESA CANT VERTICES

    do{

        printf("Ingrese cantidad de vertices del grafo: ");
        scanf("%d", &vertices); //AGREGAR WHILE PARA N>=0

    } while(vertices<=0);

    printf("\n");

    int costos[vertices][vertices]; //MATRIZ DE ADYACENCIA CON COSTOS DE LAS ARISTAS
    int i, j;

    for(i=0; i<=vertices-1; i++){  // INGRESO DE PESOS/COSTOS DEL GRAFO -APUNTE

        for(j=i+1; j<=vertices-1; j++){

            do{

                printf("Ingrese costo entre %d y %d: ", i, j); //AGREGAR WHILE PARA N>0
                scanf("%d", &costos[i][j]);

            } while(costos[i][j]<0);
        }
    }

    Kruskal(grafo, arbol, vertices, costos);

    int total = 0; //IMPRIME RESULTADO

    printf("\n\n -- ARBOL -- \n");

    for(i=0; i<(arbol)->cont; i++){

        printf("\nVertice '%d' y vertice '%d', total costo = %d", (arbol)->aristas[i].origen, (arbol)->aristas[i].dest, (arbol)->aristas[i].peso);
        total = total + (arbol)->aristas[i].peso;
    }

    printf("\n\nPeso total del arbol minimo = %d \n", total);

    free(grafo);
    free(arbol);

    return 0;
}
