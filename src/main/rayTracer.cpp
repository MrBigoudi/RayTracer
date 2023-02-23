#include "rayTracer.hpp"
#include "Camera.hpp"
#include "Image.hpp"
#include "Ray.hpp"
#include "Scene.hpp"
#include "Object.hpp"

#include <vector>

utils::Image* render(const scene::Scene & scene){
    scene::Camera* camera = scene.mCamera;
    std::vector<scene::Object*> objects = scene.mObjects; 

    // create a black image
    int width = camera->mWidth;
    int height = camera->mHeight;
    utils::Image* image = new utils::Image(width, height);

    // cast a ray for every pixels of the camera
    for(int x=0; x<width; x++){
        for(int y=0; y<height; y++){
            maths::Ray* curRay = camera->pixelToRay(x, y);
            //check if the ray intersect an object
            for(int i=0; i<int(objects.size()); i++){
                if(objects[i]->doesRayIntersect(*curRay, camera->mZmin))
                    image->mPixels[x][y] = new utils::Pixel(1.0f, 1.0f, 1.0f, x, y);
            }
        }
    }

    return image;
}