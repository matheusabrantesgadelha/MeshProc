//
// Created by Matheus Gadelha on 08/07/2015.
//

#ifndef MESHPROC_EDGE_H
#define MESHPROC_EDGE_H

#include <memory>
#include <vector>
#include <glm/vec3.hpp>

template <class TMesh>
class TEdge {
    public:
		typedef typename TMesh::Vertex __Vertex__;
		typedef typename TMesh::HalfEdge __HalfEdge__;
		TEdge( __Vertex__* _v0, __Vertex__* _v1 ) 
			: v0( _v0 ), v1( _v1 ){}

		bool operator==(const TEdge& _rhs ) const
		{
			return (this->v0 == _rhs.v0 && this->v1 == _rhs.v1) ||
					(this->v0 == _rhs.v1 && this->v1 == _rhs.v0);
		}

		bool operator!=(const TEdge& _rhs ) const
		{
			return !(*this == _rhs);
		}

		__Vertex__* v0;
		__Vertex__* v1;

		__HalfEdge__* h0;
		__HalfEdge__* h1;
};


#endif //MESHPROC_EDGE_H
