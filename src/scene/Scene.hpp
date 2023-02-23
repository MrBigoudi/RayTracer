#pragma once

#include <vector>
#include "Camera.hpp"
#include "Light.hpp"
#include "objects/Object.hpp"

namespace scene{

class Object;
class Light;
class Camera;

/**
 * A class to represent the main scene
*/
class Scene{

    public:
        /**
         * All the objects of the scene as a list
        */
        std::vector<Object*> mObjects;

        /**
         * All the light sources as a list
        */
        std::vector<Light*> mLights;

        /**
         * The camera of the scene
        */
        Camera* mCamera;


    public:
        /**
         * A basic constructor
         * @param objects The objects of the scene
         * @param camera The scene's camera
         * @param lights The scene's light sources
        */
        Scene(std::vector<Object*>objects = {}, Camera* camera = nullptr, std::vector<Light*>lights = {}){
            mObjects = objects;
            mCamera = camera;
            mLights = lights;
        }
    

};

}