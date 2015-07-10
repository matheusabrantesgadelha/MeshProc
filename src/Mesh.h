
//
// Created by MatheusGadelha on 10/07/2015.
//

#ifndef MESHPROC_MESH_H
#define MESHPROC_MESH_H

#include <vector>

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

		void addVertex(std::shared_ptr<Vertex> vertex){ vertices.push_back(vertex);}
		void printVerticesData(){for(int i=0; i<vertices.size();++i) std::cout << vertices[i]->data << std::endl;}
		std::vector<std::shared_ptr<Vertex> > vertices;
};



#endif
