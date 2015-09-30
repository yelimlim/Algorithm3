#include "stdafx.h"
#include "Grape.h"

//#define MAX 100;

const int MAX = 100;

int CycleMemorize(WeightGrape* G, WeightVertex* S, WeightVertex* E)
{
    int** pathWeight = new int*[G->vertexNum];
    for (int i = 0; i < G->vertexNum; ++i)
    {
        pathWeight[i] = new int[G->vertexNum];
    }

    for (int i = 0; i < G->vertexNum; ++i)
    {
        for (int j = 0; j < G->vertexNum; ++j)
        {
            pathWeight[i][j] = MAX;
        }
    }

    for (int i = 0; i < G->vertexNum; ++i)
    {
        pathWeight[i][S->id] = 0;
    }

    return CycleMemorize(G, G->vertexNum - 1, E->id, pathWeight);
}

//CycleMemorize ���� ���ۺκ�
//��ȯ ��
//- pathWeight[i][j] ��
//�Ű�����
//- G: �־��� �׷���
//- i: edge ��ģ Ƚ��
//- j: S�κ����� �Ÿ��� ã�����ϴ� vertex�� �ε��� �� = �ش� vertex�� id ���� ����.
//- pathWeight : �Ÿ��� �����ϱ� ���� ��
int CycleMemorize(WeightGrape* G, int i, int j, int** pathWeight)
{
    if (i < 0)
    {
        return MAX;
    }

    if (pathWeight[i][j] != MAX)
    {
        return pathWeight[i][j];
    }

    for (int e = 0; e < G->vertexes[j]->inEdge.size(); ++e)
    {
        int weight = G->vertexes[j]->inEdge[e]->weight + CycleMemorize(G, i - 1, G->vertexes[j]->inEdge[e]->S->id, pathWeight);

        if (pathWeight[i][j] > weight)
        {
            pathWeight[i][j] = weight;
        }
    }

    return pathWeight[i][j];
}

int CycleTopological(WeightGrape* G, WeightVertex* S, WeightVertex* E)
{
    WeightGrape newG;
    MakeDubleG(G, &newG);

    std::list<WeightVertex*> sortedG;

    TopologicalSort(&newG, &sortedG);

    for (auto v : sortedG)
    {
        v->distance = MAX;
    }

    int sIndex = S->id;

    for (int i = 0; i < G->vertexNum; ++i)
    {
        newG.vertexes[sIndex + i * G->vertexNum]->distance = 0;
    }
   
    for (auto i : sortedG)
    {
        for (int k = 0; k < i->outEdge.size(); ++k)
        {
            int dis = i->distance + i->outEdge[k]->weight;

            if (i->outEdge[k]->E->distance > dis)
            {
                i->outEdge[k]->E->distance = dis;
            }
        }
    }
    
    return newG.vertexes[E->id + (G->vertexNum - 1) *G->vertexNum]->distance;
}

void MakeDubleG(WeightGrape* G, WeightGrape* newG)
{
    for (int i = 0; i < G->vertexNum; ++i)
    {
        TwoIndexVertex* v = new TwoIndexVertex(G->vertexes[i], 0, i);
        AddVertex(newG, v);
    }

    for (int i = 1; i < G->vertexNum; ++i)
    {
        for (int j = 0; j < G->vertexNum; ++j)
        {
            TwoIndexVertex* v = new TwoIndexVertex(G->vertexes[j], i, j);
            AddVertex(newG, v);

            for (int k = 0; k < G->vertexes[j]->inEdge.size(); ++k)
            {
                int s = G->vertexes[j]->inEdge[k]->S->id + (i - 1) * G->vertexNum;

                LinkDirectVertex(newG, newG->vertexes[s], v, G->vertexes[j]->inEdge[k]->weight);
            }
        }
    }
}

int CycleBottomUp(WeightGrape* G, WeightVertex* S, WeightVertex* E)
{
    int** pathWeight = new int*[G->vertexNum];
    for (int i = 0; i < G->vertexNum; ++i)
    {
        pathWeight[i] = new int[G->vertexNum];
    }

    for (int i = 0; i < G->vertexNum; ++i)
    {
        for (int j = 0; j < G->vertexNum; ++j)
        {
            pathWeight[i][j] = MAX;
        }
    }

    for (int i = 0; i < G->vertexNum; ++i)
    {
        pathWeight[i][S->id] = 0;
    }

    for (int i = 1; i < G->vertexNum; ++i)
    {
        for (int j = 0; j < G->vertexNum; ++i)
        {
            for (int k = 0; k < G->vertexes[j]->inEdge.size(); ++k)
            {
                int dis = G->vertexes[j]->inEdge[k]->S->distance + G->vertexes[j]->inEdge[k]->weight;

                if (pathWeight[i][j] > dis)
                {
                    pathWeight[i][j] = dis;
                }
            }
        }
    }

    return pathWeight[G->vertexNum - 1][E->id];
}