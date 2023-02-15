#pragma once

#include "Vector3.hpp"

namespace utils {

/**
 * A class to manipulate a pixel
*/
class Pixel{

    public:
        /**
         * The pixel color
        */
        maths::Vector3* mColor;

        /**
         * The pixel position
        */
        int mPos[2];

        /**
         * The max color for a pixel
        */
        static const int MAX_COLOR = 255;

    public:
        /**
         * A basic constructor
         * @param color The pixel's color
         * @param x The pixel abscissa
         * @param y The pixel ordinate
        */
        Pixel(maths::Vector3* color, int x, int y){
            mColor = color;
            mPos[0] = x;
            mPos[1] = y;
        }

        /**
         * A basic constructor
         * @param r The pixel color's red component
         * @param g The pixel color's green component
         * @param b The pixel color's blue component
         * @param x The pixel abscissa
         * @param y The pixel ordinate
        */
        Pixel(float r, float g, float b, int x, int y){
            mColor = new maths::Vector3(r,g,b,maths::COLOR);
            mPos[0] = x;
            mPos[1] = y;
        }

        /**
         * A constructor by copy
         * @param pixel The pixel to copy
        */
        Pixel(const Pixel & pixel){
            mColor = new maths::Vector3(pixel.mColor);
            mPos[0] = pixel.mPos[0];
            mPos[1] = pixel.mPos[1];
        }

        // GETTERS
        /**
         * A getter for the pixel's abscissa
         * @return The pixel's abscissa
        */
        int x() const {return mPos[0];}

        /**
         * A getter for the pixel's ordinate
         * @return The pixel's ordinate
        */
        int y() const {return mPos[1];}

        /**
         * A getter for the pixel's colour
         * @return The pixel's colour
        */
        maths::Vector3* c() const {return mColor;}

        /**
         * A getter for the pixel's red component converted into an int between 0 and 255
         * @return The pixel's red component
        */
        int r() const {return int(mColor->r() * MAX_COLOR);}

        /**
         * A getter for the pixel's green component converted into an int between 0 and 255
         * @return The pixel's green component
        */
        int g() const {return int(mColor->g() * MAX_COLOR);}

        /**
         * A getter for the pixel's blue component converted into an int between 0 and 255
         * @return The pixel's blue component
        */
        int b() const {return int(mColor->b() * MAX_COLOR);}
};

}