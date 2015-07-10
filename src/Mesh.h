
//
// Created by MatheusGadelha on 10/07/2015.
//

#ifndef MESHPROC_MESH_H
#define MESHPROC_MESH_H

#include <vector>
#include <iostream>

#include "THalfEdge.h"
#include "TVertex.h"
#include "TFace.h"
#include "TEdge.h"

template< typename T >
class Mesh
{
	public:
		typedef Mesh<T> Self;
		typedef THalfEdge<Self> HalfEdge;
		typedef TFace<Self> Face;
		typedef TEdge<Self> Edge;
		typedef TVertex<Self> Vertex;
		typedef T VertexContent;

		Mesh()
		{
		}

		void addVertex(Vertex _vertex){ vertices.push_back(_vertex);}
		void addEdge(Edge _edge){ edges.push_back(_edge);}
		void addFace(Face _face){ faces.push_back(_face);}

		void buildStructure()
		{
			
		}

		void printVerticesData(){
			for(int i=0; i<vertices.size();++i) std::cout << vertices[i].data << std::endl;
		}

		std::vector<Vertex> vertices;
		std::vector<Edge> edges;
		std::vector<Face> faces;
		std::vector<HalfEdge> halfedges;
};



#endif
