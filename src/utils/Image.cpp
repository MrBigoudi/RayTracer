#include <fstream>

#include "Image.hpp"

using namespace utils;

bool Image::write(const std::string & file) const {
    // check whether we could create the file
    std::ofstream objFile(file);
    if (!objFile){
        std::fprintf(stderr, "Error, failed to open %s!\n", file.c_str());
        return false;
    }

    // put the metadata in the file
    objFile << "P3\n# width  height\n" << w() << " " << h() << "\n# max color\n" << Pixel::MAX_COLOR << "\n";

    // put the pixels' colors in the file
    for (int j=0; j<h(); j++){
        for (int i = 0; i < w(); i++){
            Pixel* pixelTmp = mPixels[i][j];
            objFile << " " << pixelTmp->r()
                    << " " << pixelTmp->g()
                    << " " << pixelTmp->b();
        }
        objFile << "\n";
    }

    return true;

}