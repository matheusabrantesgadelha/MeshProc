//
// Created by netolcc06 on 09/07/2015.
//

#ifndef MESHPROC_HALFEDGE_H
#define MESHPROC_HALFEDGE_H

#include <memory>


template <class TMesh>
class THalfEdge {
	typedef typename TMesh::Vertex __Vertex__;
	typedef typename TMesh::HalfEdge __HalfEdge__;

	public:

		THalfEdge(){}
		
		__Vertex__ source;
		__Vertex__ target;
		std::weak_ptr<__HalfEdge__> prev;
		std::weak_ptr<__HalfEdge__> next;
		std::weak_ptr<__HalfEdge__> opposite;

};


#endif //MESHPROC_HALFEDGE_H
