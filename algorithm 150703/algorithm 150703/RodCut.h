#include "stdafx.h"
#include <vector>

int RodCutRecursive(int rodLength, std::vector<int>* price)
{
    if (rodLength == 0)
    {
        return 0;
    }

    int big = 0;

    for (int i = 1; i <= rodLength; ++i)
    {
        int p = price->at(i) + RodCutRecursive(rodLength - i, price);
        if (big < p)
        {
            big = p;
        }
    }

    return big;
}

int RodCutMemorize(int rodLength, std::vector<int>* price, int* result)
{
    if (result[rodLength] != -1)
    {
        return result[rodLength];
    }

    if (rodLength == 0)
    {
        result[rodLength] = 0;
    }
    else
    {
        int big = 0;

        for (int i = 1; i <= rodLength; ++i)
        {
            int p = price->at(i) + RodCutMemorize(rodLength, price, result);

            if (big < p)
            {
                big = p;
            }
        }

        result[rodLength] = big;
    }

    return result[rodLength];
}

int RodCutMemorize(int rodLength, std::vector<int>* price)
{
    if (rodLength == 0)
    {
        return 0;
    }

    int* result = new int[rodLength];

    for (int i = 0; i <= rodLength; ++i)
    {
        result[i] = -1;
    }

    int res = RodCutMemorize(rodLength, price, result);

    delete[] result;

    return res;
}

int RodCutBottomUp(int rodLength, std::vector<int>* price)
{
    if (rodLength == 0)
    {
        return 0;
    }

    int* result = new int[rodLength];

    for (int i = 0; i <= rodLength; ++i)
    {
        result[i] = -1;
    }

    result[0] = 0;
    result[1] = price->at(1);

    for (int i = 1; i <= rodLength; ++i)
    {
        int big = price->at(i);
        for (int j = 1; j <= i; ++j)
        {
            int p = result[j] + result[i - j];
            if (big < p)
            {
                big = p;
            }
        }
        result[i] = big;
    }

    int res = result[rodLength];

    delete[] result;

    return res;
}

//다시 한 번 볼 것
int RodCutBottomUpWhereCut(int rodLength, std::vector<int>* price, int* cut)
{
    if (rodLength == 0)
    {
        return 0;
    }

    int* result = new int[rodLength];
    cut = new int[rodLength];

    for (int i = 0; i <= rodLength; ++i)
    {
        result[i] = -1;
        cut[i] = 0;
    }

    result[0] = 0;
    result[1] = price->at(1);

    for (int i = 1; i <= rodLength; ++i)
    {
        int big = price->at(i);
        int where = 0;
        for (int j = 1; j <= i; ++j)
        {
            int p = result[j] + result[i - j];
            if (big < p)
            {
                big = p;
                where = j;
            }
        }
        result[i] = big;
        cut[i] = where;
    }

    int res = result[rodLength];

    delete[] result;

    return res;
}

void PrintRodCut(int* cut, int rodLength)
{
    while (rodLength > 0)
    {
        printf("%s ", cut[rodLength]);
        rodLength -= cut[rodLength];
    }
}