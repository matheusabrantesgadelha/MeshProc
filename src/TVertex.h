//
// Created by netolcc06 on 08/07/2015.
//

#ifndef MESHPROC_VERTEX_H
#define MESHPROC_VERTEX_H

#include <memory>
#include <vector>
#include <glm/vec3.hpp>

template <class TMesh>
class TVertex {
    public:
		typedef typename TMesh::HalfEdge __HalfEdge__;
		typedef typename TMesh::VertexContent __VertexContent__;

		TVertex( __VertexContent__ _content, glm::vec3 _position ) 
			: data( _content ), position( _position ){}

		TVertex( glm::vec3 _position ) 
			: position( _position ){}

        __VertexContent__ data;
        glm::vec3 position;
		std::vector< __HalfEdge__* > outHalfEdges;

		int id;
};


#endif //MESHPROC_VERTEX_H
