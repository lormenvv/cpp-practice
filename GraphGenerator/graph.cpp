#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include "graph.h"


typedef std::pair<Vertex, Vertex> Edge;
std::vector<Vertex> vertexList;
std::vector<Edge> edgeList;
std::pair<std::vector<Vertex>, std::vector<Edge>> graph;
static int ascii_char = 97; //starts at 'a'



Vertex make_vertex() {
	Vertex v;
	v.label = ascii_char;
	v.degree = 0;
	ascii_char++;
	add_vertex(v);
	return v;
}

void add_vertex(Vertex v) {
	vertexList.push_back(v);
}

void inc_degree(Vertex& v) {
	v.degree++;
}


void add_edge(Vertex a, Vertex b) {
	Edge edge = std::make_pair(a, b);
	edgeList.push_back(edge);
}

void make_graph() {
	graph = std::make_pair(vertexList, edgeList);
}


void print_graph() {
	std::cout << "G = (V, E), where V = {";
	for (Vertex& v : vertexList) {
		std::cout << v.label << ", ";
	}
	std::cout << "}, and ";

	std::cout << "E = {";
	for (Edge& e : edgeList) {
		std::cout << "(" << e.first.label << ", " << e.second.label << ")" << ", ";
	}
	std::cout << "}";
}

void make_degree(std::vector<Vertex> vertexList, std::vector<Edge> edgeList) {
	std::map<char, int> degrees;
	bool isConnected;
	for (Edge& e : edgeList) {
		if (degrees.find(e.first.label) == degrees.end() && degrees.find(e.second.label) == degrees.end()) {
			degrees[e.first.label] = 1;
			degrees[e.second.label] = 1;
		} else {
			degrees[e.first.label]++;
			if (degrees.find(e.second.label) == degrees.end()) {
				degrees[e.second.label] = 1;
			}
			else {
				degrees[e.second.label]++;
			}
		}
	}

	for (auto itr = degrees.begin(); itr != degrees.end(); ++itr) {
		std::cout << "Degree of Vertex " << itr->first << ": " << itr->second << std::endl;
	}

	for (Vertex& v : vertexList) {
		if (degrees.find(v.label) == degrees.end()) {
			std::cout << "Vertex " << v.label << " is a vertex with degree 0." << std::endl;
			isConnected = false;
		}
	}
	if (vertexList.size() != 1) {
		std::cout << "This graph is a disconnected graph." << std::endl;
	}
}

std::vector<Vertex> getVertexList() {
	return vertexList;
}

std::vector<Edge> getEdgeList() {
	return edgeList;
}