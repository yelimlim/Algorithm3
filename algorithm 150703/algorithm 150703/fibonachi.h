#include "stdafx.h"
#include "Grape.h"
#include <vector>

int FibonacciRecursion(int n)
{
    if (n < 2)
    {
        return n;
    }

    return FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
}

int FibonacciTopDown(int n)
{
    int* result = new int[n];

    for (int i = 0; i <= n; ++i)
    {
        result[i] = -1;
    }
    
    int res = FibonacciTopDown(n, result);

    delete[] result;

    return res;
}

int FibonacciTopDown(int n, int* result)
{
    if (result[n] == -1)
    {
        return result[n];
    }

    if (n < 2)
    {
        result[n] = n;
    }
    else
    {
        result[n] = FibonacciTopDown(n - 1, result) + FibonacciTopDown(n - 2, result);
    }

    return result[n];
}

int FibonacciBottomUp(int n)
{
    int* result = new int[n];
    
    for (int i = 0; i <= n; ++i)
    {
        result[n] = -1;
    }

    result[0] = 0;
    result[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        result[i] = result[n - 1] + result[n - 2];
    }

    int res = result[n];

    delete[] result;

    return res;
}

int FibonacciTopological(int n)
{
    NonWeightGrape g;

    NonWeightVertex* a = new NonWeightVertex{ 0, 0, 0, std::vector<NonWeightVertex*>(), false };
    NonWeightVertex* b = new NonWeightVertex{ 1, 1, 0, std::vector<NonWeightVertex*>(), false };
    AddVertex(&g, a, 0);
    AddVertex(&g, b, 1);

    for (int i = 2; i <= n; ++i)
    {
        NonWeightVertex* v = new NonWeightVertex{ i, -1, 0, std::vector<NonWeightVertex*>(), false };
        AddVertex(&g, v, i);
        LinkDirectVertex(g.vertexes[i - 1], v);
        LinkDirectVertex(g.vertexes[i - 2], v);
    }

    std::vector<NonWeightVertex*> vector;

    TopologicalSort(&g, vector);

    for (int i = 2; i <= n; ++i)
    {
        vector[i]->value = vector[i - 1]->value + vector[i - 2]->value;
    }

    return vector[n]->value;
}