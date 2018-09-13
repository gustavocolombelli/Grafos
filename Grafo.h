#ifndef GRAFO_H   // guardas de cabe�alho, impedem inclus�es c�clicas
#define GRAFO_H

#include<stdio.h>
#include<stdlib.h>

//Lista de adjac�ncia

typedef struct grafo Grafo;

struct grafo{

    int isPonderado;
    int quantidadeVertices;
    int grauMax;
    int ** arestas;
    float **pesos;
    int *graus;

};

Grafo * gr;

Grafo * criaGrafo(int quantidadeVertices, int grauMax, int isPonderado);
void liberaGrafo(Grafo*gr);

int insereAresta(Grafo*gr, int origem, int destino, int isDigrafo, float peso);
int removeAresta(Grafo*gr, int origem, int destino, int isDigrafo);

// Buscas
void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont);
void buscaProfundidadeGrafo(Grafo *gr, int verticeInicial, int *visitado);



/*
Busca em largura.

Faz a partida de um v�rtice inicial, explorando todos os v�rtices vizinhos.
Em seguida, para cada v�rtice vizinho, ela repete este processo, visitando
os v�rtices ainda inexplorados

Pode ser usado para:
 -Achar componentes conectados;
 -Achar o menor caminho entre dois v�rtices;
 -Testar biparti��o em grafos;

*/
void buscaLarguraGrafo(Grafo *gr, int ini, int *visitado);


/*
Busca pelo menos caminho.

Parte de um v�rtice inicial, calcula a menor dist�ncia desse
vertice a todos os demais (desde que exista um caminho entre eles)

 -Algoritmo de Dijkstra
    -Resolve esse problema para grafos "dirigido" ou "n�o dirigido" com arestas de peso "n�o negativo"
*/
void menorCaminhoGrafo(Grafo *gr, int ini, int*ant, float *dist);
int procuraMenorDistancia(float *dis, int *visitado, int NV);
#endif
