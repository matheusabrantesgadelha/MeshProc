
//
// Created by MatheusGadelha on 10/07/2015.
//

#ifndef MESHPROC_MESH_H
#define MESHPROC_MESH_H

#include "THalfEdge.h"
#include "TVertex.h"

template< typename T >
class Mesh
{
	public:
		typedef Mesh<T> Self;
		typedef THalfEdge<Self> HalfEdge;
		typedef TVertex<Self> Vertex;
		typedef T VertexContent;

		Mesh()
		{
		}

		std::vector<Vertex> vertices;
};



#endif
