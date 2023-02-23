#pragma once

#include "Object.hpp"
#include "Texture_Material.hpp"
#include "Vector3.hpp"

namespace scene{

/**
 * A class to represent a sphere
*/
class Sphere : Object{

    public:
        /**
         * The origin of the sphere
        */
        maths::Vector3* mOrigin;

        /**
         * The radisu of the sphere
        */
        float mRadius;

    public:
        /**
         * A basic constructor
         * @param texture The sphere's texture
         * @param origin The sphere's origin
         * @param radius The sphere's radius
        */
        Sphere(Texture_Material* texture, const maths::Vector3 & origin = new maths::Vector3(), float radius = 1.0f){
            mTexture = texture;
            mOrigin = new maths::Vector3(origin);
            mRadius = radius;
        }

        /**
        * Check if a given ray intersects the object
        * @param ray A ray
        * @param limit The max number of iterations
        * @return nullptr if it doesn't, the coordinates of the intersection point if it does
        */
        maths::Vector3* doesRayIntersect(const maths::Ray & ray, int limit) const override;

        /**
         * Check if a given point is in the object
         * @param point The point we want to test
         * @return Ture if it is, Flase if it isn't
        */
        virtual bool isPointInObject(const maths::Vector3 & point) const override;

        /**
        * Get the normal at a given point
        * @param point The point at which we want the normal
        * @return The normal to the surface at the specific point
        */
        maths::Vector3* getNormal(const maths::Vector3 & point) const override;

        /**
        * Get the texture at a given point
        * @param point The point at which we want the texture
        * @return The texture at the specific point
        */
        std::vector<float> getTextureParameters(const maths::Vector3 & point) const override{
            return mTexture->getParameters(point);
        };

        /**
        * Cast an object into a printable string
        * @return The object as a string
        */
        std::string toString() const override;


};

};