//
// Created by netolcc06 on 09/07/2015.
//

#ifndef MESHPROC_HALFEDGE_H
#define MESHPROC_HALFEDGE_H

#include <memory>
#include <iostream>

template <class TMesh>
class THalfEdge {
	typedef typename TMesh::Vertex __Vertex__;
	typedef typename TMesh::HalfEdge __HalfEdge__;
	typedef typename TMesh::Face __Face__;

	public:

		THalfEdge(){}

		friend std::ostream& operator<<( std::ostream& _out, THalfEdge _he )
		{
			_out << "{ Vertex source: " << _he.source->id 
				<< ", Vertex target: " << _he.target->id 
				<< " }";
			return _out;
		}
		
		__Vertex__* source;
		__Vertex__* target;
		__HalfEdge__* prev;
		__HalfEdge__* next;
		__HalfEdge__* opposite;
		__Face__* face;

};


#endif //MESHPROC_HALFEDGE_H
