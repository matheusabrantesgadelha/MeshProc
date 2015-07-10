
//
// Created by MatheusGadelha on 10/07/2015.
//

#ifndef MESHPROC_MESH_H
#define MESHPROC_MESH_H

#include "HalfEdge.h"
#include "Vertex.h"

template< typename T >
class Mesh
{
	public:
		typedef Mesh<T> Self;
		typedef HalfEdge<Self> MeshHalfEdge;
		typedef Vertex<Self> MeshVertex;
		typedef T MeshVertexContent;

		Mesh()
		{
		}

		std::vector<MeshVertex> vertices;
};



#endif
