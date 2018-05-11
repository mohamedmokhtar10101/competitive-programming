#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include<stdlib.h>
#define MAXVERICES 4
typedef int GraphElement;
typedef struct edge
{
    int endPoint;
    struct edge * nextEdge;
} Edge;
typedef struct vertix
{   int numberOfEdges;
    GraphElement e;
    Edge * firstEdge;
} Vertix;
typedef struct graph
{
    int size;
    int numberOfEdges;
    Vertix vertices[MAXVERICES];
} Graph;
void intializeGraph(Graph * pg)
{
    int i;
    pg->size = 0;
    pg->numberOfEdges = 0;
    for(i = 0;i < MAXVERICES ;i++)
    {
        pg->vertices[i].firstEdge = NULL;
         pg->vertices[i].numberOfEdges = 0;
    }
}
static void traverseDepthFirstAux(Graph * pg , int k , void (*visit)(GraphElement) , int visited [])
{
    (*visit)(pg->vertices[ k ].e);
    visited[ k ] = 1;
    Edge * t ;
    for(t = pg->vertices[ k ].firstEdge ; t != NULL ; t = t->nextEdge)
        if(!visited[ t->endPoint ])
            traverseDepthFirstAux(pg , t->endPoint , visit , visited);
}
void traverseDepthFirst(Graph * pg , int start , void (*visit)(GraphElement))
{
    int visited[ MAXVERICES ] = {0};
    int i;
    if(pg->size != 0)
    {

    traverseDepthFirstAux(pg , start , visit , visited);
    for(i = 0 ; i < pg->size ; i++)
        if(!visited[ i ])
            traverseDepthFirstAux(pg , i , visit ,visited);
    }
}
void buildGraphFromAdjacency(Graph * pg  , int size , int graph[][MAXVERICES])
{
    int i;
    int j;
    Edge * e;
    Edge * hold;
    for(i = 0 ; i < size ; i++)
    {
        pg->vertices[ i ].e = i;
        for(j = 0 ; j < MAXVERICES ; j++)
            if(graph [ i ][ j ])
            {
                e = malloc(sizeof(Edge));
                e->endPoint = j;
                e->nextEdge = NULL;
               if(pg->vertices[ i ].firstEdge == NULL)
                   pg->vertices[ i ].firstEdge = e;
               else
                   hold->nextEdge = e;

                hold = e;
                pg->vertices[ i ].numberOfEdges++;
            }
        pg->numberOfEdges += pg->vertices[ i ].numberOfEdges;
    }

   pg ->size = size;
}
void clearGraph(Graph * pg)
{
    int i ;
    Edge * current;
    Edge * hold;
    for(i = 0 ; i < pg->size ; i++)
    {
        for(current = pg->vertices[ i ].firstEdge ; current != NULL ;)
        {
            hold = current->nextEdge;
            free(current);
            current = hold;
        }
        pg->vertices[ i ].firstEdge = NULL;
        pg->vertices[ i ].numberOfEdges = 0;
    }
    pg->size = 0;
    pg->numberOfEdges = 0;
}
int graphVerticesNumber(Graph * pg)
{
    return  pg->size;
}
int graphEdgesNumber(Graph * pg)
{
    return pg->numberOfEdges;
}
int graphEmpty(Graph * pg)
{
    return !pg->size;
}
int graphFull(Graph *pg)
{
    return pg->size == MAXVERICES;
}
int vertixEdgesNumber(Graph * pg , int index)
{
    return pg->vertices[ index ].numberOfEdges;
}
#endif // GRAPH_H_INCLUDED
