#include <iostream>
#include <vector>
#include <list>
#include <memory>

#include "Mesh.h"

int main()
{
	Mesh<int> mesh;
	Mesh<int>::MeshVertex vertex( 15 );

	mesh.vertices.push_back( vertex );
	for( auto v : mesh.vertices )
		std::cout << v.data << std::endl;

    return 0;
}
