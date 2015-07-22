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

		void addVertex(Vertex _vertex){ 
			_vertex.id = vertices.size();
			vertices.push_back(_vertex);
		}

		void addEdge(Edge _edge){ edges.push_back(_edge);}
		void addFace(Face _face){ 
			faces.push_back(_face);
		}

		void buildMesh()
		{
			for( Face face : faces )
			{
				int firstHE = 0, lastHE = 0;
				for( size_t i=0; i<face.vertices.size(); i++ )
				{
					Edge newEdge( face.vertices[i], 
							face.vertices[ (i+1) % face.vertices.size()] );

					HalfEdge he;
					he.source = face.vertices[i];
					he.target = face.vertices[ (i+1) % face.vertices.size()];
					he.face = &face;
					if( i > 0 ) he.prev = &halfedges[ halfedges.size()-1 ];
					halfedges.push_back( he );
					if( i== 0 ) firstHE = halfedges.size()-1;
					if( i==face.vertices.size()-1 ) lastHE = halfedges.size()-1;
					
					int edgeIdx = findEdge( newEdge );

					if( edgeIdx == -1 )
					{
						newEdge.h0 = &halfedges[ halfedges.size()-1 ];
						edges.push_back( newEdge );
					}
					else
					{
						edges[edgeIdx].h1 = &halfedges[ halfedges.size()-1 ];
						halfedges[ halfedges.size()-1 ].opposite = edges[edgeIdx].h0;
						edges[edgeIdx].h0->opposite = &halfedges[ halfedges.size()-1 ];
					}
				}

				for( size_t i=firstHE; i<=lastHE; ++i )
				{
					if( i != lastHE ) halfedges[i].next = &(halfedges[i+1]);
					else halfedges[i].next = &(halfedges[firstHE]);
				}
			}
		}
		
		int findEdge( Vertex* _v0, Vertex* _v1 ) const
		{
			for( size_t i = 0; i<edges.size(); ++i )
				if( edges[i] == Edge(_v0,_v1) )
					return i;

			return -1;
		}

		int findEdge( Edge _edge ) const
		{
			return findEdge( _edge.v0, _edge.v1 );
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
