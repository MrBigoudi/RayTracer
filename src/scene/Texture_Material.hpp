#pragma once

#include <vector>
#include "Vector3.hpp"

namespace scene{

/**
 * An abstract class to represent textures
*/
struct Texture_Material{
    /**
     * Get all the paramters for the texture and the material (kd, ks, ...) on a given point in the surface
     * @param coords The coordinates of the point
    */
    virtual std::vector<float> getParameters(const maths::Vector3 & coords) const;

    /**
     * Cast a texture into a printable string
     * @return The texture as a string
    */
    virtual std::string toString() const;
};

};