#pragma once

#include "Texture_Material.hpp"
#include "Vector3.hpp"
#include "Ray.hpp"

namespace scene{

class Texture_Material;

/**
 * A virtual class representing an object
*/
class Object{

    public:
        /**
        * The object's texture
        */
        Texture_Material* mTexture;

        /**
        * Check if a given ray intersects the object
        * @param ray A ray
        * @param limit The max number of iterations
        * @return nullptr if it doesn't, the coordinates of the intersection point if it does
        */
        virtual maths::Vector3* doesRayIntersect(const maths::Ray & ray, int limit) const = 0;

        /**
        * Check if a given point is in the object
        * @param point The point we want to test
        * @return Ture if it is, Flase if it isn't
        */
        virtual bool isPointInObject(const maths::Vector3 & point) const = 0;

        /**
        * Get the normal at a given point
        * @param point The point at which we want the normal
        * @return The normal to the surface at the specific point
        */
        virtual maths::Vector3* getNormal(const maths::Vector3 & point) const = 0;

        /**
        * Get the texture at a given point
        * @param point The point at which we want the texture
        * @return The texture at the specific point
        */
        virtual std::vector<float> getTextureParameters(const maths::Vector3 & point) const{
            return mTexture->getParameters(point);
        };

        /**
        * Cast an object into a printable string
        * @return The object as a string
        */
        virtual std::string toString() const = 0;

        /**
         * An empty destructor
        */
        ~Object(){};

};

};