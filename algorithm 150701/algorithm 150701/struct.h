#include <vector>

struct Node
{
    Node* left;
    Node* right;
};

struct Tree
{
    Node* head;
};

struct Vertex
{
    int id;
    int edgeNum;
    std::vector<Vertex*> edge;
    bool isVisit;
};

struct Grape
{
    Vertex* source;
    std::vector<Vertex*> vertexes;
};