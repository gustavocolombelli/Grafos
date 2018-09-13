#include "Grafo.h"

Grafo * criaGrafo(int quantidadeVertices, int grauMax, int isPonderado)
{

    Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));

    if(gr != NULL){

        int i;

        gr->quantidadeVertices = quantidadeVertices;
        gr->grauMax = grauMax;
        gr->isPonderado = ( isPonderado !=0 ) ? 1 : 0;
        gr->graus=(int *)calloc( quantidadeVertices, sizeof(int));
        gr->arestas=(int** )malloc( quantidadeVertices * sizeof(int));

        for( i=0 ; i < quantidadeVertices ; i++ )
        {
            gr->arestas[i]=(int* )malloc(grauMax * sizeof(int));
        }

        if( gr->isPonderado )
        {
            gr->pesos=(float**)malloc(quantidadeVertices*sizeof(float*));

            for( i=0 ; i < quantidadeVertices ; i++ )
            {
                gr->pesos[i]=(float*)malloc(grauMax*sizeof(float));
            }

        }
    }
    return gr;
}

void liberaGrafo(Grafo*gr) {
     int i;
    if(gr != NULL ) {


        for(i=0;i<gr->quantidadeVertices;i++)
            free(gr->arestas[i]);
        free(gr->arestas);
    }

    if(gr->isPonderado){
        for(i=0;i<gr->quantidadeVertices;i++)
            free(gr->pesos[i]);
        free(gr->pesos);
    }
    free(gr->graus);
    free(gr);

};

int insereAresta(Grafo*gr, int origem, int destino, int isDigrafo, float peso) {

    if( gr == NULL )return 0;

    if( origem < 0 || origem >= gr->quantidadeVertices )return 0;

    if( destino < 0 || destino >= gr->quantidadeVertices )return 0;

    gr->arestas[origem][gr->graus[origem]] = destino;

    if( gr->isPonderado) gr->pesos[origem][gr->graus[origem]] = peso;

    gr->graus[origem]++;

    if( isDigrafo == 0 ) insereAresta(gr, destino, origem, 1, peso);

    return 1;

};

int removeAresta(Grafo*gr, int origem, int destino, int isDigrafo) {

    if( gr == NULL) return 0;

    if( origem  < 0 || origem >= gr->quantidadeVertices) return 0;

    if( destino < 0 || destino >= gr->quantidadeVertices) return 0;

    int i = 0;

    while( i < gr->graus[origem] && gr->arestas[origem][i] != destino)
        i++;

    if( i == gr->graus[origem] ) return 0;

    gr->graus[origem]--;

    gr->arestas[origem][i] = gr->arestas[origem][gr->graus[origem]];

    if( gr->isPonderado )
        gr->pesos[origem][i] = gr->pesos[origem][gr->graus[origem]];

    if(isDigrafo == 0)
        removeAresta(gr, destino, origem, 1);

    return 1;


};

void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont) {

    int i;
    visitado[ini] = cont;

    for( i=0 ; i<gr->graus[ini] ; i++){

        if(!visitado[gr->arestas[ini][i]])

            buscaProfundidade( gr, gr->arestas[ini][i], visitado, cont+1);

    }

};

void buscaProfundidadeGrafo(Grafo *gr, int verticeInicial, int *visitado)
{

    int i;
    int cont = 1;

    for( i = 0; i < gr->quantidadeVertices ; i++ )
        visitado[i] = 0;

    buscaProfundidade(gr,verticeInicial,visitado,cont);

};

void buscaLarguraGrafo(Grafo *gr, int ini, int *visitado) {
    int i, vert, numeroDeVertices, cont=1, *fila, IF=0, FF=0;

    //Faz marcação de vértices como não visitados
    for( i=0 ; i<gr->quantidadeVertices ; i++)
        visitado[i]=0;

    //Cria fila, visita e insere ini na fila
    numeroDeVertices = gr->quantidadeVertices;

    fila=(int*) malloc(numeroDeVertices* sizeof(int));
    FF++;
    fila[FF]= ini;
    visitado[ini] = cont;

    while(IF != FF){
        //pega o primeiro da fila
        IF = (IF + 1) % numeroDeVertices;
        vert = fila[IF];
        cont++;

        //visita os vizinhos ainda não visitados e coloca na fila
        for( i=0 ; i < gr->graus[vert] ; i++){
            if( !visitado[gr->arestas[vert][i]] ){
                FF = (FF+1)%numeroDeVertices;
                fila[FF] = gr->arestas[vert][i];
                visitado[gr->arestas[vert][i]] = cont;
            }
        }

    }
    free(fila);
};
void menorCaminhoGrafo(Grafo *gr, int ini, int*ant, float *dist) {

    int i, cont, numeroDeVertices, ind, *visitado, u;

    cont = numeroDeVertices = gr->quantidadeVertices;
    visitado = (int*) malloc(numeroDeVertices * sizeof(int));

    for( i = 0 ; i < numeroDeVertices ; i++ )
    {
        ant[i]= -1;
        dist[i] = -1;
        visitado[i]=0;
    }

    dist[ini] = 0;

    while( cont > 0 ) {

        u = procuraMenorDistancia(dist, visitado, numeroDeVertices);

        if( u == -1 )
            break;

        visitado[u] = 1;
        cont--;

        for(i=0;i<gr->graus[u];i++) {
            ind = gr->arestas[u][i];
            if(dist[ind] < 0)
            {
                dist[ind] = dist[u] +1;
                ant[ind] = u;
            }
            else
            {
                if(dist[ind] > dist[u] +1)
                {
                    dist[ind] = dist[u] +1;
                }
                ant[ind] = u;
            }
        }
    }

    free(visitado);

};

int procuraMenorDistancia(float *distancia, int *visitado, int numeroDeVertices) {

    int i, menor = -1, primeiro=1;

    for( i=0 ; i< numeroDeVertices ; i++ ){
        if( distancia[i] >= 0 && visitado[i] == 0 ){
            if( primeiro )
            {

                menor = i;
                primeiro = 0;

            }
            else
            {
                if(distancia[menor] > distancia[i])
                        menor = i;
            }
        }

    }
    return menor;
};
