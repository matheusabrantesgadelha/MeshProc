#ifndef MESHLOADER_H_
#define MESHLOADER_H_

#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
#include <vector>

#include "StandardMesh.h"
std::vector<int> parseFaceVData( std::string _s );

bool loadObj( StandardMesh& _mesh, const std::string _path )
{
	std::ifstream file( _path );
	std::string line;
	std::vector<glm::vec3> vPositions;
	std::vector<glm::vec2> vts;
	std::vector<glm::vec3> vns;
	while( std::getline( file, line ))
	{
		std::stringstream lineStream;
		lineStream << line;
		std::string lineId;
		lineStream >> lineId;
		if( lineId == "v" )
		{
			glm::vec3 vertexPos;
			lineStream >> vertexPos.x >> vertexPos.y >> vertexPos.z;
			vPositions.push_back(vertexPos);
			StandardMesh::Vertex v = StandardMesh::Vertex( vertexPos );
			_mesh.addVertex( v );
			std::cout << vertexPos.x << " " << vertexPos.y << " " << vertexPos.z << std::endl;
		}
		if( lineId == "vt" )
		{
			glm::vec2 vt;
			lineStream >> vt.x >> vt.y;
			vts.push_back(vt);
			std::cout << vt.x << " " << vt.y << std::endl;
		}
		if( lineId == "vn" )
		{
			glm::vec3 vn;
			lineStream >> vn.x >> vn.y >> vn.z;
			vns.push_back(vn);
			std::cout << vn.x << " " << vn.y << " " << vn.z << std::endl;
		}
		if( lineId == "f" )
		{
			std::string vdata;
			StandardMesh::Face face;
			while( lineStream >> vdata )
			{
				std::vector<int> data = parseFaceVData( vdata );
				size_t vidx = data[0]-1;
				face.addVertex( &_mesh.vertices[vidx] );
			}
			_mesh.addFace( face );
		}
	}
	return true;
}

std::vector<int> parseFaceVData( std::string _s )
{
	std::vector<int> result;
	std::stringstream stream (_s);
	std::string piece;
	while( std::getline( stream, piece, '/' ))
	{
		if( !piece.empty() )
		{
			result.push_back(std::stoi(piece));
		}
	}
	return result;
}

#endif
