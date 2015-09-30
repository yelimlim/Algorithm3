// algorithm 150701.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Tree.h"
#include "Grape.h"
#include <vector>

Tree MakeExampleTree()
{
    Tree* tree = new Tree{ nullptr };
    Node* a = new Node{ nullptr, nullptr };
    Node* b = new Node{ nullptr, nullptr };
    Node* c = new Node{ nullptr, nullptr };
    Node* d = new Node{ nullptr, nullptr };
    Node* e = new Node{ nullptr, nullptr };
    Node* f = new Node{ nullptr, nullptr };

    AddTreeNode(tree, a);
    AddTreeNode(a, b);
    AddTreeNode(a, c);
    AddTreeNode(b, d);
    AddTreeNode(b, e);
    AddTreeNode(c, f);

    return *tree;
}

Grape MakeExampleGrape()
{
    Grape* grape = new Grape{ nullptr, std::vector<Vertex*>() };
    Vertex* a = new Vertex{ 1, 0, std::vector<Vertex*>(), false };
    Vertex* b = new Vertex{ 2, 0, std::vector<Vertex*>(), false };
    Vertex* c = new Vertex{ 3, 0, std::vector<Vertex*>(), false };
    Vertex* d = new Vertex{ 4, 0, std::vector<Vertex*>(), false };
    Vertex* e = new Vertex{ 5, 0, std::vector<Vertex*>(), false };
    Vertex* f = new Vertex{ 6, 0, std::vector<Vertex*>(), false };
    Vertex* g = new Vertex{ 7, 0, std::vector<Vertex*>(), false };

    AddVertex(grape, a);
    AddVertex(grape, b);
    AddVertex(grape, c);
    AddVertex(grape, d);
    AddVertex(grape, e);
    AddVertex(grape, f);
    AddVertex(grape, g);

    LinkVertex(a, b);
    LinkVertex(b, c);
    LinkVertex(c, d);
    LinkVertex(a, e);
    LinkVertex(c, e);
    LinkVertex(e, f);
    LinkVertex(f, g);

    return *grape;
}

Grape MakeExampleDirectGrape()
{
    Grape* grape = new Grape{ nullptr, std::vector<Vertex*>() };
    Vertex* a = new Vertex{ 1, 0, std::vector<Vertex*>(), false };
    Vertex* b = new Vertex{ 2, 0, std::vector<Vertex*>(), false };
    Vertex* c = new Vertex{ 3, 0, std::vector<Vertex*>(), false };
    Vertex* d = new Vertex{ 4, 0, std::vector<Vertex*>(), false };
    Vertex* e = new Vertex{ 5, 0, std::vector<Vertex*>(), false };
    Vertex* f = new Vertex{ 6, 0, std::vector<Vertex*>(), false };
    Vertex* g = new Vertex{ 7, 0, std::vector<Vertex*>(), false };

    AddVertex(grape, a);
    AddVertex(grape, b);
    AddVertex(grape, c);
    AddVertex(grape, d);
    AddVertex(grape, e);
    AddVertex(grape, f);
    AddVertex(grape, g);

    LinkDirectVertex(a, b);
    LinkDirectVertex(b, c);
    LinkDirectVertex(c, d);
    LinkDirectVertex(a, e);
    LinkDirectVertex(e, c);
    LinkDirectVertex(e, f);
    LinkDirectVertex(f, g);

    return *grape;
}

int _tmain(int argc, _TCHAR* argv[])
{
//     Tree tree = MakeExampleTree();
// 
//     int nodeNum = NodeCount(&tree);
// 
//     printf("nodeNum : %d\n", nodeNum);
//     getchar();

//     Grape grape = MakeExampleGrape();
// 
//     //BFS(&grape);
//     DFS(&grape);
//     getchar();

    Grape grape = MakeExampleDirectGrape();
    TopologicalSort(&grape);
    getchar();

	return 0;
}

