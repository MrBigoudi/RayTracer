#include <iostream>
#include <cstdlib>

#include <vector>

#include "Camera.hpp"
#include "Image.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include "Object.hpp"
#include "Sphere.hpp"
#include "rayTracer.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv){

    // utils::Image* image = new utils::Image(640, 480);
    // image->write("media/producedImages/test.ppm");

    // std::vector<std::vector<utils::Pixel*>> pixels;
    // for (int i=0; i<640; i++){
    //     std::vector<utils::Pixel*> pixelsTmp;
    //     float r = i/640.f;
    //     float g = r;
    //     float b = 1-i/640.f;
    //     for (int j=0; j<480; j++){
    //         pixelsTmp.push_back(new utils::Pixel(r, g, b, i, j));
    //     }
    //     pixels.push_back(pixelsTmp);
    // }

    // utils::Image* image = new utils::Image(pixels);
    // image->write("media/producedImages/test.ppm");

    scene::Object* sphere = (scene::Object*) new scene::Sphere(nullptr, new maths::Vector3(), 10.0f);
    std::vector<scene::Object*> objects;
    objects.push_back(sphere);

    scene::Camera* camera = new scene::Camera(0.0f, 1.7f, 1.7f, 100.0f, 
                                new maths::Vector3(0.0f, 0.0f, -10.0f), 
                                new maths::Vector3(1.0f, 1.0f, 1.0f),
                                new maths::Vector3(0.0f, 1.0f));

    scene::Scene* scene = new scene::Scene(objects, camera);
    
    utils::Image* results = render(*scene);
    results->write("media/producedImages/test1Sphere.ppm");

    exit(EXIT_SUCCESS);
}