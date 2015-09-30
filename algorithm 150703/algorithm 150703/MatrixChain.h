#include "stdafx.h"
#include "Grape.h"

#include <list>

int MatrixChainRecursive(std::list<Matrix*>* M)
{
    if (M->size() == 1)
    {
        return 0;
    }

    for (std::list<Matrix*>::iterator iter = M->begin(); iter != M->end(); ++iter)
    {
        std::list<Matrix*> front;
        std::list<Matrix*>::iterator f = front.begin();
        front.insert(++f, M->begin(), iter);

        std::list<Matrix*> back;
        std::list<Matrix*>::iterator b = back.begin();
        back.insert(++b, ++iter, M->end());
        --iter;

        int num = MatrixChainRecursive(&front) + MatrixChainRecursive(&back) + M->front()->rowNum * iter->rowNum *M->back()->rowNum;
    }
}