//
// Created by Matheus Gadelha on 08/07/2015.
//

#ifndef MESHPROC_FACE_H
#define MESHPROC_FACE_H

#include <memory>
#include <vector>
#include <glm/vec3.hpp>

template <class TMesh>
class TFace {
    public:
		typedef typename TMesh::HalfEdge __HalfEdge__;
		typedef typename TMesh::Vertex __Vertex__;
		TFace(){}
		TFace( __HalfEdge__* _halfEdge ) : halfEdge( _halfEdge ){}
		TFace( std::vector<__Vertex__* >& _vertices ) 
			: vertices( _vertices ){}

		void addVertex( __Vertex__* _v )
		{
			vertices.push_back( _v );
		}

		__HalfEdge__* halfEdge;
		std::vector< __Vertex__* > vertices;
};


#endif //MESHPROC_FACE_H
