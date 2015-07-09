//
// Created by netolcc06 on 08/07/2015.
//

#ifndef MESHPROC_VERTEX_H
#define MESHPROC_VERTEX_H

#include <glm/vec3.hpp>

template <typename T>
class Vertex {

    public:

        glm::vec3 position;

    private:
        T data;
};


#endif //MESHPROC_VERTEX_H
