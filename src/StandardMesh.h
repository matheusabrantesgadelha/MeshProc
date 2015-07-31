#ifndef STANDARDMESH_H_
#define STANDARDMESH_H_

#include <tuple>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include "GenericMesh.h"

class StandardMesh : public GenericMesh< std::tuple<glm::vec3, glm::vec2> >
{
	public:

		static glm::vec3& getNormal( StandardMesh::Vertex _v )
		{
			return std::get<0>(_v.data);
		}

		static glm::vec2& getUV( StandardMesh::Vertex _v )
		{
			return std::get<1>(_v.data);
		}

		glm::vec3& getNormal( size_t _idx ) 
		{
			return getNormal( vertices[_idx] );
		}

		glm::vec2& getUV( size_t _idx ) 
		{
			return getUV( vertices[_idx] );
		}
};


#endif
