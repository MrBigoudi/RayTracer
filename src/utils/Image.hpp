#pragma once

#include <vector>
#include <string>

#include "Pixel.hpp"

namespace utils {

/**
 * A class to manipulate images as files
*/
class Image{

    public:
        /**
         * A matrix of pixels
        */
        std::vector<std::vector<Pixel*>> mPixels;

        /**
         * The image dimensions
        */
        int mDim[2];

    public:
        /**
         * Construct a black image of the given size
         * @param w The image's width
         * @param h The image's height
        */
        Image(int w, int h){
            mDim[0] = w;
            mDim[1] = h;

            for (int i=0; i<w; i++){
                std::vector<Pixel*> col;
                for (int j=0; j<h; j++){
                    col.push_back(new Pixel(0.0f, 0.0f, 0.0f, i, j));
                }
                mPixels.push_back(col);
            }
        }

        /**
         * Construct an image given a matrix of pixels
         * @param pixels The pixel matrix
        */
        Image(const std::vector<std::vector<Pixel*>> & pixels){
            mDim[0] = pixels.size();
            mDim[1] = pixels[0].size();
            for (int i=0; i<int(pixels.size()); i++){
                std::vector<Pixel*> col;
                for (int j=0; j<int(pixels[0].size()); j++){
                    col.push_back(new Pixel(*pixels[i][j]));
                }
                mPixels.push_back(col);
            }
        }

        /**
         * Constructor by copy
         * @param image The image we want to copy
        */
        Image(const Image& image){
            Image(image.mPixels);
        }

        // GETTERS
        /**
         * The image width
        */
        int w() const {return mDim[0];}

        /**
         * The image height
        */
        int h() const {return mDim[1];}


        /**
         * Write an image into a given file in the PPM format (http:
//netpbm.sourceforge.net/doc/ppm.html)
         * @param file The file we'll produce
        */
        bool write(const std::string & file) const;

};

}