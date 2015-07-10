#include <iostream>
#include <vector>
#include <list>
#include <memory>

#include "Mesh.h"

int main()
{
	Mesh<int> mesh;
	Mesh<int>::Vertex vertex( 15 );

	mesh.vertices.push_back( vertex );
	mesh.vertices.push_back( Mesh<int>::Vertex(18) );
	mesh.vertices.push_back( Mesh<int>::Vertex(18) );
	mesh.vertices.push_back( Mesh<int>::Vertex(18) );

	for( auto v : mesh.vertices )
		std::cout << v.data << std::endl;

    return 0;
}
