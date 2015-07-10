#include <iostream>
#include <vector>
#include <list>
#include <memory>

#include "Mesh.h"

int main()
{
	Mesh<int> mesh;

	std::vector<std::weak_ptr<Mesh<int>::Vertex>> vertices;
	std::shared_ptr<Mesh<int>::Vertex> vertex = std::make_shared<Mesh<int>::Vertex>(87);

	mesh.addVertex(vertex);
	mesh.addVertex(std::make_shared<Mesh<int>::Vertex>(123));
	//mesh.addVertex(new Mesh<int>::Vertex(18));
	//mesh.addVertex(new Mesh<int>::Vertex(198987));

	//for( auto v : mesh.vertices )
	//	std::cout << v.data << std::endl;

	mesh.printVerticesData();

    return 0;
}
