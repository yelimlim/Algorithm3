#include "stdafx.h"
#include <stack>
#include <vector>
#include <list>

//For NonWeight Grape
void DFS(NonWeightGrape* G, std::vector<NonWeightVertex*>* vector)
{
    NonWeightVertex* V;
    std::stack<NonWeightVertex*> S;

    G->source->isVisit = true;
    S.push(G->source);
    vector->push_back(G->source);

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
                vector->push_back(V->edge[i]);
            }
        }
    }
}

void TopologicalSort(NonWeightGrape* G, std::vector<NonWeightVertex*>* vector)
{
    printf("TopologicalSort");

    DFS(G, vector);

    printf("\n");
}

void TopologicalSort(NonWeightGrape* G)
{
    std::vector<NonWeightVertex*> vector;

    TopologicalSort(G, &vector);

    for (auto& vertex : vector)
    {
        printf("%d, ", vertex->id);
    }

    printf("\n");
}

void AddVertex(NonWeightGrape* G, NonWeightVertex* V)
{
    G->vertexes.push_back(V);

    if (G->source == nullptr)
    {
        G->source = V;
    }
}

void AddVertex(NonWeightGrape* G, NonWeightVertex* V, int n)
{
    G->vertexes[n] = V;

    if (G->source == nullptr)
    {
        G->source = V;
    }
}

void LinkDirectVertex(NonWeightVertex* start, NonWeightVertex* end)
{
    start->edge.push_back(end);
    ++start->edgeNum;
}






//For Weight Grape
void DFS(WeightGrape* G, std::list<WeightVertex*>* list)
{
    WeightVertex* V;
    std::stack<WeightVertex*> stack;

    G->source->isVisit = true;
    stack.push(G->source);
    list->push_back(G->source);

    while (!stack.empty())
    {
        V = stack.top();
        stack.pop();

        for (int i = 0; i < V->outEdge.size(); ++i)
        {
            if (!V->outEdge[i]->S->isVisit)
            {
                V->outEdge[i]->E->isVisit = true;
                stack.push(V->outEdge[i]->S);
                list->push_back(V->outEdge[i]->E);
            }
        }
    }
}

void TopologicalSort(WeightGrape* G, std::list<WeightVertex*>* list)
{
    printf("TopologicalSort");

    while (list->size <= G->vertexNum)
    {
        std::list<WeightVertex*> temp;

        DFS(G, &temp);

        auto iter = temp.begin();
        list->insert(iter++, list->begin(), list->end());
    }

    printf("\n");
}

void TopologicalSort(WeightGrape* G)
{
    std::list<WeightVertex*> list;

    TopologicalSort(G, &list);

    for (auto& vertex : list)
    {
        printf("%d, ", vertex->id);
    }

    printf("\n");
}

void AddVertex(WeightGrape* G, WeightVertex* V)
{
    G->vertexes.push_back(V);

    if (G->source == nullptr)
    {
        G->source = V;
    }
}

void LinkDirectVertex(WeightGrape* G, WeightVertex* start, WeightVertex* end, int weight)
{
    Edge* edge = new Edge{ weight, start, end };

    G->edges.push_back(edge);
    start->outEdge.push_back(edge);
    end->inEdge.push_back(edge);
}
