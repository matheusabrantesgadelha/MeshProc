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

        glm::vec3 position;
		std::vector< std::weak_ptr<__HalfEdge__> > outHalfEdges;

        __VertexContent__ data;

		TVertex( __VertexContent__ _content ) : data( _content ){}
};


#endif //MESHPROC_VERTEX_H
