#include <stdio.h>
#include <stdlib.h>

#include "Grafo.h"

int main()
{
   int isDigrafo;
   int i=0;
   Grafo * gr = criaGrafo(5, 5, 0);

   printf("Inserindo arestas no Grafo...");
   isDigrafo=0;

   insereAresta(gr, 0, 1, isDigrafo, 0);
   insereAresta(gr, 1, 3, isDigrafo, 0);
   insereAresta(gr, 1, 2, isDigrafo, 0);
   insereAresta(gr, 2, 4, isDigrafo, 0);
   insereAresta(gr, 3, 0, isDigrafo, 0);
   insereAresta(gr, 3, 4, isDigrafo, 0);
   insereAresta(gr, 4, 1, isDigrafo, 0);

   int vis[5];

   //--- BUSCA EM PROFUNDIDADE ---
   printf("\nRealizando busca em profundidade...");
   buscaProfundidadeGrafo(gr, 0, vis);

    for(i=0;i<5;i++)
        printf("\n%d", vis[i]);

    liberaGrafo(gr);

   //--- BUSCA EM LARGURA ---
   printf("\nRealizando busca em largura...");
   isDigrafo = 1;
   gr = criaGrafo(5, 5, 0);

   insereAresta(gr, 0, 1, isDigrafo, 0);
   insereAresta(gr, 1, 3, isDigrafo, 0);
   insereAresta(gr, 1, 2, isDigrafo, 0);
   insereAresta(gr, 2, 4, isDigrafo, 0);
   insereAresta(gr, 3, 0, isDigrafo, 0);
   insereAresta(gr, 3, 4, isDigrafo, 0);
   insereAresta(gr, 4, 1, isDigrafo, 0);

   buscaLarguraGrafo(gr,0,vis);
   for(i=0;i<5;i++)
        printf("\n%d", vis[i]);

    liberaGrafo(gr);

   //--- BUSCA PELO MENOR CAMINHO ---
   printf("\nRealizando busca do menor caminho...");
   isDigrafo = 1;
   gr = criaGrafo(5, 5, 0);

   insereAresta(gr, 0, 1, isDigrafo, 0);
   insereAresta(gr, 1, 3, isDigrafo, 0);
   insereAresta(gr, 1, 2, isDigrafo, 0);
   insereAresta(gr, 2, 4, isDigrafo, 0);
   insereAresta(gr, 3, 0, isDigrafo, 0);
   insereAresta(gr, 3, 4, isDigrafo, 0);
   insereAresta(gr, 4, 1, isDigrafo, 0);

   int ant[5];
   float distancia[5];

   menorCaminhoGrafo(gr, 0, ant, distancia);
    for(i=0;i<5;i++)
        printf("\nDistancia: %.2f || Ant: %d", distancia[i], ant[i]);

   liberaGrafo(gr);
//------------------------------------------------------
    return 0;


}
