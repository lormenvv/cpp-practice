#ifndef GRAPH
#define GRAPH

#include <vector>
#include <utility>

typedef struct Vertex {
    int degree;
    char label;
} Vertex;

extern typedef std::pair<Vertex, Vertex> Edge;
extern std::vector<Vertex> vertexList;
extern std::vector<Edge> edgeList;
extern std::pair<std::vector<Vertex>, std::vector<Edge>> graph;


Vertex make_vertex();
void add_vertex(Vertex v);
void inc_degree(Vertex& v);
void add_edge(Vertex a, Vertex b);
void make_graph();
void print_graph();
void make_degree(std::vector<Vertex> vertexList, std::vector<Edge> edgeList);
std::vector<Vertex> getVertexList();
std::vector<Edge> getEdgeList();

#endif