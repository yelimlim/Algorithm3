#include "stdafx.h"
#include "struct.h"
#include <queue>
#include <stack>

void BFS(Grape G)
{
    Vertex* V;
    std::queue<Vertex*> Q;
    Q.push(G.source);

    while (Q.empty())
    {
        V = Q.front();
        Q.pop();

        printf("Vertex -id %d\n", V->id);

        for (int i = 0; i < V->edgeNum - 1; ++i)
        {
            if (!V->edge[i]->isVisit)
            {
                V->edge[i]->isVisit = true;
                Q.push(V->edge[i]);
            }
        }
    }
}

void DFS(Grape G)
{
    Vertex* V;
    std::stack<Vertex*> S;
    S.push(G.source);

    while (S.empty())
    {
        V = S.top();
        S.pop();

        printf("Vertex -id %d\n", V->id);

        for (int i = 0; i < V->edgeNum - 1; ++i)
        {
            if (!V->edge[i]->isVisit)
            {
                V->edge[i]->isVisit = true;
                S.push(V->edge[i]);
            }
        }
    }
}

void AddVertex(Grape* G, int )