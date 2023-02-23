#pragma once

#include <vector>
#include "Vector3.hpp"

namespace scene{

/**
 * An abstract class to represent textures
*/
class Texture_Material{
    public:
        /**
        * Get all the paramters for the texture and the material (kd, ks, ...) on a given point in the surface
        * @param coords The coordinates of the point
        */
        virtual std::vector<float> getParameters(const maths::Vector3 & coords) const = 0;

        /**
        * Cast a texture into a printable string
        * @return The texture as a string
        */
        virtual std::string toString() const = 0;

        /**
         * An empty destructor
        */
        ~Texture_Material(){};
};

};