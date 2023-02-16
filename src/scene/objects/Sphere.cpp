#include "Sphere.hpp"
#include "Vector3.hpp"
#include <cstddef>

using namespace scene;

bool Sphere::isPointInObject(const maths::Vector3 & point) const {
    return maths::Vector3::distance(point, mOrigin) <= mRadius;
}

maths::Vector3* Sphere::doesRayIntersect(const maths::Ray & ray, int limit) const {   
    maths::Vector3* curRayPoint = ray.mOrigin;
    float k;
    for(int i=0; i<limit; i++){
        k = i*mRadius; // we're checking every || radius || to avoid unnecessary computations
        curRayPoint = ray.getPoint(k);
        if(isPointInObject(curRayPoint))
            return curRayPoint;
    }

    return nullptr;
}

maths::Vector3* Sphere::getNormal(const maths::Vector3 & point) const {
    return new maths::Vector3((point - mOrigin).normalize());
}

std::string Sphere::toString() const {
    char buffer[256];
    sprintf(buffer, "texture: %s\norigin: %s, radius: %f", mTexture->toString().c_str() ,mOrigin->toString().c_str(), mRadius);
    return buffer;
};

