#include <iostream>
#include <vector>
#include <list>
#include <memory>

#include "Mesh.h"

int main()
{
	Mesh<int> mesh;

	std::vector<std::weak_ptr<Mesh<int>::Vertex>> vertices;
	Mesh<int>::Vertex v0(0, glm::vec3(0,1,0));
	Mesh<int>::Vertex v1(1, glm::vec3(1,1,0));
	Mesh<int>::Vertex v2(2, glm::vec3(1,0,0));
	Mesh<int>::Vertex v3(3, glm::vec3(0,0,0));

	Mesh<int>::Face f0;
	f0.addVertex(&v0);
	f0.addVertex(&v3);
	f0.addVertex(&v1);

	Mesh<int>::Face f1;
	f1.addVertex(&v1);
	f1.addVertex(&v3);
	f1.addVertex(&v2);
//	std::shared_ptr<Mesh<int>::Edge> e0 = std::make_shared<Mesh<int>::Edge>(v0,v1);
//	std::shared_ptr<Mesh<int>::Edge> e1 = std::make_shared<Mesh<int>::Edge>(v1,v2);
//	std::shared_ptr<Mesh<int>::Edge> e2 = std::make_shared<Mesh<int>::Edge>(v2,v3);
//	std::shared_ptr<Mesh<int>::Edge> e3 = std::make_shared<Mesh<int>::Edge>(v3,v0);
//	std::shared_ptr<Mesh<int>::Edge> e4 = std::make_shared<Mesh<int>::Edge>(v3,v1);

	mesh.addVertex(v0);
	mesh.addVertex(v1);
	mesh.addVertex(v2);
	mesh.addVertex(v3);

	mesh.addFace(f0);
	mesh.addFace(f1);
//	mesh.addEdge(e0);
//	mesh.addEdge(e1);
//	mesh.addEdge(e2);
//	mesh.addEdge(e3);
//	mesh.addEdge(e4);

	//mesh.addVertex(new Mesh<int>::Vertex(18));
	//mesh.addVertex(new Mesh<int>::Vertex(198987));

	//for( auto v : mesh.vertices )
	//	std::cout << v.data << std::endl;

	mesh.printVerticesData();

    return 0;
}
