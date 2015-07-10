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
		TEdge( __Vertex__* _v0, __Vertex__* _v1 ) 
			: v0( _v0 ), v1( _v1 ){}

		__Vertex__* v0;
		__Vertex__* v1;
};


#endif //MESHPROC_EDGE_H
