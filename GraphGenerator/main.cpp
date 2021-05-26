#include <iostream>
#include <vector>
#include <utility>
#include "graph.h"

int main() {
	char response;

	//initialization
	std::cout << "The graph has been initialized. Choose starting vertex? (Y/N)";
	std::cin >> response;
	if ((response == 'Y' || response == 'y')) {
		Vertex v1 = make_vertex();
		std::cout << "Connect vertex with another vertex? (Y/N)";
		std::cin >> response; //if yes, create vertices A, B and create edge (A, B) to start off the graph. if no, create vertex A and stop there
		if ((response == 'Y' || response == 'y')) {
			Vertex v2 = make_vertex();
			add_edge(v1, v2);
		}
	} else if ((response == 'N' || response == 'n')) {
		std::cout << "This graph has no vertices or edges! Kinda lonely..." << std::endl;
		return 0;
	}

	
	//main loop
	bool cont = true; //boolean for main loop
	int vPos; //position for which vertex to connect with
	int vNum = 0; //helps list out the vertex in numerical order
	while (cont) {
		std::cout << std::endl;
		std::cout << "Choose next vertex? (Y/N)";
		std::cin >> response;
		if ((response == 'Y' || response == 'y')) {
			Vertex v = make_vertex();
			std::cout << "Vertex " << v.label << " has been generated. Connect vertices? (Y/N)";
			std::cin >> response;
			while ((response == 'Y' || response == 'y')) {
				std::cout << "Connect this vertex with which existing vertices? (Select the number of the position of the vertex you want.)" << std::endl;
				for (Vertex& v : getVertexList()) {
					vNum++;
					std::cout << vNum << ". " << v.label << std::endl;
				}
				std::cin >> vPos;
				add_edge(getVertexList()[vPos - 1], v);
				vNum = 0;
				std::cout << "Connect another? (Y/N)";
				std::cin >> response;
			}
		} else if ((response == 'N' || response == 'n')) {
			print_graph();
			std::cout << std::endl;
			make_degree(getVertexList(), getEdgeList());
			cont = false;
		}
	}
	return 0;
}