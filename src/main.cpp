#include <iostream>
#include <vector>
#include <list>
#include <memory>

#include "Mesh.h"

int main()
{
	Mesh<int> mesh;

	Mesh<int>::Vertex v0(0, glm::vec3(0,1,0));
	Mesh<int>::Vertex v1(1, glm::vec3(1,1,0));
	Mesh<int>::Vertex v2(2, glm::vec3(1,0,0));
	Mesh<int>::Vertex v3(3, glm::vec3(0,0,0));

	mesh.addVertex(v0);
	mesh.addVertex(v1);
	mesh.addVertex(v2);
	mesh.addVertex(v3);

	Mesh<int>::Face f0;
	f0.addVertex(&mesh.vertices[0]);
	f0.addVertex(&mesh.vertices[3]);
	f0.addVertex(&mesh.vertices[1]);

	Mesh<int>::Face f1;
	f1.addVertex(&mesh.vertices[1]);
	f1.addVertex(&mesh.vertices[3]);
	f1.addVertex(&mesh.vertices[2]);
//	std::shared_ptr<Mesh<int>::Edge> e0 = std::make_shared<Mesh<int>::Edge>(v0,v1);
//	std::shared_ptr<Mesh<int>::Edge> e1 = std::make_shared<Mesh<int>::Edge>(v1,v2);
//	std::shared_ptr<Mesh<int>::Edge> e2 = std::make_shared<Mesh<int>::Edge>(v2,v3);
//	std::shared_ptr<Mesh<int>::Edge> e3 = std::make_shared<Mesh<int>::Edge>(v3,v0);
//	std::shared_ptr<Mesh<int>::Edge> e4 = std::make_shared<Mesh<int>::Edge>(v3,v1);

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
	mesh.buildMesh();
	std::cout << "Num. of Halfedges: " << mesh.halfedges.size() << std::endl;
	std::cout << "Num. of Edges: " << mesh.edges.size() << std::endl;

	for( auto he : mesh.halfedges )
	{
		std::cout << he << std::endl;
	}

	mesh.printVerticesData();

    return 0;
}
