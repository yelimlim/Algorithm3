#include "stdafx.h"
#include <queue>
#include <stack>
#include <list>

void BFS(Grape* G)
{
    printf("BFS\n\n");

    Vertex* V;
    std::queue<Vertex*> Q;

    G->source->isVisit = true;
    Q.push(G->source);

    while (!Q.empty())
    {
        V = Q.front();
        Q.pop();

        printf("Vertex -id %d\n", V->id);

        for (int i = 0; i < V->edgeNum; ++i)
        {
            if (!V->edge[i]->isVisit)
            {
                V->edge[i]->isVisit = true;
                Q.push(V->edge[i]);
            }
        }
    }
}

void DFS(Grape* G)
{
    printf("DFS\n\n");

    Vertex* V;
    std::stack<Vertex*> S;

    G->source->isVisit = true;
    S.push(G->source);

    while (!S.empty())
    {
        V = S.top();
        S.pop();

        printf("Vertex -id %d\n", V->id);

        for (int i = 0; i < V->edgeNum; ++i)
        {
            if (!V->edge[i]->isVisit)
            {
                V->edge[i]->isVisit = true;
                S.push(V->edge[i]);
            }
        }
    }
}

void DFS(Grape* G, std::list<Vertex*>* list)
{
    Vertex* V;
    std::stack<Vertex*> S;

    G->source->isVisit = true;
    S.push(G->source);
    list->push_back(G->source);

    while (!S.empty())
    {
        V = S.top();
        S.pop();

        for (int i = 0; i < V->edgeNum; ++i)
        {
            if (!V->edge[i]->isVisit)
            {
                V->edge[i]->isVisit = true;
                S.push(V->edge[i]);
                list->push_back(V->edge[i]);
            }
        }
    }
}

void TopologicalSort(Grape* G)
{
    printf("TopologicalSort");

    std::list<Vertex*> list;

    DFS(G, &list);

    for (auto& vertex : list)
    {
        printf("%d, ", vertex->id);
    }

    printf("\n");
}

void AddVertex(Grape* G, Vertex* V)
{
    G->vertexes.push_back(V);

    if (G->source == nullptr)
    {
        G->source = V;
    }
}

void LinkVertex(Vertex* a, Vertex* b)
{
    a->edge.push_back(b);
    ++a->edgeNum;
    b->edge.push_back(a);
    ++b->edgeNum;
}

void LinkDirectVertex(Vertex* start, Vertex* end)
{
    start->edge.push_back(end);
    ++start->edgeNum;
}