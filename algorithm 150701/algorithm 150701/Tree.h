#include "stdafx.h"

int NodeCount(Node* N)
{
    if (N == nullptr)
    {
        return 0;
    }

    return NodeCount(N->left) + NodeCount(N->right) + 1;
}

int NodeCount(Tree* T)
{
    if (T->head == nullptr)
    {
        return 0;
    }

    return NodeCount(T->head->left) + NodeCount(T->head->right) + 1;
}

bool AddTreeNode(Tree* T, Node* N)
{
    if (T->head == nullptr)
    {
        T->head = N;
        return true;
    }

    return false;
}

bool AddTreeNode(Node* pN, Node* cN)
{
    if (pN->left == nullptr)
    {
        pN->left = cN;
        return true;
    }
    else if (pN->right == nullptr)
    {
        pN->right = cN;
        return true;
    }

    return false;
}