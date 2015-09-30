#include <vector>

struct NonWeightVertex
{
    int id;
    int value;
    int edgeNum;
    std::vector<NonWeightVertex*> edge;
    bool isVisit;
};

struct NonWeightGrape
{
    NonWeightVertex* source;
    std::vector<NonWeightVertex*> vertexes;
    int vertexNum;
};

struct Edge
{
    int weight;
    WeightVertex* S;
    WeightVertex* E;
};

struct WeightVertex
{
    int id;
    int value;
    int distance;
    std::vector<Edge*> inEdge;
    std::vector<Edge*> outEdge;
    bool isVisit;
};

struct TwoIndexVertex : WeightVertex
{
    int x;
    int y;

    TwoIndexVertex(WeightVertex* v, int _x, int _y)
    {
        id= v->id;
        value = v->value;
        distance = v->distance;
        inEdge = v->inEdge;
        outEdge = v->outEdge;
        isVisit = v->isVisit;

        x = _x;
        y = _y;
    }
};

struct WeightGrape
{
    std::vector<WeightVertex*> vertexes;
    std::vector<Edge*> edges;
    int vertexNum;
    WeightVertex* source;
};

struct Matrix
{
    int** vlaue;
    int rowNum;
    int columnNum;
};