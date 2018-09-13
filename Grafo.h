#ifndef GRAFO_H   // guardas de cabeçalho, impedem inclusões cíclicas
#define GRAFO_H

#include<stdio.h>
#include<stdlib.h>

//Lista de adjacência

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

Faz a partida de um vértice inicial, explorando todos os vértices vizinhos.
Em seguida, para cada vértice vizinho, ela repete este processo, visitando
os vértices ainda inexplorados

Pode ser usado para:
 -Achar componentes conectados;
 -Achar o menor caminho entre dois vértices;
 -Testar bipartição em grafos;

*/
void buscaLarguraGrafo(Grafo *gr, int ini, int *visitado);


/*
Busca pelo menos caminho.

Parte de um vértice inicial, calcula a menor distância desse
vertice a todos os demais (desde que exista um caminho entre eles)

 -Algoritmo de Dijkstra
    -Resolve esse problema para grafos "dirigido" ou "não dirigido" com arestas de peso "não negativo"
*/
void menorCaminhoGrafo(Grafo *gr, int ini, int*ant, float *dist);
int procuraMenorDistancia(float *dis, int *visitado, int NV);
#endif
