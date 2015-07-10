//
// Created by netolcc06 on 09/07/2015.
//

#ifndef MESHPROC_HALFEDGE_H
#define MESHPROC_HALFEDGE_H

template <class TMesh>
class HalfEdge {
	typedef typename TMesh::MeshVertex __Vertex__;

	public:
		
		__Vertex__ source;
		__Vertex__ target;
};


#endif //MESHPROC_HALFEDGE_H