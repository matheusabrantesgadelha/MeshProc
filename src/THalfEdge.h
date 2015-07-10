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
	typedef typename TMesh::Face __Face__;

	public:

		THalfEdge(){}
		
		__Vertex__* source;
		__Vertex__* target;
		__HalfEdge__* prev;
		__HalfEdge__* next;
		__HalfEdge__* opposite;
		__Face__* face;

};


#endif //MESHPROC_HALFEDGE_H
