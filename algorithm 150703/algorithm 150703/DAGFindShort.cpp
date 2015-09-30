#include "stdafx.h"
#include "Grape.h"
#include <vector>

#define MAX 100

int DAGMemorize(WeightGrape* G, WeightVertex* S, WeightVertex* E)
{
    int* pathWeight = new int[G->vertexNum];

    for (int i = 0; i < G->vertexNum; ++i)
    {
        pathWeight[i] = MAX;
    }

    DAGMemorize(G, S, E, G->vertexNum - 1, pathWeight);

    return pathWeight[G->vertexNum - 1];
}

int DAGMemorize(WeightGrape* G, WeightVertex* S, WeightVertex* E, int k, int* pathWeight)
{
    if (pathWeight[k] != MAX)
    {
        return pathWeight[k];
    }

    if (E == S)
    {
        pathWeight[k] = 0;
        return 0;
    }
    else
    {
        int shortPath = MAX;

        for (int i = 0; i < E->inEdge.size(); ++i)
        {
            int path = E->inEdge[i]->weight + DAGMemorize(G, S, E->inEdge[i]->S, k - 1, pathWeight);

            if (shortPath > path)
            {
                shortPath = path;
            }
        }

        pathWeight[k] = shortPath;

        return pathWeight[k];
    }
} 

int DAGTopological(WeightGrape* G, WeightVertex* S, WeightVertex* E)
{
    std::list<WeightVertex*> sortedG;
    TopologicalSort(G, &sortedG);

    for (auto v : sortedG)
    {
        v->distance = MAX;
    }

    S->distance = 0;

    for (int i = 0; i < sortedG.size(); ++i)
    {
        for (auto j : sortedG)
        {
            for (int k = 0; k < j->outEdge.size(); ++k)
            {
                int dis = j->distance + j->outEdge[k]->weight;

                if (j->outEdge[k]->E->distance > dis)
                {
                    j->outEdge[k]->E->distance = dis;
                }
            }
        }
    }

    return E->distance;
}