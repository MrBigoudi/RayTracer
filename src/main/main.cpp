#include <iostream>
#include <cstdlib>

#include <vector>

#include "Image.hpp"
#include "Scene.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv){

    // utils::Image* image = new utils::Image(640, 480);
    // image->write("media/producedImages/test.ppm");

    std::vector<std::vector<utils::Pixel*>> pixels;
    for (int i=0; i<640; i++){
        std::vector<utils::Pixel*> pixelsTmp;
        float r = i/640.f;
        float g = r;
        float b = 1-i/640.f;
        for (int j=0; j<480; j++){
            pixelsTmp.push_back(new utils::Pixel(r, g, b, i, j));
        }
        pixels.push_back(pixelsTmp);
    }

    utils::Image* image = new utils::Image(pixels);
    image->write("media/producedImages/test.ppm");

    exit(EXIT_SUCCESS);
}