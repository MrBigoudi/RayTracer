#pragma once

#include "Vector3.hpp"
namespace maths{

/**
 * A class representing a ray as a line
*/
class Ray{

    public:
        /**
         * The origin of the ray
        */
        Vector3* mOrigin;

        /**
         * The direction of the ray
        */
        Vector3* mDirection;

    public:
        /**
         * A basic constructor
         * @param origin The origin of the ray
         * @param direction The direction of the ray
        */
        Ray(const Vector3 & origin, const Vector3 & direction){
            mOrigin = new Vector3(origin);
            mDirection = new Vector3(direction);
        };

        /**
         * Get a point in the ray
         * @param k The weight of the point along the ray direction
        */
        Vector3* getPoint(float k) const {
            // test if the point is after the origin
            assert(k >= 0.f);
            return new Vector3(((*mDirection)*k) + (*mOrigin));
        };

        /**
         * Cast a ray into a printable string
         * @return The ray as a string
        */
        std::string toString() const {
            char buffer[256];
            sprintf(buffer, "origin: %s\ndirection: %s", mOrigin->toString().c_str(), mDirection->toString().c_str());
            return buffer;
        };


};

};