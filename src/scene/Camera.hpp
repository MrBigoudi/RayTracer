#pragma once

#include "Vector3.hpp"
#include "Ray.hpp"

#include <cmath>

namespace scene{

/**
 * The scene's camera
*/
class Camera{

    public:
        /**
         * The camera's focal length
        */
        float mFocal;

        /**
         * Fov angle in the x direction
        */
        float mAlpha;

        /**
         * Fov angle in the y direction
        */
        float mBeta;

        /**
         * Position of the image plane
        */
        float mZmin;

        /**
         * Width of the image plane
        */
        int mWidth;

        /**
         * Height of the image plane
        */
        int mHeight;

        /**
         * The camera's position
        */
        maths::Vector3* mPosition;

        /**
         * The camera's spotted point
        */
        maths::Vector3* mSpotted;

        /**
         * The direction of the sky
        */
        maths::Vector3* mUp;


    public:
        /**
         * A basic constructor
         * @param f The focal length
         * @param alpha The fov angle in the x direction
         * @param beta The fov angle int the y direction
         * @param zmin The position of the image plane
         * @param pos The camera's position
         * @param spotted The camera's spotted point
         * @param up The direction of the sky
        */
        Camera(float f, float alpha, float beta, float zmin, const maths::Vector3 & pos, const maths::Vector3 & spotted, const maths::Vector3 & up){
            mFocal = f;
            mAlpha = alpha;
            mBeta = beta;
            mZmin = zmin;
            mWidth  = (int)(tan(alpha/2.0f)*zmin)<<1;
            mHeight = (int)(tan(beta /2.0f)*zmin)<<1;
            mPosition = new maths::Vector3(pos);
            mSpotted = new maths::Vector3(spotted);
            mUp = new maths::Vector3(up);
        }

        /**
         * Turn a pixel into a ray
         * @param pixelX The pixel's abscissa
         * @param pixelY The pixel's ordinate
         * @return A ray 
        */
        maths::Ray* pixelToRay(int pixelX, int pixelY){
            maths::Vector3* destination = new maths::Vector3(pixelX, pixelY, mZmin);
            maths::Vector3* direction = new maths::Vector3((destination-mPosition));
            direction->normalize();
            return new maths::Ray(mPosition, direction);
        };

        /**
         * Cast a camera into a printable string
         * @return The camera as a string
        */
        std::string toString() const {
            char buffer[256];
            sprintf(buffer, "focal: %f, alpha: %f, beta: %f, zmin: %f, width: %d, height: %d\nposition: %s\nspotted: %s\nup: %s", 
                        mFocal, mAlpha, mBeta, mZmin, mWidth, mHeight,
                        mPosition->toString().c_str(), mSpotted->toString().c_str(), mUp->toString().c_str());
            return buffer;
        };
};

}